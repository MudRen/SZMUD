//Cracked by Roath
#include <armor.h>

inherit HEAD;

void create()
{
    set_name("��ñ", ({"caomao", "hat"}));
    set_weight(500);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "һ��ũ�ҳ����Ĳ�ñ��\n");
	set("unit", "��");
	set("material", "cloth");
	set("armor_type", "head");
	set("armor_prop/armor", 1);
	set("value", 100);
    }
}
