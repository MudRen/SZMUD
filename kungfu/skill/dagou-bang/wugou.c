// Code of ShenZhou
//wugou.c �򹷰����������޹���
//code by slow

#include <ansi.h>
#include <armor.h> 
#include <combat.h> 

inherit F_DBASE;
inherit F_SSERVER;
string *wugou_msg=({
HIY"$N��Цһ����������һ��������������һʽ���������족��ʱʹ������ȴ���޾����á�\n"NOR,
HIY"$N�������£��ǰ���Ȼ���������������綾�߳�������Ѹ�ײ����ڶ�֮�ƴ���$n���š�\n"NOR,
HIY"$Nһ��δ�ϴ������������Ϊ�̡����а�����ǹ��,��ͷ�һ����һȦ��Ӱ����$n����������\n"NOR,
HIY"$N�����������ոջ��Ǳ仯�������ʽ����ʱ�����޻��ڣ�ֱȡü�ģ���$n������⡣\n"NOR,
HIY"$N���а���Ȼ��������ޱȣ�����ճ��$n����һ��������$n�iת��Ų�ǰ�������Ӱ�����㹥����ʵ�������˷�����˼��\n"NOR,
HIY"$Nһ���ǳɡ������޹������һʽ,ɲ�Ǽ������Ӱ��ס$n���Ѵ򹷰������ӵ����� !\n"NOR});

int perform(object me, object target)
{
        int ap,dp,pp;
        int i,enfor;
        int num;
        string msg;
        int damage,skill;

        if( !target ) target = offensive_target(me);

        if( me->query("wugou") < 60)
                return notify_fail("�㻹ûѧ�ᡸ�����޹�����\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������޹���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( target->is_busy() ) {
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
        }

        if( me->query_temp("ban",1) )
                return notify_fail("������ʹ�ð��־���\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("�����õĲ��ǻ����������޷�ʩչ�������޹�����\n");

          if( me->query_skill("force") <450 )
                return notify_fail("��Ļ����������δ�����޷�ʩչ�������޹������\n");


	if ( me->query_skill("stick") < 500 )
                return notify_fail("��Ĵ򹷰�����Ϊ���㣬������ʹ�á������޹�����\n");

        if( me->query("max_neili") < 8000 || me->query("neili") <3000 )
                return notify_fail("���������Ϊ�������޷�ʹ�á������޹�����\n");
        if( me->query("max_jingli") < 5000 || me->query("jingli") < 2000)
                return notify_fail("��ľ������㣬�޷�ʹ�á������޹�����\n");
        if( !me->query("rank") || me->query("rank") < 9)
                return notify_fail("����ؤ�Ｖ��̫���˰� ��\n");
        message_vision(HIW"$N�����������һ·���򹷰�����ʹ�ñ䷨�޷����������彥�����ֳ���,����һ�У�������£�\n",me,target);
        message_vision(HIG"�����Ǵ򹷰����ľ��С������޹���,��˵�����ֱ仯����һ���̽�����������˷��ǰ�,����������\n",me,target);
        message_vision(HIG"���м�ʮ����ȮҲһ������ˣ���ν�������޹������Ǵ��壬����֮������ף�������ѧ�еľ���!\n"NOR,me,target);
        ap = COMBAT_D->skill_power(me,"stick", SKILL_USAGE_ATTACK)/1000 + 1; 
        pp = COMBAT_D->skill_power(target,"parry", SKILL_USAGE_ATTACK)/1000 + 1; 
        dp = COMBAT_D->skill_power(target,"dodge", SKILL_USAGE_ATTACK)/1000 + 1; 
        num = me->query("wugou");
        if (wizardp(me) ) printf("ap = %d ,dp =%d ,pp =%d \n",ap,dp,pp);
        skill = me->query_skill("stick") + me->query_skill("huntian-qigong",1);
        if ( skill >1200 ) skill = 1200;
        if (num < 100) num = 3;
        else if (num <200) num =4;
        else if (num <500) num =5;
        else num = 6;
        enfor = (me->query("jiali") + me->query("jiajin") )/2;
        for (i=0;i<num;i++)
        {
        if (i == 5) break;
        damage = skill/10 + skill*(10-i)/100 + random(enfor/2);
        damage = damage /2 + random(damage);   
        if (damage > 400) damage = 400;
        if (damage < 180) damage = 180;
        if (wizardp(me)) printf("i = %d,damage = %d\n",i,damage);
        me->add_temp("apply/damage",damage);
        me->add_temp("apply/attack",damage);
        msg = wugou_msg[i];
        message_vision(msg,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->add_temp("apply/damage",-damage);
        me->add_temp("apply/attack",-damage);
        }
        if (num==6 && ap > random((pp+dp)/2) )
        {
            call_out("last_hit",1,me,target);
        }
           me->add("neili",-250);
        me->start_busy(2+random(num/2));
        return 1;
}
void last_hit(object me,object target) 
{
        object weapon;
          if( !objectp(weapon = me->query_temp("weapon")) ||(!target) )   return;
              message_vision(wugou_msg[5],me,target);
              target->receive_damage("qi", 1000 + random(2000),  me);
                 target->receive_wound("qi",500+random(500), me);
                  COMBAT_D->report_status(target);  
}
