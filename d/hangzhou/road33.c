// Code of ShenZhou
// ��ʯ���
// Dong  11/03/1996.
// modified by aln  2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���ýΣ�������������ϲ����������
���������ºͷ����塣�����������á�
LONG
        );

        set("exits", ([ /* sizeof() == 3 */ 
                 "southup" : __DIR__"tianzhu0",
                 "west" : __DIR__"road34",
                 "east" :  __DIR__"road32",
        ]));

	set("cost", 1);
        set("outdoors", "hangzhou");

        setup();
        replace_program(ROOM);
}
