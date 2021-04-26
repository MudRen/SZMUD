// Code of ShenZhou
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�߹�����");
	set("long", @LONG
���ǰ���ɽ���߹�֮�У���ľ�������ݴ��в�ʱ����ɳɳ֮����
�ƺ���ʲ���ڲ������شܶ���
LONG
	);

	set("exits", ([ 
	    "northwest" : __DIR__"shegu12",
	    "east" : __DIR__"shegu10",
	]));

	set("objects", ([
	    "/d/city/obj/branch"+(1+random(4)) : 1,
	    "/d/wudang/npc/yetu" : 1,
	]));

	set("hide_snake", random(3));
	set("grass", 1);

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "snake_room.h"
