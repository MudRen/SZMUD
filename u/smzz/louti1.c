// smzz mk in 2002 5.21
#include <ansi.h> 　　　　
inherit ROOM;
void create()
{
set("short",RED"楼梯一级"NOR);
set("long",
"这是通往沙漠之子睡房的楼梯一层\n"
);
set("exits",
([
"up": "u/smzz/louti2",
"down":"u/smzz/room",
]));
setup();
}
