// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 5001
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"神州大街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
这里是酷侠(kuxia)的[1;36m酷侠 [1;37m& [1;32m小白菜 [1;33m的[1;35m温情[1;34m蜗居[37;0m。
    这是酷侠为小白菜盖的温情蜗居，从此小白菜不再流浪，有空他们就会在这里温情一会儿。^_^
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","kuxia");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"