//Cracked by Roath
// wdroad5.c
// by Xiang

inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
你走在一条青石大道上，四周静悄悄的。西北方就是陕鄂边界了。北方有一
片空地，不知道是什么时候被人平整出来的。遥遥向北望去，空地周围的树木长
得甚是茂密。
LONG
        );
        set("outdoors", "sanbuguan");

        set("exits", ([
                "east" : __DIR__"road5",
                "north" : "/d/taohua/kongdi",
                "northwest" : __DIR__"xroad1",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
