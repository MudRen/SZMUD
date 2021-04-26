// Code of ShenZhou
// heji.c �������澭���޷������ϻ���
// xQin 8/99
/*
Ⱥ�������Ѽ�ʶ������޵���������������������ͬʱ�õ���
һ��һ�̣�һ��һ�գ����������Ȼ����ı��С�
*/

#include <ansi.h>

int perform(object me)
{
	object *inv, weapon1, weapon2;
	string short;
	int i;

	if( me->query_temp("secondary_weapon") )
		return notify_fail("���Ѿ�װ�����������ˡ�\n");

	inv = all_inventory(me);
	for( i=0; i < sizeof(inv); i++ )
	{
		short = inv[i]->query("id");
		if( (short == "bishou" || short == "duanjian" || short == "yuchang jian"
			|| inv[i]->query("name") == "�̵�" || short == "yang dao")
			&& mapp(inv[i]->query("weapon_prop")) )
		{
			weapon2 = inv[i];
			break;
		}
	}

        if( !(weapon1 = me->query_temp("weapon")) || weapon1->query("skill_type") != "whip"
		|| !objectp(weapon2) )
		return notify_fail("�����ϲ��޳��ֵı������޷����С��ϻ�����\n");

	if( (int)me->query_skill("whip") < 350 )
		return notify_fail("��ı޷�������죬�в����������似���С��ϻ�����\n");

	message_vision(HIC"$N����һ����"+ weapon1->name() +
	HIC"��ʱ���ʮ������СС��Ȧ�ӣ��ÿ��Ѽ������ַ��������������¶����һ"+ 
	weapon2->query("unit") + weapon2->name() +HIC"��\n"NOR, me);

	weapon2->set("flag", 2);
	weapon2->wield();
	weapon2->delete("flag");

	return 1;
}
