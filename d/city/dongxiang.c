// Code of ShenZhou
// Room: /city/dongxiang.c
// YZC 1995/12/04 

// Jay 2/3/97

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�뷿");
	set("long", @LONG
������С��Ĺ뷿��һ���������������һ����齷���ǽ�ǣ�����ϸɴ��
��С��������һ��ջ��ڳ�˼������������԰��
LONG
	);

	set("exits", ([
		"west" : __DIR__"houyuan",
		"north" : __DIR__"huayuan",
	]));

	set("objects", ([
		__DIR__"npc/shuanghua" : 1,
	]));
	set("cost", 0);
	setup();
	replace_program(ROOM);
}

