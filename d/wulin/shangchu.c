// room /d/wulin/shangchu.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "赏善处");
        set("long", @LONG
这里就是赏善处，赏善使者经常在这里奖赏为武林同盟作出突出贡献的义士，
为他们颁发奖品。在桌子上面放着四个精美的盒子。
LONG
        );

        set("exits", ([
         "east" : __DIR__"xiayitang",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
