// /gumu/jianshi3.c
// copy from /gumu/jianshi2.c
// motified by april 2001.11.10

#include <room.h>

inherit ROOM;

void create()
{
	set("short","练剑室");

	set("long",@LONG
这是杨过隐居古墓后练剑的石室，石墙(wall)上刻着他的心得体会。
现在专门供古墓弟子研习(yanxi)之用。
LONG);

	set("item_desc",([
		"wall" : "你可以通过研习(yanxi)墙上的要诀来提高自己的玄铁剑法修为。\n",
		"stone" : "一块看似很奇怪的青石。\n"
		]));
 
	set("exits",([
		"south" : __DIR__"mudao6",
		]));

	set("cost",1);
	set("count",0);
	setup();

}

void init()
{
	add_action("do_yanxi", "yanxi");
}

int do_yanxi(string arg)
{       
	object me = this_player();
	int check;
	if ( !arg ) return notify_fail( "你要钻研什么?\n");
	if ( arg!="wall") return notify_fail( "你要钻研什么?\n");

	if ( me->query("gender") != "男性" )
		return notify_fail("你学不了玄铁剑法。\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你连字都不认识怎么钻研呀，还事先学点文化(literate)吧。\n");

	if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting()) return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if ( me->query_skill("yunu-xinjing",1) < 25 )
        return notify_fail("你的内功修为不够，无法领会要决的精义！\n");

	if( me->query_skill("sword",1) < me->query_skill("xuantie-jian",1) *2/3 )
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

	check = (int)me->query_skill("xuantie-jian",1);
	if ( check * check * check > (int)me->query("combat_exp") * 10)
		return notify_fail ("你的实战经验不足，怎么钻研也难以提高！\n");

	if ( check > 200) 
		return notify_fail("墙上的玄铁剑法要决的精髓你尽入你的掌握，再也不能从这里提高了。\n");

	if ((!present("jian",me))&&(!present("sword",me)))
		return notify_fail("你身上一把剑都没有，无法更深入地研习玄铁剑法。\n");

	if ( me->query("jing") < 40 || me->query("jingli") < 20 
		|| me->query("neili") < 10 )
		return notify_fail("你累得练墙上的字都看不清楚了，还是歇息一下吧。\n");
	
	me->receive_damage("jing", 30 ,"过度疲劳致死");
	me->receive_damage("jingli", 15 ,"过度疲劳致死");
	me->add("neili", -5);

	message_vision("$N对照着墙上的要决开始参悟玄铁剑法的精髓……\n", me);

	me->improve_skill("xuantie-jian", me->query_int()/2 + me->query_skill("sword",1)/2);
	
	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}
	return 1;
}



