// Code of ShenZhou
//  ������
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG
һ������·�������������ܷǳ��İ�����ż���ſ���Щ���˴ҴҶ�����
�ϱ��ֱ�����ɽ��·��
LONG
        );

    set("exits", ([ /* sizeof() == 2 */ 
                  "northdown" : __DIR__"road32", 
                  "southdown" : __DIR__"road42", 
                 ])
        );

	set("cost", 3);
        set("tjjob", 2);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
