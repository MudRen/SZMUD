// Code of ShenZhou
// gangzhang.c ����

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("����", ({ "gangzhang", "staff", "zhang" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ�ĸ������ȣ��ɵ������á�\n");
		set("value", 250);
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
  	init_staff(25);
	setup();
}
