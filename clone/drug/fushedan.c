// Code of ShenZhou
//  poison: fushedan.c
// Jay 3/18/96

// more work needed to use this object to make poison

inherit ITEM;
int cure_ob(string);

void create()
{
	set_name("���ߵ�", ({"shedan", "dan"}));
        set("unit", "��");
	set("long", "����һֻ��ӨӨ�ĸ��ߵ������Ʊ���ҩ�����ԭ�ϡ�\n");
	set("value", 500);
	set("medicine", 1);
                set("no_sell", 1);
        setup();
}

/*
int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        return notify_fail("����������\n");
}
*/


int cure_ob(object me)
{

   message_vision("$N����һ��" + name() + "��\n", me);
   if ((int)me->query_condition("snake_poison") > 0) {
      me->apply_condition("snake_poison", 0);
   write("ͻȻ������ø������緭������....");
      me->add("qi",-500);
   }

   destruct(this_object());
   return 1;
}
