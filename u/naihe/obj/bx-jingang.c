// 送给spark的儿童节礼物啦  :)  presents.c
// by naihe  02-05-31  for spark.


#include <ansi.h>
inherit ITEM;

string now,now_muyang,now_where,
now="none",
now_where="ok";

void bian_gold();
void back();

void create()
{
	set_name(HIC"变形金刚"NOR, ({"jingang", "kingkong","bianxing jingang"}));
	set("long","这是一个四四方方的东西，原来是个变形金刚。\n你可以把它变（bianxing）成不同的造型，还可以玩（play）它。\n");
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 0);
	}
	setup();
}

void init()
{
	add_action("do_bianxing","bianxing");
	add_action("play_this","play");
}

int do_bianxing(string arg)
{
	object new_gold,me;
	me=this_player();
	new_gold=new("/clone/money/gold");
	new_gold->set_amount(1+random(5));

	if(!arg) return notify_fail("可以变成：car gun plane 和 gold .\n");

	if(arg!="car" && arg!="gun" && arg!="plane" && arg!="gold")
		return notify_fail("这东西可弄不出来，又不是百变金刚！\n");

	if(now_where!="ok") return notify_fail("哎，它还没回来耶，怎么变捏？\n");

	now=arg;

	if(arg=="car")
	{
	    message_vision("$N拿起"HIC"变形金刚"NOR"弄来弄去，把它弄成了一辆小车！\n",me);
	    now_muyang="小车";
	}

	if(arg=="gun")
	{
	    message_vision("$N拿起"HIC"变形金刚"NOR"弄来弄去，把它弄成了一支小手枪！\n",me);
	    now_muyang="小手枪";
	}

	if(arg=="plane")
	{
	    message_vision("$N拿起"HIC"变形金刚"NOR"弄来弄去，把它弄成了一架小飞机！\n",me);
	    now_muyang="小飞机";
	}

	if(arg=="gold")
	{
	    message_vision("$N拿起"HIC"变形金刚"NOR"弄来弄去，把它弄坏碎掉了！只见里面掉出了一些"HIY"黄金"NOR"！！！\n",me);
	    new_gold->move(environment(me));
          bian_gold();
        return 1;
	}

	this_object()->set("long","这是一个变形金刚，现在给弄成了"+now_muyang+"的模样。\n你可以把它变（bianxing）成不同的造型，还可以玩（play）它。\n");
	return 1;
}

void bian_gold()
{
	destruct(this_object());
}

int play_this(string arg)
{
	object me,who,ob,yeah;
	me=this_player();
	yeah=new("/clone/money/silver");

	if(now=="none")
	{
		message_vision("$N拿起四四方方的"HIC"变形金刚"NOR"玩来玩去，觉得好无聊哦～～\n",this_player());
		return 1;
	}

	if(now=="car")
	{
		if(now_where!="ok") return notify_fail("哎，"+now_muyang+"还没回来耶！\n");
		message_vision("$N拿起"+now_muyang+"往外一推，"+now_muyang+"轱辘轱辘地滚了出去。\n",this_player());
		now_where="out";
		call_out("back",3+random(8));
		return 1;
	}

	if(now=="plane")
	{
		if(now_where!="ok") return notify_fail("哎，"+now_muyang+"还没回来耶！\n");
		message_vision("$N拿起"+now_muyang+"往天上一放，"+now_muyang+"「咻」的一声飞了出去。\n",this_player());
		now_where="out";
		call_out("back",3+random(8));
		return 1;
	}

	if(now=="gun")
	{
		if(!arg)
		{
			message_vision("$N拿起"+now_muyang+"到处乱指，口里「砰砰砰」的叫着，玩得开心极了。\n",me);
			return 1;
		}

	        who=present(arg,environment(me));
      		if(!who) return notify_fail("啊？谁？\n");

		if(time()-query_temp("playtime")<3)
		{
		    message_vision("$N拿起"+now_muyang+"到处乱指，口里「砰砰砰」的叫着，玩得开心极了。\n",me);
		    return 1;
		}

                 tell_room(environment(me),me->query("name")+"拿起"+now_muyang+"指着"+who->query("name")+"天真地叫道：“钱来！钱来！”\n",({me,who}));
                  tell_object(who,me->query("name")+"拿起"+now_muyang+"指着你天真地叫道：“钱来！钱来！”\n");
                  write("你拿起"+now_muyang+"指着"+who->query("name")+"天真地叫道：“钱来！钱来！”\n");

		if(!present("silver_money",who) || random(2)==1)
		{
                        tell_room(environment(me),who->query("name")+"哭笑不得，拍了拍"+me->query("name")+"的头，说道：“小傻瓜。”\n",({me,who}));
			tell_object(who,"你哭笑不得，拍了拍"+me->query("name")+"的头，说道：“小傻瓜。”\n");
			write(who->query("name")+"哭笑不得，拍了拍你的头，说道：“小傻瓜。”\n");
		}

		else
		{
                        tell_room(environment(me),who->query("name")+"哭笑不得，只好掏出一两银子递给"+me->query("name")+"，说道：“乖，买糖吃哦。”\n",({me,who}));
			tell_object(who,"你哭笑不得，只好掏出一两银子递给"+me->query("name")+"，说道：“乖，买糖吃哦。”\n");
			write(who->query("name")+"哭笑不得，只好掏出一两银子递给你，说道：“乖，买糖吃哦。”\n");
			ob=(present("silver_money",who));
			ob->add_amount(-1);
			yeah->set_amount(1);
			yeah->move(me);
		}

		set_temp("playtime",time());
		return 1;
	}

	return 1;
}

void back()
{
	message_vision("只见"HIC""+now_muyang+""NOR"转了个圈，又兜了回来。\n",this_player());
	now_where="ok";
}

