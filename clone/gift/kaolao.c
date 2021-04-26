// xisuidan.c 仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "犒劳丹" NOR, ({ "dan", "kaolao dan", "kaolaodan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "吃了这枚丹药，运气好的话你可以增加30点贡献度。\n");
                set("value", 10000);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        if (me->query("stroy/kaolao") >= 1000000)
        {
                message_vision("$N突然放了一个奇臭无比的响屁。\n", me);
                tell_object(me, "你觉得大概是吃坏了肚子。\n");
        } else
        if (random(10) == 0)
        {
                tell_object(me, "不过你觉得好像没什么作用。\n");
        } else
        {
                tell_object(me, HIY "你感到自己的神州贡献度增加了。\n" NOR);
                me->add("shenzhou/pts", 50);
        }

        me->add("story/kaolao", 1);
        destruct(this_object());
	return 1;
}
