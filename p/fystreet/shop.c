#include <ansi.h>
inherit ROOM;
void create()
{	set("short",GRN"家具铺"NOR);
	set("long",@LONG
这里是神州大街尽头的一间家具铺子，最近神州大街搬来了许多叱咤
风云的大人物。他们中的有些是杀人无数的魔王，有些是仗义疏财的大侠
客，有些是富甲一方的富豪。这些新搬来的人家，全都在这里购置家具，
所以这家店铺门前正忙得不亦乐乎。
LONG	);
	set("exits",([
	"east" : __DIR__"street0",
	"up" : __DIR__"shop2",
	"down" : __DIR__"bar",
	]));
	set("coor/x",60);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}