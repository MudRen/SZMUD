// Code of ShenZhou
//yun xixia
//by xiaojian on Oct8,2000
//Modify by Scatter

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount,int amount1);

int exert(object me, object target)
{
        int skill,str;
//        if (!wizardp(me))
//        return notify_fail("�⹦��Ŀǰ��������ҿ��š�\n");
    if( objectp(target) && target != me ) 
        return notify_fail("��ֻ������ϼ���������Լ���ս����\n");
        if(me->query_skill("zixia-gong",1) <300)
                return notify_fail("�����ϼ����Ϊ������\n");
        if(me->query_skill("zhengqi-jue",1)<210)
                return notify_fail("�����������򲻵����޷�ʩչ��ϼ�񹦡�\n");
        if(me->query_skill("ziyin-yin",1)<210)
                return notify_fail("����������򲻵����޷�ʩչ��ϼ�񹦡�\n");
        if( me->query_skill_mapped("force") != "zixia-gong" )
        return notify_fail("�����õĲ�����ϼ����ʩչ������ϼ�񹦣�\n");
        if( (int)me->query("max_neili") <1000)
                return notify_fail("���������Ϊ���㣬�޷�ʩչ��ϼ�񹦣�\n");
        if( (int)me->query("neili") < 800  )
        return notify_fail("�������������\n");
        if( me->query("family/master_id") == "feng qingyang" )
                return notify_fail("���ǽ��ڸ��֣�ʩչ�������ڵĸ����\n");
    if( me->query_temp("leidong") )
        return notify_fail("���Ѿ���ʹ���׶������ˣ��޷�ͬʱ������ϼ�񹦣�\n");
        if( me->query_temp("zixia"))
                return notify_fail("���Ѿ�ʩչ����ϼ���ˡ�\n");
        skill = (int)me->query_skill("zixia-gong",1);
        str = me->query_str();
    
    message_vision(
MAG"$N΢һ����������ϼ�񹦣�����ͻȻ������ʢ��ֻ��������һ�ּ�����$N�����ֻظ��糣��\n" NOR, me);

        me->add("neili", -skill);
    me->receive_damage("jingli",skill/2,"����͸֧��������");
        me->set_temp("zixia",1);        
    me->add_temp( "apply/attack", skill/2 );
    me->add_temp( "apply/dodge", skill/2 );
    me->add_temp("apply/strength",str);
        
    me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill,str:),skill/3);
    if( me->is_fighting() )
                me->start_busy(1+ random(1));
    return 1;
}

void remove_effect(object me, int amount, int amount1)
{
	me->add_temp( "apply/attack", -amount/2 );
	me->add_temp( "apply/dodge", -amount/2 );
        me->add_temp("apply/strength", -amount1);
        me->delete_temp("zixia");
        tell_object(me, "�����ϼ��������ϣ��������ջص��\n");
}

