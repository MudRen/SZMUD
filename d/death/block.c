// Code of ShenZhou
inherit ROOM;

void create()
{
	set("short","������");
	set("long","������ֻ����·һ��...\n");
	set("valid_startroom",1);
	set("cost", 0);
	setup();
}

void init()
{
	object ob = this_player();

	if (!wizardp(ob)) {
		add_action("block_cmd","",1);
		ob->set("startroom", "/d/death/death");
		ob->set("block", 1);
	}
}

int block_cmd()
{
	string cmd;
	cmd = query_verb();
	if ( cmd == "quit" || cmd == "suicide" || cmd == "goto")
		return 0;
	return 1;
}
