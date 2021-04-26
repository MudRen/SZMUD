// Code of ShenZhou
// yulu-wan.c �Ż���¶��

#include <ansi.h>

inherit PILL;

void create()
{
	set_name(GRN "�Ż���¶��" NOR, ({"yulu wan", "wan"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���Ż���¶�裬����һ����������Ƣ��������\n");
		set("no_drop","�Ż���¶��������ף��������ӣ� \n");
		set("value", 10000);
		set("medicine", 1);
	}

	setup();
}

int cure_ob(object me)
{
	if (me->query_condition("cool_drug") > 0){
        me->add("max_neili", -1);
        message_vision(HIR "$N����һ���Ż���¶�裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        destruct(this_object());
        return 1;
        }
	me->set("eff_jing", (int)me->query("max_jing"));
	me->add("jing", 200);
	me->add("jingli", 200);
	me->set("eff_qi", (int)me->query("max_qi"));
	me->add("qi", 200);
//	if (random(3)==1) me->add("max_neili", 3);
//	me->set("neili", (int)me->query("max_neili"));
        
	message_vision(HIG 
"$N����һ���Ż���¶�裬һ������֮��ֱ͸���ֻ���þ���������Ѫ��ӯ����������ԴԴ��������ƣ��һɨ����! \n" NOR, me);

	me->apply_condition("cool_drug", 30);
	destruct(this_object());
	return 1;
}

void init()
{
        add_action("do_pour", "drop");
}

int effect_in_liquid(object ob)
{
	tell_object(this_player(),GRN"��ֻ������������ԴԴ�������������ơ�\n"NOR);
        this_player()->add("neili", random(100)+100);
        return 0;
}
