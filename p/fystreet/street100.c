// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 100
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"神州大街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
这里是香水(dior)的[1;32m香水[1;33m望月[1;32m居[37;0m。
    有空来坐坐
LONG	);
	set("exits",([
	"west" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","dior");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"