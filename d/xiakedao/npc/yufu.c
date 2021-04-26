//Cracked by Roath
// yufu.c ���͵����
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

int ask_leave();
int do_enter();
void greeting(object);

void create()
{
	set_name("���", ({ "yu fu", "fu"}));
	set("long", "������ȥ�������ͨͨ�������������Ц�ݡ�\n");
	set("gender", "����");
	set("age", 40);
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
	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("cuff", 30);
	set_skill("sword", 30);
	
	set("inquiry", ([
			"���͵�" :	"����������͵�����λ����ÿ�궼�ɵ��ӵ���ԭ����Ѱ���ʲ����������ϵ�������ǽ��걻ѡ�ϵİɡ�\n",
			"��"     : 	"�Ǵ����ҵġ�\n",
			"��ԭ"   : 	(: ask_leave :),
			"����"   : 	"������������ɽ\n",
			"�뵺"   :  (: ask_leave :),
		]));
	setup();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	object room;
	if ((int)me->query_temp("marks/��") == 1)
	{	
		command("say ��ϲ����ϲ������Ի���ԭ�ˡ�");
	}
	else if ((int)me->query_temp("marks/��") == 2)
	{	
		command("whisper " + me->query("id") + " ���ϴ��ɡ��𱻱��˿����ˡ�(enter)");
	}
	else
	{	if (me->query_temp(this_object()->query("id")) == 0 )
		{	command("hi " + me->query("id"));
			command("say 
          �㲻���Ĵ�����(look)��������ʲ�ᶫ���㶼���Լ�����
    (get)���š�������Ȳ��(i or inventory)��������������Щʲ
    �ᡣ��Ҫ��ʱ�ز��(hp)�������״̬��Ҫ�Ƕ��˻���˾�ȥ��
    Щ�Եĺȵİɡ���Ҫ����ʲ������������ҡ�
    "+HBRED+HIW"(ask fu about ���͵���ask fu about �뵺)"NOR);
			me->set_temp(this_object()->query("id"), 1);

		}
	}
}
int ask_leave()
{	object me = this_player();
	if ((int)me->query_temp("marks/��"))
	{	
		command("say ��ϲ����ϲ������Ի���ԭ�ˡ�");
	}
	else
	{	command("shake " + me->query("id"));
		command("say Ҫȥ��ԭ�ɵ�Ҫ����ͬ����У���Ҳ����˽�Գ���������\n" +
			"�����е�С�ɣ������ͻ������뵺����ԭȥ�������ˡ�");
	}
	return 1;
}
int accept_object(object me, object ob)
{	
	if (ob->query("id") != "fish")
	{	message_vision("����$Nҡ��ҡͷ��˵�������Լ����Űɡ�\n", me);
		return 0;
	}
	if (ob->query("speical") == 0)
	{	message_vision("���ӹ�$N���е�$n���˿�����$Nҡ��ҡͷ˵���������㵽�����ǣ��Լ����Űɡ�\n", me, ob);
		return 0;
	}
	message_vision("����˸߲��ҵؽӹ�$N���е�$n��\n", me, ob);
	command("whisper " + me->query("id") + " ���һ����ٻ������ɱ𱻱��˿����ˡ�");
	me->set_temp("marks/��", 2);
	return 1;
}
