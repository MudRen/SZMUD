// Code of ShenZhou

#include <ansi.h>
inherit PILL;

void setup()
{}

int cure_ob(string);
void create()
{
	set_name(BLU"��ʯ�񶴵�"NOR, ({"yudong dan", "heishi dan", "dan"}));
	set_weight(50);
	if (clonep())
    	set_default_object(__FILE__);
    else 
    {
		set("unit", "��");
        set("long", "�ںڵ�һ��ҩ�裬�������ۣ�ȴ������ɵ�����ʥҩ��\n");
		set("value", 20000);
		set("medicine", 1);
    }
        setup();
}

int cure_ob(object me)
{
	if (me->query_condition("cool_drug") > 0)
	{
        if (me->query("neili") > 500)
	        me->add("neili", -500);
		else
			me->add("neili",-(me->query("neili")));
        message_vision(BLU"$N����һ�ź�ʯ�񶴵�����������������ӿ����������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        destruct(this_object());
        return 1;
	}
   message_vision(HIM"$N����һ�ź�ʯ�񶴵���ֻ������ͨ�����������ͣ������˶����к�ת��\n"NOR, me);
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
		me->apply_condition("cool_drug", 20);

        if ((((int)me->query_condition("qs_damage")) > 0) && 
(((int)me->query_condition("qs_damage")) < 30))
        me->clear_condition("qs_damage");
  		else
  		
me->apply_condition("qs_damage",(int)me->query_condition("qs_damage")-30);
		destruct(this_object());
   return 1;
}

