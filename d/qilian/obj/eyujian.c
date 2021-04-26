// Code of ShenZhou
// Ryu, 12/16/96
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void init()
{
        add_action("do_cut", "cut");
	add_action("do_cut", "jian");
}

void create()
{
        set_name("�����", ({"ezui jian", "jian"}));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѳ����Ĵ��������������ֵ�����״��������һ�����ݣ������������һ����\n");
                set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��������������С�\n");
                set("unwield_msg", "$N�����е�����������¡�\n");
        }
	init_blade(100);
	setup();
}

int do_cut(string arg)
{
        object target;
	object me = this_player();
	object weapon;
//        if( !target ) target = offensive_target(me);

	if (!arg)
        return notify_fail("��Ҫ��ʲô��\n");

	target = present(arg,environment(me));

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ʲ�᣿\n");

        if( !objectp(weapon = target->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip" )
                return notify_fail("ʲ�᣿\n");
	message_vision(HIW "$N���������������$n��" + weapon->name()
			+ "��ȥ��\n" NOR, me, target);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
	message_vision(HIW "ֻ���������꡹��һ����$n���е�" + weapon->name()
                                + "�Ѿ���Ϊ���أ�\n" NOR, me, target);
                        weapon->unequip();
                        weapon->move(environment(target));
                        weapon->set("name", "�ϵ���" + weapon->query("name"));
                        weapon->set("value", 0);
                        weapon->set("weapon_prop", 0);
                        target->reset_action();
        } else {
        message_vision(HIW"����$n������$N����ͼ�����е�����\n" NOR, me, target);
        }

        return 1;
}
