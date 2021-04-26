// room /d/wulin/xiaolu8.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
小路已到尽头，左右两处为罚恶使者的居所。罚恶居由石头砌成，仅
观其建筑便凛然感到一种威严。

LONG
        );

        set("exits", ([
        "south" : __DIR__"xiaolu7",
        "east" : __DIR__"fajue",
        "west" : __DIR__"fajuw",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
