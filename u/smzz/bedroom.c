// smzz mk in 2002 5.21 
#include <ansi.h> 
inherit ROOM; 
void create() 
{
set("short",HIC"睡放"NOR);
set("long",
"沙漠之子的睡房,一个大的你走到边就要吃一盒气锅鸡\n"
"的大房间里面的摆设其实很简单,一张"MAG"苏夢馨"NOR"牌压不断\n"
"钢床,和一对苏夢馨姐妹站在窗户的旁边一副小心翼翼的样子\n"
""HIM"~~~~~~~~~~~~~~~~~~"NOR"\n" 
""HIM"*"HIW"[]"NOR"               "HIM"*\n"NOR 
""HIM"*                 *"NOR"\n" 
""HIM"*"HIW"[]"NOR"               "HIM"*\n"NOR 
""HIM"*                 *"NOR"\n" 
""HIM"~~~~~~~~~~~~~~~~~~"NOR"\n" 
);
set("sleep_room",1);
set("no_fight",1);
set("exits",
([
"down": __DIR__"louti3",
]));
setup();
}
