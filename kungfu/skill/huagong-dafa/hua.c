//Code of Shenzhou
//coding by Slow
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me);
void checking(object me);

int exert(object me, object target)
{
          int lv;

             if (!me->query("canewhua"))  return notify_fail("�㻹û�õ������󷨵��洫��\n");
              if (me->query("family/family_name") != "������")
          return notify_fail("�������������ɵĶ��ž�ѧ��\n");
                lv = (int)me->query_skill("huagong-dafa", 1); 
           if( target == me) target=offensive_target(me);
           if( !target )target = offensive_target(me);
      if( !target ) target = me->select_opponent();
/*
           if( !target||!me->is_fighting() )
                    return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
*/
          if( me->query_temp("newhua") )
                    return notify_fail("���Ѿ�ʩչ���������ˣ�\n");


              if( me->query_skill("huagong-dafa", 1) < 360 )
                  return notify_fail("��Ļ����󷨻��δ����\n");

        if( me->query_skill_mapped("force") != "huagong-dafa")
                  return notify_fail("������ʹ���ڹ����ǻ����󷨣��޷�ʩչ������\n");

          if( me->query("neili") <= 3000 )
                  return notify_fail("�������������ʩչ�����󷨣�\n");

          if( me->query("jingli") <= 2500 )
                  return notify_fail("��ľ���������ʩչ�����󷨣�\n");
/*
            if ((int)me->query_skill("pixie-jian", 1) >=1)
          return notify_fail("��а�����뻯���󷨵�����������㣣��޷�ʩչ�����󷨵ĸ����\n");
*/
        if( me->query_skill_mapped("sword") == "pixie-jian" ||
        me->query_skill_mapped("parry") == "pixie-jian" ||
        me->query_skill_mapped("dodge") == "pixie-jian" )
          return notify_fail("��а�����뻯���󷨵�����������㣣�ͬʱʩչ�����󷨺ͱ�а������\n");
        if(me->is_busy())
                  return notify_fail("����æ����,û�취ʩչ������! \n");

message_vision(
HIB"$NͻȻ��ɫ������������Ц��������Ȼ�ӿ���������һ˫������ú������졣\n"
HIG"ֻ��$NԽ��Խ���������ߣ������󷨼���������������$N����ֻ���ۣ������ķ緫��\n"
HIB"�Ĵ���������������������һ�ɹ���ӿ���ȵ����ˡ�\n" NOR, me, target ); 


           me->set_temp("newhua",(int)me->query_skill("huagong-dafa", 1)/10+10);
               call_out("checking", 1, me); 
        return 1;
}

  void checking(object me)
{
              int num,ap,dp,dmg;
          object target;

if(!me) return;
          if (!me->query_temp("newhua")) return;
        target = me->query_temp("offensive_target");
          num=(int)me->query_temp("newhua");

        if( me->query_skill_mapped("sword") == "pixie-jian" ||
         me->query_skill_mapped("parry") == "pixie-jian" ||
        me->query_skill_mapped("dodge") == "pixie-jian" )
         {
         me->delete_temp("newhua");
         message_vision(HIY "\n$N�ñ�а�����뻯���󷨵�����������㣣�ͬʱʩչ�����󷨺ͱ�а��������\n"NOR, me);;
          return;
           }
           me->set_temp("newhua",me->query_temp("newhua")-1);
       if( wizardp(me) )  tell_object(me,sprintf("<����ʱ�仹ʣ%d��>\n",num));
          if( num<1 ) {
  message_vision(YEL"$N����������֧�������ѽ��ѷ��ӵ����µġ������󷨡������ջص��\n"NOR, me);
           me->delete_temp("newhua");
                return;
        }
          if( !target ) target = offensive_target(me);
          if( !target || !target->is_character() || !me->is_fighting(target) )
          {
//        return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
           call_out("checking", 1, me); 
            return;
          }


        if( !living(me) || me->is_ghost()  )
        {
                  remove_effect(me);
                return;
        }
/*
        if( !target || environment(me) != environment(target) || !me->is_fighting() )
        {
                  tell_object(me, "\n�㲻��ս����,ֻ���ջ��˻����󷨡�\n" );
            me->delete_temp("newhua");
                return;
        }
*/
         ap=me->query("combat_exp");
         dp=target->query("combat_exp");
              if (random(15)>4)
          {
         if(ap>random(dp*5/4))
         {
              message_vision( 
HIR "$n�ոտ���$N��ֻ����һ�������ޱȵ���������Ҫ���Լ�������ȥ����æ�˹�������\n"
CYN "$N���һ�����������ڵ�˫����ץס$n�����Ŵ�Ѩ��$n������費�ɷ��������ҽС�\n" NOR, me, target ); 
                      tell_object(target, HIR "��ͻȻ����ȫ�����������Ʊ�ӿ��������֫��������Ҳʹ����������\n" NOR); 
                      tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR); 
                dmg=(int)me->query_skill("force")*4 +random(600);
                target->receive_damage("qi", dmg, me ); 
                       target->receive_wound("qi", dmg/2+random(dmg/2), me); 
            me->add("qi", (int)me->query_skill("force") ); 
             COMBAT_D->report_status(target);
               target->start_busy(random(3));
          }
     }
        else{
              message_vision( 
HIB"��������"+HIW+"����"+HIB+"��$N�İٻᡢ����̫��Ѩ��������а�ֱ��ü�ġ�\n"
HIB"$N��ͷ����������һ������֮����ͻȻ����һת���ۿ���仯��������Ӱ����Ӱ������������צ��$nץȥ��\n"
HIB"$N��ɫԽ�����������ϵ�����������Ĺĵ�֮�·����̶������ŵ�$n�ķ����ң����Ʋ��ɵü�����������\n"
HIW"$N��$n�������ƣ���Хһ������������˫�������¸�ǽһ�����˹�ȥ��$nֻ�ø��ȴ������Ѩ��¶���š�\n" NOR, 
                           me, target ); 
   if(ap>random(dp*5/4))
            {
                      message_vision( 
                              HIR "$N�پ�����΢ʹ����ͬ��������˸�С�ף�ȫ��������ˮ����ѭ�׷�й������\n\n" NOR, 
                              target ); 
                      tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR); 
                      if ((int)target->query("neili") > (int)me->query_skill("force")) 
                      { 
                               target->add("neili", -(int)me->query_skill("force")*3/2 ); 
                               me->add("neili", ((int)me->query_skill("force"))/2); 
                      }else{ 
                               me->add("neili", ((int)me->query_skill("force"))/5); 
                              target->set("neili", 0); 
                      } 
          }
       }
                            call_out("checking", 1+random(5), me); 
        return;
}

  void remove_effect(object me) 
{
        if (!me) return;
          me->delete_temp("newhua");
        me->start_busy(1);
}