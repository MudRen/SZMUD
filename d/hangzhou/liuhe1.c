// Code of ShenZhou
// ������
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "������");
    set("long", @LONG
��������ɽ����������������֮ǰ�������������������������͡�
֮����֮��ҵ����ֹ�Լ�������ϡ����ǡ��죬�أ��ķ�������˼��
�����˽�����ʮ���㣬�����ķ����̽�������һ������ֻ�����塣
LONG	);

    set("exits", ([ /* sizeof() == 1 */ 
                   "eastdown" : __DIR__"road78", 
                 ])
       );
	set("cost", 3);
    setup();
    replace_program(ROOM);
}