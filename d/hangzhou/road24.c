// Code of ShenZhou
// ��ʯ���
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "��ʯ���");
    set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������
һƬ̫ƽ���־��󡣽ֶ�����һ�ҿ͵ꡣ
LONG);

    set("exits", ([ /* sizeof() == 3 */ 
                   "north" : __DIR__"road22", 
                   "southwest" : __DIR__"road25", 
                   "east" : __DIR__"kedian", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
