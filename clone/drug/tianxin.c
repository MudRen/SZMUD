// Code of ShenZhou
// tianxin.c ���Ľⶾ��
// xQin 04/01

#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
   set_name(WHT"���Ľⶾ��"NOR, ({"tianxin dan", "jiedu dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("no_sell",1);
      set("no_get",1);
      set("no_drop",1);
      set("unit", "��");
              set("long",
"����һ�ŻҰ�ɫ��ҩ���ɶ���ҩ�����ö��ɣ����䵱�ɵĽⶾ��ҩ��\n�Խ����ǳ������������Ч��\n");

      set("value", 20000);
   }
   setup();
}


int cure_ob(object me)
{
	message_vision("$N����һ��" + name() + "��\n", me);
   
	if ((int)me->query_condition("snake_poison") > 10) {
        me->apply_condition("snake_poison", (int)me->query_condition("snake_poison") - 10);
	}
   	if ((int)me->query_condition("xx_poison") > 10) {
      	me->apply_condition("xx_poison", (int)me->query_condition("xx_poison") - 10);
   	}
   
   	if ((int)me->query_condition("insect_poison") > 10) {
      	me->apply_condition("insect_poison", (int)me->query_condition("insect_poison") - 10);
   	}
   
   	if ((int)me->query_condition("insect_poison") > 10) {
      	me->apply_condition("insect_poison", (int)me->query_condition("insect_poison") - 10);
   	}
   
   	if ((int)me->query_condition("sl_poison") > 10) {
      	me->apply_condition("sl_poison", (int)me->query_condition("sl_poison") - 10);
   	}
   
   	if ((int)me->query_condition("hanbing_poison") > 10) {
      	me->apply_condition("hanbing_poison", (int)me->query_condition("hanbing_poison") - 10);
   	}
   
   	if ((int)me->query_condition("bt_poison") > 10) {
      	me->apply_condition("bt_poison", (int)me->query_condition("bt_poison") - 10);
   	}
   
   	if ((int)me->query_condition("huadu_poison") > 10) {
      	me->apply_condition("huadu_poison", (int)me->query_condition("huadu_poison") - 10);
   	}
   
   	if ((int)me->query_condition("qianzhu-poison") > 5) {
      	me->apply_condition("qianzhu-poison", (int)me->query_condition("qianzhu-poison") - 5);
   	}
   
   	tell_object(me, "��е���һ�������Ե���ӿ����ͷ�������Ѳ�����ǰ�Ĳִ١�\n");
   	destruct(this_object());
   	return 1;
	}
