// Code of ShenZhou
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�߹�ɽ��");
	set("long", @LONG
���ǰ���ɽ�߹��е�ɽ·����һ������ȳ�����С�������ŵ���
����������������С�ɽ·������ľ�������ݴ��в�ʱ����ɳɳ֮��
���ƺ���ʲ���ڲ������شܶ��������ߵ���ľ�ƺ��Ƚ�ϡ�١�
LONG
	);

	set("exits", ([ 
	    "southeast" : __DIR__"shegu4",
	    "northwest" : __DIR__"shegu6",
	]));

	set("objects", ([
	    "/d/city/obj/branch2" : 1,
	    "/d/city/npc/maque" : 2,
	]));

	set("hide_snake", random(3));
	set("grass", 1);

	set("cost", 3);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "snake_room.h"
