/*
[1] dali fix report                          ���(lnere)(Mon May 20)
----------------------------------------------------------------------
         ����
        �����Ṧ--������
           ԭ�й��ܣ���
           �޸Ĺ��ܣ�perform qingyun ������ֱ�ϣ�
                 ��������������Ч�ȼ�100������������Ч�ȼ�100��
                        ���ܣ������ʱjifa dodge 10%��
                        ���ƣ�ʱ����5-10tick��
                        �ڹ����裺100/�Ρ�
***********************************************************************
snowyu by 2002/5
*/

#include <ansi.h>
inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        string msg;
        int i, extra;

        if( me->query_temp("qingyun") )
                return notify_fail("���������á�����ֱ�ϡ��ķ���\n");

        if( me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail("�����õ��ڹ��롸����ֱ�ϡ��ķ���㣣�\n");

        if( me->query_skill("kurong-changong", 1) < 100 )
                return notify_fail("����ڹ���Ϊ���δ������δ��������ֱ�ϡ���\n");

        if( me->query("neili") < 1000 )
                return notify_fail("�����������������������ʩչ������ֱ�ϡ���\n");
        
        if( me->query_skill("duanshi-shenfa", 1) < 100 )
                return notify_fail("��Ķ�������Ϊ��������δ��������ֱ�ϡ���\n");

        msg= HIW"$N��Ȼ��ɫһ�䣬˫Ŀһ��,��������ķ���ȫ��������ת�������죬������Ȼ�ӿ�, ����������С�\n" NOR;
     
        me->add("neili", -100);
        me->add("jingli", -100);
        
        extra = ((int)me->query_skill("kurong-changong",1)+(int)me->query_skill("duanshi-shenfa",1))/2;
		
		me->add_temp("apply/dodge", extra/5);


        me->set_temp("qingyun", 1);
        call_out("remove_effect", extra/5, me, extra);
		message_vision(msg, me);
     
		return 1;
}

 

void remove_effect(object me, int extra)
{
        if (!me) return;
        me->add_temp("apply/dodge", -extra/5);
        me->delete_temp("qingyun");
		message_vision(HIW"$Nֻ�������ķ�����ɢȥ,����������������\n"NOR,me);
}
