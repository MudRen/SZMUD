// Code of ShenZhou
// cloth: changpao.c
// Jay 3/17/96

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("��˹����", ({ "bosi robe", "robe"}));
        set("long", "����һ��������Ĳ�˹���ۡ�\n");
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/changpao.c");
//***** END OF ADDING *****
                set("value", 300);
                set("armor_prop/armor", 6);
        }
        setup();
}

