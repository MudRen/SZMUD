// 红烧骸骨，看着怕怕吃着香！！！ hs_haigu.c
// by naihe  02-06-06

#include <ansi.h>
inherit ITEM;

int weight,remaining,
remaining=10+(random(6)),
weight=(remaining*3000+1000);

void create()
{
	set_name(RED"红烧骸骨"NOR, ({"hongshao haigu"}));
	set_weight(weight);
	set("long", "这是一道看起来挺吓人的菜：红烧骸骨，但味道非常的好。\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "道");
		set("value", 0);
		set("food_supply", 10);
	}
}

void init()
{
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_puke","puke");
}

int do_food(string arg)
{
	object ob,me;

	me=this_player();
	ob=this_object();

	if(arg != ob->query("id"))
	return 0;

	if (me->is_busy())
	{
		write("吃那么快，小心呛死，自己也成了做菜的原料。\n");
		return 1;
	}

	if ((int)me->query("food") >= (int)me->max_food_capacity())
	{
		write("虽然味道很好，但你实在吃不下了。\n");
		return 1;
	}

	me->add("food", (int)query("food_supply"));

	if(me->is_fighting())
	me->start_busy(1);

	me->start_busy(2);
	remaining-=1;

	if (remaining>0)
		{
			message_vision("$N拿起其中一块"+this_object()->query("name")+"啃来啃去，果然滋味无穷。\n",me);
			message_vision("$N把口里的那块骨头啃得没任何味道了，才不舍地吐了出来。\n"NOR,me);
			new(__DIR__"hs_gutou")->move(environment(me));
			weight-=3000;
			this_object()->set_weight(weight);
// 吃了越多，食物自然就越轻啦。
		}

	else
		{
			message_vision("$N咬下最后一块"+this_object()->query("name")+"，居然连骨头都舍不得扔，也嚼碎了吞了下去。\n",me);
			me->add("food", (int)query("food_supply"));
// 连骨头都吃掉了，自然要额外加点食物补给。
			destruct(this_object());
		}
	return 1;
}

int do_puke(string arg)
{
	int temp_food;

	temp_food=this_player()->query("food");

	if(arg) return 0;

	if(temp_food<50)
	{
		write("你还饿着呢，小心把肠子胃肺脾肝什么的都吐掉了。\n");
		return 1;
	}

	message_vision(CYN"$N"CYN"突然「稀哩哗啦」呕出了一大堆东西，觉得开始有点饿了。\n"NOR,this_player());
	this_player()->set("food",temp_food-50);
	return 1;
}

