// Code of ShenZhou
// mwjian_book.c 

inherit ITEM;

void create()
{
	set_name("��������", ({ "xuedao book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
		"һ����ĻƳ���Ƶľ��飬\n");
		set("value", 5000);
		set("material", "paper");
		set("skill", ([
			"name":	"mingwang-jian", // name of the skill
			"exp_required":	10000,	  // minimum combat experience required
			"jing_cost":	30+random(30),	  // jing cost every time study this
			"difficulty":	25,	  // the base int to learn this skill
			"max_skill":	99,	  // the maximum level you can learn
		]) );
	}
}
