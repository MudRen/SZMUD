// Code of ShenZhou
// taomu-jian.c
//maco �޸� 26/8/99

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIM"��ľ��"NOR,({ "taomu jian", "taomu", "jian" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "wood");
		set("long", "����һ�������������ֹ��Ƴɵ���ľ�����ƺ�����һ���ñ�����\n");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_sword(3);
	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int exp1, exp2, bonus, gain;
	int int1, int2, age1, age2;
	float gain1, gain2, gain3;
	mapping fam1, fam2;
	object where;
	
	where = environment(me);
	fam1 = (mapping)me->query("family");
	fam2 = (mapping)victim->query("family");	

	if (strsrch(file_name(where), "/d/taohua/") < 0)
		return; 

	if (!fam1 || fam1["family_name"] != "�һ���")
		return;
	if (!fam2 || fam2["family_name"] != "�һ���")
		return;

	if (!userp(victim)) 
		return;

	if ((string)query("owner") != (string)me->query("id"))
		return;


	exp1 = me->query("combat_exp");
	exp2 = victim->query("combat_exp");
	int1 = me->query_int();
	int2 = victim->query_int();
	age1 = me->query("age");
	age2 = victim->query("age");
	
	if (exp1 > exp2) gain1 = (int)(exp1/exp2);
		else gain1 = (int)(exp2/exp1);
	if (gain1 > 2) gain1 = 0;
	if (int1 > int2) gain2 = int1-int2;
		else gain2 = int2-int1;
	if (gain2 > 4) gain2 = 0;
	if (age1 > age2) gain3 = age1/age2;
		else gain3 = age2/age1;
	if (gain3 > 1.2) gain3 = 0.2;
	
	gain = (gain1+gain2)*gain3;
	if (gain > 3) gain = 3;
	gain = gain*(int2+int1)/40+random(2);
	bonus = (int)(gain+damage_bonus/100*gain);

	me->apply_condition("th_gain", me->query_condition("th_gain")+1);
        me->add_temp("exp_gain", (int)bonus);
        victim->add_temp("exp_gain", (int)bonus );
	me->set_temp("partner",victim->name());
	victim->set_temp("partner",me->name());
//	me->add("combat_exp", (int)bonus);
        me->add_temp("pot_gain", (int)bonus );
	victim->add_temp("pot_gain", (int)bonus );
	set_heart_beat(1);
	return;
}
