           // Code of ShenZhou  
           // qiulong-bang
           // Lnere  
             
#include <ansi.h>  
#include <weapon.h>  
#include "/clone/unique/special_weapon.h"  
           inherit F_UNIQUE;  
           inherit WHIP;  
           void create()  
           {  
                   set_name(HIY"˫����˿�����"NOR, ({"qiulong bang", "bang", "stick"}));  
                   set_weight(8000);  
                   if (clonep())  
                           set_default_object(__FILE__);  
                   else {  
                           set("unit", "��");  
                           set("long", 
                           HIW"�˰���Լ������磬����ȫ����ͷ���������������У�ͨ����ǧ�����ٺ���˿��ͷ�����ͣ���Ӳ��ʩ��"+NOR+" \n" 
                           "����ͷ���¸���һ���������������ȿɵ���ޣ��ֿɵ�˫ǹ�����ܵ���ʹ�á��ƺ���ͷ֮�а������ء�\n");  
                           set("value", 8000000);  
                           set("material", "bamboo");  
                           set("rigidity", 5000);  
                           set("dao", 4);  
                           set("wield_msg", 
                           HIC"$N�������һ������ȥ���ι�״�ı�����\n" 
                           YEL"ֻ�������Ʊ޷Ǳ��ƹ��ǹ������������ɴ��������ɵ���ͷ��\n"NOR);  
                           set("unwield_msg", 
                           YEL"$N�����е�˫����˿��������²������䡣\n"NOR);  
                   }  
                   init_whip(50);  
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
                    return notify_fail("��Ҫ����˭��\n");  

                 victim = present(arg,environment(me));  
      
                  if (!victim) 
                         return notify_fail("���ﲢ�޴��ˣ�\n"); 

                  if (query("dao") < 1)  
                         return notify_fail("��ͷ�ﰵ�صķɵ��Ѿ�������ˡ�\n");  
 
                  if (!living(victim))  
                         return notify_fail("�ⲻ�ǻ��\n");  
             
                  if( me->is_busy() )  
                          return notify_fail("��ǰһ��������û�����ꡣ\n");  

                  if (victim == me) return notify_fail("�αض��һ�٣�\n");  

                  if( environment(me)->query("no_fight") )  
                              return notify_fail("�����ﲻ�ܹ������ˡ�\n");  
         
      
                  message_vision(HIW"$NͻȻ�������ڰ��еĻ��ء�\n" 
                        CYN"ֻ������һ��Ϊ�������˵������Ȼ�ſ�������ı�����ɭɭ�ķɵ��������̶����ƿ�֮������$n��ȥ�� \n" NOR, me, victim); 
                  add("dao", -1);  
                  if( random(me->query("combat_exp")) > (int)victim->query("combat_exp")/2){    
                  message_vision(BLU"$Nֻ��ר��Ӧս���������ƿ�֮��ʱ�������ܣ�����Ϊʱ����\n" 
                  HIR"ֻ��$Nһ���ҽУ��ı������Ѵ��ض�������Ѫ��ӿ��������Ȼ���˼��ء�\n"NOR, victim);   
                  victim->receive_wound("qi", 5000, "��" + me->query("name") +"ɱ����");   
                  victim->receive_wound("jing", 300, "��" + me->query("name") +"ɱ����");   
                  if (!victim->is_killing(me))   
                  victim->kill_ob(me);   
                  } else {   
                  message_vision(HIW"$N�����������б���ȥ���ı����в�Ь������$N�����ŵ��亹���ܣ������ֽ��\n"NOR, victim);   
                  if (!victim->is_killing(me))   
                  victim->kill_ob(me);   
                  }   
                  return 1;   
               }   
       
      
