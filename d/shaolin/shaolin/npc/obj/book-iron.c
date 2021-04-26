// Code of ShenZhou
// book3.c

#include <armor.h>

//inherit ITEM;
inherit HANDS;
void create()
{
	set_name("������", ({ "iron hand", "hand", "shu", "book" }));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�׽����ƪ\n"
			"����һ�������ƣ����氼��͹͹���������β����ĳ��档\n");
		set("value", 70000);
		set("material", "steel");
		set("real", 1);
		set("shaolin", 1);
		set("armor_prop/armor", 3 );
		set("skill", ([
			"name":	"parry",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	29	// the maximum level you can learn
		]) );
	}
}

void init()
{
	if( this_player() == environment() )
		add_action("do_study", "study");
}

int do_study(string arg)
{
	object me = this_player();

	if ( arg != "iron hand" && arg != "hand" )
	return notify_fail("��Ҫѧʲô��\n");

	if( me->is_busy() )
                return notify_fail("��ǰһ��������û�����ꡣ\n");

	if ( me->query("jingli") < 50)
	return notify_fail("��ľ���������\n");

	if ( me->is_fighting() 
	&& (int)me->query_skill("parry", 1) >= 30 
	&& (int)me->query_skill("parry", 1) <= 100 )
	{
		me->receive_damage("jingli", random(60), "��������������");
		me->improve_skill("parry", random(me->query_str()*2));
		me->start_busy(1);
		message_vision("$Nһ��ս����һ�߳�ռ���ææ���ó����������űȻ���\n", me);
		return 1;
	}

	return 0;
}
