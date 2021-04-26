// Room: /d/changan/xfroad2.c
// by bravo 

inherit ROOM;

void create()
{
        set("short", "幸福大街");
        set("long", @LONG
走到这里，往西北方向就是官府了。远望官府大门，几个衙役正无精
打采地站在那里闲聊，街上有些落叶，一阵风吹来，让人不寒而栗。
LONG );
        set("outdoors", "changan");
        set("no_clean_up", 0);
        set("exits", ([
                "southeast"  : __DIR__"center",
                "northwest" : __DIR__"gfdoor",
                "northeast"  : __DIR__"xfroad3",
                "southwest" : __DIR__"xfroad1",
        ]));
set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}
