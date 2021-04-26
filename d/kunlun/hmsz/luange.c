// luange.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "暖阁");
                  set("long",@long
你来到一座暖阁之中。昆仑一带极为寒冷，暖阁中却温暖如春，
可又不见何处生着炭火，但见阁中陈设辉煌灿烂，榻上椅上都铺
着锦缎软垫。
long);
                 set("exits",([
"east" : __DIR__"tingwai",
"west" : __DIR__"hmttang",
  "enter" : __DIR__"pianting",
]));

              setup();
              replace_program(ROOM);
}
