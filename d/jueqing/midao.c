// /d/jueqing/midao.c
inherit ROOM;

void create()
{
        set("short","密道");

        set("long",@LONG
一条昏暗的密道，四壁明显有人为斧凿的痕迹，墙上一支松油火把
正在“哔哔啵啵”地燃烧着。
LONG );
		
		set("exits",([
			"southeast" : "/d/jueqing/shanlu1",
			]));
        
		set("coor/x",0);
		set("coor/y",0);
		set("coor/z",0);
		setup();
		replace_program(ROOM);
}

