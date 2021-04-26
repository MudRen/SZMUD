// Code of ShenZhou
// yaodai.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name( "Ƥ����", ({ "yao dai", "yaodai" }) );
	set_weight(300);
	set_max_encumbrance(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ��Ƥ�ʵĿ��������в�͸�գ����ԷŸ�������С�\n");
		set("value", 250);
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/yaodai.c");
//***** END OF ADDING *****
		set("material", "leather");
		set("armor_prop/armor", 5);
		set("shaolin",1);
	}
	setup();
}

int is_container() { return 1; }
