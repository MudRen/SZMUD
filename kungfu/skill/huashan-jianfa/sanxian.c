/* ����������ϼ�񹦶��˵��˽��ϣ�����һ������ͷֱ���������б������������ȺȦ 
ת�������������������������ӽ���Ծ��������Ⱥ�������ã����������ģ���һ������ 
�켫������屳�����۾����������Զ�ܡ�����"��"��һ���������˳������������ 
�ڰ�գ������޴���������ǰԾ���ؽ�����Ҳ�Ѳ�����ȴ��������ͦ����������ǰ������ 
��ľ��֮�ϣ���һ���������ӱ���Ծ����ľ��֮���۵�һ���죬����Ⱥ��������ľ���� 
�������ͣ������ھ���ע����������������������������������಻�����硣 
    �����ֶ�"��"��һ������һ���л��������г�����ϲ�á���ο����֮̾�飬������ 
�˶�����Ϊ����延ϲ�����������һ�¶������֮��������������Ⱥ����û���������� 
��Ⱥʩչƽ��������������������Ȼ�κβ�������壬���������˵Ľл������Ƕ���ͬ�� 
�Է������´��ǰ�ŭ����"�����������ɽ�"�ǻ�ɽ�ɽ��ڵľ����������ڵ���ԭ����֪ 
�����������ԲУ����ڵ������Դ˽���ɱ�˺ü������ں��֡������ڵ��ӽ����ڵĵ����� 
¾��������û�ɽ������֮�����ں�����ϸ��������ʽ����"�����������ɽ�"������ 
�������ն�ʱ����ʽ����������������������£�����֮ʱ�����˾�˵�����н������� 
ħ�������󽣷����ȴ���˱���"����Ԧ��"�Ĳ��������������˵��Ư��������ȴ 
�޲������*/
//Cracked by Kafei
//duoming.c �����������ɽ� 
#include <combat.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void chkpfm(object me, object target, int amount);
int perform(object me, object target)
{
        object weapon, weapon1;
        int lvl1, lvl2, amount, amount2;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����������ɽ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽������ʹ�ö����������ɽ���\n");

        if (!living(target))
                return notify_fail("���Ѿ��ε��ˣ���������׵�ɱ������\n");
        if( me->query_temp("kuaijian",1) ) 
                return notify_fail("������ʹ�á����콣��!"); 
        
        if( me->query_temp("yijian",1) ) 
                return notify_fail("������ʹ�á�����һ����!"); 

        if( me->query_skill_mapped("force") != "zixia-gong" )
                return notify_fail("�����õĲ�����ϼ�����޷�ʩչ�����������ɽ���\n");

        if( (lvl1=me->query_skill("zixia-gong", 1)) < 100 )
                return notify_fail("�����ϼ�����δ�����޷�ʩչ�����������ɽ���\n");

        if( (lvl2=me->query_skill("sword")) < 200 )
                return notify_fail("�㻪ɽ������Ϊ���㣬������ʹ�ö����������ɽ���\n");

        if( (lvl2 - lvl1) < lvl2 / 4 && lvl1 < 200)
                return notify_fail("�����������ɽ���Ҫ����տ�Ľ�����\n");

        amount = lvl2 * (1 + random(2));

        if ( amount < 500 ) amount = 500;
        if ( amount > 2000 ) amount = 2000;
	if (amount > 1000) amount2 = 1000;
	else amount2 = amount;
        if( me->query("neili") <= amount )
                return notify_fail("�����������ʹ�ö����������ɽ���\n");
        if( me->query("jingli") <= amount )
                return notify_fail("��ľ�������ʹ�ö����������ɽ���\n");

        me->set_temp("sxj-c" , 1);
        message_vision(HIR "\n$N"+HIR+"�ĵ��ھ�����������"+weapon->name()+HIR+"�ϣ�����ɱ�ţ�һ����$n"+HIR+"��ͷֱ������\n" NOR, me, target);
        chkpfm(me, target, amount);
        if(me->query_temp("sxj-d")=="fail_all"){
                me->add("jingli",-amount2 / 9);
                me->add("neili",-amount2 / 6);
                me->start_busy( 1+random(1) );
                return 1;
        }
        me->set_temp("sxj-c" , 2);
        message_vision(HIW "\n$N"+HIW+(me->query_temp("sxj-d")=="ok"?"":"һ�����У�")+"�������������ʯ���Ȧת"NOR+weapon->name()+HIW"����$n"+HIW+"������������\n" NOR, me, target);
        chkpfm(me, target, amount);
        if(me->query_temp("sxj-d")=="fail_all"){
                me->add("jingli",-amount2 / 5);
                me->add("neili",-amount2 / 3);
                me->start_busy( 1+random(2) );
                return 1;
        }
        me->set_temp("sxj-c" , 3);
        message_vision(HIY "\n$N"+HIY+"����������"+weapon->name()+HIY"���ã�����$n"+HIY+"���ģ���һ�����м��죬$n�������۾����������Զ�ܣ���\n" NOR, me, target);
        chkpfm(me, target, amount);
        if((int)target->query("eff_qi") * 100 /(int)target->query("max_qi") <= 5
         && (int)target->query("qi") * 100 /(int)target->query("max_qi") <= 1
         && me->query_temp("sxj-c") == 3 && me->query_temp("sxj-d") == "ok")
        {
                message_vision(HIR "\n$N"+HIR+"�����ھ���ע������ǿ��֮����"+weapon->name()+HIR+"���������������̳�$n"+HIR+"ǰ�����磡��\n" NOR, me, target);
                target->receive_damage("qi", amount * 100, "��"+me->name()+"�ö����������ɽ�һ����������ˣ�"); 
                if (wizardp(me))
                        tell_object(me,HIR"super attack!!\n"NOR);
        }
        me->add("jingli",-amount2 / 3);
        me->add("neili",-amount2 / 2);
        me->start_busy( 1+random(3) );
        return 1;
}
void chkpfm(object me, object target, int amount)
{
        object weapon2 = target->query_temp("weapon");
        string attack_skill, dodge_skill, parry_skill, result, sword_skill, msg = "";
        object weapon = me->query_temp("weapon");
        int ap, dp, pp, damage, level, level2, dam;

        if( !me->is_fighting(target) || !living(target) ) 
                return;

	dam = me->query_temp("apply/damage");
        level = me->query_skill("sword");
        level2 = target->query_skill("sword");
        damage = (amount+level) * (random(level / 100));
        sword_skill = target->query_skill_mapped("sword");
        ap = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
        if( ap < 1) ap = 1;
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
        if( target->is_busy() ) dp /= 3;
        if( dp < 1 ) dp = 1;
        if( level2*1/2 > level || (sword_skill == "dugu-jiujian" && level2 > 500)){
                msg += HIY"$n�Ѿ�����$N���������У�";
                switch(random(2)){
                        case 1:
                                dodge_skill = target->query_skill_mapped("dodge");
                                if( !dodge_skill ) dodge_skill = "dodge";
                                msg += "ʹ��"+to_chinese(dodge_skill)+"������$N���������ƶ��˹�ȥ��\n"NOR+SKILL_D(dodge_skill)->query_dodge_msg();
                                me->set_temp("sxj-d","fail_all");
                                break;
                        case 2:
                                if( weapon2 ){
                                        parry_skill = target->query_skill_mapped("parry");
                                        if( !parry_skill ) parry_skill = "parry";
                                        msg += "ʹ��"+to_chinese(parry_skill)+"�ĸ���֮����$N���������Ƶ�ס�ˡ�\n"NOR+SKILL_D(parry_skill)->query_parry_msg(weapon2, target);
                                        me->set_temp("sxj-d","fail_all");
                                }else{
                                        dodge_skill = target->query_skill_mapped("dodge");
                                        if( !dodge_skill ) dodge_skill = "dodge";
                                        msg += "��$N�������ң������޷�������$nֻ��ʩչ�Ṧ��ܡ�\n"NOR;
                                        if( random(ap + dp) < random(dp*2) ){
                                                msg += SKILL_D(dodge_skill)->query_parry_msg();
                                                me->set_temp("sxj-d","fail_all");
                                        }else{
                                                msg += "$n��δ���ü�������$N��"+weapon->name()+"���ж������������������\n"NOR;
                                                target->receive_damage("qi", damage/3, me);
                                                target->receive_wound("qi", damage/6, me);
                                                if (me->query_temp("sxj-c") == 3)
                                                        result = COMBAT_D->damage_msg(damage, "����");
                                                else result = COMBAT_D->damage_msg(damage, "����");
                                                msg += result;
                                                result = COMBAT_D->status_msg((int)target->query("qi") * 100 /
                                                        (int)target->query("max_qi"));
                                                msg += "( $n"+result+" )\n";
                                                me->set_temp("sxj-d","ok");
                                        } 
                                }
                                break;
                }
        }else if( random(ap + dp) < random(dp*2/3) ){
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg();
                me->set_temp("sxj-d","fail");
        }else{
                pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
                if( target->is_busy() ) pp /= 2;
                if( pp < 1 ) pp = 1;

                if( random(ap + pp) < random(pp*3/4) )
                {
                        
                        parry_skill = target->query_skill_mapped("parry");
                        if( !parry_skill || !SKILL_D(parry_skill)->parry_available()) 
                                parry_skill = "parry";
                        msg += SKILL_D(parry_skill)->query_parry_msg(weapon2, target);
                        me->set_temp("sxj-d","fail");
                }else{
                        target->receive_damage("qi", damage, me);
                        target->receive_wound("qi", damage/3, me);
                        if (me->query_temp("sxj-c") == 3)
                                result = COMBAT_D->damage_msg(damage, "����");
                        else result = COMBAT_D->damage_msg(damage, "����");
                        msg += result;
                        result = COMBAT_D->status_msg((int)target->query("qi") * 100 /
                                (int)target->query("max_qi"));
                        msg += "( $n"+result+" )\n";
                        me->set_temp("sxj-d","ok");
                }
        }
        if (me->query_temp("sxj-c") == 1)
                msg = replace_string( msg, "$l", "ͷ��" );
        if (me->query_temp("sxj-c") == 2)
                msg = replace_string( msg, "$l", "����" );
        if (me->query_temp("sxj-c") == 3)
                msg = replace_string( msg, "$l", "����" );
        msg = replace_string( msg, "$w", (me->query_temp("weapon"))->name());
        message_vision(msg, me, target);
        return;
}
