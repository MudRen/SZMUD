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
	    "southeast" : __DIR__"shegu_maze6",
	    "east" : __DIR__"shegu_maze7",
	    "west" : __DIR__"shegu24",
	]));

	if(random(5) == 0)
	set("objects", ([
	    "/d/baituo/npc/bt_snake" : 1,
	]));

	set("hide_python", random(2));

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "python_room.h"
