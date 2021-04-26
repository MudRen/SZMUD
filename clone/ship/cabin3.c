// Code of ShenZhou
// cabin1.c

#include <ansi.h>
inherit ROOM;

void create()
{
        string argg;
        int num;

	set("short", "����");
	set("long", @LONG
����һ��խС�Ĳշ����ƻ�찵�������г�����һ����ζ���ƺ�
������ζ������ζ��ùζ�Ĵ��ӻ⡣�շ�һ�Ƿ��ż�����ľͰ(tong)
�ͼ�������ɣ�����ɣ��м���ż��Ŵ���
LONG
	);

	set("item_desc", ([
	    "tong" : "��ֻװ����ˮ�ĵ�ľͰ��\n",
	]));

	set("resource/water", 1);
	set("objects",([
		"/clone/food/yugan" : 2,
                "/clone/food/larou" : 2,
	]));

        set("sleep_room", 1);
	set("no_fight", 1);

	set("cost", 0);

	setup();

        if( sscanf(__FILE__, "%s%d", argg, num) == 2 )
        set("exits", ([
                "up" : __DIR__"seaboat" + num,
        ]));

        replace_program(ROOM);
}

