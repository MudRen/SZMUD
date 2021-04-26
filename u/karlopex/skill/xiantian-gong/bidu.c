// Code of ShenZhou
//bidu.c ȫ��̱ƶ����� 
// changed by maco

#include "/kungfu/skill/poison_list.h"

int exert(object me, object target)
{
	string poi_name, poison, poi_color, col_ansi;
	int i, xtg, poi_lvl, neili_cost, xtg_reg;

	xtg = (int)me->query_skill("xiantian-gong", 1);

	if ((int)me->query_skill("xiantian-gong",1) < 100)
		return notify_fail("������칦��Ϊ�������ƶ����衣\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("����ڹ���Ϊ�����ƶ����衣\n");

	if( me->is_fighting() )
		return notify_fail("���޷���ս�����˹��ƶ���\n");


		for( i=0; i < sizeof(poison_list); i++ )
			if( me->query_condition(poison_list[i]["poison"]) > 0 )
			{
				poison = poison_list[i]["poison"];
				poi_name = poison_list[i]["name"];
				poi_color = poison_list[i]["color"];
				col_ansi = poison_list[i]["ansi"];
				poi_lvl = poison_list[i]["lvl"];
				break;
			}

		if( poi_lvl == 0 )
			return notify_fail("�㲢δ�ж���\n");

		neili_cost = poi_lvl*100;
		xtg_reg = 100+poi_lvl*10;

		if( (int)me->query("neili") < neili_cost+200 )
			return notify_fail("�����ڵ�������������ʹ���칦�Ƴ����϶��ʡ�\n");

		if( xtg < xtg_reg )
			return notify_fail("������칦��Ϊ�����ܻ���" + poi_name + "��\n");

		me->set("jiali", 0);
		//$N����ˮ���ڣ���ˮֱ����ͷ����
		//ֻ������һ��Ŀ��������������������һ�ٷ�����һ����ˮ��������ɺ�ɫ������ɫȴҲ�Ը�����
		message_vision("$N��ϥ���£��������칦����������ס" + col_ansi  + poi_name + NOR"���У�ͷ��һ���������������ϣ���������һ�㡣\n", me);

		me->start_busy(poi_lvl);
		call_out("bidu", poi_lvl, me, poi_name, poison, xtg, poi_lvl, neili_cost);

		return 1;
}

int bidu(object me, string poi_name, string poison, int xtg, int poi_lvl, int neili_cost)
{
	int poi_amount, cure_amount, cure;

	if( !me || me->is_ghost() || !living(me) )
		return 0;

	poi_amount = (int)me->query_condition(poison, 1); // how deep I have got poisoned.
	cure_amount = (xtg*xtg)/(50*poi_lvl); // how deep the poison I can cure.
	cure = xtg/poi_lvl; // once can cure how much.

	me->add("neili", -neili_cost);

	if( poi_amount > cure_amount ) // if I poisoned more than I can cure.
	{
		write("���˹�һ�����������ƣ��û�ϵ�����" + poi_name + "�����������Ȼ��֮������\n");
		return 0;
	}
	message_vision("$N��Ŀ��������������������һ�ٷ�������ɫ�Ը�����\n", me);
//����һ���������ҳ�������һ����ˮ����������Ȼ����ˮ���ֽ���������ڡ���ʱ��֪�������ڹ��Ƴ����϶��ʣ�����ˮ�����������ĸ���ˮ��ˮ�в��޺�ɫ������һЦ������û�����������Ÿ��أ����˳���
//	me->add("max_neili", -1);
	if( poi_amount < cure ) // if my poison less than once I can cure.
		me->apply_condition(poison, 0);
	else
		me->apply_condition(poison, poi_amount-cure);

	return 1;
}
