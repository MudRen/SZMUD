// Code of ShenZhou
// ���ɽ��
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "���ɽ");
   set("long", @LONG
ɽ����һ��Сͤ������ͤ�������ο͵�ɽǰ����ɽ�ᶼ�ڴ�СЪ��
ɽ·�����������ϡ�������һ����·��
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "west" : __DIR__"road77", 
                  "eastup" : __DIR__"yuhuang4", 
                ])
       );

	set("cost", 3);
        set("fjing", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
