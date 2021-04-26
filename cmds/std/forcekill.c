// Code of ShenZhou
// forcekill.c 
inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string arg)
{
	object target, victim, dummy;
	string name1, name2;

	if (!arg) return notify_fail("��Ҫ����˭ɱ˭��\n");

        if( sscanf(arg, "%s with %s", name2, name1) != 2 ) return notify_fail("ָ�����\n");

	if ( name1 == name2 ) return notify_fail("��Ҫ�����Լ�ɱ�Լ����㷢ʲô�񾭰���\n");
	if ( name1 == me->query("id") ) return notify_fail("�αض��һ�٣�\n");
	if ( name2 == me->query("id") ) return notify_fail("�������ҪѰ��Ҳ��������鷳��\n");

	target = present(name1, environment(me));
        if (!target) return notify_fail("���ﲢ�޴�Ŀ�꣡\n");
	if (!living(target)) return notify_fail("��Ŀ�겻�ǻ��\n");
	if ( userp(target)) return notify_fail("����Ȼ�����˲���������������\n");

	victim = present(name2, environment(me));
        if (!victim) return notify_fail("���ﲢ������ɱ��Ŀ�꣡\n");
	if (!living(victim)) return notify_fail("����ɱ��Ŀ�겻�ǻ��\n");

	if (!wizardp(me) && (wizardp(target) || wizardp(victim))) return notify_fail("�󵨣�����ı����ʦ��\n");

    if( target->query_condition("xs_necromancy") < 0 || !target->query_temp("block_msg/all", 1) 
                || (me->query("id") != target->query("xueshan/necromancy_singer")) )
//	if (!target->query_temp("cursed", 1) || !target->query_temp("block_msg/all", 1))
		return notify_fail("�㲻����ô�ɣ�\n");

	if (me->query_skill("necromancy", 1) < 90)
		return notify_fail("��Ľ�������򲻹���\n");

	if ( !me->query("env/invisibility") )   
		message_vision(HIR "$N��Ц�ж���$n���˼������䣬������ָ��ָ"+victim->name()+"��\n", me, target);
	message("vision", HIR "ֻ��"+target->name()+"ʧ�������Ƶ���"+victim->name()+"�������ҵĹ����������������أ�\n" NOR, environment(target), ({target}));
	tell_object(target,"�������Ժ���������������"+victim->name()+"�������ҵĹ����������������أ�\n");

	target->kill_ob(victim);

	return 1;
}
