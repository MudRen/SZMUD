// shanao1.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "ɽ��");
                  set("long",@long
�������߶��Ǹ�ɽ,�պõ�ס�˷�ɳ,����һ�ж��ǹ�ͺͺ��,
����Զ�������ǿ鿪����.
long);
                 set("exits",([
"west" : __DIR__"shanao",
"east" : __DIR__"hmgate",
"northup" : __DIR__"shanpo",
]));

set("cost",1);
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
