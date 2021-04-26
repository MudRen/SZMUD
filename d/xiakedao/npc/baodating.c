//Cracked by Roath
// baodating.c 
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

void greeting(object);

string *home_locations = ({
	"/d/xiakedao/shatan",
	"/d/xiakedao/pubu",
	"/d/xiakedao/dadong",
	"/d/xiakedao/xiakexing1",
});

string* secret = ({
	"������� "+HBRED+HIW+"help"NOR+" ����һЩ�����Ķ��������������֪�������ġ�",
	"��˵�䵱���ŵ����δ����Ƕ��б��ؼ�������ѧ�ڹ��ġ�",
	"��˵�������е���������һ������Ṧ�ؾ��ľ���Ƭ��",
	"��˵��ɽ��������һ�������ϳ˽�����ɽ����",
	"��˵ʧ���Ѿõ�ԧ�����������ݸ����������С�",
	"��˵�䵱ɽ�µ������п���ʰ�������������м�������˲ι���",
	"��˵�����±�������һ�ſ����ϳ�ȭ�ƹ����ʯ����",
});

string *greet = ({
	"���֪���������ֶ�����Щ���ɣ�",
	"���֪��ÿ�����ɵ�������",
	"���֪��ÿ����������Щ�书��",
	"���֪��ÿ�����ɶ���Щʲ�����",
});
	
void create()
{
	set_name("�ⲻ��", ({ "wu buzhi", "wu"}));
	set("nickname", "������");
	set("long", 
"һλ���ݵ�С��ͷ�������۹�������ת��һ�����������ӡ���˵��֪
���ܶ��������ܡ�\n");
	set("gender", "����");
	set("age", 60);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("race", "����");	
	set("max_qi", 200);
	set("eff_qi", 200);
	set("qi", 200);
	set("max_jing", 200);
	set("eff_jing", 200);
	set("jing", 200);
	set("max_neili", 200);
	set("eff_neili", 200);
	set("neili", 200);
	set("max_jingli", 200);
	set("eff_jingli", 200);
	set("jingli", 200);
	set("combat_exp", 10000);
	set("score", 1000);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("cuff", 20);
	set_skill("sword", 20);
      set("chat_chance", 2);
	set("chat_msg", 
	    ({
      	"��������: ��������������֪���Ҳ�֪������һ��û��֪���ˡ�\n",
      	"��������: ����֪��Щ������\n",
      	"��������: ��˵�����͵���Ϫˮ����һ�ֹ��㡣\n",	
      	"��������: ��˵���͵�����λ�����������Ͷ���������ʮ���ˡ�\n",	
      	"��������: ��˵���Ͷ�����书�����µ�һ����û��ѧ���ء�\n",	
		(: random_move :),
	    }) );

	setup();
}

void init()
{
        object me = this_player();        
	  object home;
        home = load_object(home_locations[random(sizeof(home_locations))]);
//	  move(home);

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	int total, i;
	total = sizeof(greet);
	i = random(total);
//	command("say " + i);
//	command("say ����֪����");
	command("say " + greet[i] + "�������Ҹ�����
���Ҹ����㣬����Щʲ���ʾ�أ�");
}
int accept_object(object who, object ob)
{	object me = this_player();
	int count;
	count = (int) me->query_temp("secret");
	if (count == -1)
	{	command("say ���������㣬����û���ˡ�\n");
		command("dunno "+ me->query("id"));
		return 1;	
	}
	if (random(5) > 2)
	{	command("whisper " + me->query("id") + " ����ﲻ����"+HBRED+HIW"help"NOR+"��");
		return 1;
	}
	if (count == 0)
	{	
		command("papaya " + me->query("id") );
		command("whisper "+ me->query("id") + " " + (secret[count]));
		command("hehe " + me->query("id"));
		count = count + 1;
	}
	else if (count < sizeof(secret))
	{	command("whisper "+ me->query("id") + " " + secret[count]);
		count = count + 1;
	}
	else
	{	count = -1;
	}
	me->set_temp("secret", count);
	return 1;
}
