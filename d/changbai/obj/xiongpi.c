// Code of ShenZhou
// xiongpi.c ��Ƥ
// ywz 09/05/1996

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIW "��Ƥ" NOR, ({ "xiongpi", "pi" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 7000);
		set("material", "cloth");
		set("long",
		"����һ��ӱ���������ȡ�µ�Ƥ���������ܹ�������ů��������Ч�Ķ�ܹ�����\n");
		set("wear_msg", HIY "$N����$n���ǣ�ů�ͼ��ˣ�\n" NOR);
		set("remove_msg", HIY "$N����$n�����÷�����ߡ�\n" NOR);
		set("unwear_msg", HIY "$N����$n�����÷�����ߡ�\n" NOR);
		set("armor_prop/armor", 60);
	}
	setup();
}
