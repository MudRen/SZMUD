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
������������򶫱ߺ����ϱߡ������߱����ϱ�ʯɽ��
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                   "east" : __DIR__"road11", 
                   "west" : __DIR__"road13", 
                   "northup" : __DIR__"baoshi1", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
