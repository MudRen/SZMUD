//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("����", ({"liang mian", "mian"}));
    set_weight(100);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "һ�����棬��������Щ֥�飬ͦ���˵ġ�\n");
	set("unit", "��");
	set("food_remaining", 3);
	set("food_supply", 80);
	set("value", 150);
    }
}
