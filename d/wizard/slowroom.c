#include <ansi.h>
inherit ROOM;
void create()
{
               set("short", HIG"风雨交加"NOR);
          set("long", HIY @LONG
slow 的工作室。
LONG NOR);
        set("exits", ([
                  "down" : "/d/city/guangchang",
         "west" : "/d/wizard/wizard_room",
                  "south" : "/d/wizard/general_r",

]));
                 set("no_sleep", 1);
                 call_other("/clone/board/slow_b", "???");  
                 setup(); 
}
