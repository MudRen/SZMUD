// Code of ShenZhou
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me,object target)
{
        if (target != me)
                return notify_fail("ɢ�������˺������ã�\n");

        if (!(me->query_temp("jinzhongzhao")))
                return notify_fail("�㲢û�����ý�ղ������񹦣�\n");
	if( (int)me->query_temp("jingang") ) 
                return notify_fail("���������ý�շ�ħ�������ͨ���޷�ɢȥ��ղ������񹦡�\n");

        if (me->query_skill("hunyuan-yiqi",1) < 100)
                return notify_fail("��Ļ�Ԫһ������Ϊ��򲻹������ڽ�ղ��������޷��������磡\n");
	if (me->query_skill("force",1) < 100)
                return notify_fail("����ڹ���Ϊ��򲻹������ڽ�ղ��������޷��������磡\n");
	if (me->query_skill("buddhism",1) < 100)
                return notify_fail("��������ķ���Ϊ��򲻹������ڽ�ղ��������޷��������磡\n");
        if (me->query("max_neili")<2500
                || me->query("neili") < me->query("max_neili")/10)
                return notify_fail("�����������,�޷�ɢȥ��ղ������񹦣�\n");
        
        message("vision", HIC "\n"+me->query("name")+"˫�ƺ�ʮ��ǿ����Ϣ������һ����������ղ������񹦻���ɢȥ��\n\n" NOR, environment(me), me);
        tell_object(me, HIW "\n��˫�ƺ�ʮ��ǿ����Ϣ����������ɢȥ��\n\n" NOR);

        me->delete_temp("jinzhongzhao");

        me->add("neili", -200);

        return 1;
}