#define ID 3600
#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIW"空地"NOR);
	set("long",@LONG
这是拥挤的城市中难得一见的开阔地，不过，这里已经被打扫干净，
看上去正在寻找买家呢。想在这里拥有一套自己的房间可不容易，必须要
缴纳一大笔的购地款。
LONG	);
	set("roomid",ID);
  if(ID%2) set("exits",(["east":__DIR__"street"+(string)(ID/100),]));
  else set("exits",(["west":__DIR__"street"+(string)(ID/100),]));
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}