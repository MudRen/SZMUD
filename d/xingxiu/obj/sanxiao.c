// Code of ShenZhou
#include <ansi.h>

inherit ITEM;
int throw_ob(object me, object victim);
void create()
{
   set_name(BLU"��ң��Цɢ"NOR, ({"sanxiao san", "san", "sanxiao", "zhuihun"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("value", 10);
      set("skill", "feixing-shu");
   }
   setup();
}

void init()
{
        object me = this_player();
        add_action("throw_ob2","tan"); 
}

int throw_ob(object me, object victim)
{
   int skill, skill2, thr, dod, poi, my_neili, u_neili, myexp, urexp, par;
   mapping myfam, vfam;
   
   
   if ( (!( myfam= me->query("family")) || myfam["family_name"] != "������"))
                  return notify_fail("ֻ�����޵������ñ����ش��ڹ�����ʹ����Цɢ��\n"); 

   if (me->is_fighting())
   	return notify_fail("����æ�Ŵ���أ��ڲ���������\n");	

   if( me->query("neili") <= 5000 ){
        write("�����������������ң��Цɢ����\n");
        return 1;
   }

   if (me->query_skill("poison", 1) < 100){
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
   
   tell_object(me, BLU"������һ��ָ������ң��Цɢ��"+victim->query("name")+"���ϵ�ȥ��\n"NOR);
   	

   if (me->query_skill("poison", 1) < 100){
           this_object()->set_temp("used", 1);
           me->apply_condition("sxs_poison",4); 
           tell_object(me, "�㶾���û����������Լ��ˣ�\n");
           destruct(this_object());
        return 1;
   }

   if (me->query_skill("poison", 1) < victim->query_skill("poison", 1) + 30){
           victim->apply_condition("insect_poison", 100);
           return 1;
   }

   thr = me->query_skill("feixing-shu", 1);
   poi = me->query_skill("poison",1);
   dod = (int)victim->query_skill("force",1);
   par = (int)victim->query_skill("parry",1);
   
   my_neili = me->query("neili")/3*2;
   u_neili = (int)victim->query("neili")/3*2;
   
   skill = thr + poi + my_neili;
   skill2 = dod + par + u_neili;
   skill += me->query("combat_exp")/10000;
   skill2 += victim->query("combat_exp")/10000;
   me->add("neili", -150);

   myexp=me->query("combat_exp");
   urexp=victim->query("combat_exp"); 

   if (wizardp(me))
   	printf("my skill=%d  ur skill=%d\n",skill, skill2);

   if ( skill > skill2+random(skill2/2) ){

        if (urexp>=myexp && strsrch(base_name(environment(me)),"/d/bwdh")!=0) 
                me->improve_skill("feixing-shu", 1000);
        
        if(userp(victim) && urexp>=myexp && strsrch(base_name(environment(me)),"/d/bwdh")!=0){
                me->add("combat_exp", 1000);
                me->add_skill("feixing-shu",1);
        }
        
        if(userp(victim)) me->apply_condition("pker", 250);
                
        //if( !victim->is_killing(me) ) victim->kill_ob(me);
        this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        victim->apply_condition("sxs_poison",4);      
        destruct(this_object());
        return 1;
   } else if (skill>skill2){
   	message_vision(HIY"$nͻȻ����һ�����Ϯ����æ���һԾ�����˿�ȥ��\n"NOR, me, victim);
   	this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        if( !victim->is_killing(me) ) victim->kill_ob(me);
        me->start_busy(random(3)+1);
   } else {
        message_vision(HIR"$n����һ����һ���ھ�������������Цɢ������$N������ȥ��\n" NOR, me, victim);
        this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        me->apply_condition("sxs_poison",4);
        me->start_busy(random(3)+1);
        if( !victim->is_killing(me) ) victim->kill_ob(me);
  }
  
  destruct(this_object());
  return 1;
}    
