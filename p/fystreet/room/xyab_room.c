//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 2601
inherit ROOM;
void create()
{	set("short","$GRE$洞房$[37;0m");
	set("long",@LONGLONGAGO
世界杯的整个运作过程，充斥着典型的雄性符号：流汗的男人、强壮的身体、粗鲁的举止、畅通无阻的粗口、煞有介事的“波经”(足球评述)、啤酒、花生……而所有的雌性代表，都不过被挪用来作陪衬kk性感的啤酒女郎、裹着巴西球衣身材丰满的金发洋妞、过场的客席女主持人kk以凸显这场嘉年华会的男性主导地位，一切摆布安排，都是从男性视线观点出发。;　　几乎，一个男性被归纳为足球爱好者是
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","xyab");
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
   call_other("/p/fystreet/board/xyab_board","???");
}
#include "indoor_func.c"
