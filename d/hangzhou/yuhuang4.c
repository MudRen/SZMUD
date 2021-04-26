// Code of ShenZhou
// ���ɽ·
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	int i;
   set("short", "ɽ·");
   set("long", @LONG
ɽ·��᫣��������ӡ�������ľ�Դ䣬����ï�ܡ�ɽ·����һɽ
������˵������ʱ�ᴫ���������������ϻ�������������ɽ��·����
����ɽ�㵽��ɽ�ס�
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "westdown" : __DIR__"yuhuang5", 
                  "eastup" : __DIR__"yuhuang3", 
                ])
       );
	i = random (3);
        switch (i) {
        case 0:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
            "/d/city/npc/maque" : 1,
        ]));
	break;
	case 1:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
            "/d/wudang/npc/yetu" : 1,
        ]));
	break;
        case 2:
	set("objects", ([
            "/d/city/obj/branch2" : 1,
            "/d/city/npc/laohu" : 1,
        ]));
	break;
	}
	set("cost", 2);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
