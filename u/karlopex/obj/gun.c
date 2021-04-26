/*-------------------------------------------------------------
** 文件名: lingfeng.c
** Copyright (c) 2000-2001
** 创建人: 葉楓         
** 日  期: 2001.8.8
** 描  述: 武器--狙击步枪
**-----------------------------------------------------------*/

#include <weapon.h>
#include <ansi.h>

#include "/u/lisser/inherit/gun.h"
void create()
{
        set_name(HIR"狙击"HIG"步枪"NOR,({ "zuji buqiang", "buqiang", "gun" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("s_name","狙击步枪");
                set("unit", "支");
                set("value", 1000000);
                set("material", "steel");
                set("no_steal", "这个东西你偷不到。\n");
                set("no_sell", "你不能贩卖军火！\n");
                set("long","这是一支重型狙击步枪，是狙击手的必要装备。\n");
                set("org_long","这是一支重型狙击步枪，是狙击手的必要装备。\n");
                set("wield_msg", HIG"只见$N将背上的$n"+HIG+"解下来，调整了一下，开始瞄准。。。\n"NOR );
                set("unwield_msg", "$N轻轻地将$n重新背在背上。\n"NOR);
                set("unequip_msg", "$N轻轻地将$n重新背在背上。\n"NOR);
                set("rigidity", 300);
                set("shape", ({ "long", "gun" }) );
        }
        init_gun(500);
        setup();
}
int wield()
{
        object me = this_player();
        object ob = this_object();
        int hp = me->query("max_qi");
        int ret;

        if( !wizardp(me) ){
                ob->set("wield_msg", CYN"$N将$n"CYN"拿在手里，发现$n"CYN"自己不会用！\n"NOR );
                return 1;
        }else if( ret = ::wield() ){
                set("wield_msg", HIG"只见$N将背上的$n"+HIG+"解下来，调整了一下，开始瞄准。。。\n"NOR );
        	add_action("do_pull","miao");
		return ret;
	}
}
