// u/oytj/obj/zizhu.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(MAG "����" NOR, ({"fugui zhu","zhu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("long","���ǲʺ�Ӻ�Զ�ĵط�Ū���������ӣ��ǳ�Ư����\n");  
                set_weight(30000);
                set("value", 5000000);
                set("unit", "��");
                set("no_get", 1);
                set("no_drop", 1);
        }
        setup();
}
