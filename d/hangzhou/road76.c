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
����������򶫱��������ߣ���������һ�������
LONG	);

    set("exits", ([ /* sizeof() == 3 */ 
                   "northeast" : __DIR__"road75", 
                   "south" : __DIR__"road77", 
                   "west" : __DIR__"road66", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
