// Code of ShenZhou
// Room: /d/dali/dinganfu2.c
#include "room.h"
inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
�����Ǵ�����ͼ���Ա��ס�����������Ϊ��ԭ�������ң���Ӷ�������ֽ�
����ʿΪ�������׼����佫�����߶�ס���������������һЩ�᷿�������Է���
�ϱ���һ��﷿���ṩ��ʳ��Ժ�ǵ�һ��С��ͨ���ⷿ��
LONG);
	set("objects", ([
		__DIR__"npc/xiaosi" : 2,
		__DIR__"npc/weishi3" : 2,
		]));
	set("exits", ([
		"north" : __DIR__"dinganfu",
		"south" : __DIR__"dinganfu5",
		"west"  : __DIR__"dinganfu3",
		"east"  : __DIR__"dinganfu4",
		"enter"	: __DIR__"dinganfu6",
		]));
	create_door("enter","ľ��","out", DOOR_CLOSED);
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir=="east" || dir=="west")
	{
		if (dir=="west" && me->query("gender")=="Ů��") return notify_fail("�������ӵ��᷿��\n");
		if (dir=="east" && me->query("gender")=="����") return notify_fail("����Ů�ӵ��᷿��\n");
	}
	return ::valid_leave(me, dir);
}
