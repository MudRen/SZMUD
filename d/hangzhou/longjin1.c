// Code of ShenZhou
// ��������
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "����");
   set("long", @LONG
LONG        );

    set("exits", ([ /* sizeof() == 1 */ 
                   "west" : __DIR__"longjin0", 
                 ])
        );
	set("cost", 0);
    setup();
    replace_program(ROOM);

}