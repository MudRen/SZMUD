// Code of ShenZhou
// nightsuit.c
// cleansword

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ҹ��ˮ��", ({ "shui kao", "night suit", "suit" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "����һ���ڹ�������ҹ��ˮ�������Ϻ�����Ч�Ķ�ܹ�����\n");
                set("unit", "��");
                set("material", "cloth");
		set("value", 200);
                set("armor_prop/armor", 5);
        }
        setup();
}

void init()
{
	add_action("do_wear", "wear");
	add_action("do_remove", "remove");
}

int do_wear(string arg)
{
	if (!arg || (arg != "shui kao" && arg != "night suit" && arg != "suit") ) return 0;
	this_player()->set_temp("apply/dodge", 3);

	return 0;
}

int do_remove(string arg)
{
	if (!arg || (arg != "shui kao" && arg != "night suit" && arg != "suit") ) return 0;
	this_player()->delete_temp("apply/dodge");

	return 0;
}
