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
	    "east" : __DIR__"shegu32",
	    "west" : __DIR__"shegu_maze7",
	]));

	set("hide_python", random(2));

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "python_room.h"
