// Code of ShenZhou
// medicine: xuelian.c
// Jay 3/18/96
// Ryu, 12/5/96

inherit ITEM;

void setup()
{}

int cure_ob(string);
void create()
{
        set_name("ѩ��", ({"xuelian", "lian", "lotus"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", "����һֻ֧���ں���ĵط�����������ѩ����\n");
                set("value", 10000);
		set("medicine", 1);
        }
        setup();
}

int cure_ob(object me)
{
   message_vision("$N����һ֧" + name() + "��\n", me);
   if ((int)me->query_condition("snake_poison") > 0) {
      me->apply_condition("snake_poison", 0);
   }
   if ((int)me->query_condition("insect_poison") > 0) {
      me->apply_condition("insect_poison", 0);
   }
   if ((int)me->query_condition("sl_poison") > 0) {
	me->apply_condition("sl_poison", 0);
   }
   if ((int)me->query_condition("xx_poison") > 10 
   && (int)me->query_condition("xx_poison") < 50) {
      me->apply_condition("xx_poison", (int)me->query_condition("xx_poison") - 10);
   }
   if ((int)me->query_condition("xx_poison") > 50)
   tell_object(me, "���е������ƶ�̫����ڷ�����ûʲôЧ��\n");
   destruct(this_object());
   return 1;
}

