// Code of ShenZhou
// ��ɽɽ·
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "ɽ·");
    set("long", @LONG
ɽ����ľï�ܣ������������ﻹ���������ɡ������߱㵽�˻�������
�ϱ�������ɽ��·��
LONG);

   set("exits", ([ /* sizeof() == 2 */ 
                  "south" : __DIR__"road13", 
                  "north" : __DIR__"hl1", 			
                ])
       );
	set("cost", 3);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
