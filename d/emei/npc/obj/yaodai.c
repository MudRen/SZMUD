// Code of ShenZhou
// huyao.c

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
		set("value", 20);
		set("material", "waist");
		set("armor_prop/armor", 5);
	}
	setup();
}

int is_container() { return 1; }

int reject(object ob) 
{ 
	if (ob && ob->query("weapon_prop") ) return 0;
	if (sizeof(all_inventory(this_object()))==0) return 0;
	notify_fail("Ƥ�����ٷŲ����κζ����ˡ�\n");
	return 1;
}
