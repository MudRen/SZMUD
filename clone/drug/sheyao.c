// Code of ShenZhou
#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
   set_name("��ҩ", ({"she yao", "yao"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("value", 200);
                set("no_sell", 1);
   }
   setup();
}


int cure_ob(object me)
{
   message_vision("$N����һ��" + name() + "��\n", me);
   if ((int)me->query_condition("snake_poison") > 7) {
      me->apply_condition("snake_poison", (int)me->query_condition("snake_poison") - 5);
   }

   destruct(this_object());
   return 1;
}
