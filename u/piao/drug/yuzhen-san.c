// Code of ShenZhou
//yuzhen-san.c
//kane 1998.5
#include <ansi.h>
inherit PILL;

void setup()
{}

int cure_ob(string);
void create()
{
	set_name(HIC"����ɢ"NOR, ({"yuzhen san", "san"}));
	set_weight(80);
	if (clonep())
    	set_default_object(__FILE__);
    else 
    {
		set("unit", "��");
        set("long", "����ɢ�ǻ�ɽ�ɵ�������ҩ���ɽ���ϼ������ɵ��ˡ�\n");
		set("value", 500);
		set("medicine", 1);
    }
        setup();
}

int cure_ob(object me)
{
	if (me->query_condition("hot_drug") > 0)
	{
        me->add("qi", -300);
        message_vision(BLU"$N����һ������ɢ�������ؿ��ƶ��ѵ��������ش���ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        destruct(this_object());
        return 1;
	}
	
   
	message_vision(HIY"$N����һ������ɢ��ֻ������̩ͨ�����ƴ���ת��\n"NOR, me);

	me->receive_curing("qi",500);	    
	me->apply_condition("hot_drug", 15);

        if ((((int)me->query_condition("hyz_damage")) > 0) && 
(((int)me->query_condition("hyz_damage")) < 30))
        	me->apply_condition("hyz_damage",0);
	else
  		
me->apply_condition("hyz_damage",(int)me->query_condition("hyz_damage")-30);
	destruct(this_object());
   return 1;
}

