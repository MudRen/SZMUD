// Code of ShenZhou
// yijing.c

inherit ITEM;

void create()
{
	set_name( "�׾���˵��ƪ��", ({ "jing", "yi jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���׾�������д�ţ�\n
�������ߣ�ʥ��֮����Ҳ���������������顣
�����۱�������������ԣ�����춸��ᣬ����س����˳춵��£������
�壻�����ԣ����������
\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"qimen-dunjia",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 15, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	60,	// the maximum level you can learn
		]) );
	}
}
