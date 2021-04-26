// Code of ShenZhou
// jinzhongzhao
// modified by aln 4 / 98
//remodied by xiaojian on March 20, 2000
// Modified by Felix 5/2002

#include <ansi.h>

//inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        string msg;
        int i, extra;

/*
        if( !me->is_fighting() )
                return notify_fail("��ղ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
*/

        if( me->query_temp("jinzhongzhao") )
                return notify_fail("���������ý�ղ������񹦣�\n");

        if( (int)me->query_temp("jingang") ) 
                return notify_fail("���������ý�շ�ħ�������ͨ������δ�����޷�ͬʱ���ý�ղ������񹦡�\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi")
                return notify_fail("�����õ��ڹ����ղ���������㣣�\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 160 )
                return notify_fail("����ڹ���Ϊ���δ������δ�����ղ������񹦣�\n");

        if( (int)me->query_skill("banruo-zhang", 1) < 200 )
                return notify_fail("��İ����ƻ��δ������δ���ɽ�ղ������񹦣�\n");

        if( me->query("neili") < 2000 )
                return notify_fail("�����������������������ʩչ��ղ������񹦣�\n");
        
        message_vision(
        HIY"$N˫�ֺ�ʮ����֮�������ڶ������ϱ���ׯ�ϣ��������о�����ת��"
        "���������޷��Զ�������˿�����������Ƿ��Ų���֮�ؽ�ղ�������ͨ��\n"NOR,me);
        me->add("neili", -300);
        me->add("jingli", -100);

        me->start_busy(3);
        
        extra = me->query_skill("force");
        me->set_temp("jinzhongzhao", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra/2);

        return 1;
}

void remove_effect(object me)
{	
	if (me->query_temp("jinzhongzhao")) {
        me->delete_temp("jinzhongzhao");
        tell_object(me, YEL"\n��ֻ��������ת���������ò�ɢȥ������������Ϣ���ɡ�\n"NOR);
}
}

