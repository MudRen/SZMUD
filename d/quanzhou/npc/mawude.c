// Code of ShenZhou
// mawude.c �����
// qfy August 1, 1996

inherit NPC;
int do_ask(string);
int do_say(string);

void create()
{
	set_name("�����", ({ "ma wude", "ma", "wude" }));
	set("long", "��������º����ÿͣ������ϳ�֮�磬��Ե���ѡ�\n");
	set("gender", "����");
	set("age", 55);

	set_skill("literate", 50);

	set_skill("hand", 70);
	set_skill("dodge", 60);
	set_skill("force", 75);
	set_skill("parry", 70);
	set_skill("blade", 75);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 40000);
	set("shen_type", 1);

	set("inquiry", ([
		"ѧ��" : "ѧ��ֻ�븶�������ӣ�����ס������",
		"ѧ��" : "ֻ�븶�������ӡ�",
		"���" : "���Ƕ����ң����ڰ���(stick)���ȷ�(staff) ��ȭ��(cuff)��",
		"����" : "���ǵ��в���ͷ���Ե���(blade)��צ��(claw)���ơ�",
		"������" : "���ǽ�����ͷ���Խ���(sword)������(strike)������",
		"����" : "���ǰ�������ͷ�����ڰ���(throwing)��ָ��(finger)��",
	]) );

	set("chat_chance", 10);
	set("chat_msg", ({
		"�����˵��������ӭ����������ݡ���\n",
		"�����˵������ѧ��ֻ�븶�������ӣ�����ס��������\n",
		"�����˵�������ڴ˿�ѧ���ڹ���ȭ�ţ��������Ṧ���мܡ���\n",
		"�����˵�����������ҳ���ǰ��Ȳ���ͷ��ȭ������һ������\n",
		"�����˵�����������ǵ��в���ͷ���Ե�����צ�����ơ���\n",
		"�����˵����������������ݵĽ�����ͷ��ͬʱ���°ܽ���������\n",
		"�����˵��������������ݵİ�������ͷ��������ָ������\n",
	}) );	
	setup();

	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	add_action("do_ask", "ask");
	add_action("do_say", "say");
}

int do_ask(string arg)
{
	object me;
	me=this_player();

	if (arg=="ma about ��������"
		|| arg=="ma about ������") { 
                me->set_temp("asked",1); 
		write("��������´����йء��������ɡ�����Ϣ��\n");
		command( "?");
		return 1;
		}
	if (arg=="ma about ����"
		|| arg=="ma about ����"
		|| arg=="����"
		&& me->query_temp("aksed")) {
		me->set_temp("asked", 2); 
		write("��������´����йء�����������Ϣ��\n");
		command( "nod2");
		return 1;
		}
	if (arg=="ma about ����" && me->query_temp("asked")==2) {
		me->set_temp("asked", 3); 
		write("��������´����йء����񡻵���Ϣ��\n");
		command( "oh " + this_object()->query("id") + "");
		return 1;
		}
	if (arg=="ma about ͬȥ" && me->query_temp("asked")==3) {
		me->set_temp("asked", 4); 
		write("��������´����йء�ͬȥ������Ϣ��\n");
		command( "shake " + me->query("id") + "");
		command( "say ������ﻹ�кܶ�����Ҫ��䣬û��ʱ�䡣");
		return 1;
		}
	if (arg=="ma about ��ȥ" && me->query_temp("asked")==4) {
		me->set_temp("asked", 5); 
		write("��������´����йء���ȥ������Ϣ��\n");
		command( "en " + me->query("id") + "");
		return 1;
		}
        return 0;
}

int do_say(string arg)
{
	object me;
	me=this_player();

	if (arg=="�ҷǳ���ȥ����" && me->query_temp("asked")==5) {
		write("��������������󣬷�Ҫȥ����ɽ���񲻿ɡ�\n");
		me->set_temp("asked",6);
		command( "consider");
		command( "say ����ôҲ�ñ�ʾһ����ĳ���ɡ�");
		return 1;
	}
	return 0;
}

int accept_object(object who, object ob)
{
	object bt;

	if (who->query_temp("asked",6) && ob->name()=="�ƽ�") {
                command( "consider");
                command( "ok " + this_object()->query("id") + "");
                command( "say �Ҹ���д����������Լ�ȥ�ɡ�");
		who->delete_temp("asked");
		bt=new("/d/dali/obj/baitie");
		bt->move(who);
                message_vision("����¸���" + who->query("name") + "һ�������\n", who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }

	if ((int)who->query("combat_exp") > 3500) {
		command( "say "+RANK_D->query_respect(who)+"�������и��ף��������������ѧ���˶��ٶ�����������Ͷ��ʦ�ɡ�");
		return 0;
	}

	if (!(int)who->query_temp("mark/��")) who->set_temp("mark/��", 0);

	if (ob->query("money_id") && ob->value() >= 500) {
		command( "say "+RANK_D->query_respect(who)+"��Զǧ������������������뵽��Ժѧϰ����ϲ���Ĺ���ɡ�");
		who->set_temp("mark/��", 1);
		return 1;
	}

	return 0;
}

void destroying(object me, object obj)
{
	destruct(obj);
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/��"))
                return 0;
        return 1;
}
