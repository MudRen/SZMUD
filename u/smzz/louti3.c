// smzz mk in 2002 5.21 
#include <ansi.h> 
inherit ROOM; 
void create() 
{
set("short",HIG"¥������"NOR); 
set("long", 
"����ͨ��ɳĮ֮��˯����¥������\n" 
);
set("exits", 
([
"up": __DIR__"bedroom", 
"down": __DIR__"louti2", 
]));
setup();
}
