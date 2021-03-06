//                标准描述长度示例                                   |
// 火炉，专门用来做菜： 红烧骸骨，哈哈哈  huolu.c
// by naihe 奈何  2002-06-06

#include <ansi.h>
inherit ITEM;

string temp_now;

void create()
{
	set_name(HIR"火炉"NOR, ({"huo lu"}));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一个火炉，可以用来烧菜（cook!）。\n");
	set("unit", "个");
	set("value", 1);
	}

	setup();
}

void init()
{
	add_action("do_cook","cook!");
}

int do_cook(string arg)
{
	object me,cook_use,cook_things,fire_things;
	me=this_player();

	cook_use=present("huo lu",me);
	cook_things=present("skeleton",me);
	fire_things=present("shuzhi",me);

	if(!arg) return notify_fail("你想做什么菜哪？\n");

	if(arg!="skeleton") return notify_fail("这个火炉只能做一道菜（skeleton）。\n");

	if(!cook_things) return notify_fail("你身上没带着原料吧，怎么做菜？\n");

        if((int)me->query("neili") < 1000)
	{
		if(!fire_things) return notify_fail("你的内力不够，还是老老实实的找根树枝树干什么的来烧火罢。\n");

		if(!cook_use) message_vision(HIR"$N点燃了"+fire_things->query("name")+""HIR"把炉子烧得旺旺的。\n"NOR,me);

		else
		{
		  message_vision(HIR"$N把火炉放到地上，点燃了"+fire_things->query("name")+""HIR"把炉子烧得旺旺的。\n"NOR,me);
		  cook_use->move(environment(me));
		}

		destruct(fire_things);
		message_vision(HIR"$N把一具骸骨放进了火炉里烧了起来。\n"NOR,me);
		destruct(cook_things);
		message_vision(HIY"$N做出了一道 『红烧骸骨』 ！\n"NOR,me);
		new(__DIR__"hs_haigu")->move(me);
		return 1;
	}

	if(!cook_use) message_vision(HIR"$N催起内力把炉子烘得热乎乎的。\n"NOR,me);
	else
	{
	    message_vision(HIR"$N把火炉放到地上，催起内力把炉子烘得热乎乎的。\n"NOR,me);
	    cook_use->move(environment(me));
	}

        me->add("neili",-999);
	message_vision(HIR"$N把一具骸骨放进了火炉里烧了起来。\n"NOR,me);
	destruct(cook_things);
	message_vision(HIY"$N做出了一道 『红烧骸骨』 ！\n"NOR,me);
	new(__DIR__"hs_haigu")->move(me);
	return 1;
}

