// smzz mk in 2002 5.21 
#include <ansi.h> 
inherit ROOM; 
void create() 
{
set("short",HIM"楼梯二级"NOR); 
set("long", 
"这是通往沙漠之子睡房的楼梯二层\n" 
);
set("exits", 
([
"up": __DIR__"louti3", 
"down": __DIR__"louti1", 
]));
setup();
}
