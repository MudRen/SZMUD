// Code of ShenZhou
// Npc: /kungfu/class/shaolin/dao-guo.c
// Date: YZC 96/01/19  AceP: 97/8/3

#include <ansi.h>
inherit NPC;

string ask_me();
int repairing_1(object, object);
int repairing_2(object, object);
int repairing_3(object, object);
int repairing_4(object, object);
int do_back(object);
int do_return(object, object);
int do_remind(object, object);
int forget_lier(object, object);

void create()
{
	set_name("������ʦ", ({
		"daoguo chanshi",
		"daoguo",
		"chanshi",
	}));

	set("long",
		"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
		"�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
		);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 40);
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
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("luohan-quan", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("cibei-dao", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

	prepare_skill("cuff", "luohan-quan");

	create_family("������", 39, "����");
	set("inquiry", ([
		"ľ��"     : (: ask_me :),
		"����"	   : (: ask_me :),
		"��ľ��"   : (: ask_me :)
		]));

	setup();

	carry_object("/clone/weapon/jiedao")->wield();
	carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

void init()
{	
	object me, ob;
	me = this_object();

	::init();

	if (environment()==find_object("/d/shaolin/shanmen.c"))
	{
		command("hmm");
		command("say �һ�����Ҫ�Ļ�Ҫ�ɣ����ܳ���ȥ���һ�ȥ�ˡ�");
		say("�����Ҵ�ææ�뿪�ˡ�\n");
		command("follow none");

		me->move("/d/shaolin/guangchang3");
		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	}


	if( objectp(ob = present("mu ren", environment())) )
	{
		remove_call_out("repairing_1");
		call_out("repairing_1", 5, me, ob);
	}
}



int repairing_1(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 
	command("say �����ľ�˰ɣ� ���������ƣ� ���ڱ��ϴ��ţ����ܰ���ʲôæ��");
	set_temp("in_repair",1);
	remove_call_out("repairing_2");
	call_out("repairing_2", 2+random(3), me, ob);
	return 1;
}

int repairing_2(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 
	if( ob->query("damaged") )
	{
		message_vision(GRN "\n������ʦ����ľ������һ�ᣬ�����Ű⶯ľ�˵���֫���Դ�����������߶��ʲô��\n\n" NOR, me);
		remove_call_out("repairing_3");
		call_out("repairing_3", 2+random(2), me, ob);
	}

	else
	{
		command("say ��ľ�˺ö˶˵���û���� ������Զ�������ҹ�����");
		command("follow none");

		message_vision(GRN "\n������ʦ���Ĺĵ����ˡ�\n" NOR, me);
		me->move("/d/shaolin/guangchang3");
		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	}
	return 1;
}

int repairing_3(object me, object ob)
{
	command("say ��ԭ����ˣ��������޿��ɣ�");
	message_vision(GRN "\n�����Ŵӻ����ͳ�һ��ѹ���������ľ�˵����壬��Ū�˼��¡�\n\n" NOR, me);
	remove_call_out("repairing_4");
	call_out("repairing_4", 3+random(3), me, ob);
	return 1;
}

int repairing_4(object me, object ob)
{
	if( random(2) == 0 ) 
	{		
		command("say �ã��޺��ˣ�");
		ob->delete("damaged");
		ob->set("fight_times", 0);	
		message_vision(GRN "\nľ�˵�����֨֨��Ť���˼��£��ָ�������վ������̬��\n\n" NOR, me);
	}
	else 
		message_vision(GRN "\n������ʦ̾�˿�����˵�����������У���ľ���𻵵�̫�����ˣ�û�������ˣ�\n" NOR, me);

	command("say �ã��������ˣ�");
	command("wave");
	command("follow none");
	delete_temp("in_repair");
	message_vision(GRN "\n������ʦ���˳�ȥ��\n" NOR, me);
	me->move("/d/shaolin/guangchang3");
	remove_call_out("do_back");
	call_out("do_back", random(15), me);
	return 1;
}



int do_back(object me)
{
	me->move("/d/shaolin/twdian");
	return 1;
}

int do_remind(object me, object ob)
{
	if (	objectp(ob)
		&& me->query_leader()==ob
		&& !me->query_temp("in_repair")
		&& present(ob, environment(me)))
	{
		command("push "+getuid(ob));
		command("say ��ô��û�����ľ�˵ĵط�������㣬�һ��б�Ļ���أ�");
	}
	return 1;
}

int do_return(object me, object ob)
{
	if ( me->query_leader() == ob && ob && !me->query_temp("in_repair"))
	{
		if (present(ob, environment(me)))
		{
			command("angry "+getuid(ob));
			command("say �㵽����û��ľ��Ҫ���ް����ǲ�����ƭ�Ұ������һ�ȥ�ˣ�");
			set_temp("lier",getuid(ob));
			remove_call_out("forget_lier");
			call_out("forget_lier", 300, me, ob);
		}

		message_vision(GRN "\n������ʦ���Ĺĵ����ˡ�\n" NOR, me);
		command("follow none");
		me->move("/d/shaolin/guangchang3");

		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	}
	return 1;
}

int forget_lier(object me, object ob)
{
	if (query_temp("lier")==getuid(ob))
		delete_temp("lier");
	return 1;
}


string ask_me()
{
	mapping fam; 

	object ob, me;
	ob = this_player();
	me = this_object();

	if ((!(fam = ob->query("family")) || fam["family_name"] != "������") && !ob->query_temp("allow_repair") )
		return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

	if (query_leader() && present(query_leader(), environment()))
		return "�Բ����������л�������Ȼ��ȥ���������Ұɡ�";

	if (getuid(ob)==query_temp("lier"))
		return "����һ�ո�ƭ�����˰��죬ȴû��ľ��Ҫ�ޡ���������æ����Ȼ����˵�ɡ�";

	command("say ľ�˴����ǰɣ� �ðɣ��Ҹ���ȥ������");
	command("follow " + ob->query("id"));

	remove_call_out("do_remind");
	call_out("do_remind", 50, me, ob);

	remove_call_out("do_return");
	call_out("do_return", 100, me, ob);
	
	return "�����߰գ�\n";
}

int accept_object(object me, object ob)
{
	command("smile");
	command("say �����ӷ𣬶�л" + RANK_D->query_respect(me) + "�� ��");
	
	if(ob->query("money_id") && ob->value() >= 10000 && me->query("class") != "bonze" )
	me->set_temp("allow_repair", 1);

	return 1;
}
