//����(Yujiang wan)
//abian(��ң��)2001/8/
//last update by April 2001.09.26

#include <ansi.h>

inherit ITEM;

int cure_ob(string);
void init();

void create()
{
	set_name(HIY "����" NOR, ({"Yujiang wan", "Yujiang", "wan"}));
    set_weight(25);
    if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 60000);
        set("medicine", 1);
	}

    setup();
}

int cure_ob(object me)
{
//	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
//	me->set("eff_qi", (int)me->query("max_qi"));
//	me->set("qi", (int)me->query("max_qi"));
	if (me->query_condition("yf_zhen_poison") > 0)
        me->apply_condition("yf_zhen_poison", me->query_condition("yf_zhen_poison") - 100);
	message_vision(HIY "$N������һ�����裬������ǳ��ĸ���ʵ���Ǻóԡ�\n"NOR
		+HIY"��о����ڵķ䶾��������ȥ��\n" NOR, me);

	destruct(this_object());
	return 1;
}
