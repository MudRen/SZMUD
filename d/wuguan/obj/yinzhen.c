// sz,obj:yinzhen.c                
// 97.10.1  by Aug

#include <weapon.h>
inherit THROWING;

void create()
#include <ansi.h>

{
	set_name(HIW"����"NOR, ({ "yinzhen" , "yin zhen", "zhen"  }) );
	set_weight(200);

	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "ö");
		set("long",
HIW"����һö���糤�����룬ϸ�����ͣ���Ϊҽ�Ҵ�Ѩ����֮�á�\n"NOR);
//set("value", 100);		
		set("yingdu", 50);
		set("base_unit", "ö");
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
		set("wield_msg", HIW"$N��Ƥ�����ó�һ��$n"+HIW"�������\n"NOR);
		set("unwield_msg", HIW"$N�����е�$n"+HIW"�Ż�Ƥ�ҡ�\n"NOR);
	}
	set_amount(1);
	init_throwing(30);
	setup();
}