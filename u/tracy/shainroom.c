//by tracy
#include <ansi.h> 
inherit ROOM; 
void create()
{
     set("short", HIM"桃桃小筑"NOR);
     set("long", " 
还没进屋，一股香香甜甜的味道扑面而来环顾四周，天蓝色的墙壁上面挂着\n一把白色的吉他.粉色的小床,让你不禁在上面坐了一下,软软的,整个人都陷\n了进去.玻璃做的屋顶让你一抬头就看到了天上的星星.为什么脚下软棉棉的?\n难道是棉花的地板？不。。其实这是在云彩上面的小房子. \n   "HIM"    .    .   .          .    "NOR"                 
   "HIM"    .  ./~~~~~~~~~~~~'~.|  "NOR"   
   "HIM"     ,/,.,...........,.|  ."NOR" 
   "HIM"||  ..▎#  ▎田  田  ▎| ▎ "NOR"
   "HIM"||    ▎   ▎        ▎|'▎ o  .. "NOR"  
   "HIM"||  ■■■■■■■■■■〓▄▃▂▁ "NOR"
");
     set("exits", ([ 
        "cs" : "/d/city/guangchang",
        "south" : __DIR__"workroom",
      ]));
     set("valid_startroom", 1);
     set("no_fight", 1);
     set("sleep_room", 1);
     set("no_death", 1);
     set("no_clean_up", 0);
     setup();
     
}
