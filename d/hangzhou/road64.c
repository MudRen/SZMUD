// Code of ShenZhou
 // ˮ�ֶ�
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", HIC"ˮ�ֶ�"NOR);
    set("long", @LONG
ˮ�ֶ����������ڣ���������й�ɽȪ��ʯ����ӿ����Ȫˮ����
��ʯ����г�ö������С���Ȼ�����������������١���ʯ���־䡣��
�������кܶ�����ʯ����������ɽ��·�����ϱ㵽����ϼ����
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                  "westup" : __DIR__"road63", 
                  "eastdown" : __DIR__"road65", 
                ])
       );
	set("cost", 2);
        set("fjing", 1);
    setup();
    replace_program(ROOM);
}
