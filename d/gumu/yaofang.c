// July 31,2000
// Code by April
// /gumu/yaofang.c

inherit ROOM;

void create()
{
	set("short","ҩ��");

	set("long",@LONG
����һ��ҩ��������һ���и�ҩ¯���������µĹ�Ĺʥҩ�����������ơ�
LONG);

	set("exits",([ 
		"south" : __DIR__"mudao16",
		]));

	set("objects", ([
             "/kungfu/class/gumu/obj/yaolu" : 1,
             "/kungfu/class/gumu/npc/baiyi_yaofang" : 1,
        ]));

	set("cost",1);

	setup();
}

