// road: /zhongnan/dong.c
// update by lara 01.10.23

inherit ROOM;

void create()
{
	set("short", "山洞");
 
    set("long",@LONG
在这小山洞的深处，一股强大的水流自地上流出，形成一条小河流向
洞外。如果想再进一步深入的话，就得要跳入水中了。往外可到小河边。
往里就要潜水(dive)了。
LONG);
	set("exits",([ "out" : __DIR__"river",
		]) );

	set("cost",2);
	setup();
}

void init()
{
    add_action("do_dive", "dive");
    add_action("do_dive", "qian");
}

int do_dive(string arg)
{
    object me = this_player();

    if (!arg || arg=="") return 0;

    if ( arg == "river" || arg == "water") 
	{
		message_vision("$N一纵身跳入水中......", me);

        if (me->query_skill("yunu-xinjing",1)<60 )
	 	{
			message_vision("可惜$N在水底摸索了半天什么也没摸到，只好爬回岸上。\n", me);
        }
        else {
			message("vision", "\n\n", environment(me));
         //   message("vision","你在水底潜行，慢慢向深处摸去......\n\n\n", environment(me));
            message_vision("$N在水底潜行，慢慢向深处摸去......\n\n\n", me);
            me->move("/d/gumu/water2");
        }
        return 1;
	}
	
	return 0;
}
