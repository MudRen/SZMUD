// Code of ShenZhou
// qianzhu-poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
                tell_object(me, "��������������, ������Ȼ�ް��ˣ�\n");
                return 0;
        }
	/*
	if (!living(me)) {
	    me->die();
	    return 0;
	}
	*/
        me->apply_condition("qianzhu-poison", duration - 1);
	tell_object(me, YEL "��ֻ����һ��ͷ��, ��ǰֻ������ʰ�쵵�һƬģ��, ԭ�����е�ǧ�����ַ�����!\n" NOR);
	if (me->query("neili") > duration*duration) {
 	    message_vision(CYN "$N�������ǿ��ѹסǧ�붾������ʱ�о��ö���.\n" NOR, me);
	    me->add("neili", -duration*duration);
	    me->receive_wound("qi", duration);
	    me->receive_wound("jing", duration);
	}else {
 	    message_vision(CYN "$Nһ��ҡ��, ���ᵤ��֮��ȴ�᲻�����������Щˤ��.\n" NOR, me);
	    me->receive_wound("qi", duration*duration/2, "��������");
	    me->receive_wound("jing", duration*duration/2, "��������");
	}
        return 1;
}
