//gangqing.c 钢钎
//of shenzhou
//snowlf by 201/11/09

#include <ansi.h>
#include <weapon.h>
inherit STAFF;
//inherit ITEM;

void create()
{
	set_name( CYN "钢钎" NOR , ({"qian","gang qian"}) );
	set_weight(2300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "
    这只一柄钢钎，通身用纯钢打造，是破石和翘石的工具，采石的过程
遇到整片的石层时，用镐基本是无能为力的，就须要用钎和锤来破开它们
，想在采石时提高效，这两样工具可是必不可少的哦！
");
		set("value", 200);
		set("material", "iron");
		set("wield_msg", "$N拿起一柄$n。(握在手中做什么呢？是想当武器用吧？也可以啊。xixi!)\n");
//
		set("unwield_msg", "$N放下手中的$n。\n");
            	set("no_sell",1);
              	set("no_steal",1);
//            	set("no_clean_up",1);
//            	set("no_drop",1);
//        	set("no_give",1);
/* 这不是消耗品，如果no drop .no give 那不是要永远带在身上？不妥吧? 
   ----- 所以先关了，如果真须要再开好了。----snowlf      */
            	
	}
	init_staff(25);  
//不明白这个属性的意思，所以先关掉 --- snowlf

	setup();
}
