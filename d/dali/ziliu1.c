// Code of ShenZhou
// Room: /d/dali/ziliu1.c

inherit ROOM;

void create()
{
        set("short", "别院");
        set("long", @LONG
这里是大理高官府第,庭院并不太深.西面是大厅,门外种植着无数茶花,
花枝茂盛.
LONG
        );
       
        set("exits", ([ /* sizeof() == 2 */
                "north" : __DIR__"wangfu1.c",       
                "west" : __DIR__"ziliu2.c",
                ]));

        
        set("no_clean_up", 0);
        set("wangfu", 1);

        setup();
}
