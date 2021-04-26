// Code of ShenZhou
// jiuyin-jing2.c �����澭�¾�

inherit ITEM;

void create()
{
	set_name("�����澭", ({ "jing", "jiuyin-zhenjing" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ֳ�С�飬������д�š������澭�����²᡹�����֣�������������д�����С�֡�\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"claw",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost":	50,	// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	60	// the maximum level you can learn
		]) );
	}
}
