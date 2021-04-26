// room /d/wulin/xiayitang.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "侠义堂");
        set("long", @LONG
这里是武林同盟的侠义堂，武林同盟赏善使者平时不下山时，通常都
是在这里办理武林公案。上首正中放着把太师椅，赏善使者就坐在上面开
堂审理。西面就是赏善处。
LONG
        );

        set("exits", ([
                "south" : __DIR__"zoulang",
                "north" : __DIR__"zhengqiting",
                "west" : __DIR__"shangchu",
        ]));

        set("objects",([
                 __DIR__"npc/yishi" : 3,
        ]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("cost", 2);
        setup();
}
 