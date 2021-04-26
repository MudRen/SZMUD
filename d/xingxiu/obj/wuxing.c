// Code of ShenZhou
#include <ansi.h>

inherit ITEM;
int throw_ob(object me, object victim);
void create()
{
   set_name(HIW"����ɢ"NOR, ({"wuxing san", "san", "wuxing"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("value", 10);
      set("skill", "feixing-shu");
   }
   setup();
}

int throw_ob(object me, object victim)
{
   int skill, skill2, thr, dod, poi, my_neili, u_neili, myexp, urexp, par;
   mapping myfam, vfam;
   
   
   if ( (!( myfam= me->query("family")) || myfam["family_name"] != "������"))
                  return notify_fail("ֻ�����޵������ñ����ش��ڹ�����ʹ������ɢ��\n"); 

   if (me->is_fighting())
   	return notify_fail("����æ�Ŵ���أ��ڲ���������\n");	

   if( me->query("neili") <= 2500 ){
        write("�������������������ɢ����\n");
        return 1;
   }

   if (me->query_skill("poison", 1) < 120){
        write("���Ķ������Լ���\n");
        return 1;
   }

   if( environment(me)->query("no_fight") ) return notify_fail("����!\n");
	
   if( me->is_busy() ) return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");
	

   if (victim->query_condition("sxs_poison")){  
        write("������������Ц׷��ɢ���������ӣ�\n");
        return 1;
   }

   if (me->query_condition("pker") > 240 && userp(victim)){
        write("��е�һ˿�ھΣ���ͻȻ����������\n");
        return 1;
   }
   
   message_vision("$N΢΢һЦ�����Сָ��$n����һ����$n������ǰһ�����ƺ���һ��������Լ�Ʈ����\n"NOR, me, victim);

   if (me->query_skill("poison", 1) < victim->query_skill("poison", 1) + 30){
           victim->apply_condition("insect_poison", 100);
           return 1;
   }

   thr = me->query_skill("feixing-shu", 1);
   poi = me->query_skill("poison",1);
   dod = (int)victim->query_skill("force",1);
      
   my_neili = me->query("neili");
   u_neili = (int)victim->query("neili");
   
   skill = thr + poi + my_neili;
   skill2 = dod + u_neili;
   skill += me->query("combat_exp")/1000;
   skill2 += victim->query("combat_exp")/1000;
   me->add("neili", -150);

   myexp=me->query("combat_exp");
   urexp=victim->query("combat_exp");

   if ( skill > skill2){

        if (urexp>=myexp/2) 
                me->improve_skill("feixing-shu", 1000);
        
        /*
        if(userp(victim) && urexp>=myexp && strsrch(base_name(environment(me)),"/d/bwdh")!=0){
                me->add("combat_exp", 1000);
                me->add_skill("feixing-shu",1);
        }*/
        
        
        if(userp(victim)) me->apply_condition("pker", 250);
                
        //if( !victim->is_killing(me) ) victim->kill_ob(me);
        this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        victim->apply_condition("sanpoison",me->query_skill("poison",1));      
        if( !victim->is_killing(me) ) victim->kill_ob(me);
        destruct(this_object());
      
  	me->start_busy(2);
  	victim->start_busy(2);
        
        return 1;
   } else {
        message_vision(HIR"$n����һ����һ���ھ���������������ɢ������$N������ȥ��\n" NOR, me, victim);
        this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        victim->apply_condition("sanpoison",me->query_skill("poison",1));      
        if( !victim->is_killing(me) ) victim->kill_ob(me);
  }
  
  me->start_busy(2);
  victim->start_busy(2);
  
  destruct(this_object());
  return 1;
}    
