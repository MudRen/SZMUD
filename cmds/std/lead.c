// Code of ShenZhou
//lead.c ����
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object victim;
	string comm;

		  if (!arg) return notify_fail("��Ҫ��˭�������ߣ�\n");

		  if ( arg == me->query("id") ) return notify_fail("��Ҫ�Լ������Լ���������\n");

	victim = present(arg, environment(me));
		  if (!victim) return notify_fail("���ﲢ�޴��ˣ�\n");
		  if (!living(victim)) return notify_fail("�ⲻ�ǻ��\n");

	 if (victim->query("no_get", 1))
					 return notify_fail("������첻�ߣ�\n");

	if ( !me->query("env/invisibility") ){

	if ( !userp(victim) && victim->query("sjsz/team_name") && victim->query("sjsz/team_name") == me->query("sjsz/team_name") ){
		message_vision("\n$N����$n˵�����������߰ɣ��Ҵ���ȥ���ط���\n",me, victim);
		message_vision("$N���˿�$n��ʹ���˵�����ðɣ�\n\n",victim, me, );
		victim->set_leader(me);
		return 1;
	}

    if( victim->query_condition("xs_necromancy") < 0 || !victim->query_temp("block_msg/all", 1) 
                || (me->query("id") != victim->query("xueshan/necromancy_singer")) ) {
//	if ( !victim->query_temp("cursed", 1) || !victim->query_temp("block_msg/all", 1)){
	message_vision("\n$N����$n˵�����������߰ɣ��Ҵ���ȥ���ط���\n\n",me, victim);
	tell_object(victim, YEL "�����Ը�����" + me->query("name") +"�ߣ�������� follow " + me->query("id") +"��ָ�\n" NOR);
					 write(YEL "�����ȶԷ�ͬ��������ŶԷ��ߡ�\n" NOR);
					 return 1;
	}
	if (me->query_skill("necromancy", 1) < 45)
		return notify_fail("��Ľ�������򲻹���\n");

	message_vision(HIR "$N��Ц��������$nһ�С�\n" NOR, me, victim);
	tell_object(victim,"�����Ժ����о���"+me->name()+"��������ˣ���ø�������\n");

	victim->set_leader(me);
	return 1;
	}
}
