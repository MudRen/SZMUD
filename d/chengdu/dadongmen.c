// /d/chengdu/dadongmen.c
// By Jpei

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "大东门");
	set("long", @LONG
这是就是成都的东城门了。成都地处川中，一向少有战事困扰，所以很少
见到有士兵。城门的墙上张贴着一纸告示(gaoshi)。
LONG
	);

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
		"west" : __DIR__"dongdajie2",
		"east" : __DIR__"eroad1",
		"north" : __DIR__"chenggenlu5",
	]));
        set("outdoors", "chengdu");
        set("cost", 1);
	setup();
}

string look_gaoshi()
{
 	return FINGER_D->get_killer() + "\n益州刺史\n吴天德\n";
}

