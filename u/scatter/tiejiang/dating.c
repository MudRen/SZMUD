//code by cheap
//11/10/01
#include <ansi.h>

inherit ROOM; 

void create()

{
        set("short",HIC"大厅"NOR);
        set("long",
"这里是车行大厅，堂上东西有两根楹住，挂着一幅对联，正墙上悬挂一个横\n"
"匾，横匾上写著“万事胜意”四个大字。老板正在和顾客讨价还价呢。\n"
); 
        set("exits", ([ 
               "out":"/newjob/tiejiang/gate", 
                      ])); 
        set("objects", ([ 
                "/newjob/tiejiang/npc/feng.c" : 1, 
                        ]) );
        set("day_shop",1);
        setup();
}
