// Code of ShenZhou
// oufen.c ź��

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("ź��", ({ "oufen" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ��óԵ�ź��,����̫����\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
        }
    setup();
}

