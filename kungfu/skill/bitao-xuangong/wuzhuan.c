// Code of ShenZhou
// wuzhuan.c ������ת

#include <ansi.h>

//inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        string msg;
        int i, extra;

        if( me->query_temp("wuzhuan") )
                return notify_fail("���������á�������ת���ķ���\n");

        if( me->query_skill_mapped("force") != "bitao-xuangong")
                return notify_fail("�����õ��ڹ��롸������ת���ķ���㣣�\n");

        if( me->query_skill("bitao-xuangong", 1) < 90 )
                return notify_fail("����ڹ���Ϊ���δ������δ����������ת����\n");

        if( me->query("neili") < 600 )
                return notify_fail("�����������������������ʩչ��������ת����\n");
        
        if( me->query_skill("qimen-dunjia", 1) < 120 )
                return notify_fail("������Ŷݼ���Ϊ��������δ����������ת����\n");

        msg = HIG "$N����������ʢ�����»������žŹ����Է�λ��ͷ��ð�����ڰ�����";
        msg += "��������������ӿ֮�������������ѷ��ӵ����£�\n"NOR;
        me->add("neili", -200);
        me->add("jingli", -100);
        
/*
        if( me->is_fighting() ) {
        msg += HIB "$Nһ����Х�����²������Ų�������ǰ�������������з���";
        msg += "���ȶ�Ӱ��˲��ֻ����ʮ����Ӱ������������߲�����\n"NOR;
        }
*/

        extra = (int)me->query_skill("qimen-dunjia",1);
        me->add_temp("apply/dodge", extra/5);
        me->add_temp("apply/dexerity", extra/10);
        me->add_temp("apply/speed", extra/30);

        me->set_temp("wuzhuan", 1);
        me->set_temp("wuzhuan_hit", extra/60 + random(2));

	if(me->query_temp("wuzhuan_hit") > 4)
	me->set_temp("wuzhuan_hit",4);
	
        call_out("remove_effect", extra/3, me, extra);

        message_vision(msg, me);

        return 1;
}

void remove_effect(object me, int extra)
{
        if (!me) return;
        me->add_temp("apply/dodge", -extra/5);
        me->add_temp("apply/dexerity", -extra/10);
        me->add_temp("apply/speed", -extra/30);

        me->delete_temp("wuzhuan_hit");
        me->delete_temp("wuzhuan");
        message_vision(CYN"$Nֻ��������ת���������ò�������������Ϣ���ɡ�\n"NOR,me);
}
