// shanao.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "山坳");
                  set("long",@long
这里两边都是高山,刚好挡住了风沙,但是一切都是光秃秃的,
东边远处好像是块开阔地.
long);
                 set("exits",([
"west" : __DIR__"shenshan3",
"east" : __DIR__"shanao1",
]));

set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
