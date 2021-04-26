// Code of ShenZhou
// book2.c

inherit ITEM;

void create()
{
	set_name("��ɽ����", ({ "shu", "qifa", "book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"��ҳ΢�ʻ�ɫ����Ȼ�Ǿ�����ﻭ������������ͼ�Σ����Ų�ͬ���ơ�\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"feixing-shu",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	30	// the maximum level you can learn
		]) );
	}
}
