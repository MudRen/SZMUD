// Code of ShenZhou
// /kungfu/skill/xianglong-zhang/xianglong.c  perform ����һ��
// Lara 2001/11/11

#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit F_SSERVER;

void remove_effect(object me, object target, int lvl);
void msg_display(object me, object target, int lvl);

int perform(object me, object target)
{
        object armor;
        int jiali, jiajin, lvl, my_exp;
	
        my_exp = me->query("combat_exp");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�㲻��ս���С�\n");

        if( me->query_temp("yield") )
                return notify_fail("�㲻���ƣ����ʹ������һ����\n");

        if ( objectp(me->query_temp("weapon")) )
                return notify_fail("�㲻�ǿ��֡�\n");

        if( me->query_temp("xianglong",1) ){
                return notify_fail("������ʹ�ý���һ����\n");	
	}

        if( (int)me->query("max_jingli", 1) < 5000 )
                return notify_fail("��ľ�����Ϊ����������ʩչ����һ����\n");

        if( (int)me->query("max_neili", 1) < 8000 )
                return notify_fail("���������Ϊ����������ʩչ����һ����\n");

        if( me->query_skill("force") < 500 )
                return notify_fail("��Ļ����������δ�����޷�ʩչ����һ����\n");

        if( me->query_skill("strike") < 500 )
                return notify_fail("��Ľ���ʮ������Ϊ������\n");

        if ( me->query_skill_mapped("force") != "huntian-qigong")
                                         return notify_fail("�������ڹ����ԣ�\n");

        if( me->query("neili") <= lvl*2 )
                                         return notify_fail("�������������\n");

        if( me->query("jingli") <= 150 )
                                         return notify_fail("��ľ���������\n");

        me->set_temp("xianglong",1);
        message_vision(HIR "$N���۵��˫����������ת�˸�ԲȦ������������ȫ��������\n\n" NOR, me,target);
        lvl = (int)(lvl / 5);
        me->add("neili", -lvl*2); 
        me->add("jingli", -100);  
        jiali = me->query("jiali");
        jiajin = me->query("jiajin");
        me->add_temp("apply/parry", lvl );
	me->start_busy(1+random(2));

  	call_out("msg_display",1+(int)((me->query_skill("strike")-300)/50),me,target,lvl);

        return 1;
}

void msg_display(object me, object target, int lvl)
{

	string *circle, msg;


        circle = ({
                "$NͻȻ���һ����˫���������$p�����ͻ���ȥ��\n",
                "$N������������һ�������ֺ���һ�ƣ�����$p��ȥ��\n"
        });

        msg = HIG"\n"+ circle[random(sizeof(circle))] +"\n" NOR;

        circle = ({
                "����δ����$p�Ѹ��ؿں������������֮�䣬$N��������ŭ������ӿ������",
                "ֻһ˲֮�䣬$p�����Ϣ���ͣ�$N��������ŭ����ӿ���Ʋ��ɵ���������һ�����εĸ�ǽ����$p��ǰ���塣"
        });

        msg = msg + HIG"\n"+ circle[random(sizeof(circle))] +"\n" NOR;

        if( target
            &&  target->is_character()
            &&  me->is_fighting(target) ) {
        message_vision(msg, me, target);
        call_out("remove_effect",2,me,target,lvl);
        } else {
	    me->delete_temp("xianglong");
	    me->add_temp("apply/parry",-lvl);
	}
        return 0;
}

void remove_effect(object me, object target, int lvl)
{
int jiali, jiajin, ap, dp, pp,dmg,damage;
object weapon;
string *limbs, limb, result, str, type;

	weapon=target->query_temp("weapon");
        ap = COMBAT_D->skill_power(me,"strike", SKILL_USAGE_ATTACK);
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
        type = "����";
	
        if (wizardp(me))
                printf("ap = %d , pp = %d , dp = %d , me->query_temp(apply/parry) = %d , lvl = %d .\n",ap*2,pp,dp,me->query_temp("apply/parry"),lvl);
        if( target
        &&      target->is_character()
        &&      me->is_fighting(target) ) {

        if( random(ap) > random((dp+pp)*(1-(me->query_skill("strike")/1000))/2) ) {
            message_vision(HIM"$N��˫���Ѹ��Ż��������һ���������ش���$p�ؿڣ����ſ������������߹Ƕ��˼�����\n"NOR, me, target);
            dmg = (int)(((me->query_skill("strike")-300)/50)+1) * 1000 + me->query("jiali")*2 + me->query("jiajin")*2;

            target->receive_damage("qi", dmg,  me);
            target->receive_wound("qi", dmg/2+random(dmg/2), me);
            target->start_busy(1+random(2));
	
            if(jiali > me->query("neili"))
                jiali = me->query("neili");
            if(jiajin > me->query("jingli"))
                jiajin = me->query("jingli")-1;
            
            me->add("neili", -jiali-lvl);
            me->add("jingli", -jiajin-lvl/2);

            limbs = target->query("limbs");

            result = COMBAT_D->damage_msg(dmg, type);
            result = replace_string( result, "$l", limbs[random(sizeof(limbs))]);
            result = replace_string( result, "$p", target->name() );
            message_vision(result, me, target);

            str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
            message_vision("($N"+str+")\n", target);
        } else {
            if ( objectp(weapon) )
            { message_vision(HIC "$n��֮�£�$p����������Բ��ס��ǰ��ͬʱ���������Ʈ�����ˣ��ܿ���$N��һ�ơ�\n" NOR, me, target, weapon);}
            else {
            message_vision(HIC "$n��֮�£�˫������������Բ��ס��ǰ��ͬʱ���������Ʈ�����ˣ��ܿ���$N��һ�ơ�\n" NOR, me, target);}
        }
        }
        me->delete_temp("xianglong");
	me->add_temp("apply/parry",-lvl);
        if (wizardp(me))
                printf("ap = %d , pp = %d , dp = %d , me->query_temp(apply/parry) = %d , lvl = %d .\n",ap*2,pp,dp,me->query_temp("apply/parry"),lvl);
        return 0;
}