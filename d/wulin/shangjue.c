// room /d/wulin/shangjue.c
//Lara 2001/10/19
inherit ROOM;
void create()
{
        set("short", "赏善居");
        set("long", @LONG
大名鼎鼎的赏善使者的居处,目前这里是空的。
LONG
        );

        set("exits", ([
         "west" : __DIR__"xiaolu4",        
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
