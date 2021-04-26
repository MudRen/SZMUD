// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 301
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"风云街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
风云街，风云城内风云人物居住的地方，能在这里拥有一间房子是无数人的
梦想。狮子的[1;33m仰天阁[2;37;0m就在这里。郁郁葱葱的松林，鸟语花香。
抬头仰天望，笑看风云过。
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","lion");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"