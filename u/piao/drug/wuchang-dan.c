// Code of ShenZhou
// wuchang-dan.c �޳���

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void create()
{
        set_name(HIR "�޳���" NOR, ({"wuchang dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�����һ�������ʥҩ�޳�����\n");
                set("value", 2000);
		set("medicine", 1);
        }
        setup();
}

int cure_ob(object me)
{
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
        {
                this_player()->add("neili", -100);
                message_vision(HIR "$N����һ���޳�����ֻ����ͷ�ؽ��ᣬ�������ڣ�
ԭ����ʳ̫�࣬ҩЧ�ʵ��䷴��\n" NOR, this_player());
                this_player()->apply_condition("bonze_drug",
                this_player()->query_condition("bonze_drug")+10);
		destruct(this_object());
        }
	me->set("eff_qi", (int)me->query("max_qi"));

	message_vision(HIG 
"$N����һ���޳�������ʱ�������㣬�������\n" NOR, me);
	this_player()->apply_condition("bonze_drug",
                this_player()->query_condition("bonze_drug")+10);

	destruct(this_object());
	return 1;
}

