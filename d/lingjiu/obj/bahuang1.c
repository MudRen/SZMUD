/*Updated by George 98/7*/
// bahuang2.c
inherit ITEM;

#include <ansi.h>

void create()
{
	set_name( HIB "�˻Ĺ������¾�" NOR, ({ "juanzhou","book", "shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ɵľ��ᣬ����д��һЩģ�������֡�\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"bahuang-gong",	
			"exp_required":	50000,	// minimum combat experience required
			"jing_cost": 30, 	// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	100,	// the maximum level you can learn
		]) );
	}
}
