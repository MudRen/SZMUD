// Code of ShenZhou
// Room: /city/bingqiku.c
// mariner 5/2002

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "监狱");
        set("long", @LONG
这里是监狱，约莫两丈见方的一间大石室，墙壁和顶板都是大石
所砌。墙角里放着一只粪桶，鼻中闻到的尽是臭气和霉气。西面墙上
开着一扇小窗(window)。
LONG
        );

        set("cost", 0);
        set("no_fight", 1);
        setup();
}
void init()
{
    object cloth = new ( "/clone/misc/cloth" );
    object me = this_player();
    int times = 1;
	
	add_action("do_fight", "fight");
    add_action("do_fight", "kill");
    add_action("do_fight", "hit");
    add_action("do_fight", "throw");
    add_action("do_visit", "look");
	
	if (this_player()->query_condition("embedded")>0)
		this_player()->apply_condition("embedded", 0);
	if ( me->query( "no_cloth" ) )
    {
        times = me->query( "no_cloth" );
        call_out( "move_out", 100*times, me );
    }    
}

void move_out( object me )
{
    object cloth = new( "/clone/misc/cloth" );
    if ( !me ) return;
    
        message_vision("看$N有悔改之意，州府决定释放$N。\n",me);
        message_vision("老狱卒扔给$N一包旧衣服，命$N穿上，然后一脚把$N踢出了牢房。\n",me);
    cloth->move( me );
    cloth->wear();
    me->move( "/d/city/kedian" );
}

int do_visit(string arg)
{
    object env, me = this_player();

    if (arg != "window") return 0;

    if(!( env = find_object("/d/city/bingyin")) )
    env = load_object("/d/city/bingyin");

    tell_room(env, "你发现有一双眼睛在窗子背後张望。\n");
    return "/cmds/std/look"->look_room(me, env);
}
int do_fight(string arg)
{
        write("你觉双腿发软，手也提不起来！\n");
        return 1;
}
