// Code of ShenZhou
// lupi.c ¹Ƥ
// ywz 09/05/1996

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(YEL "¹Ƥ" NOR, ({ "hupi", "pi" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 3000);
		set("material", "cloth");
		set("long",
		"����һ��Ӷ���Ұ¹����ȡ�µ�Ƥ���������ܹ�������ů��������Ч�Ķ�ܹ�����\n");
		set("wear_msg", HIY "$N����$n���ǣ�ů�ͼ��ˣ�\n" NOR);
		set("remove_msg", HIY "$N����$n�����÷�����ߡ�\n" NOR);
		set("unwear_msg", HIY "$N����$n�����÷�����ߡ�\n" NOR);
		set("armor_prop/armor", 28);
	}
	setup();
}
