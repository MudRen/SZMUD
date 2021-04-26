// Code of ShenZhou
//lingzhi.c

#include <ansi.h>

inherit ITEM;

int cure_ob(string);
void init();

void create()
{
        set_name(HIW "��֥" NOR, ({"ling zhi", "zhi"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
                set("long", HIW"����һö��֥����Լ�Ĵ磬��ɡ״��ͨ�徧�ס�\n"NOR);
		set("value", 2000);
		set("medicine", 1);
	}

	setup();
}

int cure_ob(object me)
{
	if (me->query_condition("cool_drug") > 0){
        me->add("max_jingli", -1);
        me->add("eff_jingli", -1);
        message_vision(HIR "$N����һö��֥��ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        destruct(this_object());
        return 1;
        }
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("jingli", (int)me->query("max_jingli"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("neili", (int)me->query("max_neili"));
        
	message_vision(HIG "$N����һö��֥��ֻ���þ���������Ѫ��ӯ����������ԴԴ�������������ٸе������ɿ�! \n" NOR, me);

	me->apply_condition("cool_drug", 30);
	destruct(this_object());
	return 1;
}
