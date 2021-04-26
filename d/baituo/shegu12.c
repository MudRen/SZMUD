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
�ƺ���ʲ���ڲ������شܶ������洫��һ�󵭵������⡣
LONG
	);

	set("exits", ([ 
	    "north" : __DIR__"shegu_pool",
	    "southeast" : __DIR__"shegu11",
	]));

	set("objects", ([
	    "/d/baituo/npc/bt_snake" : 1,
	]));

	set("hide_snake", random(3));
	set("grass", 1);

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "snake_room.h"
