           // Code of ShenZhou  
           // qiulong-bang
           // Lnere  
             
#include <ansi.h>  
#include <weapon.h>  
#include "/clone/unique/special_weapon.h"  
           inherit F_UNIQUE;  
           inherit STICK;  
           void create()  
           {  
                   set_name(HIY"双龙银丝虬龙棒"NOR, ({"qiulong bang", "bang", "stick"}));  
                   set_weight(8000);  
                   if (clonep())  
                           set_default_object(__FILE__);  
                   else {  
                           set("unit", "根");  
                           set("long", 
                           HIW"此棒长约五尺六寸，两端全是龙头，龙舌是两口利刃，通身用千年紫藤和银丝、头发缠就，软硬兼施。"+NOR+" \n" 
                           "在龙头上下各有一个倒钩。因而此物既可当软鞭，又可当双枪，更能当棍使用。似乎龙头之中暗含机关。\n");  
                           set("value", 8000000);  
                           set("material", "bamboo");  
                           set("rigidity", 5000);  
                           set("dao", 4);  
                           set("wield_msg", 
                           HIC"$N缓缓抽出一根看上去奇形怪状的兵器。\n" 
                           YEL"只见此物似鞭非鞭似棍非棍，两端则是由纯金打造而成的龙头。\n"NOR);  
                           set("unwield_msg", 
                           YEL"$N把手中的双龙银丝虬龙棒重新缠回腰间。\n"NOR);  
                   }  
                   init_stick(30);  
                   setup();  
  
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
                    return notify_fail("你要攻击谁？\n");  

                 victim = present(arg,environment(me));  
      
                  if (!victim) 
                         return notify_fail("这里并无此人！\n"); 

                  if (query("dao") < 1)  
                         return notify_fail("龙头里暗藏的飞刀已经被射光了。\n");  
 
                  if (!living(victim))  
                         return notify_fail("这不是活物！\n");  
             
                  if( me->is_busy() )  
                          return notify_fail("你前一个动作还没有做完。\n");  

                  if (victim == me) return notify_fail("何必多此一举？\n");  

                  if( environment(me)->query("no_fight") )  
                              return notify_fail("在这里不能攻击他人。\n");  
         
      
                  message_vision(HIW"$N突然启动藏于棒中的机关。\n" 
                        CYN"只见棒身一分为二，两端的龙嘴忽然张开，喷出四柄阴气森森的飞刀，发出刺耳的破空之声向着$n射去。 \n" NOR, me, victim); 
                  add("dao", -1);  
                  if( random(me->query("combat_exp")) > (int)victim->query("combat_exp")/2){    
                  message_vision(BLU"$N只顾专心应战，待听到破空之声时想纵身躲避，但已为时已晚。\n" 
                  HIR"只听$N一声惨叫，四柄利刃已传胸而过，鲜血喷涌而出，显然受伤极重。\n"NOR, victim);   
                  victim->receive_wound("qi", 5000, "被" + me->query("name") +"杀死了");   
                  victim->receive_wound("jing", 300, "被" + me->query("name") +"杀死了");   
                  if (!victim->is_killing(me))   
                  victim->kill_ob(me);   
                  } else {   
                  message_vision(HIW"$N急运真气向后斜射出去，四柄利刃擦鞋而过。$N已是吓的冷汗淋淋，面如金纸。\n"NOR, victim);   
                  if (!victim->is_killing(me))   
                  victim->kill_ob(me);   
                  }   
                  return 1;   
               }   
       
      
