// Code of ShenZhou
// wsky 4/7/00

#include <ansi.h>
#include <weapon.h>

inherit ITEM;

void create()
{
        set_name("����", ({ "du dan", "dan"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR"һ���Ⱥ���Ѫ�ĵ��衣\n"NOR);
                set("material", "stone");
        }
        setup();
}

