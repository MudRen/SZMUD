// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 200
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"神州大街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
这里是神聊(chat)的[1;32m聚贤庄[37;0m。
    这里是传说中的铁血盟龙头老大神聊的居所。
LONG	);
	set("exits",([
	"west" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","chat");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"