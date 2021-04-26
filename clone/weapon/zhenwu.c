// Code of ShenZhou
// zhenwu.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name("���佣", ({ "zhenwu sword", "zhenwu", "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
			"ֻ����������ͭ�̰�쵣���ͭ˿Ƕ������׭�ģ������䡱��\n");
                set("value", 7000);
                set("material", "steel");
		set("rigidity", 1500);
                set("wield_msg", 
			"ֻ������쬡���һ�����پ��������棬$N�������Ѿ�����һ�ѱ�������$n��\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }

        init_sword(120);
        setup();
}

void init()
{
	if( this_player() == environment() )
		add_action("do_study", "study");
}

int do_study(string arg)
{
	object me = this_player();

	if ( arg != "youlong sword" && arg != "youlong" && arg != "sword")
	return notify_fail("��Ҫѧʲô��\n");

	if ( me->is_fighting() 
	&& (int)me->query_skill("sword", 1) >= 30 
	&& (int)me->query_skill("sword", 1) <= 100
	&& (int)me->query("combat_exp") >= 50000 )
	{
		me->receive_damage("jing", 30);
		me->improve_skill("sword", me->query("int"));
		tell_object(me, "ֻ��������һ�����������������䣬��Խ���������������һ�㣡\n", me);
		return 1;
	}

	return 0;
}

