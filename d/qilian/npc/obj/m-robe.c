// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(WHT"�ɹ�ս��"NOR, ({"robe", "zhanpao"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "��");
		set("long", "һ���ɹ���ʿ������ս�ۡ�\n");
        set("material", "cloth");
        set("armor_prop/armor", 20);
    }
    setup();
}
