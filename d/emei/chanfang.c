// Code of ShenZhou
// chanfang.c 禅房

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "禅房");
	set("long", @LONG
这里是一间安静宽敞的禅房，乃是庵中弟子打坐修行之所。地下整整
齐齐地放着许多蒲团。几位年轻师太和俗家女弟子正肃容入定。
LONG
	);
	set("exits", ([
		"west" : __DIR__"fushou1",
	]));

	set("jingzuo_room", 1);
	set("no_fight", 1);

	set("cost", 0);
	setup();
	replace_program(ROOM);

}
