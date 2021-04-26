//白驼训蛇场   u/spark/trainroom.c
//by spark    5/24/2002

#include <room.h> 
inherit ROOM;

void create()
{
	set("short", "训蛇场"); 
    set("long", @LONG
这里是白驼山庄训练毒蛇的地方。不时见到有身穿白袍的白驼弟子挥
舞手中的蛇杖指挥着群蛇的行动。空气中弥漫着腥臭，即使在阳光下这里
群蛇涌动的情景仍然让人不寒而栗。
LONG
      );
	set("exits", ([
		"northeast" : __DIR__"kongdi2", 
		]));
	set("outdoors","baituo");
	setup();
	set("cost",1);
   	replace_program(ROOM);
}
