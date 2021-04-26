// Code of ShenZhou
// Npc: 
// Date: 

#include <ansi.h>

inherit NPC;

string ask_me();
int repairing_1(object, object);
int repairing_2(object, object);
int repairing_3(object, object);
int repairing_4(object, object);
int do_back(object);

void create()
{
	set_name("СƼ", ({
		"xiao ping",
		"ping",
	}));
	set("long",
		"����һ��������ʮ���������ɵ�СѾ������Ҷü�������ˮ������ʮ��һ���������ӣ�������Ͷ��֮���ƺ������书��\n"
		"��˵��������ɽ����һ����Ů����½��ׯ�������������̷�½��ׯ��ϰ�����ա�\n"
	);


	set("gender", "Ů��");
	set("attitude", "friendly");

	set("age", 18);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 100000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("strike", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("literate", 50);


	set("inquiry", ([
		"ľ��"     : (: ask_me :),
		"����"	   : (: ask_me :),
		"��ľ��"   : (: ask_me :)
	]));

	setup();

//        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/taihu/obj/red_cloth")->wear();
}

void init()
{	
	object me, ob;

	me = this_object();

	::init();
	if( objectp(ob = present("mu ren", environment())) )
	{
		remove_call_out("repairing_1");
		call_out("repairing_1", 5, me, ob);
	}
}

int repairing_1(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 

	command("say �����ľ�˰ɣ� ���������ƣ� ���ڱ�����ʵ���ţ�����");
	
	remove_call_out("repairing_2");
	call_out("repairing_2", 2+random(3), me, ob);

	return 1;
}

int repairing_2(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 

	if( ob->query("damaged") )
	{
		message_vision(GRN "\nСƼ����ľ������һ�ᣬ�����Ű⶯ľ�˵���֫���Դ�������üͷ����һ�����\n\n" NOR, me);
		remove_call_out("repairing_3");
		call_out("repairing_3", 2+random(2), me, ob);
	}
	else
	{
		command("say �󱿹ϣ���ľ�˺ö˶˵���û���� ������Զ�������ҹ�����");
		command("follow none");

		message_vision(GRN "\nСƼ����죬���Ĺĵ����ˡ�\n" NOR, me);
		me->move("/d/taihu/liangong");

		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	}

	return 1;
}
	
int repairing_3(object me, object ob)
{
	command("say ��������Ү���������޿��ɣ�");
	message_vision(GRN "\nСƼ���Ŵӻ����ͳ�һ��ѹ���������ľ�˵����壬��Ū�˼��¡�\n\n" NOR, me);

	remove_call_out("repairing_4");
	call_out("repairing_4", 3+random(3), me, ob);

	return 1;
}

int repairing_4(object me, object ob)
{
	if( random(1) == 0 ) 
	{		
		command("say �ã��޺��ˣ�");
		ob->delete("damaged");
		ob->set("fight_times", 0);	
		message_vision(GRN "\nľ�˵�����֨֨��Ť���˼��£��ָ�������վ������̬��\n\n" NOR, me);
	}
	else 
		message_vision(GRN "\nСƼ̾�˿�����˵�����������У���ľ���𻵵�̫�����ˣ�û�������ˣ�\n" NOR, me);

	command("say �ã��������ˣ�");
	command("wave");
	command("follow none");

	message_vision(GRN "\nСƼ���˳�ȥ��\n" NOR, me);
	me->move("/d/taihu/liangong");

	remove_call_out("do_back");
	call_out("do_back", random(15), me);

	return 1;
}

int do_back(object me)
{
	me->move("/d/taihu/huayuan");
	return 1;
}

string ask_me()
{
	mapping fam; 
	object ob;

	ob = this_player();
	
	if ((!(fam = ob->query("family")) || fam["family_name"] != "�һ���") && !ob->query_temp("allow_repair") )
		return RANK_D->query_respect(ob) + 
		"�뱾ׯ������������֪�˻��Ӻ�̸��";

	command("say ľ���ִ����ǰɣ� ������鷳���ðɣ�����͸���ȥ������");
	command("follow " + ob->query("id"));

	return "�����߰գ�\n";
}
/*
int accept_object(object me, object ob)
{
	command("smile");
	command("say �����ӷ𣬶�л" + RANK_D->query_respect(me) + "�� ��");

	if(ob->query("money_id") && ob->value() >= 10000 && me->query("class") != "bonze" )
	me->set_temp("allow_repair", 1);

	return 1;
}
*/
