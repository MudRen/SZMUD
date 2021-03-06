// qlg/asgard_door   ℅骇甤
// snowlf by 2001.12.16



#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIM"仙山"NOR);
        set("long",
    "这是隐落云端的一座仙山，你的面前是一座晶莹剔透的水晶宫，门前绿草如
茵，东边有一小片"+HIR+"枫林"+NOR+"，你手搭凉棚，拨开云头向下界看去，却正是天池灵山之
上。
    拾阶而上，近得宫前，但见门前两盏宫灯上分别书有"+HIG+"【沁】"+NOR+","+HIM+"【涟】"+NOR+"二字。
    
");
        set("no_fight", 1);           
        set("valid_startroom",1);
        
        set("exits", ([
           "snowyu" : "/u/snowyu/yangtai",
		"west" : __DIR__"caodi",
		"enter" : "/u/snowlf/workroom",
		"east" : __DIR__"fenglin",
         	"down" : "/d/xingxiu/lingshan",
       		"newjob" : "/u/snowlf/room/meeting_room",
                "hmsz" : "/u/karlopex/hmsz-dy",
		"xrz" : "/u/xrz/workroom",
		"wr" : "/d/wizard/wizard_room",
		
        ]));

        set("item_desc", ([
                        "下界": "你手搭凉棚，拨开云头向下界看去，却正是天池灵山。\n",
                        "枫林": "    这时正是仲秋时节，枫树的叶子都红子了。好一片红叶！你赞叹著！睁大眼
睛注视著，那些红叶似带著无尽的喜悦，在秋天的阳光下，伸展著枝丫，绽放生
命的光华，你轻叹著，第一次了解前人词句＂晓来谁染霜林醉＂的意境！　    \n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",1);
        set("no_steal",1);

        setup();

}
