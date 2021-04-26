// Code of ShenZhou
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;
string look_cave();

void create()
{
	set("short", "ɽ��");

	if(random(3) != 0 ) {
		set("long", @LONG
���ǰ���ɽ���߹�֮�У���������ɽ�ڣ���������ʯ����ʯ����
ϡϡ����س��ż���С�����紵��������ʱ��һЩСʯͷ�ӱ��ϻ���
������ɽ��һ���и�С��(cave)��
LONG
		);

		set("item_desc", ([
		"cave" : (: look_cave :),
		]));

		set("hide_snake", 1);
		set("cave", 1);
	}
	else {
		set("long", @LONG
���ǰ���ɽ���߹�֮�У���������ɽ�ڣ���������ʯ����ʯ����
ϡϡ����س��ż���С�����紵��������ʱ��һЩСʯͷ�ӱ��ϻ���
������
LONG
		);
	}

	set("exits", ([ 
	    "northeast" : __DIR__"shegu23",
	]));

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "snake_room.h"
