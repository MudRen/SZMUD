// tingwai.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "厅外");
                  set("long",@long
    走了好一会，来到一座大厅之外，只见厅上扁额写着“灵獒营”三字。
里面隐隐约约听到少女的呵斥声.  
long);
                 set("exits",([
"west" : __DIR__"luange",
"enter" : __DIR__"laoying",
]));

              setup();
              replace_program(ROOM);
}
