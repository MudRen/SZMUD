#include <ansi.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit F_EQUIP;
void create()
{
        set_name("��ǹ�ӵ�", ({ "bullet" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("s_name","��ǹ�ӵ�");
        	set("long", "һϻ�ѻ���ǹר�õ��ӵ���\n");
                set("no_sell", "�㲻�ܷ�������\n");        	
        	set("base_unit", "ϻ");
        	set("unit", "��");
        	set("value", 150000);
        	set("shu", 10);
		set("damage", 10000);
		set("armor_type", "embed");
		set("weapon_type", "bullet");
		set("no_sell", 1);
        }
	set_amount(1);
        setup();
}
int wear() { return 0; }
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
