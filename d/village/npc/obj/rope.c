// Code of ShenZhou
// paper.c
inherit ITEM;

void create()
{
        set_name("����", ({"sheng zi", "sheng", "rope" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���м�ʮ�ɳ���������\n");
                set("material", "cloth");
		set("value", 200);
        }
}

