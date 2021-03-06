// Room：/u/athena/damen.c

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIW"神州风云馆"NOR);
        set("long", 
"这是一个十分巍峨的建筑，灰色的大理石墙壁，厚重的实木大门，门口有两根
擎天立柱，上挂五个大字——神州风云馆。这里记录了神州的风云变幻和沧桑历史
。门的右侧竖了一个石碑（bei）,门口还坐了一位老人，他双目无神，但似乎在思
考着什么。\n"
);
        set("no_fight",1);
        set("exits", ([
                "enter" : __DIR__"dating.c",
        ]));
        create_door("enter", "大门", "out", DOOR_CLOSED);
        set("cost", 0);
 set("item_desc", ([ 
 "bei" : "这是一块很普通而且有点班驳的石碑，奇怪的是上面没有任何字或者图案。\n", 
])); 
setup();
}
