// 小糖人儿  :)  eat_naihe.c
// by naihe  2002-05-19    for spark.

inherit ITEM;
#include <ansi.h>

void yeah();
int last=5;
string where,l_hand,r_hand,l_leg,r_leg,head,soma,now,
l_hand="yes",
r_hand="yes",
l_leg="yes",
r_leg="yes",
head="yes";

void create()
{
	set_name(WHT"小糖人儿"NOR, ({"tang ren","ren"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一个小糖人儿，笑嘻嘻的模样煞是可爱，依稀就是奈何的样子。\n");
		set("unit", "个");
		set("value", 0);
		set("food_supply", 10);
	}
	setup();
}

void init()
{
	add_action("do_food", "eat");
	add_action("do_food", "yao");
}

void yeah()
{
	object gem,me;
	me=this_player();
	gem=new("/u/naihe/obj/gem");

	gem->move(me);
	message_vision("$N咬着"WHT"小糖人儿"NOR"，发现它的身子里似乎有些东西！\n",this_player());
        destruct(this_object());
}

// 头：head 手：hand 脚：leg 身子：soma

int do_food(string arg)
{
	object me=this_player();

	string temp,can_eat;
	can_eat="no";

	if(this_object()->query("off")==1) return 0;


	if (me->is_busy())
	return notify_fail("慢慢吃，别急呀。\n");

	if(!arg) return notify_fail("你要往哪下口呀？<hand/leg/head/soma>\n");

	if(arg == "left hand") where="左边小手";
	if(arg == "right hand") where="右边小手";
	if(arg == "left leg") where="左边腿儿";
	if(arg == "right leg") where="右边腿儿";
	if(arg == "head") where="小脑袋瓜";
	if(arg == "soma") where="身子";

	if(arg!="left hand" && arg!="right hand" && arg!="left leg" && arg!="right leg" && arg!="head" && arg!="soma")
	return notify_fail("你这是想咬哪呀……\n");

	if ((int)me->query("food") >= (int)me->max_food_capacity())
		return notify_fail("你已经吃饱啦，吃不下啦。\n");

	if(arg=="left hand")
	{
		if(l_hand!="yes") return notify_fail(where+"已经给吃掉啦。\n");
		l_hand="no";
		can_eat="yes";
	}

	if(arg=="right hand")
	{
		if(r_hand!="yes") return notify_fail(where+"已经给吃掉啦。\n");
		r_hand="no";
		can_eat="yes";
	}

	if(arg=="left leg")
	{
		if(l_leg!="yes") return notify_fail(where+"已经给吃掉啦。\n");
		l_leg="no";
		can_eat="yes";
	}

	if(arg=="right leg")
	{
		if(r_leg!="yes") return notify_fail(where+"已经给吃掉啦。\n");
		r_leg="no";
		can_eat="yes";
	}

	if(arg=="head")
	{
		if(head!="yes") return notify_fail(where+"已经给吃掉啦。\n");
		head="no";
		can_eat="yes";
	}

	if(arg=="soma")
	{
		if(last!=0)
		    return notify_fail("先吃身子那别的怎么办呀。\n");

		else
		{
			message_vision("$N对着"WHT"小糖人儿"NOR"的身子一口咬了下去。\n",me);
			set("off",1);
			call_out("yeah",1);
			return 1;
		}
	}

	if(can_eat=="yes")
	{
		temp=now;
		if(last==5) now=where;
		else now=temp+"、"+where;


		if(head=="yes")
			set("long","这是个给咬过了的小糖人儿，笑嘻嘻的小脑袋挺像奈何的模样。\n它已经给吃掉了"+now+"，让人感觉怪怜惜的。\n");

		else set("long","这是一个小糖人儿，"+now+"都已经给吃掉了，\n不知道它的脸蛋原本是个什么模样的呢？\n");
		last--;
	}

	switch(random(4))
	{
		case 0:
	message_vision("$N拿起"WHT"小糖人儿"NOR"，一口把它的"+where+"咬了下来。\n",me);
		break;

		case 1:
	message_vision("$N拿着"WHT"小糖人儿"NOR"舔呀舔的，一不小心把它的"+where+"给吃掉了。\n",me);
		break;

		case 2:
	message_vision("$N看着"WHT"小糖人儿"NOR"呆呆地出神，突然把它的"+where+"给咬了下来。\n",me);
		break;

		case 3:
	message_vision("$N拿起"WHT"小糖人儿"NOR"晃来晃去的，一不小心把它的"+where+"给晃掉了，却恰好掉到了嘴里。\n",me);
		break;
	}

	if(last==0) set("long","这是一团圆乎乎的东西，似乎原先是个糖人儿。\n");

	me->start_busy(1);
	me->add("food", (int)query("food_supply"));
	return 1;
}

