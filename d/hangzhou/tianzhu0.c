// Code of ShenZhou
// ����ɽ·
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "ɽ·");
   set("long", @LONG
һ�������߳�����ɽ·�������������������졣����ɽ·�ϣ�ֻ
�����Է�����������ɫ���ˡ���ʱ�н���Ͳ�����������ϱ㵽����
���á����¾��Ǵ����
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "southup" : __DIR__"tianzhu1", 
                  "northdown" : __DIR__"road33", 
                ])
       );

	set("cost", 2);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}