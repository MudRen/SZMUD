// Code of ShenZhou
// /d/emei/baoguo2.c �����²ؾ�¥
// Shan: 96/09/22

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ؾ�¥");
	set("long", @LONG
�����Ǳ����µĲؾ�¥����¥�������������˺ö���ܣ����ϰ����˾��顣
�����������µ�Сʦ̫����һ�Ǿ����ض��ž��顣
LONG
	);
	set("exits", ([
		"south" : __DIR__"baoguo1",
	]));

        set("objects",([
                "d/emei/obj/yugajing0" : 1,
                "d/emei/obj/yugajing2" : 1,
		"d/emei/npc/daoming" :1,
        ]));


	set("cost", 0);
	setup();
}


int valid_leave(object me, string dir)
{
        if (  (dir == "south")
           && ( present("shu", this_player()) ) 
           && objectp(present("daoming", environment(me))) ) {
        message_vision("����Сʦ����$N��Ѿ������ߣ���ǰ����˵���������鲻��衣\n", me);
        return notify_fail("\n");
        }

        return ::valid_leave(me, dir);
}

