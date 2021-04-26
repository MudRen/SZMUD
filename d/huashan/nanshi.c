// Code of ShenZhou
// Room: nanshi.c ��ɽ�е�����Ϣ��
// qfy July 7, 1996 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�е�����Ϣ��");
	set("long", @LONG
���ǻ�ɽ�е��ӵ���Ϣ�ҡ���������������򵥡���ǽ���м���ľ����
���Ŵ�����һ�����ӡ�����������������
LONG
	);

	set("sleep_room", 1);
	set("no_fight", 1);

	set("exits", ([
	    "west" : __DIR__"liangong1",
	    "north" : __DIR__"zoulang3",
	]));

	create_door("north", "ľ��", "south", DOOR_CLOSED);
	create_door("west", "����", "east", DOOR_CLOSED);

	set("cost", 0);
	setup();
	//replace_program(ROOM);
}
/*
void init()
{
	add_action("do_exercise",  "exercise");
	add_action("do_exercise",  "dazuo");
	add_action("do_practice",  "practice");
	add_action("do_practice",  "lian");
	add_action("do_study",  "study");
	add_action("do_study",  "du");
}

int do_exercise(string arg)
{
	object me = this_player();

	tell_object(me, "���˳�˯�Ĵ��������㣬ʹ�㲻�ܾ�������������\n");
	return 1;
}

int do_practice(string arg)
{
	object me = this_player();

	tell_object(me, "��������̫�࣬�ط�����������ʹ�����ֽ�����ϰ��\n");
	return 1;
}

int do_study(string arg)
{
	object me = this_player();

	tell_object(me, "���˳�˯�Ĵ��������㣬ʹ�㲻�ܾ��������ж���\n");
	return 1;
}
*/
int valid_leave(object me, string dir)
{
	object *inv;
	int i;

	inv = all_inventory(me);

	if ( dir == "west" || dir == "north" ) {
		for (i=0; i<sizeof(inv); i++) {
			if (inv[i]->is_character())
			return notify_fail("�㲻�ܴ�����������뿪��Ϣ�ҡ�\n");
		}
	}

	return ::valid_leave(me, dir);
}
