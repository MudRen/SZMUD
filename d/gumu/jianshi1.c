// Aug 30,2001
// Code by Yujie
// /gumu/jianshi1.c
// update by april 2001.11.10

#include <room.h>

inherit ROOM;

void create()
{
	set("short","练剑室");

	set("long",@LONG
这是练功室的东角。这一角呈半圆形，石墙(wall)上密密麻麻刻着全
真剑法的剑招和剑诀，专门供古墓弟子研习之用。半圆弧底有块奇怪青石
(stone)，不知为何用。
LONG);

	set("item_desc",([
		"wall" : "你可以通过研习(yanxi)墙上的要诀来提高自己的全真剑法修为。\n",
		"stone" : "一块看似很奇怪的青石。\n"
		]));
 
	set("exits",([
		"northwest" : __DIR__"liangongshi1",
		]));

	set("cost",1);
	set("count",0);

	setup();

}

void init()
{
	add_action("do_yanxi", "yanxi");
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg == "" ) return 0;

	if( arg == "stone" || arg == "shi") {
        message_vision("$N走到东边，伸手到半圆的弧底推了几下，"
			+"一块大石缓缓移开，现出一扇洞门。\n\n",me);
        set("exits/eastdown", __DIR__"jianshi2");
        remove_call_out("close_door");
        call_out("close_door",15,me);   
		return 1;
	}
	else return notify_fail("你要推什么？\n");
}

void close_door()
{
	tell_room(this_object(),"过了一会儿，石洞门缓缓地关上了。\n");
	delete("exits/eastdown");
}

int do_yanxi(string arg)
{       
	object me = this_player();
	int check;

	if ( !arg ) return notify_fail( "你要钻研什么?\n");
	if ( arg!="wall") return notify_fail( "你要钻研什么?\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你连字都不认识怎么钻研呀，还事先学点文化(literate)吧。\n");

	if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting()) return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if ( me->query_skill("yunu-xinjing",1) < 25 
		&& me->query_skill("xiantian-gong",1) < 25 )
        return notify_fail("你的内功修为不够，无法领会要决的精义！\n");

	if( me->query_skill("sword",1) < me->query_skill("quanzhen-jian",1) *2/3 )
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

	check = (int)me->query_skill("quanzhen-jian",1);
	if ( check * check * check > (int)me->query("combat_exp") * 10)
		return notify_fail ("你的实战经验不足，怎么钻研也难以提高！\n");

	if ( check > 200) 
		return notify_fail("墙上全真剑法要决的精髓你尽入你的掌握，再也不能从这里提高了。\n");

	if ((!present("jian",me))&&(!present("sword",me)))
		return notify_fail("你身上一把剑都没有，无法更深入地研习全真剑法。\n");

	if ( me->query("jing") < 40 || me->query("jingli") < 20 
		|| me->query("neili") < 10 )
		return notify_fail("你累得练墙上的字都看不清楚了，还是歇息一下吧。\n");
	
	me->receive_damage("jing", 30 ,"过度疲劳致死");
	me->receive_damage("jingli", 15 ,"过度疲劳致死");
	me->add("neili", -5 );
	message_vision("$N对照着墙上的要决开始参悟全真剑法的精髓……\n", me);

	me->improve_skill("quanzhen-jian", me->query_int()/2 + me->query_skill("sword",1)/2);

	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}
	return 1;
}