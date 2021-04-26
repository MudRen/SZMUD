// Code of ShenZhou
// claw-book.c ����צ��
// xbc 1997/02/03

inherit ITEM;
inherit F_UNIQUE;
void create()
{
	set_name("��Ƥ", ({ "skin", "book", "yangpi" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�鷢�Ƶ���Ƥ��������������������С�֡�\n");
		set("value", 400);
		set("material", "paper");
		set("skill", ([
			"name":	"claw",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	40	// the maximum level you can learn
		]) );
	}
	::create();
}
