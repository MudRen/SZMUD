// Code of ShenZhou
// Ryu

#include <ansi.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit F_EQUIP;
void create()
{
        set_name("����͸�Ƕ�", ({ "tougu ding", "ding" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long", "һö��Լ�������������\n");
        	set("unit", "��");
		set("base_unit", "ö");
        	set("value", 150);
		set("damage", 8);
		set("armor_type", "embed");
                set("armor_prop/armor",1);
		set("armor_prop/attack", -60);
                set("armor_prop/defense", -60);
                set("armor_prop/unarmed", -60);
		set("no_sell", 1);
		set("unequip_msg", HIR"$Nһҧ����$n���˿��ϰ���������һ����Ѫ�͵�ӿ�˳�����\n"NOR);
        }
	set_amount(15);
        setup();
}
int wear() { return 0; }
int do_embed()
{
	::wear();
	set("no_drop", 1);
	set("no_get", 1);
	environment()->apply_condition("embedded", 100);
	return 1;
}
int unequip()
{
	::unequip();
	set("no_drop", 0);
	set("no_get", 0);
	set("embedded", 0);
	environment()->apply_condition("embedded", 0);
	environment()->receive_damage("qi", 200+random(1000));
	return 1;
}
string query_autoload() 
{ 
	if( query("equipped") )
	return query_amount() + ""; 
}

void autoload(string param)
{
        int amt;

        if( sscanf(param, "%d", amt)==1 )
                set_amount(amt);
	set("embedded", 1);
	set("no_drop", 1);
	set("no_get", 1);
	::wear();
}
