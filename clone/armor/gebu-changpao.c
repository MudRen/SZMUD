// Code of ShenZhou
// Jay 9/9/96 (Chairman Mao died twenty years ago.:(

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(GRN"�𲼳���"NOR, ({"changpao", "cloth","pao"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "��");
		set("long", "���Ǵָ�֯�ĳ��ۣ�������ȥ�ֲܴڡ�\n");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/gebu-changpao.c");
//***** END OF ADDING *****
        set("material", "cloth");
        set("armor_prop/armor", 15);
	set("value",500);
    }
    setup();
}
