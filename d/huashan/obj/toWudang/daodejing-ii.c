// Code of ShenZhou
// daodejing-ii.c

inherit ITEM;

void create()
{
	set_name( "���¾����¾�", ({ "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����¾����¾�����ͬ�����ʮһʼ�����ʵڰ�ʮһֹ��\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"taoism",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 30+random(30), 	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	100,	// the maximum level you can learn
		]) );
	}
}
