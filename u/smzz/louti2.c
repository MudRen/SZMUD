// smzz mk in 2002 5.21 
#include <ansi.h> 
inherit ROOM; 
void create() 
{
set("short",HIM"¥�ݶ���"NOR); 
set("long", 
"����ͨ��ɳĮ֮��˯����¥�ݶ���\n" 
);
set("exits", 
([
"up": __DIR__"louti3", 
"down": __DIR__"louti1", 
]));
setup();
}
