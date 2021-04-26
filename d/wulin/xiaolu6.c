// room /d/wulin/xiaolu6.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
小路到这里变得狭窄，山路乃是贴着石璧凿出。你收紧心思，小心翼
翼地继续向前走。
LONG
        );

        set("exits", ([
         "west" : __DIR__"xiaolu5",
         "east" : __DIR__"xiaolu7",
        ]));

        set("no_clean_up", 0);        
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
