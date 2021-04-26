// Code of ShenZhou
// Jay 2/5/97
#include "ansi.h"

inherit ITEM;
inherit F_UNIQUE;
int exercising(object me);
int halt_exercise(object me);

void setup()
{}

void init()
{
        add_action("do_dazuo", "lianneili");
}

void create()
{
        set_name(MAG "���վ�" NOR, ({ "shenzhao jing", "jing", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "ƾ���ؼ���ָ�����Լӿ�������(lianneili)���ٶȡ�\n");
                set("value", 5000);
                set("material", "paper");
		set("no_steal", 1);
        }
        ::create();
}

int do_dazuo(string arg)
{
        object me = this_player();
        int exercise_cost;
        object where;

        seteuid(getuid());
        where = environment(me);

        if (!present("shenzhao jing", me))
                return 0;

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (where->query("no_fight"))
		return notify_fail("�㲻���������ֻ������а���Ҵܣ��޷�����������\n");

        if (where->query("sleep_room"))
                return notify_fail("��˯���ﲻ�ܴ��������Ӱ�����ˡ�\n");

        if (me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("ս���в������ڹ������߻���ħ��\n");

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

        write("�㰴�����վ��ϵ����������������ù���һ����Ϣ��ʼ������������\n");

        me->set_temp("pending/exercise", 1);
        me->set_temp("exercise_cost", exercise_cost);
        message_vision("$N��ϥ���£���ʼ����������\n", me);
        me->start_busy((: exercising :), (:halt_exercise:));
        return 1;
}

int exercising(object me)
{
        int exercise_cost = (int)me->query_temp("exercise_cost");
        int neili_gain = 1 + (int)me->query_skill("force") / 5;
        if (exercise_cost < 1)
                return 0;
        me->add("neili", neili_gain);
        me->set_temp("exercise_cost", exercise_cost -= neili_gain);

        //me->add("qi", -neili_gain);
        me->receive_damage("qi", neili_gain, "�����߻���ħ����");

        if (exercise_cost > 0)
                return 1;

        me->set_temp("pending/exercise", 0);
        message_vision("$N�˹���ϣ��������˿�����վ��������\n", me);
        if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
                return 0;
        else {
                if ((int)me->query("max_neili") > (int)me->query_skill("force") * 10) {
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
        me->set_temp("pending/exercise", 0);
        return 1;
}

