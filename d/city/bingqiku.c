// Code of ShenZhou
// Room: /city/bingqiku.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǳ����⣬�������������������ۻ����ҡ��������������𹿰����󵶡�
�������ڰ����̵����̽����̹�����ɫ�����ı���Ӧ�о��У���һʱ��֪����ʲ
ô�á�
LONG
	);

	set("exits", ([
		"north" : __DIR__"bingyin",
	]));

	create_door("north", "����", "south", DOOR_CLOSED);
	set("cost", 0);
	setup();
	replace_program(ROOM);
}

