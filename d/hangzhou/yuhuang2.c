// Code of ShenZhou
// ���ɽ·
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "ɽ·");
   set("long", @LONG
ɽ·��᫣��������ӡ�������ľ�Դ䣬����ï�ܡ�ɽ·���Ǻ���
ͤ�������ＫĿԶ����Ⱥɽ���������۵ס���������ɽ��·��������
����ɽ��·��
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "eastdown" : __DIR__"yuhuang1", 
                  "westup" : __DIR__"yuhuang3", 
                ])
       );

	set("cost", 2);
        set("fjing", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
