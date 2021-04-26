// Code of ShenZhou
// gtxiang.c ¹ğÌ³Ïï

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "¹ğÌ³Ïï");
        set("long", @LONG
¹ğÌ³ÏïË³×ÅÊ©¸®¸ßÇ½òêÑÑ¶ø³ö£¬Ò»ÃæÊÇäıäıÁ÷Ë®µÄ¹µÇş£¬ÓÄ°µÄş¾²¡£¹ğÌ³
ÏïÎ÷ÄÏÃæ±ãÊÇ³ĞÌìËÂ¡£
LONG
        );

        set("exits", ([ /* sizeof() == 3 */
		"southwest" : __DIR__"chengtian",
		"north" : __DIR__"jiangfu",
		"west" : __DIR__"xuetang",
	]));

	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	set("cost", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        me->set_temp("mark/Öì", 0);
        return 1;
}
