// Code of ShenZhou
 // ɽ·
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "ɽ·");
    set("long", @LONG
����С·�ϣ�ֻ����ɽ��Ұ���������͵Ĳ��ũ����Ů���ڻ�
Ц���вɲ衣ɽ·�����������ߣ����߾�����������������һ����
·��
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                  "east" : __DIR__"road63",
                  "south" : "/d/quanzhou/qzroad5",
                  "westup" : __DIR__"road61", 
                  "north" : __DIR__"longjin0", 
                  "northeast" : __DIR__"road43", 
                ])
       );
	set("objects", ([
                __DIR__"npc/caichanu" : 2,
        ]));
	set("cost", 2);
        set("fjing", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
