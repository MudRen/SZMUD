// Code of ShenZhou
// NPC mawude.c �����
// Acep
// For Beiming quest
// teller.c

inherit NPC;

int do_ask(string);
int do_say(string);

void create()
{
// use old code
	set("inquiry", ([
		"������" :
"��������������������������گ����ɽ���ɣ������˾�ס����ɽ���������ֶ���\n"
"���������ڣ����ڽ���ʮ��������ʽ΢����������ȴ���˲Ŷ�ʢ��\n",
		"����" :
"���ڴ����ʹ�����Ϊ����֮��ÿ�����꣬�������µ��ӱ��ڽ������б��䶷����\n"
"��ʤ��һ�ڵ��ڽ�������ס���꣬�������������б��ԡ��峡������Ӯ��������Ϊ\n"
"ʤ����������ʮ��ǰ��ʤ����ס���������������������������һŭ����������\n"
"Ǩ��ɽ�����˺󼴲��ٲ�Ԥ�Ƚ����붫������Ҳ��ͨ���ʡ���ʮ����������������\n"
"����ʤ��������ʤ���ĴΣ�����ʤ�����Ρ�",
		"����" :
"���ڴ����ʹ�����Ϊ����֮��ÿ�����꣬�������µ��ӱ��ڽ������б��䶷����\n"
"��ʤ��һ�ڵ��ڽ�������ס���꣬�������������б��ԡ��峡������Ӯ��������Ϊ\n"
"ʤ����������ʮ��ǰ��ʤ����ס���������������������������һŭ����������\n"
"Ǩ��ɽ�����˺󼴲��ٲ�Ԥ�Ƚ����붫������Ҳ��ͨ���ʡ���ʮ����������������\n"
"����ʤ��������ʤ���ĴΣ�����ʤ�����Ρ�",
		"����" :
"���ڴ����ʹ�����Ϊ����֮��ÿ�����꣬�������µ��ӱ��ڽ������б��䶷����\n"
"��ʤ��һ�ڵ��ڽ�������ס���꣬�������������б��ԡ��峡������Ӯ��������Ϊ\n"
"ʤ����������ʮ��ǰ��ʤ����ס���������������������������һŭ����������\n"
"Ǩ��ɽ�����˺󼴲��ٲ�Ԥ�Ƚ����붫������Ҳ��ͨ���ʡ���ʮ����������������\n"
"����ʤ��������ʤ���ĴΣ�����ʤ�����Ρ�",
		"����" :
"ÿ�궷���ᣬ�������������˻Ṳͬ��������һЩ��֤�ˣ�����Ҳ����Щ�����е�\n"
"֪��֮ʿ��Ϊ����ļα���\n",
		"ͬȥ" : "���...�ǳ���Ǹ���������ں�æ��������ǰ��������εĶ������ˡ�\n",
		"��ȥ" : "δ����������ǲ��ᱻ׼����ɽ�ġ���˵��Ҳ����ʶ·��\n",
		"·"   : "ȥ����ɽ��·���Բ�����Ҳ����ʶ��\n",
       ]) );
	setup();

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

	if (arg=="ma about ������") { write("nod"); me->set_temp("asked",1); }
	if (arg=="ma about ����"
		|| arg=="ma about ����"
		|| arg=="����"
		&& me->query_temp("aksed")) {
		me->set_temp("asked", 2); }
	if (arg=="ma about ����" && me->query_temp("asked")==2) {
		me->set_temp("asked", 3); }
	if (arg=="ma about ͬȥ" && me->query_temp("asked")==3) {
		me->set_temp("asked", 4); }
	if (arg=="ma about ��ȥ" && me->query_temp("asked")==4) {
		me->set_temp("asked", 5); }
	return 0;
}

int do_say(string arg)
{
	object me;
	me=this_player();

	if (arg=="�ҷǳ���ȥ����" && me->query_temp("asked")==5) {
		write("��������������󣬷�Ҫȥ����ɽ���񲻿ɡ�\n");
		me->set_temp("asked",6);
		return 1;
	}
	return 0;
}

int accept_object(object who, object ob)
{
	object bt;
		
	if (ob->query("money_id")
		&& ob->value()==80
		&& who->query_temp("asked")==6 
		&& present("gold", who)
		&& !query_temp("given"))
	{
		write("����µ��˵�ͷ��˵�������ðɣ��Ҹ���д����������Լ�ȥ�ɡ���\n");
		say("����¸���" + who->query("name") + "һ�������\n");
		set_temp("given",1);
		who->delete_temp("asked");
		bt=new("/d/dali/obj/baitie");
		bt->move(who);
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), ob);
		return 1;
	}
}

void destroying(object me, object obj)
{
	destruct(obj);
}
