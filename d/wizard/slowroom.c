#include <ansi.h>
inherit ROOM;
void create()
{
               set("short", HIG"���꽻��"NOR);
          set("long", HIY @LONG
slow �Ĺ����ҡ�
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
