// Code of ShenZhou
// Room: /city/bingyin.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ������е�
�������������е����š�����������Ϣ����ǽ��������˧��������ɫ��Ѱ������
�ܡ�������һ����(door)��������һ��С����(window)��
LONG
	);

	set("item_desc", ([
		"door" : "����һ�ȼ�������š�\n",
	]));
	set("exits", ([
		"west" : __DIR__"jail",
		"south" : __DIR__"bingyindamen",
	]));

	set("objects", ([
		__DIR__"npc/shi" : 1,
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 4,
	]));

	create_door("west", "����", "east", DOOR_CLOSED);
	set("cost", 0);
	setup();
}
void init()
{
	add_action("do_visit", "look");
	add_action("do_pass", "pass");
}

int do_pass(string arg)
{
	object ob;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô��\n");

	if (ob->query_weight() > 5000)
		return notify_fail(ob->query("name")+"̫���ˣ����ܴӴ���������ȥ��\n");

	if (ob->query("id") == "huashi fen" || ob->query("id") == "tie he" || ob->is_container() || ob->query("hsf"))
		return notify_fail("��������Ų���ȥ��\n");

	message_vision("$N��һ"+ob->query("unit")+"$n�Ӵ������˽�ȥ��\n", this_player(), ob);
	ob->move("/d/city/dalao");
	message("vision", this_player()->name()+"�Ӵ���������һ"
		+ob->query("unit")+ob->query("name")+"��\n",environment(ob), ob);
	return 1;
}
int do_visit(string arg)
{
	object env, me = this_player();	

	if (arg != "window") return 0;

	if(!( env = find_object("/d/city/dalao")) )
	        env = load_object("/d/city/dalao");

	message_vision("$Nſ�ڴ�̨��������ȥ��\n", me);
	tell_room(env, "��е���һ˫�۾��ڴ�������㡣\n");
	return COMMAND_DIR"std/look"->look_room(me, env);
}
int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "west")
		return notify_fail("�ٱ���ס�����ȥ·��\n");

	return ::valid_leave(me, dir);
}

