// Code of ShenZhou
// xuedao.c  Ѫ��

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(RED"Ѫ��"NOR, ({ "xue dao", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", RED"һ���������嵶��������ס�������������һ�㡣������ȥ��������һƬ��
��֮ɫ��\n" NOR);
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", RED "ֻ����ৡ���һ����Ѫ�����ʷɳ���$N����������סһ�����߷��ź�⣬������һƬѪ����\n" NOR);
		set("unwield_msg", RED " �߽����ʡ�\n" NOR);
		set("shaolin", 1);
//		set("no_drop", 1);
	}
	init_blade(200);
	setup();
}
void init()
{
        object me = this_player();

        if ( !me->query_skill("xue-dao") )  {

        }

        add_action("do_lian","lian");
        add_action("do_lian","practise");
}

int do_lian(string arg)
{
        object weapon, me = this_player();

        if ( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade" )
	return notify_fail( "��ʹ�õ��������ԡ�\n");
	
	if ( arg == "blade" && !me->is_fighting()
        && (int)me->query("combat_exp") >= 50000  
	&& present("xuedao book", me)
        && ((int)me->query_skill("xue-dao",1) >= 50
	&& (int)me->query_skill("xue-dao",1) <= 200
        && me->query("family/master_id") == "xuedao laozu" )) {
		me->receive_damage("jingli",10);
                me->improve_skill("xue-dao", me->query("int")+10);
	if( me->query_skill("xue-dao",1) > 150 ) me->receive_damage("jingli", 5 );
        if( me->query_skill("xue-dao",1) > 180 ) me->receive_damage("jingli", 10);
        if( me->query_skill("xue-dao",1) > 200 ) me->receive_damage("jingli", 15);
                tell_object(me,"���Ѫ�����������ˣ�\n", me);
        }
	else
		tell_object(me,"ʲ�᣿\n",me);
	
        return 1;
}