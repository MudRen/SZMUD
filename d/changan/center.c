// Room: /d/changan/center.c
// by bravo 

inherit ROOM;

void create()
{
        set("short", "十字街头");
        set("long", @LONG
这里就是长安城最繁华的地方了。从这里可以通往城的各个地方，再往前
走，就是府衙大门，那是黎明百姓伸冤，说理的地方。因为靠近官府，所以这
里时常有巡捕在走动巡查。大街上正有几个姑娘在卖话，还有一些卖艺的在演
示武艺，引得过往的人连连叫好！
LONG );
        set("outdoors", "changan");
        set("no_clean_up", 0);
        set("exits", ([
                "southeast"  : __DIR__"wwroad5",
                "southwest" : __DIR__"wwroad2",
                "northeast"  : __DIR__"xfroad5",
                "northwest" : __DIR__"xfroad2",
        ]));
        set("objects",([
                 "d/city/npc/xunbu":1,
                 "d/city/npc/liumang":1,
        ]));
        set("fanhua", 2);

        setup();
        replace_program(ROOM);
}
