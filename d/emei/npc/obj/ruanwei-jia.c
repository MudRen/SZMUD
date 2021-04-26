// Code of ShenZhou
// d/emei/obj/ruanwei-jia.c

#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit ARMOR;

void create()
{
	set_name("��⬼�", ({ "ruanwei jia", "jia" }));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", 
"����һ����⬼ס�\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 7000000);
		set("wear_msg", HIY "$N����һ����⬼ס�\n" NOR);
		set("unequip_msg", HIY "$N����⬼�����������\n" NOR);
		set("armor_prop/armor", 250);
//		set("no_drop", 1);
	}
	setup();
	::create();
}

mixed hit_by(object me, object victim, int damage, object weapon)
{
	string result;
	if ( weapon )
		return damage/3;
	else {
		damage /= 2;
		if (damage > 0)
		    me->receive_wound("qi", damage/2, "����⬼״�����");
		result = "ֻ��$N���һ����æ���֣������ѱ���⬼״̵���Ѫ���졣\n";
		result+= "( $N"+ COMBAT_D->eff_status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
		return ([ "result": result, "damage": damage+random(damage) ]);
	}
}
		

			
