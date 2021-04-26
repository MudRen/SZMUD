// jiuer -- 9/20/2001
// jianbing.c ´ÐÓÍ¼å±ý

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("´ÐÓÍ¼å±ý", ({"jian bing", "pancake"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»µúÁ½Ãæ½¹ÏãµÄ¹ü´ÐÓÍÐ¡¼å±ý¡£\n");
                set("unit", "µú");
                set("value", 10);
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}
