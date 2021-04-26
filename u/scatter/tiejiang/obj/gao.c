//gao.c 镐也叫"鹤嘴锄"
//of shenzhou
//snowlf by 201/11/09

#include <ansi.h>
#include <weapon.h>
//inherit ITEM;
inherit HAMMER;

void create()
{
	set_name( CYN "镐" NOR , ({"gao","hezui chu ","chu"}) );
	set_weight(2000);
        set("unit", "把");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		
		set("long", "    镐也叫鹤嘴锄，锐三角形的镐头中腰有孔，装著坚纫的檀木或桑木
把，镐头是用纯刚打造的，一头是尖锥形的，另一头有刃如斧，坚实而锋
利，是垦荒和采石/矿必不可少的工具！
");
		set("value", 200);
		set("material", "iron");
		set("wield_msg", "$N拿起一把$n，握在手中。\n");
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
