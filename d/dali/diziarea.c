// Code of ShenZhou
// diziarea.c
#include "room.h"
inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
�����Ǵ�����ͼ���Ա��ס�����������Ϊ��ԭ�������ң���Ӷ
�������ֽ�����ʿΪ�������׼����佫�����߶�ס�������������
��һЩ�᷿�������Է����ϱ���һ��﷿���ṩ��ʳ��Ժ�ǵ�һ��С
��ͨ���ⷿ��
LONG );

	set("cost", 1);
	set("exits", ([
		"north" : __DIR__"dinganfu.c",
		"west"  : __DIR__"wofang1.c",
		"east"  : __DIR__"wofang2.c",
		"south" : __DIR__"chufang.c",
		"enter"	: __DIR__"kufang.c",
		]));

	set("objects", ([
		__DIR__"npc/xiaosi" : 2,
		__DIR__"npc/weishi3" : 2,
		]));

	set ("wangfu", 1);
	create_door("enter","ľ��","out", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir=="east" || dir=="west") {
		if (dir=="west" && me->query("gender")=="Ů��")
			return notify_fail("�������ӵ��᷿��\n");
		if (dir=="east" && me->query("gender")=="����")
			return notify_fail("����Ů�ӵ��᷿��\n");
	}
	return ::valid_leave(me, dir);
}
