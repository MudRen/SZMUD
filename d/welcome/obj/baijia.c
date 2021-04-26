// Code of ShenZhou
// baijia.c

inherit ITEM;

void create()
{
        set_name("《百家姓》", ({"baijia xing", "book"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是中国古代学童的启蒙读物之一。\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":		"literate",		// name of the skill
			"exp_required":	0,			// minimum combat experience required
								// to learn this skill.
			"jing_cost":	5,			// jing cost every time study this
			"difficulty":	1,			// the base int to learn this skill
								// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	5			// the maximum level you can learn
								// from this object.
		]) );
	}
}
