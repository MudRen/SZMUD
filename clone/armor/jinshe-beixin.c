// Code of ShenZhou
// cloth.c ���߱���
// qfy July 6, 1996.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name("���߱���", ({ "jinshe beixin", "jinshe", "beixin" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 100000);
                set("material", "cloth");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/jinshe-beixin.c");
//***** END OF ADDING *****
		set("long",
		"һ���������Ƥ���ġ�Ƥ�����Ͻ���ƬƬ���������⡣�ǽ�����\n"
		"���������µ�����֮����ˮ���֣���ǹ���롣\n");
		set("wear_msg", HIY "$N����$n����â�ܶ��������������ߣ�����Χ��������ֱ�ӡ�\n" NOR);
		set("unequip_msg", HIY "$N����$n��������������Ĵܣ���ɢ���١�\n" NOR);
                set("armor_prop/armor", 270);
        }
        setup();
}
