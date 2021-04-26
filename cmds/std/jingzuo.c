// Code of ShenZhou
// jingzuo.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int jingzuoing(object me);
int halt_jingzuo(object me);

int main(object me, string arg)
{
	int busy_time, pot_gain;
	int yuga_lvl;
	mapping fam;
	object where;

	seteuid(getuid());
	where = environment(me);

	if( !(fam = me->query("family")) || fam["family_name"] != "������" )
		return notify_fail("�����������ж���ͬ���ػ�����Ƕ��ҵ��ӣ������й���\n");
	
	if( !where->query("jingzuo_room") )
		return notify_fail("�˴����˾���������\n");

	if( (yuga_lvl = me->query_skill("mahayana", 1)) < 20 ) 
		return notify_fail("�������ͷ���Ϊ̫�ͣ������й�������\n");

	if( me->is_busy() )
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("ս���о��ޣ�����������\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("�����ھ��������޷�������ħ���ޡ�\n");

	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
		return notify_fail("���������������������������ܾ��ޡ�\n");

        pot_gain = yuga_lvl/15 + random(5);
	pot_gain += random(yuga_lvl < 100 ? 6 : 8);
	busy_time = 30/pot_gain;
	pot_gain = 1 + random(pot_gain*2);
	busy_time *= pot_gain;
	if (me->query("food") + me->query("water") < 20) busy_time *= 2;
// printf("yual_lvl=%d, busy_time=%d, pot_gain=%d\n", yuga_lvl, busy_time, pot_gain);
	message_vision("$N��ϥ���£������۾���ʼ������\n", me);
	me->set_temp("pending/jingzuo", 1);
	me->set_temp("jingzuo/time", busy_time);
	me->set_temp("jingzuo/pot", pot_gain);
	me->start_busy((: jingzuoing :), (:halt_jingzuo:));
	return 1;
}

int jingzuoing(object me)
{
	int time = (int)me->query_temp("jingzuo/time");
	int pot_gain = (int)me->query_temp("jingzuo/pot");
	
	if( time < 1 ) return 0;
	me->set_temp("jingzuo/time", time-=2);

	if( random(12) == 5 )
	{
		me->update_condition();
		if( (int)me->query("water") > 0 ) me->add("water", -1);
		if( (int)me->query("food") > 0 ) me->add("food", -1);
	}

	if( time > 0 ) return 1;
	
	me->set_temp("pending/jingzuo", 0);

	message_vision("$N���������۾�������һ����վ��������\n", me);

        tell_object(me, HIC "���Ǳ��������" + chinese_number(pot_gain) + "�㣡\n" NOR);
                me->add("potential", pot_gain);
    log_file("job/emei",me->query("name") +" (" + me->query("id") + ") ���Ҿ������ " + 
        0 + " �㾭��� "+ pot_gain + " ��ǳ�� "+ctime(time())+"\n");

	if( me->query("potential") > me->query("max_potential") )
		me->set("potential", me->query("max_potential"));

	me->receive_heal("jing", me->query_con());
	me->receive_heal("qi", me->query_con());
	if( (int)me->query("jingli") < (int)me->query("max_jingli") )
		me->add("jingli", me->query_con());
	me->improve_skill("mahayana", 1+random(3*pot_gain));
}

int halt_jingzuo(object me) 
{
	me->set_temp("jingzuo/time", 0);
	me->set_temp("jingzuo/pot", 0);
	me->set_temp("pending/jingzuo", 0);
	return 1;
}
	

int help(object me)
{
        write(@HELP
ָ���ʽ : jingzuo

������������������Ǳ�ܡ��˶���������������ʽ��
HELP
        );
        return 1;
}
