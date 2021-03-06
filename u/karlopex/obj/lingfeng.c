/*-------------------------------------------------------------
** 文件名: lingfeng.c
** Copyright (c) 2000-2001
** 创建人: 葉楓         
** 日  期: 2001.8.8
** 描  述: 武器--長劍
**-----------------------------------------------------------*/

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
#include "/u/karlopex/inherit/map.h"
string place(object me);
int query_autoload() {
	if (query("autoload") == "karlopex")
		return 1;
	else return 0;
}
void create()
{
        set_name(NOR+CYN"凌枫剑"NOR,({ "lingfeng jian", "lingfeng", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "steel");
                set("no_steal", "这个东西你偷不到。\n");
                set("long","这是一柄看似普通的长剑，剑身发出青湛的光芒，在剑的末端到剑尖有一道淡淡的水痕。\n");
                set("wield_msg", HIB"只见一道"HIC"青光"HIB"闪过，四周充满了杀气，令人不寒而栗。\n"NOR );
                set("unwield_msg", "$N右手轻轻反转将$n收入剑鞘中。\n"HIC"四周的杀气顿时消失。\n"NOR);
                set("rigidity", 300);
                set("shape", ({ "long", "sword" }) );
        }
        init_sword(100);
        setup();
}
int wield()
{
        object me = this_player();
        object ob = this_object();
        int hp = me->query("max_qi");
        int ret;

        if( wizhood(me) != "(designer)" && wizhood(me) != "(wizard)" && wizhood(me) != "(arch)" && wizhood(me) != "(admin)" && getuid(me) != "karlopex" )
        {
                ob->set("wield_msg", CYN"$N刚刚将$n"CYN"刚拨出来，只觉从$n"CYN"的剑身渐渐气化，蒸发掉了！\n"NOR );
                me->receive_damage("qi", hp / 8, "莫名其妙地死了");
                me->receive_wound("qi", hp / 10, "莫名其妙地死了");
		call_out("destroy_jian", 0, me, ob);
                return 1;
        }else if( ret = ::wield() )
       {
                message_vision(CYN"$N用右手中指和食指轻带$n"CYN"的剑柄，将$n"CYN"缓缓地从剑鞘拨出。\n"NOR, me, ob);
                if ( me->query("id") == "karlopex")       
                        me->add("max_neili", 10);
                else me->add("max_neili", -10);
                return ret;
        }
}
#include "/u/karlopex/inherit/lingfeng.h"
