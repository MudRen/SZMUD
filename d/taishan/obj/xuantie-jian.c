// Code of ShenZhou
// xuantie-jian ������
// qfy July 5, 1996

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name("�����ؽ�",({ "xuantie jian", "xuantie", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 8000);
                set("material", "steel");
                set("long", 
		"�˽�������ĺ�����״��ȴ�ǳ���֮�������߽��涼�Ƕۿڣ������ԲԲ�����Ǹ�����\n");
                set("wield_msg", HIY "$N����$n�����������޹⣬�����������ƺ�Ҫ��һ������ѹ�١�\n" NOR);
                set("unwield_msg", HIY "����է�գ�����ͽ�֡�\n" NOR);
                set("unequip_msg", HIY "����է�գ�����ͽ�֡�\n" NOR);
        }
	init_sword(280);
        setup();
	::create();
}

void init()
{
	object me = this_player();
	
	if ( !me->query_skill("dugu-jiujian") )  {
	
	}

	add_action("do_lian","lian");
	add_action("do_lian","practise");
}

int do_lian(string arg)
{
	object weapon, me = this_player();

	if (arg != "sword") return 0;

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword" )
	   return notify_fail( "��ʹ�õ��������ԡ�\n");
	
	if ( arg == "sword" && !me->is_fighting() 
	&& (int)me->query_skill("sword", 1) >= 50
	&& (int)me->query_skill("sword", 1) <= 120
	&& (int)me->query("combat_exp") >= 50000 ) {
	   me->receive_damage("jingli",50);
	   me->improve_skill("sword", me->query("int")+20);
	   tell_object(me,"��Ļ������������ˣ�\n", me);
	
	   if ( (int)me->query_skill("dugu-jiujian",1) >= 30 
	   && (int)me->query_skill("dugu-jiujian",1) <= 120 
	   && me->query("family/master_id") == "feng qingyang" ) {
		me->improve_skill("dugu-jiujian", me->query("int")+20);
		tell_object(me,"��Ķ��¾Ž������ˣ�\n", me);
   	   }
	return 1;
	}
	else {return 0;}
}
