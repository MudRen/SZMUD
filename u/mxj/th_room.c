#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIM"世外桃源"NOR);  
    set("long",
"
你不知不觉来到了"HIM"世外桃源"NOR",这里是马冥风和桃花弟子谈天说地的好去处。
"
);
        set("exits", ([
"out" : "/d/city/wumiao",
"thd" : "/d/taohua/hyjuchu",
"gyz" : "/d/taihu/shufang",

]));
set("objects", ([
"/d/taohua/obj/tiexiao" : 1,
"/d/taohua/obj/zhuxiao" : 1,
"/d/taohua/obj/bagua" : 1,
]));
                 setup(); 
}
