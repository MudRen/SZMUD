// Code of ShenZhou
// by keny
// �����Ʒ� 120 ���������޼� 100 ����
// ������Ϊ����������мܵȼ���

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
int damage,skill;
        string *limb, type, result, str,msg;

        type = "����";

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ˮ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("liushui") )
                return notify_fail("������ʹ������ˮ���ˣ�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("���ֲ���ʩչ����ˮ�䣡\n");

        if( me->query_skill_mapped("strike") != "kunlun-zhang" )
                return notify_fail("�����õĲ��������ƣ�����ʩչ����ˮ�䣡\n");

        if( me->query_skill_prepared("strike") != "kunlun-zhang" )
                return notify_fail("�������Ĳ��������ƣ�����ʩչ����ˮ�䣡\n");

        if( me->query_skill_mapped("force") != "xuantian-wuji" )
                return notify_fail("�����õĲ��������޼�����ʩչ���������ƣ�\n");

        if( me->query_skill("xuantian-wuji") < 100 )
                return notify_fail("��������޼������δ�����޷�ʩչ����ˮ�䣡\n");

        if( me->query_skill("kunlun-zhang") < 120 )
                return notify_fail("��������ƻ��δ�����޷�ʩչ����ˮ�䣡\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�����������ʹ������ˮ�䣡\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("��ľ�������ʹ������ˮ�䣡\n");     
        if( me->query("jing") <= 200 )
                return notify_fail("��ľ�����ʹ������ˮ�䣡\n");


message_vision(
HIY "\n$Nʩ���������еľ���"+HIC"������ˮ�䡿"+NOR"��"+HIY"˫����ͬ�糵��ת��һ�ᣬ�������˺�����������ͬ������Ӳ��\n" NOR, me);

        me->set_temp("liushui", 1);

skill =  ( me->query_skill("kunlun-zhang")+ me->query_skill("force") ) / 2;
me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/damage",  skill/6);
        me->add_temp("apply/dodge",  skill/2);
        me->add_temp("apply/parry",  skill/2);
        me->add_temp("apply/defense",  skill/2);
        me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/attack", -skill/2);
        me->add("neili", -skill/2);
        me->add("jingli", -100);
        me->add("jing", -100);
        me->start_busy(random(2));

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/15);

        return 1;
}

private int remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", -amount);
        me->add_temp("apply/damage", -amount/3);
        me->add_temp("apply/parry", -amount);
        me->add_temp("apply/dodge", -amount);
        me->add_temp("apply/defense", -amount);
        me->delete_temp("liushui");
        message_vision(
        YEL "\n$N���������˿����������������ˣ�\n\n" NOR, me);

        return 0;
}
