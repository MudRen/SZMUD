// /gumu/biaoshi2.c
// July 31,2000
// Code by April
// piao 修改于 2001/09/22
// update by arpil 2001.11.10

inherit ROOM;

void create()
{
	set("short","练镖室");

	set("long",@LONG
这是练功室的西角。这一角呈三角形，石墙(wall)上密密麻麻刻着
暗器要诀，专门供古墓弟子练镖之用。
LONG);

	set("item_desc",([
		"wall" : "你可以通过钻研(yanxi)墙上的要决来提高自己的暗器。\n"
		]));

	set("exits",([
		"northeast" : __DIR__"liangongshi1"
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
	if ( arg != "wall" ) return notify_fail( "你要钻研什么?\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你连字都不认识怎么钻研呀，还事先学点文化(literate)吧。\n");

	if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting()) return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	check = (int)me->query_skill("throwing",1);
	if ( check * check * check > (int)me->query("combat_exp") * 10)
		return notify_fail ("你的实战经验不足，怎么钻研也难以提高！\n");

	if ( check > 200)
		return notify_fail("墙上要决的精髓你尽入你的掌握之中，再也不能从这里学到什么了\n");

	if ((int)me->query("jing") < 20 || me->query("jingli") < 20 )
        return notify_fail("你累的练墙上的字都看不清楚了，还是歇息一下吧。\n");

	me->receive_damage("jing", 15);
	me->receive_damage("jingli", 15);
	message_vision("$N对照着墙上的要诀开始参悟暗器的精髓。\n", me);

	me->improve_skill("throwing", me->query_int()/2);

	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}
	return 1;
}
