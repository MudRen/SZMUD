// Code of ShenZhou
// qianzi


#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("¹��ǥ��", ({ "lugu qianzi", "qianzi" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��¹���Ƴɵ�ǥ�ӣ��������԰Ѳδ�������(wa)����\n");
                set("value", 100);
                set("material", "steel");
        }
        init_sword(5);
        setup();
}

