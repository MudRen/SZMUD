// Code of ShenZhou
// tonggu.c
//

inherit ITEM;

void create()
{
        set_name("ͭ��", ({ "tonggu" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
		set("material", "iron");
                set("long", "����һֻ���������ͭ�ġ�\n");
                set("value", 10);
        }
        setup();
}
