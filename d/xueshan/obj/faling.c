// Code of ShenZhou
// weapon: ����

#include <weapon.h>
 
inherit HAMMER;
 
void create()
{
        set_name("����", ({ "fa ling","fa","ling" }) );           
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");                                
		set("value", 10);
                set("material", "iron");                             
                set("long", "����һ�����壬ҡ���������������졣\n");
		set("wield_msg", "$N��������һ��$n���������\n");
		set("unequip_msg", "$N��$n���������һ����䡣\n");
        }
        init_hammer(1);
	setup();
}
