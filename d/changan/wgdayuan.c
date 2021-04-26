//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","武馆大院");
	set("long",@LONG
你站在武馆的教练场中，地上铺着黄色的细砂，一群二十来岁的小伙子正
在努力的操练着，边上还有位教头模样的人在纠正他们的错误。还有个小伙子
在喊着。前面有堵墙(wall)，墙的后面就是长安城的赌坊。
LONG
	);
	set("exits",([
		"east" : __DIR__"wuguan",
	]));

	setup();
}
void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return 0;

        if( arg=="wall")
        {
                if (me->query_skill("dodge",1)<100)
                    write("你试图翻过墙到赌坊那边去，但老是跳不上去。\n");
                else {
                    write("你纵身跃过了墙。\n");
                    message("vision",
                             me->name() + "一纵身跃过了墙，到赌坊去了。\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"dufang");
                    message("vision",
                             me->name() + "从武馆大院跃了过来。\n",
                             environment(me), ({me}) );
                }
                return 1;
           
        }
}

