// Code of ShenZhou
// baixian-wan.c ������
// ywz 08/31/96

#include <ansi.h>

inherit ITEM;

int cure_ob(string);
void create()
{
	set_name(HIW "������" NOR, ({"baixian-wan", "wan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long", "����һ�������裬����ȥ�������ģ���͸�����⣬��֪�����˻�...\n");
		set("medicine", 1);
		set("value", 10000);
        }

        setup();
}

int cure_ob(object me)
{
	message_vision(HIG "$N����һ�������裬ֻ����������Ѫ���ڣ���...���Դ�ҩ��!!! \n" NOR, me);

//	me->set("eff_jing", (int)me->query("min_jing"));
	me->set("jing", (int)me->query("min_jing"));
//	me->set("eff_qi", (int)me->query("min_qi"));
	me->set("qi", (int)me->query("min_qi"));
//	me->set("neili", (int)me->query("max_neili"));

        destruct(this_object());
        return 1;
}
