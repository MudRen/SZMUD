// Code of ShenZhou
#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
   set_name("����ɢ", ({"qingxin san", "san"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("value", 400);
      set("medicine", 1);
   }
   setup();
}

int cure_ob(object me)
{
   message_vision("$N����һ��" + name() + "��\n", me);
   if ((int)me->query_condition("xx_poison") > 7
   && (int)me->query_condition("xx_poison") < 50) {
      me->apply_condition("xx_poison", (int)me->query_condition("xx_poison") - 7);
   }
   if ((int)me->query_condition("snake_poison") > 7) {
      me->apply_condition("snake_poison", (int)me->query_condition("snake_poison") - 7);
   }
   if ((int)me->query_condition("insect_poison") > 7) {
      me->apply_condition("insect_poison", (int)me->query_condition("insect_poison") - 7);
   }
   if ((int)me->query_condition("xx_poison") > 50)
   tell_object(me, "���е������ƶ�̫����ڷ���ҩûʲôЧ��\n");
   destruct(this_object());
   return 1;
}
