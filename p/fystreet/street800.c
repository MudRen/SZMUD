// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 800
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"神州大街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
这里是刀锋边缘(fjss)的[1;37m留云[1;32m山庄[37;0m。
    万壑松声山雨过  一川花气水风生
LONG	);
	set("exits",([
	"west" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","fjss");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"