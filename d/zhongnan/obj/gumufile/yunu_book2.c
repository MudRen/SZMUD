// Code of ShenZhou
// ziyin_book2.c

inherit ITEM;

void create()
{
	set_name("��Ů��ʮ�ľ��¾�", ({ "yunu book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","��Ů��ʮ�ľ��ǹ�Ĺ�������������ķ�Ҫ����ʮ���෴����\n"
			   "��˼���񵡣�������ɢ�����������𣬶�������ƣ�����������٣�\n"
			   "��Ц����ˣ���������壬���������磬��ϲ��������ң���ŭ���\n"
			   "�������������ר�Բ��Σ�����򽹼���������ʮ���಻����ɥ��֮��Ҳ��\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":		"yunu-jue",		// name of the skill
			"exp_required":	0,			// minimum combat experience required
								// to learn this skill.
			"jing_cost":	40,			// jing cost every time study this
			"difficulty":	20,			// the base int to learn this skill
								// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	100			// the maximum level you can learn
								// from this object.
		]) );
	}
}
