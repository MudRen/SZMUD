// Aug 30,2001
// Code by Yujie
// /gumu/zhangshi1.c
// update by april 2001.11.05
inherit ROOM;

void create()
{
	set("short","练掌室");

	set("long",@LONG
这是练功室的窄面，石墙(wall)上密密麻麻刻着各种图形和文字，似
乎是练武要诀。
LONG);

	set("item_desc",(["wall" : "你仔细研究着，发现图形中的男形使了一套掌法和拳法结合的功夫，女形\n"
		+"使的是一套拳法和指法结合的功夫，奥妙无比。你开始研习(yanxi)起来。\n"]));

	set("exits",([
		"south" : __DIR__"liangongshi1"
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
	int cuff_lvl,strike_lvl,finger_lvl;
	
	if ( !arg )	return notify_fail( "你要钻研什么?\n");
	if ( arg != "wall" ) return notify_fail( "你要钻研什么?\n");

	if ( me->is_busy() ) return notify_fail("你正忙着呢！\n");
	if( me->is_fighting() ) return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if ( (int)me->query_skill("literate", 1) < 1) {
		write("你连字都不认识怎么钻研呀，还事先学点文化(literate)吧。\n");
		return 1;
	}

	if ((int)me->query("jing") < 30 || me->query("jingli") < 30 ){
        write("你累得连墙上的字都看不清楚了，还是歇息一下吧。\n");
		return 1;
	}

	me->receive_damage("jing", 20 ,"过度疲劳致死");
	me->receive_damage("jingli", 20 ,"过度疲劳致死");

	message_vision("$N对照着墙上的要决开始参悟拳脚功夫的精髓……\n", me);

	cuff_lvl = (int)me->query_skill("cuff",1);
	if ( cuff_lvl > 200 )
		write("墙上拳法要决的精髓你尽入你的掌握，再也不能从这里提高拳法了。\n");
	else if (cuff_lvl * cuff_lvl * cuff_lvl > (int)me->query("combat_exp") * 10)
		write ("你的实战经验不足，无法提高拳法了。\n");
	else {
		me->improve_skill("cuff", me->query_int()/2);
		write("你琢磨了一阵，似乎对基本拳法略有心得。\n");
	}

	if ( me->query("gender") == "男性" ) {
		strike_lvl = (int)me->query_skill("strike",1);
		if ( strike_lvl > 200 )
			write("墙上掌法要决的精髓你尽入你的掌握，再也不能从这里提高了\n");
		else if (strike_lvl * strike_lvl * strike_lvl > (int)me->query("combat_exp") * 10)
			write ("你的实战经验不足，无法提高掌法了。\n");
		else {
			me->improve_skill("strike", me->query_int()*2/5);
			write("你琢磨了一阵，似乎对基本掌法略有心得。\n");
		}
	}

	if ( me->query("gender") == "女性" ) {
		finger_lvl = (int)me->query_skill("finger",1);
		if ( finger_lvl > 200 )
			write("墙上指法要决的精髓你尽入你的掌握，再也不能从这里提高指法了\n");
		else if (finger_lvl * finger_lvl * finger_lvl > (int)me->query("combat_exp") * 10)
			write ("你的实战经验不足，无法提高指法了。\n");
		else {
			me->improve_skill("finger", me->query_int()*2/5);
			write("你琢磨了一阵，似乎对基本指法略有心得。\n");
		}
	}
	
	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}
	return 1;
}

