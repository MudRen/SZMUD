// Code of ShenZhou
// force-book.c

inherit ITEM;

void create()
{
        set_name("���ڹ��ķ���", ({"neigong xinfa", "xinfa", "book"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�������ڹ����ķ���\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":		"force",		// name of the skill
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
