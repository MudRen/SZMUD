// Code of ShenZhou
// waiter.c

#include <ansi.h>

inherit NPC;

string ask_me(object);

void create()
{
    set_name("�츣��", ({ "tianfu" }) );
    set("gender", "����" );
    set("age", 22);
    set("combat_exp", 100);
    set("attitude", "friendly");
    set("inquiry", ([
            "dan" : (: ask_me :),
            "�츣��" : (: ask_me :),

    ]));
    setup();
}

string ask_me(object ob)
{
    object dan, me = this_player();
    if ( me->query( "tianfu4" ) )
        return "�㲻�ǳԹ�����\n";
    if ( me->query_temp( "askedtianfu" ) )
        return "�㲻��Ҫ������\n";
    me->set_temp( "askedtianfu", 1 );
    dan = new ( __DIR__"tianfu4" );
    dan->move( me );
    return "�ú��ˣ��ǵ�ÿ��ֻ�ܳ�һ�Ρ�\n";
}



