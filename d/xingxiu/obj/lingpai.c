// Code of ShenZhou
// lingpai
// wsky 4/7/00

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("����", ({ "ling pai", "ling", "pai" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������������а�̵����ơ�\n"NOR);
                set("material", "stone");
        }
        setup();
}

