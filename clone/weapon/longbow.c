// Code of ShenZhou
// bow.c

#include <ansi.h>
#include <weapon.h>

inherit BOW;

void create()
{
	set_name("����", ({ "long bow", "bow"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50000);
		set("bow_power", 20);
		set("str_requirement", 20);
		set("material", "wood");
		set("long", "����һ����ͨ��ľ�Ƴ�����\n");
		set("wield_msg", "$N�ӱ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ر���\n");
		set("unequip_msg", "$N�����е�$n��ر���\n");
		
	}	
	init_bow(10);
	setup();
}
