// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 801
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"神州大街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
这里是天仙子(tianxz)的[1;32m鹊[1;36m桥[37;0m。
    这是 牛郎 与 织女 约会 的地方，每月7月7日，必能在次相见；平常就成了 天仙一族 议事地地方。
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","tianxz");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"