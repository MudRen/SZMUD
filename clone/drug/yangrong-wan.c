// Code of ShenZhou
//yangrong-wan.c �˲�������
//kane 1998.6
#include <ansi.h>
inherit PILL;

void setup()
{}

int cure_ob(string);
void create()
{
	set_name(HIW"�˲�������"NOR, ({"yangrong wan","wan"}));
	set_weight(50);
	if (clonep())
    	set_default_object(__FILE__);
    else
    {
		set("unit", "��");
        set("long",
"һ�Ž�׹����ҩ�裬���˲εȴ�ҩ�����ƶ��ɣ������������飬\n��Ԫ�̱���������֮�˸��е���֮Ч��\n");
		set("value", 10000);
		set("medicine", 1);
                set("no_sell", 1);
    }
        setup();
}

int cure_ob(object me)
{
	if (me->query_condition("hot_drug") > 0)
	{
	        if (me->query("jingli") > 500)
		        me->add("jingli", -500);
		else
			me->add("jingli",-(me->query("jingli")));

		message_vision(BLU"$N����һ��"+query("name")+BLU"�������ؿ����ƣ���֫������ԭ����ʳ̫��\n̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        	destruct(this_object());
        	return 1;
	}
   	
	message_vision(HIW"$N����һ��"+query("name")+HIW"��ֻ��ȫ��ů���ڵģ�˵���������ã�����\n��Ȼ������\n"NOR, me);
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
    	me->set("jingli", (int)me->query("max_jingli"));
    	me->set("eff_qi", (int)me->query("max_qi"));
    	me->set("qi", (int)me->query("max_qi"));
	me->apply_condition("hot_drug",10);
        destruct(this_object());
	return 1;		
}


