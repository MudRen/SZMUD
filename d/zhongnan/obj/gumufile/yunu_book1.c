// Code of ShenZhou
// ziyin_book1.c

inherit ITEM;

void create()
{
	set_name("��Ů��ʮ�ľ��Ͼ�", ({ "yunu book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","��Ů��ʮ�ľ��ǹ�Ĺ�������������ķ�Ҫ����ʮ����������\n"
			   "��˼��������������¡������Ц���ٳ���֡���ϲ��\n"
			   "��ŭ���ٺá��ٶ��д�ʮ���٣�������֮����Ҳ��\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":		"yunu-jue",		// name of the skill
			"exp_required":	0,			// minimum combat experience required
								// to learn this skill.
			"jing_cost":	20,			// jing cost every time study this
			"difficulty":	10,			// the base int to learn this skill
								// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	60			// the maximum level you can learn
								// from this object.
		]) );
	}
}
