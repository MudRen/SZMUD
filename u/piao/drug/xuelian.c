// Code of ShenZhou
// medicine: xuelian.c
// Jay 3/18/96
// Ryu, 12/5/96
#include <ansi.h>;
inherit ITEM;

void setup()
{}

int cure_ob(string);
void create()
{
        set_name(HIM"ѩ��"NOR, ({"xuelian", "lian", "lotus"}));
	set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��ڴ��һ��ѩ��������������������̱�ѩ�㾧Ө��ף���������м䳤��ϸ˿״���Ϻ�\n"
			    "ɫ�ͳ�ɫ���\n");
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
        message_vision(HIR "$N����һöѩ����ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        destruct(this_object());
        return 1;
        }
   message_vision(HIM"$N����һ֧ѩ����һ������Ƶ����������ķΣ��پ�������ˬ��\n"NOR, me);
	me->set("eff_jing", (int)me->query("max_jing"));
        me->set("jing", (int)me->query("max_jing"));
        me->set("jingli", (int)me->query("max_jingli"));
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
	me->apply_condition("cool_drug", 30);

        if (random(2)==1){ 
	me->add("max_jingli", 1);
	me->add("eff_jingli", 1);
	}

        me->set("neili", (int)me->query("max_neili"));

        if ((int)me->query_condition("snake_poison") > 0) 
        me->apply_condition("snake_poison", 0);
  
        if ((int)me->query_condition("insect_poison") > 0) 
        me->apply_condition("insect_poison", 0);
 
        if ((int)me->query_condition("sl_poison") > 0) 
	me->apply_condition("sl_poison", 0);
   
        if ((int)me->query_condition("xx_poison") > 10 
        && (int)me->query_condition("xx_poison") < 50) 
        me->apply_condition("xx_poison", 0);
  
   destruct(this_object());
   return 1;
}

