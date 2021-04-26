// Code of ShenZhou
// mabudai.c 麻布袋

inherit ITEM;

void create()
{
	set_name("麻布袋", ({ "budai", "dai", "bag" }));
	set_weight(500);
	set_max_encumbrance(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "一只用麻布织成的袋子，好像可以装东西。\n");
		set("value", 50);
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/mabudai.c");
//***** END OF ADDING *****
		set("material", "cloth");
	}
}

int is_container() { return 1; }
