// Code of ShenZhou
// baihu.c �׻�������
// xQin 04/01

#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
   set_name(HIW"�׻�������"NOR, ({"baihu wan", "duoming wan", "wan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("no_sell",1);
      set("no_get",1);
      set("no_drop",1);
      set("unit", "��");
      set("value", 100000);
   }
   setup();
}


int cure_ob(object me)
{
   
	if (me->query_condition("bonze_drug") > 0)
        {
	me->add("max_neili", -1);
	message_vision(HIR"$N����һ��" + name() + HIR"��ֻ�������������ڷ��ڣ�ԭ����ʳҩ����࣬�ʵ��䷴��\n"NOR, me);
	destruct(this_object());
        return 1;
        }
        me->set("eff_jing", (int)me->query("max_jing"));
        me->set("jing", (int)me->query("max_jing"));
        me->set("jingli", (int)me->query("max_jingli"));
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
        me->set("neili", (int)me->query("max_neili"));

   
       message_vision(HIW"$N����һ��" + name() + HIW"��ֻ��һ�������ӵ���������˲���������ȫ�����ع鵤�\n"NOR, me);
       me->apply_condition("bonze_drug", 60);
       destruct(this_object());
       return 1;
}