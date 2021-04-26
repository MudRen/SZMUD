// Code of ShenZhou
#include <weapon.h>
#include <ansi.h>
inherit SKILL;
inherit STAFF;

int query_autoload() { return 1; }

void create()
{
	set_name(HIW+BLK"����������"NOR, ({ "lingshe zhang", "staff", "shezhang" }));
		set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
	   set("unit", "��");
	   set("long", HIW BLK"һ�����������ĺ�ɫ���ȣ����Ǹ������ƣ���ͷ���Ÿ��ѿڶ�Ц����ͷ����ͷ����¶������ѩ�׵����ݡ�\n"+
		HIW"��������������С�ߣ���ס���������£�������С������������������ӽ����������ġ�\n"NOR);
		set("value", 5000000);
		set("material", "steel");
		set("wield_msg", HIW"�ȶ˵������������£��������졣\n"NOR);
		set("unwield_msg", HIR"$N�����е�$n"HIR"����������\n"NOR);
		set("poison_applied", 100);
		set("snake_type","����");
		set("snake", 2);
	}
	init_staff(130);
	setup();
}

void init()
{
	add_action("convert","bian");
}

int wield()
{
	object me = environment();
	object ob = this_object();

	if( !wizardp(me) && me->query("id") != "litfish" )
	{
		message_vision(HIR"$N���е�$n"HIR"ͻȻ�����һ������$N��ҧһ�ڣ�\n"NOR, me, ob);
		me->apply_condition("bt_poison", random(100) +
				    me->query_condition("bt_poison"));
		ob->move(environment(me));
		return 0;
	}
	else if (::wield())
	{
		message_vision(HIR"$N���һ��$n"HIR"�������У�����������һ�壬���˲���������\n"NOR, me, ob);
		me->add("neili", -100);
		return 1;
	}
		return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{

	if (random(me->query_skill("lingshe-zhang",1))>30 ) {
	      victim->apply_condition("bt_poison",
				    random(me->query_skill("lingshe-zhang", 1)/2) +
	       victim->query_condition("bt_poison"));
	if (victim->query("poisoner") != me)
		victim->set("poisoner", me);
	}
}

int convert(string arg)
{
	object me = this_player();
	object ob;

	if (arg!="shezhang" && arg!="staff" && arg!="zhang") return 0;
		return notify_fail("�㲻�ܻ�����������Ϊ�ߡ�\n");
}

