// Code of ShenZhou
// hupi.c ��Ƥ
// ywz 09/05/1996

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY "��Ƥ" NOR, ({ "hupi", "pi" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 5000);
		set("material", "cloth");
		set("long",
		"����һ��ӳ��׻�����ȡ�µ�Ƥ���������ܹ�������ů��������Ч�Ķ�ܹ�����\n");
		set("wear_msg", HIY "$N����$n���ǣ�ů�ͼ��ˣ�\n" NOR);
		set("remove_msg", HIY "$N����$n�����÷�����ߡ�\n" NOR);
		set("unwear_msg", HIY "$N����$n�����÷�����ߡ�\n" NOR);
		set("armor_prop/armor", 50);
	}
	setup();
}
