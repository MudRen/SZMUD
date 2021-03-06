// Filename:   /d/jueqinggu/chufang.c
// Program:    Jiuer
// Date:       Aug 15, 2001

inherit ROOM;
int serve();

void create()
{
		  set("short","厨房");

		  set("long",@LONG
庄内人禁食荤腥，外客来往稀少。厨房不大，靠墙是一个灶台，灶
火正旺，灶上支一口大锅，厨娘正在忙着烧菜(serve)。 旁边小桌上摆
着几个空水碗和几盘吃剩的素食。
LONG);

	  set("exits",([ 
		  "south" : __DIR__"changlang5",
			 ]));
	  
	  set("cost",1);
	  setup();
}
void init()
{ 
	add_action("do_serve","serve");
}

int do_serve()
{
	object ob,me;
	me=this_player();

	message_vision("$N向厨娘要些食物吃喝。\n", me);

    if (!present("donggu", environment(me))
		&& !present("doufu", environment(me))
		&& !present("douya", environment(me))
	    && !present("donggu", me)
        && !present("doufu", me)
        && !present("douya", me))
	{
		switch(random(3)) {
        case 0:
			ob=new("/d/jueqing/obj/doufu");
            break;
		case 1:
			ob=new("/d/jueqing/obj/donggu");
			break;
		case 2:
			ob=new("/d/jueqing/obj/douya");
            break;
		}    
        ob->move(environment(me));
        message_vision("厨娘端出"+ob->name()+"给$N。\n", me);
	}
    else message_vision("厨娘对$N笑道：心这么贪，您把谷里人一年的供给都吃啦。\n", me);
    
    if (!present("migao", environment(me))
		&& !present("xiaowancha", environment(me))
		&& !present("huaban",environment(me))
        && !present("migao", me)
        && !present("xiaowancha", me)
		&& !present("huaban",me))
	{
        switch(random(3)) {
        case 0:
			ob=new("/d/jueqing/obj/migao");
            break;
		case 1:
			ob=new("/d/wudang/obj/xiaowancha");
            break;
		case 2:
			ob=new("/d/jueqing/obj/huaban");
			break;
		}
        ob->move(environment(me));
        message_vision("厨娘端出"+ob->name()+"给$N。\n", me);
	}
    else message_vision("厨娘对$N笑道：心这么贪，您把谷里人一年的供给都吃啦。\n", me);
    return 1;
}

int valid_leave(object me, string dir)
{
	if (present("doufu", me)
		|| present("douya", me)
        || present("donggu", me)
        || present("migao", me)
		|| present("huaban",me))
        return notify_fail("厨娘拦着你说：“您还是吃完再走吧。”\n");
	return ::valid_leave(me, dir);
}
