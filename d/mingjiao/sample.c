// Code of ShenZhou
// Room: /d/mingjiao/luanshidui.c
#include <ansi.h>
inherit ROOM;


void create()
{
        set("short",HIC "�Թ�" NOR);
        set("long", HIW @LONG
����һ���Թ���
LONG NOR
);      
/*	set("exits", ([ 
 "east" : __DIR__"shanlu23",
  "west" : __DIR__"shanlu23",
  
]));
*/
set("no_clean_up", 1);
        setup();

}
