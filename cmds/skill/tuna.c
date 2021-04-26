// Code of ShenZhou
// respirate.c

#include <skill.h>

inherit F_CLEAN_UP;

int respirating(object me);
int halt_respirate(object me);

int main(object me, string arg)
{
	int respirate_cost;
	object where;

	seteuid(getuid());
	where = environment(me);
	
	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (where->query("sleep_room"))
					 return notify_fail("��˯���ﲻ�����ɣ����Ӱ�����ˡ�\n");

	if (where->query("no_fight"))
					 return notify_fail("���ﲻ�����ŵĵط���\n");

	if (me->is_busy() || me->query_temp("pending/exercising") || me->query_temp("exit_blocked"))
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("ս���в������ɣ����߻���ħ��\n");

	if (me->query_temp("cursed", 1))
                return notify_fail("ʲô��\n");

	if( me->query("rided"))
                return notify_fail("�����������ɣ����߻���ħ��\n");

	if( !arg || !sscanf(arg, "%d", respirate_cost))
		return notify_fail("��Ҫ�����پ����У�\n");
	if (respirate_cost < 10)
		return notify_fail("�����Ϊ��û�дﵽ�Ǹ����磡\n");

	if( (int)me->query("jing") < respirate_cost )
		return notify_fail("�����ھ����㣬�޷����о�����\n");

	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
		return notify_fail("����������״��̫���ˣ��޷����о���\n");

	write("������۾���ʼ������ȫ��ů��������������\n");

	me->set_temp("pending/respirate", 1);
	me->set_temp("respirate_cost", respirate_cost);
	message_vision("$N��ϥ���£���ʼ����������\n", me);
	me->start_busy((: respirating :), (:halt_respirate:));
	return 1;
}

int respirating(object me)
{
	int respirate_cost = (int)me->query_temp("respirate_cost");
	int jingli_gain = 1 + (int)me->query_skill("force",1) / 10;
	if (respirate_cost < 1)
		return 0;
	me->add("jingli", jingli_gain);
	me->set_temp("respirate_cost", respirate_cost -= jingli_gain);

	//me->add("jing", -jingli_gain);
	me->receive_damage("jing", jingli_gain, "�����߻���ħ����");

	if (respirate_cost > 0)
		return 1;

	me->set_temp("pending/respirate", 0);
	message_vision("$N������ϣ�����˫�ۣ�վ��������\n", me);
	if ((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
		return 0;
	else {
		if ((int)me->query("max_jingli") > (int)me->query_skill("force") * me->query("con") / 2
		 || (int)me->query("eff_jingli") > (int)me->query_skill("force") * me->query("con") / 2) {
			write("��ľ�����Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
			me->set("jingli", (int)me->query("max_jingli"));
			return 0;
		}
		else {
			me->add("eff_jingli", 1);
			me->add("max_jingli", 1);
			me->set("jingli", (int)me->query("max_jingli"));
			write("��ľ��������ˣ���\n");
			return 0;
		}
	}
}

int halt_respirate(object me)
{
	if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
		me->set("jingli", (int)me->query("max_jingli") * 2);
	me->set_temp("pending/respirate", 0);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : respirate|tuna [<�ķѡ���������>]
 
�������У����á������������������������项�ķ�������ľ�
ת��ɾ�����

See also: exercise
HELP
        );
        return 1;
}
