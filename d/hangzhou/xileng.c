// Code of ShenZhou
// ������
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "������");
   set("long", @LONG
�������ν��ɽ��������������ŵĶ��ϱ��ǹ�ɽ����������һ
����ʯ�����
LONG
        );


   set("exits", ([ /* sizeof() == 2 */ 
                  "southeast" : __DIR__"gushan1", 
 		  "north" : __DIR__"road13",
                ])
       );

	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}