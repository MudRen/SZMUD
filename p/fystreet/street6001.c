// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 6001
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"神州大街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
这里是水恋月(daydream)的[1;37m 圆梦居[37;0m。
    一个圆梦的地方.开心的或不开心的都收藏在这小小的屋子里.
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","daydream");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"