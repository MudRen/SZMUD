// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 201
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"神州大街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
这里是油条(youtiao)的[1;32m随[1;33m意[1;37m居[37;0m。
    剑已入匣  人随烟云渺
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","youtiao");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"