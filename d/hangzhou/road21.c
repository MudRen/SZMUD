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
һƬ̫ƽ���־��󡣽ֵĶ�����һ����¥��
LONG);

    set("exits", ([ /* sizeof() == 3 */ 
                   "north" : __DIR__"road20", 
                   "south" : __DIR__"road22", 
                   "east" : __DIR__"louwlou", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
