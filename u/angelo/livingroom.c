#include <ansi.h>
  inherit ROOM;
void create()
{
             set("short", HIW"����"NOR);
        set("long", @LONG
 �����ǹۺ�С���Ĵ���,һ����紵����ʱ�����ĺɻ���������������䡣
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
