// Code of ShenZhou
// regenerate.c

//inherit SSERVER;

int exert(object me, object target)
{
        int n, q;

	if (target != me) 
		return notify_fail("��ֻ�����ڹ��ָ��Լ��ľ�����\n");
	
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������\n");

	if ((int)me->query("jing") >= (int)me->query("eff_jing") )
		return notify_fail("�����ھ�������\n");
	q =  (int)me->query("eff_jing") - (int)me->query("jing");

        n = 60 * q / me->query_skill("force");
         if (n < 20)
                n = 20;
        if ((int)me->query("neili") < n) {
                q = q * (int)me->query("neili") / n;
                n = (int)me->query("neili");
        }

        me->add("neili", -n);
        me->receive_heal("jing", q);

if (environment(me)!=find_object("/d/shaolin/dmyuan2"))         message_vision("$N�������˼����������������ö��ˡ�\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}

