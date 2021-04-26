// Code of ShenZhou
//sanhuang-wan.c
//kane 1998.6
// xQin 04/01

#include <ansi.h>
inherit PILL;

void setup()
{}

int cure_ob(string);
void create()
{
	set_name(HIY"���Ʊ�����"NOR, ({"sanhuang wan","wan"}));
	set_weight(50);
	if (clonep())
    	set_default_object(__FILE__);
    else
    {
	set("unit", "��");
	set("no_sell",1);
        set("no_get",1);
        set("no_drop",1);
        set("long",
"һ�ŻƳγε�ҩ�裬��ţ�ơ��ۻơ��ƻ�������Ϊ������������ҩ��\n���ƶ��ɣ����䵱�����ˡ��ƶ�����ҩ���Գ涾����Ч��\n");
		set("value", 1000);
		set("medicine", 1);
    }
        setup();
}

int cure_ob(object me)
{
	if (me->query_condition("hot_drug") > 0)
	{
       	if (me->query("neili") > 500)
	       	me->add("neili", -500);
		else
			me->add("neili",-(me->query("neili")));

		message_vision(BLU"$N����һ��"+query("name")+BLU"�����������������У���������ԭ����ʳ\n̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        destruct(this_object());
        return 1;
	}
   	
	message_vision(HIM"$N����һ��"+query("name")+HIM"��ֻ��ͨ����̩��������������ƴ��к�ת��\n"NOR, me);
	me->receive_heal("qi", 400+random(200));
	me->apply_condition("hot_drug", 15);

	if ((int)me->query_condition("insect_poison") )
	{
	me->apply_condition("insect_poison", 0);
	}
        destruct(this_object());
   	return 1;
}


