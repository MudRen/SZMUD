// Code of ShenZhou
// staff_book.c ����ͼ��
inherit ITEM;

void create()
{
	set_name("�ȷ�ͼ��", ({ "staff book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����װ�飬������������Ļ��˲������ȵ����ơ�\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"staff",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	30	// the maximum level you can learn
		]) );
	}
}
