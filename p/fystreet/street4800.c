// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 4800
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"神州大街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
这里是乌蒙夫(finger)的藤原豆腐店[37;0m。
    这里是秋名山脚的一间普通豆腐店，门面很小，门口那停了一量引有“藤原豆腐店(自家用)”字样的
LONG	);
	set("exits",([
	"west" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","finger");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"