// Code of ShenZhou
// Room: /city/kedian.c
// YZC 1995/12/04

inherit ROOM;

// Marz added indecent or inapproapriate id check here :
string* Banned_id = ({
        "ufk",
        "none",
});


void create()
{
        set("short", "有间客栈");
        set("long", @LONG
这家客栈紧靠长安城中心，所以生意非常兴隆。兼之价钱低廉，更是成
了外地游客落脚的首选。露天摆了七八张桌子，三教九流人等在此进进出出，
络绎不绝，几个跑堂的小二来来回回招待着四方来客。
LONG
        );

//      set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "楼上雅房，每夜四两白银。\n",
        ]));

        set("objects", ([
                "/d/quanzhou/npc/qzxiaoer" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"eroad2",
                "west" : __DIR__"majiu",
                "up" : __DIR__"changankezhan",
]));
        set("outdoors", "changan");
        setup();
//      "/clone/board/kedian_b"->foo();
//      "/clone/board/jiangpai_b"->foo();
}

int valid_leave(object me, string dir)
{
        string id;
        int i;

        if(me == present("xiao er"))
                return ::valid_leave(me, dir);

        if(objectp(present("xiao er", environment(me)))) {
                if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

                if ( me->query_temp("rent_paid") && dir == "west" )
                return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");
        }

        if( present("xiao er", me) && dir="west" )
                return notify_fail("好端端地你想带店小二到那里去？！\n");

        id = (string)me->query("id");
        for (i = 0; i < sizeof(Banned_id); i++)
        {
        if (id == Banned_id[i])
        {
                me->set("startroom", "/d/death/block");
                me->move("/d/death/block");
                return notify_fail("嘿嘿，看你能跑到哪里去！！\n");
        }
        }

        return ::valid_leave(me, dir);
}
