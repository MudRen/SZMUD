// Code of ShenZhou
// huxindan.c �������ĵ�
// xQin 04/01

#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
   set_name(RED"�������ĵ�"NOR, ({"huxin dan", "tianwang dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("no_sell",1);
      set("no_get",1);
      set("no_drop",1);
      set("unit", "��");
      set("value", 20000);
   }
   setup();
}


int cure_ob(object me)
{
   
   if (me->query_condition("hot_drug") > 0)
   {
   me->add("max_neili", -1);
   message_vision(HIR"$N����һ��" + name() + HIR"��ֻ�������������ڽ�ʹ��ԭ����ʳҩ����࣬�ʵ��䷴��\n"NOR, me);
   destruct(this_object());
   return 1;
   }
   me->set("eff_jing", (int)me->query("max_jing"));
   me->set("jing", (int)me->query("max_jing"));
   me->set("eff_qi", (int)me->query("max_qi"));
   me->set("qi", (int)me->query("max_qi"));

   
   message_vision(HIG"$N����һ��" + name() + HIG"��ֻ��ȫ����̩�������Ѵ��к�ת��\n"NOR, me);
   me->apply_condition("hot_drug", 20);
   destruct(this_object());
   return 1;
}