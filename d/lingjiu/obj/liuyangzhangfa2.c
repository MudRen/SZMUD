/*Updated by George 98/7*/
inherit ITEM;

void create()
{
	set_name( "��ɽ�����Ʒ�ͼ�²�", ({ "zhangfa tu", "tu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���������Ʒ��²ᣬ���滭��һЩ�׷����ӵ���ʽ���������š�\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"liuyang-zhang",	
			"exp_required":	50000,	// minimum combat experience required
			"jing_cost": 40, 	// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	100,	// the maximum level you can learn
		]) );
	}
}
