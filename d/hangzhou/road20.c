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
һƬ̫ƽ���־��󡣽ֵĶ�����һ���ھ֡�
LONG);

    set("exits", ([ /* sizeof() == 3 */ 
                   "north" : __DIR__"road11", 
                   "south" : __DIR__"road21", 
                   "east" : __DIR__"biaoju", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
