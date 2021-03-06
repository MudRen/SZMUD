// Code of ShenZhou
// minzai.c 宅区
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "宅区");
	set("long", @LONG
这是泉州居民区。区内小巷纵横，四通八达。一式的石砌矮屋，红顶青墙，
方正对称，极具闽南特色，可谓错落有致，小巧玲珑。北边和南边都是宅区。
闹的喧哗声。西边有家出名的蜜饯制作铺「源和堂」，南面有一所破败的宅子。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"minzai2",
		"south" : __DIR__"laozhai",
		"east" : __DIR__"citong_s2",
		"west" : __DIR__"yuanhe",
	]));

        set("objects", ([ 
                __DIR__"npc/girl" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
