// Code of ShenZhou
// ��ʯ���
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{       set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���ýΣ�����������ϲ�������������
����������������ߡ������ڴ�������ϱߡ��ϱ�������һ�������
LONG);

        set("exits", ([ /* sizeof() == 3 */ 
                "south" : __DIR__"road20",
                "southwest" : __DIR__"duanqiao",
                "west" : __DIR__"road12",
        ]));

	set("cost", 1);
        set("outdoors", "hangzhou");

        setup();
        replace_program(ROOM);
}
