// Code of ShenZhou
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY "ͨϬ������" NOR, ({"dilong wan", "wan"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�Ÿ뵰��С�Ļ�ɫԲ����ɫ�������������ۡ�\n");
                set("value", 10000);
		set("medicine", 1);
        }

        setup();
}

int cure_ob(object me)
{

   message_vision("$N����һ��" + name() + "��\n", me);


   if ((int)me->query_condition("xx_poison") > 0) {
      me->clear_condition("xx_poison");
   } 
   
   if ((int)me->query_condition("snake_poison") > 0) {
      me->clear_condition("snake_poison");
   } 

   if ((int)me->query_condition("insect_poison") > 0) {
      me->clear_condition("insect_poison");
   }

   if ((int)me->query_condition("sl_poison") > 0) {
      me->clear_condition("sl_poison");
   } 
        
   if ((int)me->query_condition("hsf_poison") > 0) {
      me->clear_condition("hsf_poison");
   } 

   destruct(this_object());
   return 1;
}

