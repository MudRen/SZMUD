// Code of ShenZhou
// yideng quest room 11

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�����᷿");
	set("long", @LONG
��������Ķ��᷿����Сɳ�ַ��������͡��������С�����ȴ�����
һ����ʯ�̵�С�����������һ�����֣���������ɭɭ���ľ��ޱȣ����˷��׾�
������������������ʯ�ݡ�
LONG);
	set("exits", ([
		"out" : __DIR__"yideng9",
		"north" : __DIR__"yideng12",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
	replace_program(ROOM);
}
