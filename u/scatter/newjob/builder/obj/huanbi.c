//by jiuer

inherit ITEM;

void create()
{
	set_name("毛笔", ({"mao bi", "bi"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只用上好獾毛制成的毛笔，毛锋挺直，是笔中珍品。\n");
		set("unit", "支");
		set("value", 1000);
	}
}
