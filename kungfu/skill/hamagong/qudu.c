// Code of ShenZhou
// qudu.c
//�˷��ǵ�����Ϣ�����ͷ�½��ϣ���Ѫ���У������ͻ�ӽ�������֮���س���ֻ������ѧէ����ÿ��ֻ�ܱƳ��������һ�����ϣ���������������
//ԼĪһյ��ʱ�֣���ָ�ϵγ������Ѫ�����ܼ�Ǿ���Ϊ�泩��
//�����꼫�Ǵ�����һ���͸��������ǣ���������ʩΪ����Ȼ��ľ�Լ���������һ������˫����ָ���������κ�֭��

#include <ansi.h>

#include "/kungfu/skill/poison_list.h"

int exert(object me, object target)
{
	string poi_name, poison, poi_color, col_ansi;
	int i, hmg, poi_lvl, neili_cost, hmg_reg;

	hmg = (int)me->query_skill("hamagong", 1);

	if ((int)me->query_skill("hamagong") < 20 )
		return notify_fail("��ĸ�󡹦��Ϊ�������������衣\n");

	if( (int)me->query("max_neili") < 100 )
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

		if(poison == "snake_poison" && hmg > 40)
			poi_lvl = 1;

		if(poison == "xx_poison" && hmg > 60)
			poi_lvl = 2;

		if(poison == "bt_poison" && hmg > 100)
			poi_lvl = 3;  //baituo highhand can cure his menpai's poison easier

		neili_cost = poi_lvl*100;
		hmg_reg = 10+poi_lvl*10;

		if(poi_lvl > 7 )
			return notify_fail(poi_name+"�Ķ��Բ��Ǹ�󡹦����������\n");

		if( (int)me->query("neili") < neili_cost+100 )
			return notify_fail("�����ڵ�������������ʹ��󡹦�Ƴ����϶��ʡ�\n");

		if( hmg < hmg_reg )
			return notify_fail("��ĸ�󡹦��Ϊ�����ܻ���" + poi_name + "��\n");

		message_vision("$Nͷ�½��ϣ�������Ϣ����Ѫ���У�����"+poi_name+"�ӽ�������֮���س���\n", me);

		me->start_busy(poi_lvl);
		call_out("bidu", poi_lvl, me, poi_name, poison, hmg, poi_lvl, neili_cost);

		return 1;
}

int bidu(object me, string poi_name, string poison, int hmg, int poi_lvl, int neili_cost)
{
	int poi_amount, cure_amount, cure, plv;
	plv = (int)me->query_skill("poison", 1);

	if( !me || me->is_ghost() || !living(me) )
		return 0;

	poi_amount = (int)me->query_condition(poison, 1); // how deep I have got poisoned.
	cure_amount = (hmg*hmg)/(20*poi_lvl) + plv; // how deep the poison I can cure.
	cure = hmg/poi_lvl; // once can cure how much.

	me->add("neili", -neili_cost);

	if( poi_amount > cure_amount ) // if I poisoned more than I can cure.
	{
		write("������ʩΪ����������"+poi_name+"̫���������ж�����ľ˿��������\n");
		return 0;
	}
	message_vision("ԼĪһյ��ʱ�֣�$N��ָ�ϵγ������Ѫ�����ܼ�Ǿ���Ϊ�泩��\n", me);

	if( poi_amount < cure ) // if my poison less than once I can cure.
		me->apply_condition(poison, 0);
	else
		me->apply_condition(poison, poi_amount-cure);

	return 1;
}
