//Cracked by Roath

// junfu.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("����", ({ "junfu", "cloth" }));
        set_color("$HIW$");
        set("long", "����һ�������־�����ͳһ�ľ�����\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("value", 0);
                set("armor_prop/armor", 15);
        }
        setup();
}
