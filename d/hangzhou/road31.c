// Code of ShenZhou
// ��ʯ���
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "��ʯ���");
    set("long", @LONG
��������ˣ����У���ýΣ�����������ϲ�������������
���������Ǻ鴺�š�����������򶫱��ߡ�
LONG      );

         set("exits", ([ /* sizeof() == 2 */ 
                  "west" : __DIR__"hongchun", 
                  "northeast" : __DIR__"road15", 
                ])
        );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
