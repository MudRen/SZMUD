//jiuer 9/2001
// key.c

inherit ITEM;

void create()
{
	set_name("芝房钥匙", ({"zhifang key", "key"}));
	set("long",
		"这是一把铜钥匙，环上串着根磨旧的丝绳。\n");
	set("unit", "把");
	set("weight", 10);
}

