
// Room：/u/xuebi/workroom.c

#include <ansi.h>
#include <room.h> 
inherit ROOM;

void create()
{
        set("short", HIW "白雪小筑" NOR);
        set("long", @LONG
这是一间面积大约一百平房的办公室，一进门你有一种肃穆和典雅的感觉，
左面是一排宽大的纯白色真皮沙发、正对着的是一个豪华墙上挂着几幅毕加索
的抽象画的办公套桌，墙上挂着几幅毕加索的抽象画。
LONG
        );
        set("no_fight",1);
        set("exits", ([ /* sizeof() == 3 */
                  "kd"  : "d/city/kedian",
        ]));
        setup();
}
