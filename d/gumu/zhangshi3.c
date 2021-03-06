// /gumu/zhangshi3.c
// copy from /gumu/zhangshi2.c
// motified by April 2001.11.07

#include <room.h>

inherit ROOM;

void create()
{
	set("short","练掌室");

	set("long",@LONG
这是杨过隐居古墓后练掌的石室，石墙(wall)上刻着他的心得体会。
现在专门供古墓弟子研习(yanxi)之用。
LONG);

	set("exits",([
		"south" : __DIR__"mudao5",
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
	if ( me->query("gender") != "男性" )
		return notify_fail("你学不了黯然销魂掌。\n");
	if ( arg != "wall" ) return notify_fail( "你要钻研什么?\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你连字都不认识怎么钻研呀，还事先学点文化(literate)吧。\n");

	if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting() ) return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if (me->query_skill("yunu-xinjing",1)<25) {
        write("你的玉女心经修为不够，无法领会要决的精义！\n");
		return 1;
	}

	check = (int)me->query_skill("xiaohun-zhang",1);

	if ( check * check * check > (int)me->query("combat_exp") * 10)
		return notify_fail("你的实战经验不足，无论怎么钻研黯然销魂掌也无法提高！\n");
	
	if( me->query_skill("strike",1) < check * 2/3 )
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");
		
	if ( check > 200 )
		return notify_fail("墙上黯然销魂掌要决的精髓你尽入你的掌握，再也不能从这里提高了。\n");

	if ( me->query("jing") < 40 || me->query("jingli") < 20 
		|| me->query("neili") <20 )
		return notify_fail("你累得练墙上的字都看不清楚了，还是歇息一下吧。\n");

	me->receive_damage("jing", 30 ,"过度疲劳致死");
	me->receive_damage("jingli", 15 ,"过度疲劳致死");
	me->add("neili", -10 );
	message_vision("$N对照着墙上的要决开始参悟黯然销魂掌的精髓……\n", me);

	me->improve_skill("xiaohun-zhang", me->query_int()/2+me->query_skill("strike",1)/2);
		write("你琢磨了一阵，你的黯然销魂掌提高了。\n");

	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}

	return 1;
}
	
