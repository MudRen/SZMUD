// Code of ShenZhou
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ˮ��");
	set("long", @LONG
һ̶�峺�ĳ�ˮ�����߹�ɽ´�����ˮ������ɣ��ǹ��ж����
��ҪˮԴ�����������޶���������ˮ��
LONG
	);

	set("exits", ([ 
	    "south" : __DIR__"shegu12",
	]));

	set("hide_snake", random(3));

	set("resource/water",1);
	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "snake_room.h"
