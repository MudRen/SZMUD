// Code of ShenZhou
// ��ʯ���
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "��ʯ���");
    set("long", @LONG
��������ˣ����У���ýΣ�����������ϲ�������������
������������������ߡ��ϱ���ͨ���յ̡�������������
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                   "east" : __DIR__"road13", 
                   "west" : __DIR__"road15", 
                   "south" : __DIR__"suti1", 
                   "north" : __DIR__"yuelang", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}