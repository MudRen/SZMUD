// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 600
inherit ROOM;
void create()
{       
    string *dir=({"东","西"});
    set("short",HIG"神州大街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
    set("long", 
            HIC"    这里是水手(mariner)的小船。\n"NOR +
            HIC"    小小的"+HIB"海船"NOR+HIC"。\n"NOR
            );
    set("exits",([
    "west" : __DIR__"street"+(string)(ID/100),
    ]));
    set("owner","mariner");
    set("coor/x",40+(ID%2)*20);
    set("coor/y",20+(ID/100)*10);
    set("coor/z",0);
    setup();
}
#include "outdoor_func.c"
