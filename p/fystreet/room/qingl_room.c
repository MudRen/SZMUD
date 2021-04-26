//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 701
inherit ROOM;
void create()
{	set("short","[35m观星小筑[37;0m");
	set("long",@LONGLONGAGO
这是一间虽不宽敞，却收拾得很整洁的客厅。
  正中摆放着一张做工考究，古色古香的八仙桌，
  四周随意地码放着几张竹椅。
  窗边是一盆盛开着的水仙，
  窗外隐约可见一条弯弯的小溪静静地流淌。
  微风吹过，送来缕缕紫竹的清香，令人精神为之清爽了许多。
  窗的两侧是主人自己书写的一副对子：
      一 生 携 手，倚 楼 听 风 雨
      一 世 相 伴，淡 看 江 湖 路
LONGLONGAGO	);
	set("exits",([
//         "up":"/u/snowyu/yangtai1",
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","qingl");
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
   call_other("/p/fystreet/board/qingl_board","???");
}
#include "indoor_func.c"
