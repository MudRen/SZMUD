// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 300
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"神州大街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
这里是金元宝宝(yuanbao)的[1;37m移[1;35m花[1;36m宫[37;0m。
这里边是闻名天下的移花宫, 金元宝设在长安的行宫.
LONG	);
	set("exits",([
	"west" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","yuanbao");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"
