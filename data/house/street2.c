#define ID 2
#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"风云街"+chinese_number(ID)+"号"NOR);
	set("long",@LONG
风云街，风云城内风云人物居住的地方，能在这里拥有一间房子是无数人的
梦想。一条宽敞的大道，两旁是葱葱郁郁两排青松。隐隐约约还有些房子从松林
中露出头来。
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
