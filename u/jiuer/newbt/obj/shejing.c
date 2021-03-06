// Code of ShenZhou

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"蛇经"NOR, ({ "she jing", "shejing", "jing" }) );
	set_weight(500);
//	if( clonep() )
//		set_default_object(__FILE__);
//	else {
		set("unit", "册");
		set("long", "白驼训蛇密级乃欧阳锋自闭蛇谷，苦心研炼怪蛇所得之法。需耐心琢磨。\n"
			);
		set("value", 3000);
		set("material", "skin");
	/*	set("skill", ([
			"name": "poison",      // name of the skill
            "exp_required": 0,     // minimum combat experience req
            "jing_cost":    20,    // jing cost every time study th
            "difficulty":   15,    // the base int to learn this sk
            "max_skill":    60,    // the maximum level you can lea
			]) );
	*/
//	}
		setup();
}
void init()
{  
	add_action("do_du", "du");
}

int do_du(string arg)
{
	object me = this_player();
	int level, check;
	object where;

	seteuid(getuid());
	where = environment(me);

	if(!present("she jing", me)) return 0;

	if(where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (where->query("sleep_room")) {
		write("不能在睡房里读经，这会影响他人。\n");
		return 1;
	}
	if (where->query("no_fight")) {
		write("这里空气污浊，无法专心修练。\n");
		return 1;
	}
	if (where->query("name") == "大车里") {
		write("车里太颠簸, 无法研读蛇经。 \n");
		return 1;
	}
	if (me->is_busy() || me->query_temp("pending/exercising")) {
		write("你现在正忙着呢。\n");
		return 1;
	}
	if( me->is_fighting() ) {
		write("战斗中还琢磨蛇经，找死呀！\n");
		return 1;
	}
	if( me->query("rided")) {
		write("在坐骑上琢磨蛇经，小心迷路。\n");
		return 1;
	}
	if(!arg || arg != "she jing") 
	{   
		write("你要领悟什么？\n");
        return 1;
	}
	 level = (int)me->query_skill("poison",1);
   check = level*level*level;

    if ( level < 61) {
        write("经中所言对你过于高深，你无法领悟。\n");
        return 1;
   }
   if ( level > 100) {
        write("经中所言对你太浅，没有任何帮助。\n");
        return 1;
   }
   if (check > (int)me->query("combat_exp")*10 ) {
        write("你实战经验不足，无法领悟。\n");
        return 1;
   }
   if ( (int)me->query("jing") < 30 ) 
   { 
	   write("你精神无法集中。\n");
	   return 1;
   }

   me->receive_damage("jing", 20);
   me->improve_skill("poison", me->query("int"));
   write("你按照蛇经上注释的要领，仔细琢磨起来。\n");
   return 1;
}
