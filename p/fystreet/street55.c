#define ID 55
#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIY"神州大街 "+chinese_number(ID)+" 号"NOR);
	set("long",@LONG
神州大街是风云人物们定居的地方，能在这里拥有一间房子是无数人
的梦想。一条宽敞的大道，两旁是葱葱郁郁两排青松，风格各异的房子尖
角屋檐隐隐约约地从松树后面显现出来。
LONG	);
	set("exits",([
	"south": __DIR__"street"+(string)(ID-1), 
	"west" : __DIR__"street"+(string)ID+"01",
	"east" : __DIR__"street"+(string)ID+"00",
        "north": __DIR__"street"+(string)(ID+1),
	]));
	set("coor/x",50);
	set("coor/y",20+ID*10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
