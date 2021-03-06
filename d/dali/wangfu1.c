// Code of ShenZhou
// Room: /d/dali/wangfu1.c

inherit ROOM;

void create()
{
        set("short", "王府大门:");
        set("long", @LONG
你正站在一座豪华的府门前，门前有两只极大的石狮子，门
上高悬一块横匾，上书「平南王府」四个金字。门口站着两排侍
卫，身着锦衣，手执钢刀，气宇轩昂。
LONG
        );

        set("cost", 1);
        set("exits", ([
                "east" : __DIR__"taihejie5.c",
                "enter" : __DIR__"wangfu2.c",
                ]));

        set("objects", ([
                __DIR__"npc/weishi1" : 1,
                __DIR__"npc/weishi2" : 2,
                "/kungfu/class/dali/zhuwanli" : 1,
        ]));

        set("cost", 1);

        set("no_clean_up", 0);
        set("wangfu", 1);
        set("valid_startroom",1);

        setup();
        "/clone/board/dali_b"->foo();
}

void init()
{
        object me;

        if (interactive(me = this_player())
                && me->query("family/family_name")=="大理段家"
                && !me->query("dali/employee")) {
                me->set("dali/employee",1);
                me->set("dali/trust",100);
        }
}

int valid_leave(object me, string dir)
{
        object ob;
        if (me->query("family/family_name")!="大理段家"
                && !me->query("dali/employee")
                && me->query("combat_exp") > 800000
                && dir == "enter"
                && living(ob=present("zhu wanli", environment(me))))
                return notify_fail("褚万里喝道：闲杂人等，不得入内。\n");

        return ::valid_leave(me, dir);
}
