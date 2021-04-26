// Code of ShenZhou
//xiapi.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name( "ϼ��" , ({ "xia pi", "xiapi", "cape", "pi" }));
        set_color("$HIR$");
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ��ϼ�������ϵȵ���˿������ɡ�������ڷֱ���������ź��ͼ����
���Խ�����һ��������顣\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 12000);
		set("wear_msg", HIR "$N������ϼ��������ظ��ϴ���ͷ�� ���ߵص�����ͷ��\n" NOR);
		set("unequip_msg", HIM "$N�����ؽ���ϼ������ϼ������˫���������������򸣡�\n" NOR);
		set("armor_prop/armor", 10);
		set("female_only", 1);

	}
	setup();
}
