//Cracked by Roath
#include <ansi.h>
#include <command.h>
inherit ITEM;


void create()
{
        set_name(YEL "����" NOR, ({ "qupu", "pu"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���Ѷ����������ף�������������������ӡ�\n");
                set("value", 1000);
                set("material", "silk");
             }
        setup();
}

