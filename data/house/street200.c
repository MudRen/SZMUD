#define ID 200
#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"空地"NOR);
	set("long",@LONG
这里是一片宽敞的空地，在拥挤的大城市里几乎是不可见的了。这不，这儿
也要马上就变成居住区了。只是没有人买下，因为现在这里建房子，不仅财富要
足够，名头，声望都得在风云城内赫赫有名才行，因为这里是——风云街！
LONG	);
	set("roomid",ID);
  if(ID%2) set("exits",(["east":__DIR__"street"+(string)(ID/100),]));
  else set("exits",(["west":__DIR__"street"+(string)(ID/100),]));
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
