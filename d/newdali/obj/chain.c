// Code of ShenZhou
// /d/dali/obj/chain.c ���� ��������
// mantian may/16/2001

#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_SSERVER;

void create()
{
	set_name("����", ({ "tie lian","chain" }) );
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("value", 1000);
		set("long", "����һ�����λΣ�������������\n");
		set("material", "steel");
	}
	init_whip(10);
	setup();
}

void init()
{
	add_action("do_arrest","arrest");
}

int do_arrest(string arg)
{
	object me=this_player(), weapon, victim, fighter;

	if (!me->query("dali/employee")) return notify_fail("ʲô��\n");
	if (!arg) return notify_fail("��Ҫ����˭��\n");
	if (environment(me)->query("no_fight")) return notify_fail("���ﲻ׼ս����\n");
	if (!objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tie lian") return notify_fail("����ʲô�ף�\n");
	victim = present(arg,environment(me));
	if (!victim) return notify_fail("���ﲢ�޴��ˣ�\n");
	if (victim == me) return notify_fail("�αض��һ�٣�\n");
	if (userp(victim)) return notify_fail("�㲻��������ҡ�\n");
	if (!living(victim)) return notify_fail("�ⲻ�ǻ��\n");
	if ((int)me->query_temp("marks/arrestee")) return notify_fail("���ϸ�Ҫץ���˻�ûץ������Ҫ�����ˣ�\n");
	if (strsrch(file_name(environment(me)), "/d/dali/") == -1) return notify_fail("���ﲻ�Ǵ����ڣ��ֲ����������£�\n");
	if ((!victim->is_fighting() && !victim->query_temp("robbing") && !victim->query_temp("rapping"))
		|| victim->query_temp("last_opponent") == me->query("id")
		|| victim->query("family/family_name")=="����μ�"
		|| (me->query("family/family_name") != "����μ�" && !me->query("dali/employee")))
		return notify_fail("�˼�û���������ǣ����������ˣ�\n");
	fighter = offensive_target(victim);
	if (fighter == me) return 0;
	if (!victim->is_killing(fighter->query("id"))) return notify_fail("���˷������ߡ�\n");
	if (fighter->query("qi") > victim->query("qi")) return notify_fail("����ֻ�����д��书��\n");
	if (victim->query_temp("robbing")) message_vision(HIW"$N�ȵ����󵨣������ڱ�����ǰ�������ߣ�����ȥ��\n"NOR, me);
	else if (victim->query_temp("rapping")) message_vision(HIW"$N�ȵ����ɶ񣡾����ڴ˵�Ϸ���Ҹ�Ů�����һ�ȥ���٣�\n"NOR, me);
	else message_vision(HIW"$N�ߺ�һ�����������ݵ���Ұ���ߣ����Ҽ���ȥ��\n"NOR, me);
	victim->remove_all_killer();
	fighter->remove_all_killer();
	victim->start_busy(1);
	victim->set_temp("arrestee", 1);
	me->start_busy(1);
	me->set_temp("marks/arrestee", victim->query("name"));
	victim->kill_ob(me);
	me->fight_ob(victim);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( victim->query("combat_exp",1)>50) return HIY "����Ǻ�ॵ���$n�Ĳ�����������ȥ��" NOR;
}
