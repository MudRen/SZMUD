// Code of ShenZhou
// shanshen.c ��ɽ��

inherit ITEM;
#include <ansi.h>
void setup()
{}

int cure_ob(string);
void create()
{
	set_name("��ɽ��", ({"laoshan shen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��մ��ɽ��ĳ�����ɽ�Ρ�\n");
		set("value", 10000);
                set("no_sell", 1);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	if ( (int)me->query_condition("bonze_drug" ) > 0 )
        {
                me->add("eff_jingli", -1);
		me->add("max_jingli", -1);
                message_vision(HIR "$N����һ֧��ɽ�Σ�ֻ����ͷ�ؽ��ᣬ�������ڣ�ԭ����ʳ̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
		destruct(this_object());
	}
	if( random(2) == 1)
	{
	message_vision("$N����һ����ɽ�Σ������������ġ�\n", me);
	destruct(this_object());
	return 1;
	}
	else{
		me->add("eff_jingli", 1);
		me->add("max_jingli", 1);
	message_vision(HIG"$N����һ����ɽ�Σ�ֻ���û���һ����������ð������ !\n" NOR, me);
	}
	me->apply_condition("bonze_drug", 
	this_player()->query_condition("bonze_drug")+30);
	destruct(this_object());
	return 1;
}


