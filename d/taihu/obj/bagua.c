// Code of ShenZhou
#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create()
{
        set_name("������", ({ "tie bagua", "bagua" }) );
        set_weight(10000);
	set_color(GRN);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long", "�������Ǵ����������������أ����а���ͼ����\n");
        	set("unit", "ö");
		set("base_unit", "ö");
		set("wield_msg", GRN "$N�ɿڴ����ó�$n��\n" NOR );
		set("unwield_msg", GRN "$N��$n�Żؿڴ��С�\n" NOR );
        	set("value", 1600);
		set("armor_prop/armor", 1);
		set("tanzhi",200);
        }
	set_amount(1);
	init_throwing(170);
        setup();
}
