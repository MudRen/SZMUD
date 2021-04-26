// Code of ShenZhou
inherit ROOM;

void create()
{
	set("short","��ʮ�˲����");
	set("long","�����ǵ�������ײ�...\n");
	set("valid_startroom",1);
	set("cost", 0);
	setup();
}

void init()
{
	object ob = this_player();

	if (!wizardp(ob)) {
		add_action("block_cmd","",1);
		ob->set("startroom", "/d/death/hell");
	}
}

int block_cmd()
{
	string cmd;
	cmd = query_verb();
	if (cmd == "say" || cmd == "tell" || cmd == "reply" || cmd == "who" ||
		cmd == "look" || cmd == "quit" || cmd == "suicide" || cmd == "goto")

		return 0;
	return 1;
}
