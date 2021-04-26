//Room: /d/kaifeng/eroad2s.c
// by bravo
inherit ROOM;
void create()
{
        set("short", "东大街");
        set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。向北是一条宽直的大
道。北边可以通往东城门，西南边通向南大街，东南方就是有名的望
江楼了。
LONG
        );

        set("exits", ([
                "north" : __DIR__"eroad2",
                "southwest":__DIR__"sroad2e",
                "southeast":__DIR__"tingyulou",
                ]));
         set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
