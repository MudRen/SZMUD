// Aug 30,2001
// Code by Yujie
// /gumu/zhangshi2.c
// update by April 2001.11.11

#include <room.h>

inherit ROOM;

void create()
{
	set("short","练拳室");

	set("long",@LONG
这是练功室的窄面，石墙(wall)上刻着许多拳法和指法的图形和要诀，
专门供古墓弟子研习美女拳和素寒指之用。
LONG);

	set("item_desc",(["wall" : "你可以通过研习(yanxi)墙上的要诀来提高自己的美女拳和素寒指修为。\n"
		+"左边(left)是美女拳，右边(right)是素寒指。\n"]));

	set("exits",([
		"north" : __DIR__"liangongshi2",
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
	string thisskill="meinu-quan";
	string skilltwo="suhan-zhi";
	int check;

	if ( !arg ) return notify_fail( "你要钻研什么?\n");
	if ( arg == "wall") return notify_fail("你要钻研左边(left)还是右边(right)？\n");
	if ( arg!="left" && arg!="right") return notify_fail( "你要钻研什么?\n");
	if ( arg == "right" && me->query("gender") != "女性") return notify_fail( "你学不了素寒指。\n");

	if ( (int)me->query_skill("literate", 1) < 1){
		write("你连字都不认识怎么钻研呀，还事先学点文化(literate)吧。\n");
		return 1;
	}

	if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting() ) return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if (me->query_skill("yunu-xinjing",1)<25) {
        write("你的玉女心经修为不够，无法领会要决的精义！\n");
		return 1;
	}

	if (arg == "left"){
		check = (int)me->query_skill("meinu-quan",1);
		
		if ( check * check * check > (int)me->query("combat_exp") * 10){
			write ("你的实战经验不足，无论怎么钻研美女拳法也无法提高！\n");
			return 1;
		}
		
		if( me->query_skill("cuff",1) < check * 2/3 )
			return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");
		
		if ( check > 200 )
			return notify_fail("墙上美女拳法要决的精髓你尽入你的掌握，再也不能从这里提高了。\n");

		if ( me->query("jing") < 40 || me->query("jingli") < 20 
			|| me->query("neili") <20 ){
	        write("你累得连墙上的字都看不清楚了，还是歇息一下吧。\n");
			return 1;
		}

		me->receive_damage("jing", 30 ,"过度疲劳致死");
		me->receive_damage("jingli", 15 ,"过度疲劳致死");
		me->add("neili", -10 );
		message_vision("$N对照着墙上的要决开始参悟美女拳法的精髓……\n", me);

		me->improve_skill("meinu-quan", me->query_int()/2+me->query_skill("cuff",1)/2);
		write("你琢磨了一阵，你的美女拳法提高了。\n");
	}

	if (arg == "right"){
		check = (int)me->query_skill("suhan-zhi",1);
		
		if ( check * check * check > (int)me->query("combat_exp") * 10){
			write ("你的实战经验不足，无论怎么钻研素寒指也无法提高！\n");
			return 1;
		}
		
		if( me->query_skill("finger",1) < check * 2/3 )
			return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");
		
		if ( check > 200 )
			return notify_fail("墙上素寒指法要决的精髓你尽入你的掌握，再也不能从这里提高了。\n");

		if ( me->query("jing") < 40 || me->query("jingli") < 20 
			|| me->query("neili") <20 ){
	        write("你累得练墙上的字都看不清楚了，还是歇息一下吧。\n");
			return 1;
		}

		me->receive_damage("jing", 30 ,"过度疲劳致死");
		me->receive_damage("jingli", 15 ,"过度疲劳致死");
		me->add("neili", -10 );
		message_vision("$N对照着墙上的要决开始参悟素寒指法的精髓……\n", me);

		me->improve_skill("suhan-zhi", me->query_int()/2+me->query_skill("finger",1)/2);
		write("你琢磨了一阵，你的素寒指法提高了。\n");
	}

/*
	if ((int)me->query_skill(thisskill,1) >= 91){ 
		if ((int)me->query("jingli") < 420 || (int)me->query("neili")<120 ){ 
			write("你现在状态不佳，没法继续钻研了。\n");
			return 1;
		}
		me->receive_damage("jingli", 400);
		me->add("neili",-100);

		write("你参照要决反复比划研习着美女拳法，立时收获不浅。\n");
		me->improve_skill(thisskill, me->query_skill("cuff",1)*5+me->query_skill(thisskill,1));
	}
	else{
		if ((int)me->query("jingli") < 30 || (int)me->query("qi")<30 ){ 
			write("你累得无力举拳继续修练了。\n");
			return 1;
		}
		me->receive_damage("jing", 20);
		me->receive_damage("qi", 20);           
          
		write("你对照着墙上的要决潜心钻研美女拳法，看来有所心得。\n");
		me->improve_skill(thisskill, me->query_skill("cuff",1)/4+1);
	}

	if (me->query("gender") == "女性"){ 
		if( me->query_skill("finger",1)/2 <= me->query_skill(skilltwo,1)/3 )
			return notify_fail("你想同时参照修练素寒指法，但基本指法不够无法提高。\n" );
		if ((int)me->query_skill(skilltwo,1) >= 91){ 
			if ((int)me->query("jingli") < 220 || (int)me->query("neili")<60 ){
				write("你想同时参照修练素寒指法，但已经无力继续了。\n");
				return 1;
			}
			me->receive_damage("jingli", 200);
			me->add("neili",50);

			write("你同时参照着美女拳反复修练素寒指，也有所收获。\n");
			me->improve_skill(skilltwo, me->query_skill("finger",1)*3+me->query_skill(skilltwo,1));
			return 1;
		}
		else {
			if ((int)me->query("jingli") < 15 || (int)me->query("qi")< 15 ){
				write("你想同时参照修练素寒指法，但已经无力继续了。\n");
				return 1;
			}        
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);           
  
			write("你同时参照着美女拳修练素寒指，也有所心得。\n");
			me->improve_skill(skilltwo, me->query_skill("finger",1)/6+1);
			return 1;
		}
	}
*/
	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}
	return 1;
}
	
