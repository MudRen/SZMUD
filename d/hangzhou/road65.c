// Code of ShenZhou
 // ����¤
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", HIM"����¤"NOR);
    set("long", @LONG
ɽ·����һ��С���䣬�������ܹ𻨳��֡�ÿ�������ʢ����
Ʈ���������Ϊ����ѩ���硱��������ˮ�ֶ�������ʯ�ݶ���
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                  "westup" : __DIR__"road64", 
                  "eastdown" : __DIR__"road66", 
                ])
       );
	set("cost", 2);
        set("fjing", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
