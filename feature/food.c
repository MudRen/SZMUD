// Code of ShenZhou
// food.c

#include <dbase.h>
#include <name.h>

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

int feed_ob(object me)
{
	string str;
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( !living(me) ) return 0;

	if( stringp(query("food_race")) )
		return notify_fail( "��ɲ��Ǹ��˳ԵĶ�����\n");

	if( !query("food_remaining") )
		return notify_fail( name() + "�Ѿ�ûʲô�óԵ��ˡ�\n");
	if( (int)me->query("food") >= (int)me->max_food_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");

	me->add("food", query("food_supply"));

	me->add("jingli", query("food_supply")/5);
	if( me->query("jingli") > me->query("max_jingli")) 
	me->set("jingli", me->query("max_jingli"));

	if( me->is_fighting() ) me->start_busy(2);

	// This allows customization of drinking effect.
	if( query("eat_func") ) return 1;

	set("value", 0);
	add("food_remaining", -1);
	if( !query("food_remaining") ) {
		if( !stringp(str = this_object()->query("eat_all")) )
		str = "$N��ʣ�µ�$n�Ե�ǬǬ������\n";
		message_vision(str, this_player(),this_object());
		if( !this_object()->finish_eat() )
			destruct(this_object());
	} else  {
		if( !stringp(str = this_object()->query("eat_msg")) )
		str = "$N����$nҧ�˼��ڡ�\n";
		message_vision(str, this_player(),this_object());
	}
	me->start_busy(1);
	return 1;
}
