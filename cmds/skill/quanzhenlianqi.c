// Code of ShenZhou
// exercise.c

#include <skill.h>

inherit F_CLEAN_UP;

string *koujue = ({
	 "���������к�ƾ������Ⱥ�������",
	 "��������ӯ���оߣ������ҫ���񾩡�",
	 "������ʦ���򱾳�����ʱ�޾�ȥ���š�",
	 "�����곾����ĥ����ƫ������ҫ̫�顷"
});

int exercising(object me);
//int halt_exercise(object me, object who, string why);
int halt_exercise(object me);

int main(object me, string arg)
{
        int exercise_cost;
        object where;

        seteuid(getuid());
        where = environment(me);

        if (!wizardp(me) && me->query("test-qzlq") != "ok")
                return notify_fail("�˹��ܲ����У��㲻��ʹ�á�\n");

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

        if (where->query("sleep_room"))
		return notify_fail("��˯���ﲻ�ܴ��������Ӱ�����ˡ�\n");

        if (where->query("no_fight"))
		return notify_fail("����������ã����ܴ�����\n");

        if (where->query("name") == "����")
		return notify_fail("����̫����, �������߻���ħ. \n");

        if (me->is_busy() || me->query_temp("pending/exercising") || me->query_temp("exit_blocked"))
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("ս���в������ڹ������߻���ħ��\n");
        
        if (me->query_temp("cursed", 1))
                return notify_fail("ʲô��\n");

        if( me->query("rided"))
                return notify_fail("�������ϴ��������߻���ħ��\n");

        if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");

        if( !arg || !sscanf(arg, "%d", exercise_cost))
                return notify_fail("��Ҫ��������������\n");
        if (exercise_cost < 10)
                return notify_fail("����ڹ���û�дﵽ�Ǹ����磡\n");

        if( (int)me->query("qi") < exercise_cost )
                return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

        if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
                return notify_fail("�����ھ��������޷�������Ϣ��������\n");

        if ( (int)me->query("neili") > (int)me->query("max_neili") * 2 )
        {
                me->set( "neili",me->query("max_neili") * 2 );
        }

	if( me->query_skill_mapped("force") == "xiantian-gong"
	 && (int)me->query_skill("xiantian-gong") >= 50
	 && (int)me->query_skill("xuanmen-xinfa") >= 50)
	{
		write("�㰴�������ڹ��ķ������������������ù���һ����Ϣ��ʼ������������\n");
		me->set_temp("quanzhen_lianqi","start");
	}else write("�������������ù���һ����Ϣ��ʼ������������\n");
        me->set_temp("pending/exercise", 1);
        me->set_temp("exercise_cost", exercise_cost);
        message_vision("$N��ϥ���£���ʼ����������\n", me);
        me->start_busy((: exercising :), (:halt_exercise:));
        return 1;
}

int exercising(object me)
{
	int cost;
        int exercise_cost = (int)me->query_temp("exercise_cost");
	int neili_gain = 1 + (int)me->query_skill("force") / 10;
        if (me->query("max_neili") < 3600) neili_gain = neili_gain * 2;
        if (exercise_cost < 1)
                return 0;
	if( me->query_temp("quanzhen_lianqi")=="start")
	{
		if( base_name(environment(me)) == "/d/zhongnan/yangxin" )
			cost = cost/3*2;
		neili_gain = 2 + (int)me->query_skill("force") / 5 + (int)me->query_skill("xuanmen-xinfa",1) / 10;
		cost = neili_gain*3/2;
		write("��Ĭ����"+koujue[random(4)]+"��ֻ����һ����Ϣ������Ѹ��������ȫ���е��泩�ޱȡ�\n");
		me->receive_damage("jing", cost/10, "�����߻���ħ����");
	}else cost = neili_gain;

        me->add("neili", neili_gain);
        me->set_temp("exercise_cost", exercise_cost -= neili_gain);

        //me->add("qi", -neili_gain);
        me->receive_damage("qi", neili_gain, "�����߻���ħ����");

        if (exercise_cost > 0)
                return 1;
	me->set_temp("quanzhen_lianqi","stop");
        me->set_temp("pending/exercise", 0);
        message_vision("$N�˹���ϣ��������˿�����վ��������\n", me);
        if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
                return 0;
        else {
                if ((int)me->query("max_neili") > (int)me->query_skill("force") * me->query("con") * 2 / 3) {
                        write("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
                        me->set("neili", (int)me->query("max_neili"));
                        return 0;
                }
                else {
                        me->add("max_neili", 1);
                        me->set("neili", (int)me->query("max_neili"));
                        write("������������ˣ���\n");
                        return 0;
                }
        }
}

int halt_exercise(object me)
{
        if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
                me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("quanzhen_lianqi","stop");
        me->set_temp("pending/exercise", 0);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : exercise|dazuo [<�ķѡ���������> ������� 10]

�����������������ڵ����ڸ�����������������ѵ�����弡���������
��������������������������ʽ����������������

HELP
        );
        return 1;
}
