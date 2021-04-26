// room /d/wulin/xiaolu1.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
离开殿门西行，景色转而清幽，你的心情也随之轻松下来，但想起小
路径直通向武林中赫赫有名的赏善使者的居处，不由得加快了脚步。东面
是武林同盟的殿门。
LONG
        );

        set("exits", ([
         "east" : __DIR__"dianmen",
         "west" : __DIR__"xiaolu2",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
