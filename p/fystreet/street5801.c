// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 5801
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"神州大街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
这里是柳千变(poop)的[1;36m无心居[37;0m。
    苦了大半辈子，房子终于有了！老婆在哪里？
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","poop");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"