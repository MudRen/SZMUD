// Code of ShenZhou
// tianxiang.c ���������

#include <ansi.h>

inherit ITEM;

void setup()
{}

int cure_ob(string);
void create()
{

	set_name(MAG"���������"NOR, ({"tian xiang", "gao"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�м�Ϊ��Ч�Ķ��Ҷ�����ҩ��ר�������˵ȡ�\n");
		set("value", 500);
		set("medicine", 1);
		set("no_drop", "��˱������ҩ�����˲��»�ȥ��ʦ������");
	}

	set("used", 3);
	set("emei",1);
	setup();
}

int cure_ob(object me)
{
	if (me->query("eff_qi") == me->query("max_qi"))
		return notify_fail("�����ڲ��÷���������ࡣ\n");
	
	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		this_player()->receive_wound("qi", 50, "��ҩ�������ƶ�����");
		message_vision(HIR "$N����һЩ��������ֻ࣬���˿ڷ����񻯣�ԭ����ҩ�������࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else if ( me->query_skill_mapped("force") != "linji-zhuang" ) 
		message_vision(HIC "$N����һЩ��������ֻ࣬�����ò���ԭ���ڹ�������ҩ���в�����\n" NOR, me);
	else
	{
		this_player()->receive_curing("qi", 500);
		message_vision(HIC "$N����һЩ��������ֻ࣬�����ƴ�Ϊ��ת����ɫ�ö��ˡ�\n" NOR, me);
	}

	me->apply_condition("bonze_drug", 15);

	if ( add("used", -1) < 1 ) {
		tell_object(me, "�����������������ˡ�\n");
		destruct(this_object());
	}
	return 1;

}

