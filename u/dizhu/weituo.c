// Code of ShenZhou
// weituo.c Τ�ӷ�ħ��
// by maco
//xiaojian fix weituo bug on Nov.17,2000
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, int dam,int attack);
void checking(object me,int dam,int attack);
void checking2(object me,int dam,int attack,int old_dam,int old_att);

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
        int lv, attack, dam,old_att,old_dam;

        old_att = (int)me->query_temp("apply/attack",1);
        old_dam = (int)me->query_temp("apply/damage",1);
        lv = (int)me->query_skill("damo-jian", 1); 

        if( !target ) target = offensive_target(me);
        else me->set_temp("offensive_target", target);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("Τ�ӷ�ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("sl_weituo") )
                return notify_fail("���Ѿ�ʩչ��Τ�ӷ�ħ���ˣ�\n");

        if( (int)me->query_temp("jingang") )
                return notify_fail("����������ʹ�Ž�շ�ħ���ڼ���ͨ���޷�ͬʱʩչΤ�ӷ�ħ����\n");

        if( me->query_dex() < 30 )
                return notify_fail("�������������������㣬����ʹ��Τ�ӷ�ħ����\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 100 )
                return notify_fail("��Ļ�Ԫһ�������δ�����޷�ʩչΤ�ӷ�ħ����\n");

        if( me->query_skill("buddhism", 1) < 100 )
                return notify_fail("��Է���֪���ޣ���δ���Τ�ӷ�ħ���ĳ������壡\n");

        if( me->query_skill("sword", 1) < 100 )
                return notify_fail("��Ļ���������δ���죬�޷���ԦΤ�ӷ�ħ����\n");

        if( me->query_skill("damo-jian", 1) < 100 )
                return notify_fail("��Ĵ�Ħ������Ϊ���㣬��δ�����Τ�ӷ�ħ����\n");

        if( me->query_skill("dodge") < 135 )
                return notify_fail("Τ�ӷ�ħ����Ҫ������Ṧ��ϣ�������Чʩչ��\n");

        if( me->query_skill("sword") < 135 )
                return notify_fail("�㽣��δ��¯����֮������δ�����Τ�ӷ�ħ����\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi")
                return notify_fail("������ʹ���ڹ����ǻ�Ԫһ�������޷�ʩչΤ�ӷ�ħ����\n");

        if( me->query("neili") <= 500 )
                return notify_fail("�������������ʩչΤ�ӷ�ħ����\n");

        if( me->query("jingli") <= 500 )
                return notify_fail("��ľ���������ʩչΤ�ӷ�ħ����\n");

        if( (me->query_temp("weapon"))->query("skill_type") != "sword" )
                return notify_fail("�������޽�������ʩչΤ�ӷ�ħ����\n");
        if(me->is_busy())
                return notify_fail("����æ����,û�취ʩչΤ�ӷ�ħ��! \n");

        message_vision(HIY "\n$Nչ����Τ�ӷ�ħ�������������ذ빥��"+ weapon->name() +HIY"ʹ��������������������������Ѹ�ݡ�\n" NOR, me);

        me->add("neili", -250);
        me->add("jingli", -100);

        //attack = lv/2 + random(lv/2);
        attack = lv/4+ random(lv/2);
        //dam = lv*3/4 + random(lv/4);
        dam = lv/2 + random(lv/4);

        me->set_temp("sl_weituo", 1);
        me->add_temp("apply/attack", attack);
        me->add_temp("apply/damage", dam);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("sl_weituo", 2);
        me->start_call_out( (: call_other, __FILE__, "checking2", me,dam,attack,old_dam,old_att :), 12);
        //call_out("checking", 1, me, dam, attack);
        if (wizardp(me))  
        tell_object(me, sprintf("original damage=%d, original attack= %d,damage = %d,attack = %d\n", old_dam,old_att,dam,attack));
    me->start_call_out( (: call_other, __FILE__, "checking", me,old_dam,old_att :), 1);
        return 1;
}

void checking(object me, int dam, int attack)
{
        int wt, limit;
        object weapon, target;

        weapon = me->query_temp("weapon");
        target = me->query_temp("offensive_target");

        wt = me->query_temp("sl_weituo");
        limit = 1 + (int)me->query_skill("damo-jian", 1)/100;
        
        if( !target || !me->is_fighting(target) ) target = offensive_target(me);

        if( wt > limit || wt > 5 ) {
                message_vision(HIY"\n$N�������£�����滨���Ѿ���һ·��Τ�ӷ�ħ����ʹ�ꡣ\n"NOR, me);
                remove_effect(me, dam, attack);
                me->start_busy(1);
                return;
        }

        if( !weapon || weapon->query("skill_type") != "sword" )
        {
                tell_object(me, "\n�������޽����޷�����ʩչ��Τ�ӷ�ħ������\n" );
                remove_effect(me, dam, attack);
                return;
        }

        if( !living(me) || me->is_ghost()  )
        {
                remove_effect(me, dam, attack);
                return;
        }

        if( !target || environment(me) != environment(target) || !me->is_fighting() )
        {
                tell_object(me, "\n���ջ��ˡ�Τ�ӷ�ħ�����Ĺ��ơ�\n" );
                remove_effect(me, dam, attack);
                return;
        }
        
        if( me->query_skill_mapped("sword") != "damo-jian" )
        {
                message_vision(YEL"\n$N����һ�䣬�ѷǴ�Ħ������·�ӣ��಻������Τ�ӷ�ħ����������\n"NOR, me);
                remove_effect(me, dam, attack);
                return;
        }

        //call_out("checking", 1, me, dam, attack);
        me->start_call_out( (: call_other, __FILE__, "checking", me,dam,attack :), 1);
        return;
}

void remove_effect(object me, int dam, int attack) 
{
        if (!me) return;
        me->set_temp("apply/attack", attack);
        me->set_temp("apply/damage", dam);
        me->delete_temp("sl_weituo");
        me->start_busy(1);
}

void checking2(object me,int dam,int attack,int old_dam,int old_att)
{
        if (wizardp(me))  
        tell_object(me, sprintf("after fight original damage=%d, original attack= %d,damage = %d,attack = %d\n", old_dam,old_att,dam,attack));
        if (me->query_temp("sl_weituo"))
        {
                tell_object(me, "\n�����˿���,�����ջ��ˡ�Τ�ӷ�ħ�����Ĺ��ơ�\n" );
//                 me->set_temp("apply/attack", old_att);
                me->set_temp("apply/attack", 0);
//                 me->set_temp("apply/damage", old_dam);
                me->set_temp("apply/damage", 0);
                me->delete_temp("sl_weituo");
        }

//         if((int)me->query_temp("apply/attack",1) != old_att)
        if((int)me->query_temp("apply/attack",1) != 0)
        {
//                 me->set_temp("apply/attack",old_att);
                me->set_temp("apply/attack", 0);
        }
//         if((int)me->query_temp("apply/damage",1) != old_dam)
        if((int)me->query_temp("apply/damage",1) != 0)
        {
//                 me->set_temp("apply/damage",old_dam);
                me->set_temp("apply/damage", 0);
        }
                

}

