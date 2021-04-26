// item: /d/jueqing/obj/raft2.c
// jiuer

inherit ITEM;
void setup()
{}

void init()
{
	add_action("do_ride", "ride");
}

void create()
{
	set_name("皮筏", ({"raft", "pi fa"}));
	set_weight(35000);
	set_max_encumbrance(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个手工粗制的皮筏，可以乘(ride)它。\n");
		set("value", 1000);
		set("no_get", "这样东西太沉了，你拿不动。\n");
        }
}
int do_ride(string arg)
{
	object  me = this_player();
    if (!id(arg))
		return notify_fail("你要乘什么？\n");
	message("vision",this_player()->name() + "跳上皮筏，用劲地划了起来，筏子向上游离去。\n",
		environment(me), ({me}) );
	write("你把皮筏推进水里，然後跳上去，用劲地向前划....\n\n");
	me->move("/d/jueqing/valley");
	destruct(this_object());
	return 1;
}
