// Code of ShenZhou
// ɽ·
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "ɽ·");
   set("long", @LONG
�����������С·�ϣ�������;ɽ����Ӱ��������У���ʯ�߲���
�����е��ػ��泩�����ϱ㵽�������á����¾͵���������
LONG
       );

   set("exits", ([ /* sizeof() == 2 */ 
                  "westup" : __DIR__"tianzhu5", 
                  "eastdown" : __DIR__"road62", 
                ])
       );
   
	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}