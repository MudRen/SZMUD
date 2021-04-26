// mashroom1.c 花蘑菇

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("花蘑菇", ({"hua mogu", "mashroom"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只鲜红色带白点的伞状花蘑菇。\n");
		set("unit", "只");
		set("value", 0);
		set("food_remaining", 3);
		set("food_supply", 10);
	}
}

void init()
{
	add_action("do_eat", "eat");
}
int do_eat(string arg)
{
	object me = this_player();
	if(arg =="hua mogu" || arg =="mashroom")
	{
	   write("你拿起花蘑菇咬了几口。\n");
       me->set_temp("poison", 1);
		call_out("poison", 20, me);
		return 1;
	}

}

int poison(object me)
{
        me->delete_temp("poison");
        tell_object(me, HIR"你突然感到一阵晕旋，原来你吃了有剧毒的花蘑菇！\n"NOR);
        message("vision", me->name()+"脚下几个踉跄，手脚冰凉，口吐白沫昏死过去！\n", environment(me), ({me}) );
        me->receive_wound("qi", me->query("max_qi")+100, "中剧毒而死了");
        return 1;
}
