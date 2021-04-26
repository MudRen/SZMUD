// Code of ShenZhou 
//七星绝命剑 
//Lnere 
       
#include <ansi.h>
#include <weapon.h> 
inherit F_UNIQUE; 
inherit SWORD; 
#include "/clone/unique/special_weapon.h"
void create() 
{ 
          set_name(HIC"七星绝命剑"NOR, ({"jian","sword","jueming jian"}) );
      
    set_weight(3000); 
    if( clonep() ) 
                set_default_object(__FILE__); 
    else 
        { 
                set("unit", "把"); 
        set("long",
          "这是一把三尺长的软剑毫无特别之处，只是剑刃上镶嵌着不规则排列的七粒暗红色朱砂。\n"
          "此物是江湖名宿玄机子的祖传宝剑，相传内力高者使用此剑可使剑身上的七点朱砂飞出，杀人于无形。\n");
        set("rigidity", 1500); 
        set_weight(1000); 
        set("value", 7000); 
        set("ding", 7); 
        set("material", "steel"); 
      
                set("wield_msg",
        "只见$N脸色阴沉下来\n"
        HIW"一道银光闪过$N手中多了一把软剑,剑身上"+HIR+"七点似血殷红的朱砂"+BLU+"令人毛骨悚然!\n"NOR); 
        set("unwield_msg", 
        HIW"$N反手持剑，画了一道圆弧一道银光钻入了剑鞘\n"NOR); 
      
                        init_sword(30); 
            set("actions", (: call_other, __FILE__, "query_action" :) ); 
            setup(); 
     } 
} 
     void init() 
     { 
             add_action("do_shoot", "shoot"); 
     } 
     int do_shoot(string arg) 
     { 
        object me = this_player(); 
        object victim, weapon; 
      
        if (!arg) 
             return notify_fail("你要射谁？\n"); 
      
        victim = present(arg,environment(me)); 
      
      
        if (!victim) 
             return notify_fail("这里并无此人！\n"); 
      
        if (query("ding") < 1) 
             return notify_fail("你剑身的七点朱砂已经射完了。\n"); 
      
        if (!living(victim)) 
             return notify_fail("这不是活物！\n"); 
      
        if (me->is_busy()) 
             return notify_fail("你前一个动作还没有做完。\n"); 
      
        if (victim == me) return notify_fail("何必多此一举？\n"); 
      
        if( environment(me)->query("no_fight") ) 
                     return notify_fail("在这里不能攻击他人。\n"); 
      
        message_vision(HIR"$N将内力贯注于剑，突然从剑身飞出一道红光，向$n急射而去。\n" NOR, me, victim); 
        add("ding", -1); 
        if( random(me->query("combat_exp")) > (int)victim->query("combat_exp")/2){  
        message_vision(HIR"只听一声惨叫，暗红色的朱砂已钉在了$N的身上。\n"NOR, victim); 
        victim->apply_condition("insect_poison", 100); 
        victim->receive_wound("qi", 1000, "被" + me->query("name") +"杀死了"); 
        victim->receive_wound("jing", 200, "被" + me->query("name") +"杀死了"); 
        if (!victim->is_killing(me)) 
        victim->kill_ob(me); 
        } else { 
        message_vision(HIW"但是$N机灵地躲了开去！\n"NOR, victim); 
        if (!victim->is_killing(me)) 
        victim->kill_ob(me); 
        } 
        return 1; 
     } 
