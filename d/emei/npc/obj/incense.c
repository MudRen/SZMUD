// Code of ShenZhou
// incense.c ���
// xbc 97/02/03

inherit ITEM;

void create()
{
        set_name("���",({"incense"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ֦��𣬻�������֦��������\n");
                set("unit", "֦");
                set("value", 0);
        }
        setup();
}

