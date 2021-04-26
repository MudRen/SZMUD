// Code of ShenZhou
// yijing.c

inherit ITEM;

void create()
{
	set_name( "�׾���ϵ��ƪ��", ({ "jing", "yi jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���׾���\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"qimen-dunjia",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 40, 	// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	120,	// the maximum level you can learn
		]) );
	}
}
