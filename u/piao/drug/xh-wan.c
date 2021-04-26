// Code of ShenZhou
#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
   set_name("�ۻ���", ({"xionghuang wan", "xionghuang", "wan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("value", 400);
      set("long", "����һ��ؤ�������ܽ�ٶ����ۻ��裬��������ͳ�ҧ֮�˸�����Ч��\n");
      set("medicine", 1);
   }
   setup();
}

int cure_ob(object me)
{
   message_vision("$N����һ��" + name() + "��\n", me);

   if ( !me->query_condition("xx_poison") && !me->query_condition("snake_poison")
   && !me->query_condition("insect_poison") ) {
	me->apply_condition("snake_poison", 10);
	me->apply_condition("insect_poison", 10);
	me->query_condition("xx_poison", 5);
	tell_object(me, HIR "��û�˺��ҷ�ʳ��ҩ�����д󺦣�\n\n" NOR);
	destruct(this_object());
  	return 1;
   }	

   if ( (int)me->query_condition("snake_poison") ) {
      me->apply_condition("snake_poison", (int)me->query_condition("snake_poison") - 10);
      if ( (int)me->query_condition("snake_poison") < 0 ) me->apply_condition("snake_poison", 0);
      me->set_temp("xhwan", 1);
   }

   if ( (int)me->query_condition("insect_poison") ) {
      me->apply_condition("insect_poison", (int)me->query_condition("insect_poison") - 10);
      if ( (int)me->query_condition("insect_poison") < 0 ) me->apply_condition("insect_poison", 0);
      me->set_temp("xhwan", 1);
   }

   if ( (int)me->query_condition("xx_poison") > 100 && !me->query_temp("xhwan") ) {
        return notify_fail("���еĳ����ƶ�̫����ڷ���ҩûʲôЧ�á�\n");
   }
   else {
      me->apply_condition("xx_poison", (int)me->query_condition("xx_poison") - 5);
      if ( (int)me->query_condition("xx_poison") < 0 ) me->apply_condition("xx_poison", 0);
      me->set_temp("xhwan", 1);
   }

   if ( (int)me->query_condition("sl_poison") > 100 && !me->query_temp("xhwan") ) {
        return notify_fail("���еĻ������ƶ�̫����ڷ���ҩûʲôЧ�á�\n");
   }
   else {
      me->apply_condition("sl_poison", (int)me->query_condition("sl_poison") - 5);
      if ( (int)me->query_condition("sl_poison") < 0 ) me->apply_condition("sl_poison", 0);
   }

   message_vision(YEL "$Nֻ�����˴�Ϊ��ת���ɼ��˵���Ч��\n\n" NOR, me);
   
   me->delete_temp("xhwan", 1);
   destruct(this_object());
   return 1;
}