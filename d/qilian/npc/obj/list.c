// Code of ShenZhou
// paper.c
inherit ITEM;

void create()
{
        set_name("�������Ҫ������", ({"rysj list", "list"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
        }
}

