#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"风云商场"NOR);
	set("long",@LONG
这里是风云街商场。
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