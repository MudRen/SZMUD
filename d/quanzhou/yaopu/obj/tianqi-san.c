// Code of ShenZhou
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY "�����赨ɢ" NOR, ({"tianqi san", "san"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "������һ�������赨ɢ���ɽ�綾��\n");
                set("value", 10000);
		set("medicine", 1);
        }

        setup();
}

int cure_ob(object me)
{


   if (me->query_condition("cool_drug") > 0){        
	message_vision(HIR "$N����һ��"+name()+"��ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        destruct(this_object());
        return 1;
   }

   message_vision("$N����һ��" + name() + "��\n", me);


   if ((int)me->query_condition("xx_poison") < 30) {
      me->clear_condition("xx_poison");
   } else if ((int)me->query_condition("xx_poison") >= 30)
	      me->apply_condition("xx_poison", (int)me->query_condition("xx_poison")-5);
   
   if ((int)me->query_condition("snake_poison") > 0) {
      me->clear_condition("snake_poison");
   } 

   if ((int)me->query_condition("insect_poison") > 0) {
      me->clear_condition("insect_poison");
   }

   if ((int)me->query_condition("sl_poison") < 100) {
      me->clear_condition("sl_poison");
   } else if ((int)me->query_condition("sl_poison") >= 100)
              me->apply_condition("sl_poison",(int)me->query_condition("sl_poison")-80);
        
   if ((int)me->query_condition("hsf_poison") < 50) {
      me->clear_condition("hsf_poison");
   } else if ((int)me->query_condition("hsf_poison") >= 50)
              me->apply_condition("hsf_poison",(int)me->query_condition("hsf_poison")-40);

   me->apply_condition("cool_drug", 10);
   destruct(this_object());
   return 1;
}

