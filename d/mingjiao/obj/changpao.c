// Code of ShenZhou
// cloth: changpao.c


#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("ʥ����", ({ "shenhuo pao", "pao"}));
        set("long", "����һ����ɫ�ĳ��ۣ��۵����½�������һ����ɫ�Ļ��档\n");
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("value", 250);
                set("armor_prop/armor", 10);
        }
        setup();
}
