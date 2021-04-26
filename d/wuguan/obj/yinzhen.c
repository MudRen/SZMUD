// sz,obj:yinzhen.c                
// 97.10.1  by Aug

#include <weapon.h>
inherit THROWING;

void create()
#include <ansi.h>

{
	set_name(HIW"银针"NOR, ({ "yinzhen" , "yin zhen", "zhen"  }) );
	set_weight(200);

	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "枚");
		set("long",
HIW"这是一枚三寸长的银针，细而柔韧，多为医家刺穴疗伤之用。\n"NOR);
//set("value", 100);		
		set("yingdu", 50);
		set("base_unit", "枚");
		set("base_weight", 10);
		set("base_value", 1000);
                set_temp("yinzhen", 20);
		set("no_put",1);
		set("no_drop",1);
		set("no_give",1);
		set("no_sell",1);
		set("no_steal",1);
		set("no_get",1);
		set("material","crimsonsteel");
		set("wield_msg", HIW"$N从皮囊中拿出一根$n"+HIW"捏在手里。\n"NOR);
		set("unwield_msg", HIW"$N将手中的$n"+HIW"放回皮囊。\n"NOR);
	}
	set_amount(1);
	init_throwing(30);
	setup();
}