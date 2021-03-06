// /d/kaifeng/ximen.c
//by bravo
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "南门");
        set("long", @LONG
这是开封南城门，城门正上方刻着“南门”两个楷书大字，城墙
上贴着几张官府告示(gaoshi)。一条笔直的青石板大道向南延伸。南
边是郊外，遍地麦浪金黄迷人。北边是城里。
LONG
        );

        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));
        set("exits", ([
                  "north" : __DIR__"sroad2",
                  "south" : __DIR__"tiandi1",
        ]));
        set("objects", ([
           __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        set("outdoors", "kaifeng");
        setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n开封府\n包拯\n";
}
