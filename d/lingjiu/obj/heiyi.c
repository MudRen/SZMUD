//qingyi.c
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("����", ({"hei yi", "cloth","yi"}) );
    set_weight(2000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	set("unit", "��");
		set("long", "����һ�����Ƶĺ��£���������һֻ���ա�\n");
	set("material", "cloth");
	set("armor_prop/armor", 10);
        set("value",100);
    }
    setup();
}
