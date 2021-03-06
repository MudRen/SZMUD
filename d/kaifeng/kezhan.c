// /d/kaifeng/kezhan.c
//by bravo
inherit ROOM;

void create()
{
        set("short", "无边客栈");
        set("long", @LONG       
    无边客栈是河南最大的客店，生意非常兴隆。外地游客多选择这
里落脚，你可以在这里打听到各地的风土人情。店小二里里外外忙得
团团转，沉重的地方官话你是实在听不顺耳。这是开封府官办的客栈,
接待着各地入豫的官差浪人。墙上挂着一个牌子(paizi)。
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "楼上雅房，每夜五两白银。\n",
        ]));

        set("objects", ([
         "d/city/npc/xiaoer" : 1,
              ]));

        set("exits", ([
          "northwest" : __DIR__"sroad2e",
                "up" : __DIR__"kezhan2",
        ]));

        setup();
        
}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("想白住,你找扁啊！\n");

        if ( me->query_temp("rent_paid") && dir == "west" )
                return notify_fail("客官已经付了银子，怎么不住店就走了呢！旁人还以为小店伺候不周呢！\n");

        return ::valid_leave(me, dir);
}

