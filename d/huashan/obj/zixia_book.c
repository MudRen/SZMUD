// Code of ShenZhou
// zixia_book.c ��ϼ����

inherit ITEM;
void create()
{
	set_name("��ϼ����", ({ "zixia book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
		"���ǻ�ɽ���ڵ���ɽ֮������ϼ�ؼ�������ϼ����������һ��\n"
		"һ���ڼҹ�����Ϊ�������˼����ơ�\n");
                set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"zixia-gong", // name of the skill
			"exp_required":	3000,	  // minimum combat experience required
			"jing_cost":	30,	  // jing cost every time study this
			"difficulty":	10,	  // the base int to learn this skill
			"max_skill":	50,	  // the maximum level you can learn
		]) );
	}
}
