// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 6000
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"神州大街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
这里是傲峰(hhq)的[1;32m流云清水阁[1;32m[37;0m。
      真亦假时假亦真 ,无为有时有还无
LONG	);
	set("exits",([
	"west" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","hhq");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"