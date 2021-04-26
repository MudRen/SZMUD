// Code of ShenZhou
// Room: /d/xixia/dating.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "һƷ�ô���");
	set("long", @LONG
�������úܼ򵥣�����������̫ʦ��Χ��һ�Ű����������������
�������������ӣ���ǽ�Ϲ��ţ������ã�ǽ�ǰ���һЩС������ĳ���
Ʒ��ÿ���紵���ţ��ſڵķ��巢��ɳ�Ƶĵ������ذ��ɰ���ʯ���̳ɣ�
�����ƺ�������������ɫ�Ļ��ơ�����������һ�����ε��Ŷ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dayuan",
  "west" : __DIR__"mishi",
]));
	create_door("west","ľ��","east",DOOR_CLOSED);
	set("objects", ([
		__DIR__"npc/tieshu" : 1,
		__DIR__"npc/ypshi" : 2,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir =="west" ) {
            if (present("wu shi", environment(me)))
                return notify_fail("һƷ����ʿһ�Բ����ص�����ǰ�档\n"); 
        return 1;
    }
        return ::valid_leave(me, dir);
}
