// Code of ShenZhou
// ziyin_book1.c

inherit ITEM;

void create()
{
	set_name("����������Ͼ�", ({ "ziyin book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","������ǻ�ɽ�������ĸ����\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":		"ziyin-yin",		// name of the skill
			"exp_required":	0,			// minimum combat experience required
								// to learn this skill.
			"jing_cost":	20,			// jing cost every time study this
			"difficulty":	10,			// the base int to learn this skill
								// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	30			// the maximum level you can learn
								// from this object.
		]) );
	}
}
