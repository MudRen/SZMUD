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
����������������ߣ��������յ̡�
LONG);

    set("exits", ([ /* sizeof() == 3 */ 
                   "north" : __DIR__"suti7", 
                   "west" : __DIR__"road74", 
                   "east" : __DIR__"road72", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}