//���鵤(Jueqing-dan)
//�ڱ�(Blacko)2001/8/
// update by jiuer -9/18/2001

#include <ansi.h>

inherit ITEM;

int cure_ob(string);
void init();

void create()
{
	set_name(BLU"���鵤"NOR, ({"jueqing dan", "jueqing", "dan"}));
	set_weight(50);
	if (clonep())
    	set_default_object(__FILE__);
    else 
    {
		set("unit", "ö");
        set("long", "һö���ķ������Ӱ�ĵ�ҩ��ɫ����ڣ��ȳ��̱ǡ�\n");
		set("value", 30000);
		set("medicine", 1);
                set("no_sell", 1);
    }
        setup();
}

int cure_ob(object me)
{
/*	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
*/
	
	if (me->query_condition("qh_poison") > 10)
	me->apply_condition("qh_poison", 0);
	message_vision(HIG "$N����һö���鵤����̼���һ������ֱ͸���\n" NOR, me);

	destruct(this_object());
	return 1;
}
