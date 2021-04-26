//Cracked by Roath
// puren.c ���͵�����
// Long, 6/13/97
// Update Ssy 5/3/98

#include <ansi.h>

inherit NPC;

int ask_leave();
int ask_food();
int ask_daozhu();
void greeting(object);

void create()
{
	set_name("����", ({ "si pu", "pu"}));
	set("long", "���ǵ��ϵ�һ�����ˣ��ֵ����ƺ����������ӡ�\n");
	set("gender", "����");
	set("age", 24);
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

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("cuff", 70);
	set_skill("sword", 70);
	
	set("inquiry", ([
			"������"   :  (: ask_food :),
			"��ԭ"   : 	(: ask_leave :),
			"����"   : 	(: ask_daozhu :), 
		]));
	set("food_count", 3);
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
{	if (me->query_temp(this_object()->query("id")) == 0 )
	{
		command("bow " + me->query("id"));
		command("say ��λ" + RANK_D->query_respect(me) + 
			"������һ������Щ��Ϳɸ���ʮ��һ�ε�����\n" +
			"���ᡣ");
		me->set_temp(this_object()->query("id"), 1);
	}
}
int ask_leave()
{	command("shake ");
	command("say û�е���ͬ�⣬��ɲ���˽���뵺��");
	return 1;
}
int ask_food()
{	int i;
	object you = this_player();
	object food;
	object here = environment(this_object());
	if (here->query("food_count") < 1)
	{	say("����ת���ߵ���������ǰ�����ң���ͷ��Ǹ��Ц��Ц˵�����Բ���\n" +
			"�����˺ȹ��ˡ�\n");
		return 1;
	}
	
	if (  present("laba zhou", you) )
	{	say("����������üͷ˵�������˻�Ҫ����̫̰���˰ɡ�\n");
		return 1;
	}
	else if (present("laba zhou", environment(you)))
	{	say("����������һָ�����ϲ�����һ������Ҫ�ȵĻ��ͼ������ɡ�\n");
		return 1;
	}
	food = new("/d/xiakedao/obj/zhou");
	food->move(this_object());

//	say("����ת����Աߵ����϶���һ" + food->query("unit") + food->query("name") + "�����˸��㡣\n");
	say("����ת����Աߵ����϶���һ" + food->query("unit") + food->query("name") + "��\n");
	command("give " + food->query("id") + " to " + you->query("id"));
	//food->move(you);
	here->add("food_count", -1);
	return 1;
}
int ask_daozhu()
{	object me = this_player(), here;
	string desc;
	here = environment(me);
	desc = here->query("long");
	if ( (int)here->query_temp("opened") == 0)
	{	say("����΢һ����˵������λ��������ʯ���п�˼��\n");
		say("�����������֣�������λ�������˹���������ץס���������ı�Ե\n");
		say("���Ի���������¶��һ������������\n");
		here->set("exits/enter", "/d/xiakedao/yongdao10");
		here->set_temp("opened", 1);
		desc = sprintf(desc + "    �����ѱ�������¶��һ������������\n");
		here->set("long", desc);
	}
	else
	{	say("����΢һ����˵������λ��������ʯ���п�˼�����ȥ�����ǰɡ�\n");
	}
	return 1;
}
