// Code of ShenZhou
// coin.c

#include <ansi.h>
#include <weapon.h>
//inherit MONEY;
inherit THROWING;

void create()
{
	set_name("ͭǮ", ({"coin", "coins", "coin_money" }));
        set_color("$YEL$");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "������ͨ�е�λ��С�Ļ��ң�ԼҪһ����ͭǮ��ֵ��һ��������\n");
		set("unit", "Щ");
		set("base_value", 1);
		set("base_unit", "��");
		set("wield_msg","$N�ͳ�һöͭǮ�������ġ�\n");
       	set("unwield_msg","$N��ͭǮ�Ż�������\n");

		set("base_weight", 1);
//		set("armor_prop/armor", 1);
	}
	set_amount(1);
	init_throwing(3);
	setup();
}

int value() { return query_amount() * (int)query("base_value"); }

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
        int amt;

        if( sscanf(param, "%d", amt)==1 )
                set_amount(amt);
}

