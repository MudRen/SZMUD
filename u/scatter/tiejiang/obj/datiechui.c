//datiechui.c 铁锤
//of shenzhou
//snowlf by 201/11/09

#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("大铁锤", ({ "da tie chui", "chui" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一把大铁锤！\n
");
		set("unit", "把");
		set("value", 100);
		set("material", "iron");
		set("wield_msg", "$N拿起一把$n，\n");
		set("unwield_msg", "$N放下手中的$n。\n");
            	set("no_sell",1);
              	set("no_steal",1);
//            	set("no_clean_up",1);
//            	set("no_drop",1);
//        	set("no_give",1);
/* 这不是消耗品，如果no drop .no give 那不是要永远带在身上？不妥吧? 
   ----- 所以先关了，如果真须要再开好了。----snowlf      */
            	
	}
	init_hammer(25);  
//不明白这个属性的意思，所以先关掉 --- snowlf

	setup();
}
