// Code of ShenZhou
// pink_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�ۺ����", ({ "pink cloth", "cloth" }) );
        set_color("$MAG$");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����ۺ�ɫ�ĳ����������ż�ֻ��ȵ������������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 300);
		set("material", "cloth");
		set("armor_prop/armor", 1);
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/pink_cloth.c");
//***** END OF ADDING *****
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

