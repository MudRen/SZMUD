#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"家具城"NOR);
	set("long",@LONG
这里是家具铺子的二楼，摆放着各式各样的家具，如果你要购买家具
就一定不能错过这里。这里最多的是各式各样的大床，各种外形各种颜色
的都有。此外，也少不了桌椅之类的必要家具。
    听说这里还在不断地设计新的家具呢，你可以在稍后再来看看。
LONG	);
	set("exits",([
	"down" : __DIR__"shop",
	]));
	set("objects",([
	__DIR__"npc/seller":1,
	__DIR__"npc/obj/jiaju":1,
	__DIR__"npc/obj/jiaju1":1,
	__DIR__"npc/obj/jiaju2":1,
	__DIR__"npc/obj/jiaju3":1,
	__DIR__"npc/obj/jiaju4":1,
	__DIR__"npc/obj/jiaju5":1,
	__DIR__"npc/obj/jiaju6":1,
	]));
	set("coor/x",60);
	set("coor/y",20);
	set("coor/z",10);
	set("no_fight",1);
	setup();
}