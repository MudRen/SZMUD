// room /d/wulin/fajue.c
//Lara 2001/10/19
inherit ROOM;
void create()
{
        set("short", "罚恶居");
        set("long", @LONG
大名鼎鼎的罚恶使者的居处，目前这里是空的。
LONG
        );

        set("exits", ([
         "west" : __DIR__"xiaolu8",        
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
