// shanao.c (kunlun)

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
"west" : __DIR__"shenshan3",
"east" : __DIR__"shanao1",
]));

set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
