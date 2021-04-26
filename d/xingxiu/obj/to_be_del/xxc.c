// Code of ShenZhou
int do_dz(string arg);
int exercising(object me);
int halt_exercise(object me);

void init()
{
	object me=this_player();
	if(me->query("futou_bang/sacrifice")>=35){
        	add_action("do_dz", "dazuo");
        }
}	

int do_dz(string arg)
{
	string force;
	mapping msg;
	int exercise_cost, max;
	object where, me;

	me=this_player();
	max = (int)me->query("max_neili");
	seteuid(getuid());
	where = environment(me);
	
	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
    	
    	if (me->is_exert()) return notify_fail("������ʹ��"+me->query_exert()+"��\n");

	if( me->is_fighting() )
		return notify_fail("ս���в������ڹ������߻���ħ��\n");

	if (where->query("sleep_room"))
		return notify_fail("���Ҳ��ܴ�������Ӱ�������Ϣ��\n");

        if (where->query("no_fight"))
                return notify_fail("���ﲻ׼ս����Ҳ��׼������\n");

        if( !(force = me->query_skill_mapped("force")) )
		return notify_fail("��������� enable ѡ����Ҫ�õ������ڹ���\n");

	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("��Ҫ��������������\n");
	if (exercise_cost < 10)
		return notify_fail("���޷�������Ϣ���е���˾�ϸ�ĳ̶ȣ�\n");

	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("��û����ô�������������Ϣ����ȫ������\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("�����ھ��������޷�������Ϣ��������\n");

	msg = SKILL_D(force)->exercise_msg(me);
	if (!msg || undefinedp(msg["start_my_msg"]))
		write("�������������ù���һ����Ϣ��ʼ������������\n");
	else
		write(msg["start_my_msg"]);

	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
	if (!msg || undefinedp(msg["start_other_msg"]))
		tell_room(environment(me),
			me->name() + "��ϥ���£���ʼ�˹�������\n", ({ me }));
	else
		tell_room(environment(me),
			msg["start_other_msg"], ({ me }));
	me->start_busy((: exercising :), (:halt_exercise:));
	return 1;
}

int exercising(object me)
{
	string force;
	mapping msg;
	int exercise_cost = (int)me->query_temp("exercise_cost");
	int neili_gain = 1 + (int)me->query_skill("force") / 5
		* (1 + (int)me->query_skill("force") / 50);    
		
        int max = me->query_skill("force")*8 + me->query("combat_exp")/1000;

	if (neili_gain > exercise_cost) neili_gain = exercise_cost;
	me->receive_damage("qi", neili_gain/5);
	me->add("neili", neili_gain);
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);

	force = me->query_skill_mapped("force");
	if (force) msg = SKILL_D(force)->exercise_msg(me);
	if (exercise_cost > 0) {
		if (msg && !undefinedp(msg["exec_my_msg"]))
			tell_object(me, msg["exec_my_msg"]);
		if (!random(3) && msg && !undefinedp(msg["exec_other_msg"]))
			tell_room(environment(me), msg["exec_other_msg"], ({me}));
		return 1;
	}

	me->delete_temp("pending/exercise");
	if (!msg || undefinedp(msg["end_my_msg"]))
		tell_object(me, "���˹���ϣ��������˿�����վ��������\n");
	else
		tell_object(me, msg["end_my_msg"]);
	if (!msg || undefinedp(msg["end_other_msg"]))
		tell_room(environment(me),
			me->name()+"�˹���ϣ��������˿�����վ��������\n", ({me}));
	else
		tell_room(environment(me),
			msg["end_other_msg"], ({me}));

	if (me->query("neili") < me->query("max_neili") * 2)
		return 0;
	if (me->query("max_neili") >= max){
		tell_object(me, "���������Ϊ�Ѿ��޷��������������ˡ�\n");
		me->set("neili", me->query("max_neili") * 2);
		return 0;
	        }
	me->set("neili", me->add("max_neili", 1));
	tell_object(me, "������������ˣ�\n");
	return 0;
}

int halt_exercise(object me)
{
	string force;
	mapping msg;

	if (me->query("neili") > me->query("max_neili") * 2)
		me->set("neili", me->query("max_neili") * 2);
	me->delete_temp("pending/exercise");
	force = me->query_skill_mapped("force");
	if (force) msg = SKILL_D(force)->exercise_msg(me);
	if (!msg || undefinedp(msg["halt_msg"]))
		message_vision(
			"$N���������е�����ǿ��ѹ�ص��վ��������\n", me);
	else
		message_vision(msg["halt_msg"], me);
	return 1;
}