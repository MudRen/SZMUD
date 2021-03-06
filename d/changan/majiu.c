// Code of ShenZhou
// Room: /city/majiu.c
// Cleansword 1996/12/01

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"马厩"NOR);
        set("long", @LONG
这里是走远路的人在这买马的地方，这里的马匹上等，远近闻名，一位马
正在给几匹马喂料，旁边有几位来买马的武林人士正在相马。
LONG
        );

        set("objects", ([
		"/clone/obj/car" : 2,
		"/d/shaolin/npc/ma-fu" : 1,
		"/clone/horse/xiaoma" : 2,
		"/clone/horse/huangma" : 1,
		"/clone/horse/qingma" : 1,
		"/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
     "east" : __DIR__"kezhan",
     "west" : __DIR__"xfroad5",
		        ]));

        set("outdoors", "changan");
        set("resource/water",1);
        set("cost",1);

        setup();
        replace_program(ROOM);
}
