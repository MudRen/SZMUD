// smzz mk in 2002 5.21
#include <ansi.h> ��������
inherit ROOM;
void create()
{
set("short",RED"¥��һ��"NOR);
set("long",
"����ͨ��ɳĮ֮��˯����¥��һ��\n"
);
set("exits",
([
"up": "u/smzz/louti2",
"down":"u/smzz/room",
]));
setup();
}
