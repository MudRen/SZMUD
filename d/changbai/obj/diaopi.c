// Code of ShenZhou
// diaopi.c ��Ƥ
// ywz 09/05/1996

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIW "��Ƥ" NOR, ({ "diaopi", "pi" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2500);
		set("material", "cloth");
		set("long",
		"����ɽ�ϵı���������ܹ�������ů��������Ч�Ķ�ܹ�����\n");
		set("wear_msg", HIY "$N����$n���ǣ�ů�ͼ��ˣ�\n" NOR);
		set("remove_msg", HIY "$N����$n�����÷�����ߡ�\n" NOR);
		set("unwear_msg", HIY "$N����$n�����÷�����ߡ�\n" NOR);
		set("armor_prop/armor", 25);
	}
	setup();
}
