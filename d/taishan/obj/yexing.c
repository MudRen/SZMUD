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
                set("armor_prop/armor", 5);
        }
        setup();
	set("armor_prop/dodge", 3);
}

void init()
{
}

