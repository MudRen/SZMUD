// Code of ShenZhou
//zyz /12/13/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "甬路");
        set("long", @LONG
只见两边翠竹夹路，土地下苍苔布满，中间羊肠一条石子砌
的甬路。
LONG
        );


set("wangfu", 1);
        set("outdoors", "dali");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

