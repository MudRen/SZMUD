// Code of ShenZhou
inherit ITEM;

void create()
{
        set_name("����", ({"touzi", "dice"}));
        set_weight(400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","����һ�Ź���Ǧ�����ӡ�\n");
                set("unit", "��");
                set("value",1000);
        }
}

