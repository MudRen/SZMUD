// Code of ShenZhou
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("�ֲ�", ({ "gang chan", "chan" }));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ִ���Ĳ��ӣ���ʽ�ͷ��ŵ����õķ������࣬Ψ����ͷ�Ϻ�϶�������������\n");
		set("value", 350);
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n����������\n");
	}
	init_staff(25);
	setup();
}

