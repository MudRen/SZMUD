#include <ansi.h>
  inherit ROOM;
void create()
{
             set("short", HIW"客厅"NOR);
        set("long", @LONG
 这里是观荷小筑的大厅,一阵清风吹来顿时淡淡的荷花香充满了整个房间。
LONG);
        set("exits", ([
                    "west" : "/u/angelo/workroom",
                    "east" : "/u/angelo/bedroom",
  ]));
              setup(); 
set("objects", ([ 
 "/u/angelo/genu" : 1, 
                       ])); 

}
