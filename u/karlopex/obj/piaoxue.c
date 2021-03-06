/*-------------------------------------------------------------
** 文件名: piaoxue.c
** Copyright (c) 2000-2001
** 创建人: 葉楓		
** 日  期: 2001.8.8
** 描  述: 武器--長劍
**-----------------------------------------------------------*/

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void unwield_jian(object me, object ob);
void create()
{
        set_name(WHT"飘雪剑"NOR,({ "piaoxue jian", "piaoxue", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("s_name","飘雪剑");
                set("unit", "把");
                set("value", 1000);
                set("material", "steel");
	        set("no_steal", "这个东西你偷不到。\n");
	        set("no_sell", "这个东西你卖不出去。\n");
                set("unwield_msg", "$N轻轻反转剑身$n收入剑鞘中。\n"NOR);
                set("long","这是一柄长剑，剑身发出雪白的点点光芒，就像冬季里四处飘散的雪花。\n");
		set("rigidity", 300);
		set("shape", ({ "long", "sword" }) );
        }
	init_sword(60);
        setup();
}

int wield()
{
	object me = this_player();
        object ob = this_object();
        int hp = me->query("max_qi");
	int ret;

	if( me->query("gender") != "女性" ){
		if (me->query("neili") >= 100)
			me->add("neili", -100);
		else{
			me->receive_damage("qi", hp / 10, "莫名其妙地死了");
			me->receive_wound("qi", hp / 8, "莫名其妙地死了");
		}
               set("wield_msg", CYN"$N刚刚拨出一些，只觉剑中的寒气逼人，不由得把剑收了回去！\n"NOR);
		return 1;
	}else if( ret = ::wield() ){
                set("wield_msg", WHT"$N轻轻握着$n"WHT"的剑柄，将$n"WHT"缓缓地从剑鞘拨出。\n只见无数的光点闪过，便似冬季的雪花一般，漫天飞舞。\n"NOR );
		return ret;
     	}
}
