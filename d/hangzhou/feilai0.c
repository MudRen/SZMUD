// Code of ShenZhou
// ������
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>

#define BANGZHU "/d/huanghe/npc/bangzhu"

inherit ROOM;

void create()
{       set("short", "������");        
        set("long", @LONG
�������������շ塣������ɽС�������ߣ�ֻ��Ϫ����ʯ�ڼ��
��һ��̻��¶�أ�ϲЦ���������շ��Ա���һ��������ΰ�Ķ�����
������������ɽ��·��С·���������������ߡ�
LONG);

        set("objects",([
                BANGZHU : 1,
        ]));

        set("exits", ([ /* sizeof() == 3 */ 
                "eastup" : __DIR__"feilai4", 
                "north" : __DIR__"road34", 			
                "westup" : __DIR__"feilai1",  			
        ]));

	set("cost", 4);
        set("outdoors", "hangzhou");

        setup();

        replace_program(ROOM);
}
