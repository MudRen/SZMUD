// Code of ShenZhou
// jinchuang-yao.c ��ҩ

#include <ansi.h>

inherit ITEM;

void setup()
{}
int cure_ob(string);
void create()
{

	set_name("��ҩ", ({"jin chuangyao", "jin"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������Ч�����ֽ�ҩ��ר�������˵ȡ�\n");
		set("value", 2000);
                set("no_sell", 1);
		set("no_drop", "�������������뿪�㡣\n");
	}

	set("shaolin",1);
	setup();
}

int cure_ob(object me)
{

	if (me->query("eff_qi") == me->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
	
	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		this_player()->add("eff_qi", -50);
		message_vision(HIR "$N����һЩ��ҩ��ֻ���ؿڷ�����Ż����֫������ԭ���õ�̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
		this_player()->receive_curing("qi", 50);
		message_vision(HIC "$NС������ذ�һ����ҩ�����˿��ϣ�ֻ�����ƴ�Ϊ��ת����ɫ�������ö��ˡ�\n" NOR, me);
	}

	me->apply_condition("bonze_drug", 15);

	destruct(this_object());
	return 1;

}

