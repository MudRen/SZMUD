//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 1201
inherit ROOM;
void create()
{	set("short","衣衣小筑[37;0m");
	set("long",@LONGLONGAGO
小筑中种满了白色的丁香花，微风吹过，泛起阵阵花浪，花香扑鼻。
一座抚琴台处于花海中，为了遮阳，主人巧思在琴台上撑起了白纱
每当风起琴响纱飘时，犹如处于世外仙境
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","eida");
       set("no_fight",1);
       set("no_magic",1);
       set("sleep_room",1);
       set("if_bed",1);
       set("NONPC",1);
       set("no_dazuo",1);
       set("no_study",1);
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
   call_other("/p/fystreet/board/eida_board","???");
}
#include "indoor_func.c"
