// Code of ShenZhou
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�߹�����");
	set("long", @LONG
���ǰ���ɽ���߹�֮�У���ľ�����������������ļ������죬
�ƺ���һ���ٲ���
LONG
	);

	set("exits", ([ 
	    "north" : __DIR__"shegu27",
	    "south" : __DIR__"shegu25",
	]));

	set("cost", 1);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

void init()
{
	this_player()->set("enter_shegu", 1);
}
