// Code of ShenZhou
inherit ROOM;
#include <ansi.h>
#include "battlefield.h"

void create()
{
  set("short", HIG"北院东侧"NOR);
  set("long", @LONG
这里就是比武场了，各路英雄们正大打出手，祝你好运！
当你杀死一个玩家后不要望了将其结果 (finish)，踢出比武场。
LONG
  );

  set("exits", ([
		 "north" : __DIR__"bf1en",
		 "east" : __DIR__"bf1ee",
		 "west" : __DIR__"bf1",
		 ]));
  // must have this line
  createRoom();
  setup();
}

void init()
{
  // must have this line
  initRoom();
}

