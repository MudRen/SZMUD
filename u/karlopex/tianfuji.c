// Code of ShenZhou
// waiter.c

#include <ansi.h>

inherit NPC;

string ask_me(object);

void create()
{
    set_name("天福机", ({ "tianfu" }) );
    set("gender", "男性" );
    set("age", 22);
    set("combat_exp", 100);
    set("attitude", "friendly");
    set("inquiry", ([
            "dan" : (: ask_me :),
            "天福丹" : (: ask_me :),

    ]));
    setup();
}

string ask_me(object ob)
{
    object dan, me = this_player();
    if ( me->query( "tianfu4" ) )
        return "你不是吃过了吗。\n";
    if ( me->query_temp( "askedtianfu" ) )
        return "你不是要过了吗。\n";
    me->set_temp( "askedtianfu", 1 );
    dan = new ( __DIR__"tianfu4" );
    dan->move( me );
    return "拿好了，记得每人只能吃一次。\n";
}



