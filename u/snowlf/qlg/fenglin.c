// qlg/fenglin.c 枫林
// snowlf by 2001.12.17

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIR"枫林"NOR);
        set("long","
    这时正是仲秋时节，枫树的叶子都红子了。好一片红叶！你赞叹著！睁大眼
睛注视著，那些红叶似带著无尽的喜悦，在秋天的阳光下，伸展著枝丫，绽放生
命的光华，你轻叹著，第一次了解前人词句＂晓来谁染霜林醉＂的意境！
    
"NOR);

        set("no_fight", 0);           
        set("valid_startroom",1);
        
        set("exits", ([
         	"west" : __DIR__"asgard_door",
		

		
        ]));


        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",1);
        set("no_steal",1);
        set("objects",([ 
                
                 __DIR__"npc/yutu":2,   
   
       
]));
        setup();
 
}
