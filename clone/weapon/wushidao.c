// Code of ShenZhou
// wushidao.c ��ʿ��

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("��ʿ��", ({ "wushi dao", "dao", "blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 300);
		set("material", "steel");
		set("long", "����һ���ձ����˳��õ���ʿ���������޳����������Σ��пڼ�Ϊ������\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	init_blade(30);
	setup();
}
