// obj /d/wulin/obj/qingjian
// Piao 2001/10/15
inherit ITEM;

void create()
{
        set_name("���", ({"qing jian", "jian"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�����������������\n");
                set("material", "paper");
        }
}

