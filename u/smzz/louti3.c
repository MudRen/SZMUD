// smzz mk in 2002 5.21 
#include <ansi.h> 
inherit ROOM; 
void create() 
{
set("short",HIG"楼梯三级"NOR); 
set("long", 
"这是通往沙漠之子睡房的楼梯三层\n" 
);
set("exits", 
([
"up": __DIR__"bedroom", 
"down": __DIR__"louti2", 
]));
setup();
}
