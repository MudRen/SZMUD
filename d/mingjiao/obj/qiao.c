// Code of ShenZhou
inherit ITEM;


void create()
{
        set_name("����", ({ "tie qiao", "qiao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ������ͨͨ�����£��������������ۡ�\n"
);
                set("unit", "��");
		set("no_get", 1);
		set("no_drop", 1);


        }

}
