// Code of ShenZhou
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�߹Ȼĵ�");
	set("long", @LONG
�������߹������ľ���ݻƵ�֣����ǻ�Ƨ�������İ��ž�
��ɽ����΢��ʱ�𣬴��������ľ���ܵ���ζ������ż������һЩС
����ĺ��ǣ���֪�Ǳ�ʲ�ᶾ�����޳Ե��ˡ�
LONG
	);

	set("exits", ([ 
	    "northeast" : __DIR__"shegu_maze7",
	    "northwest" : __DIR__"shegu_maze" + (5+random(4)),
	    "southwest" : __DIR__"shegu_maze6",
	    "southeast" : __DIR__"shegu_maze3",
	]));

	set("hide_python", random(2));

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "python_room.h"
