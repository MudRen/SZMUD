//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 100
inherit ROOM;
void create()
{
        set("short",HIG"香水"HIY"望月"HIG"居"NOR );
	set("long",@LONGLONGAGO
好想再回到以往那座香水城，寻找令我迷惘的人。
    她依然散发着那诱人的温存，阵阵打动我的心门。
    也许我无法分辨黄昏清晨，当我陷入你的眼神。
    也许我无法分辨刹那永恒，走在你的香水城。
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","dior");
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
   call_other("/p/fystreet/board/dior_board","???");
}
#include "indoor_func.c"
