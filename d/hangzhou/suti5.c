// Code of ShenZhou
// �յ�
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "�յ�");
   set("long", @LONG
ÿ��ʢ�ģ��ο͵��˷׷�Ѱ��СϢ�������������£�������ġ�
��������ɽ�ţ����������š�
LONG        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "south" : __DIR__"suti6", 
                  "north" : __DIR__"suti4", 
                ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
        set("fjing", 1);
   setup();
   replace_program(ROOM);
}
