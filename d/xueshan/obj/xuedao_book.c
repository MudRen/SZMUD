// Code of ShenZhou
// xuedao_book.c 

inherit ITEM;

void create()
{
	set_name("Ѫ������", ({ "xuedao book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
		"���������ż����ֲ����֣������󻭵�ͼ�С�����ȫ���������񣬸������ˣ�\n"
                "ȫ���������ǣ���Ŀ��ȧ���������ϡ�\n");
		set("value", 5000);
		set("material", "paper");
		set("no_drop","�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");
		set("skill", ([
			"name":	"xue-dao", // name of the skill
			"exp_required":	10000,	  // minimum combat experience required
			"jing_cost":	30+random(30),	  // jing cost every time study this
			"difficulty":	25,	  // the base int to learn this skill
			"max_skill":	99,	  // the maximum level you can learn
		]) );
	}
}
