// Code of ShenZhou
// hetu.c

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
	set_name( GRN"��ͼ"NOR, ({ "tu", "he tu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��¾ɵ�����ᣬ�Ͽ����������ġ���ͼ����\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name":	"qimen-dunjia",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 30+random(20), 	// jing cost every time study this
			"difficulty":	35,	// the base int to learn this skill
			"max_skill":	360,	// the maximum level you can learn
		]) );
	}
	::create();
}
