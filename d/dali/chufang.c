// Code of ShenZhou
// chufang.c

inherit ROOM;

int serve();

void create()
{
	set("short", "伙房");
	set("long", @LONG
这里是官宅的伙房，专为住在这里的官员们提供伙食(serve)。一
群身着军服的官员正围着桌子就餐，品尝大理特产的菜肴。官员们在
这里可以不受限制地吃喝要菜，但不许把食物带出厨房。
LONG
	);

	set("exits", ([
		"north" : __DIR__"diziarea.c",
	]));
	
	setup();
}

void init()
{
/*	object ob=this_player();

	if (userp(ob) && !wizardp(ob) && ob->query("family/family_name") != "大理段家") {
		message_vision("几个王府家丁冲了进来，大声嚷道：“$N你不是大理的人，怎么闯到这里来了？快滚出去！\n",ob);
		remove_call_out("kickout");
		call_out("kickout", 1, ob);
	}
*/
	add_action("do_serve", "serve");
}
/*
int kickout(object ob)
{
	if (!present(ob,find_object("/d/dali/chufang.c"))) {
		return 1;
	}
	message_vision("一群武士蜂拥而上把$N乱棍轰了出去。\n",ob);
	ob->move("/d/dali/taihejie5");
	message("vision","只听“乒”地一声，"+ob->query("name")+"从王府里被人乱棍打了出来。\n", environment(ob), ob);
	ob->apply_condition("dalikiller",100);
	return 1;
}
*/
int do_serve()
{
	object ob,me;
	me=this_player();

	message_vision("$N向厨子要些食物吃喝。\n", me);

	if (me->query("family/family_name") != "大理段家"
		&& !me->query("dali/employee"))
		return 1;

	if (!present("guoqiao mixian", environment(me))
		&& !present("guoqiao heiyu", environment(me))
		&& !present("ye er ba", environment(me))
		&& !present("guoqiao mixian", me)
		&& !present("guoqiao heiyu", me)
		&& !present("ye er ba", me))
	{
		switch(random(3)) {
		case 0:
			ob=new("/d/dali/obj/mixian");
			break;
		case 1:
			ob=new("/d/dali/obj/guoqiao");
			break;
		case 2:
			ob=new("/d/dali/obj/yeerba");
			break;
		}    
		ob->move(environment(me));
		message_vision("厨子端出"+ob->name()+"给$N。“您慢慢吃，不够还有。”\n", me);
	}
	else message_vision("厨子对$N说道：你不是有东西吃吗，吃完再说吧。\n", me);
	
	if (!present("puer cha", environment(me))
		&& !present("qiguo ji", environment(me))
		&& !present("qiguo ji", me)
		&& !present("puer cha", me)) {
		switch(random(2)) {
		case 0:
			ob=new("/d/dali/obj/qiguoji");
			break;
		case 1:
			ob=new("/d/dali/obj/puercha");
			break;
		}
		ob->move(environment(me));
		message_vision("厨子端出"+ob->name()+"给$N。“您慢慢喝，不够还有。”\n", me);
	}
	else message_vision("厨子对$N说道：你不是有东西喝吗？喝完再说吧。\n", me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (present("guoqiao mixian", me)
		|| present("guoqiao heiyu", me)
		|| present("qiguo ji", me)
		|| present("ye er ba", me)
		|| present("puer cha", me))
		return notify_fail("厨子拦着你说：“您还是吃完再走吧。”\n");
	return ::valid_leave(me, dir);
}
