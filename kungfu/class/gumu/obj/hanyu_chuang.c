// Program make by fengyu, Describing by Jiuer.
// /d/gumu/obj/hanyu_chuang.c.
// 2002/8/12. by fengyu
// modify by april 01.09.14

#include <ansi.h>
inherit ITEM;

int exercising(object me);
int halt_exercise(object me);
int leavebed();

void create()
{
	set_name(HIW"�ź���"NOR, ({"hanyu chuang","chuang","bed"}));
	set_weight(200000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","���ǹ�Ĺ��ʦ���Ż���������Ѫ���������ຮ֮�أ��������ɼ��֮���ڳ�\n"
			+ "�����Ϲź����Ƴɵ�һ�ź��� (bed)��ʵΪ��ϰ�ϳ��ڹ���������˯����\n"
			+ "����������һ��ֵ���ƽ��������ʮ�ꡣ\n");
		set("unit", "��");
		set("material", "steal");
	} 
	setup();
}

void init()
{
	add_action("do_onbed", "on");
	add_action("do_onbed", "shang");
	add_action("do_leavebed","leave");
	add_action("do_leavebed","xia");
	add_action("do_exercise","exercise");
	add_action("do_exercise","dazuo");
	add_action("do_tuna","respirate");
	add_action("do_tuna","tuna");
}

int do_onbed(string arg)
{
	int i,j;
	object *inv;	// ���� ��ǰ���� inventory ��Ʒ��������ң������顣
	object pl = this_player();
	object ob = this_object();
	object here = environment(ob);

	if(!arg || (arg != "bed" && arg != "chuang")) return 0;

	if (pl->is_busy() 
		|| pl->query_temp("pending/exercising")
		|| pl->is_fighting())
		return notify_fail("��������æ���ء�\n");

	if (pl->query_temp("onbed") ||
		pl->query_temp("pending/exercise_hanyu")) 
		return notify_fail("���Ѿ��ں�������");

	inv = all_inventory(here);
	j=0;
	for(i=0; i<sizeof(inv); i++){
		if( (int)inv[i]->query_temp("onbed")
			|| inv[i]->query_temp("pending/exercise_hanyu"))
			j += 1;
	}
	if (j>3) return notify_fail("�����ϵ���̫���ˣ��Ѿ��������ˡ�\n");

	if (pl->query("family/family_name") != "��Ĺ��")
		return notify_fail("���񴲱���̹ǣ���ֻ������������\n");

	message_vision("$N�����Ϻ��񴲡�\n", pl);
	pl->set_temp("onbed",1);
	call_out("leavebed",5);
	return 1;
}

int do_leavebed(string arg)
{
	object pl = this_player();
	object ob = this_object();
	object here = environment(ob);

	if(!arg || (arg != "bed" && arg != "chuang")){
		return 0;
	}

	if (!pl->query_temp("onbed")) return 0;

	if (pl->is_busy() 
		|| pl->query_temp("pending/exercising")
		|| pl->is_fighting())
		return notify_fail("��������æ���ء�\n");

	pl->delete_temp("onbed");
	remove_call_out("leavebed");
	message_vision("$N�����˺��񴲡�\n", pl);
	return 1;
}


int do_exercise(string arg)
{
	object me = this_player();
	int exercise_cost;
	object here;

	seteuid(getuid());
	here = environment(me);

	if (!me->query_temp("onbed")) return 0;

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

	write("��һ��Ŭ���Կ��ź����Ϲź�����һ�������ù���һ����Ϣ��ʼ������������\n");

	remove_call_out("leavebed");
	me->set_temp("pending/exercise_hanyu", 1);
	me->set_temp("exercise_cost", exercise_cost);
	message_vision("$N��ϥ���£���ʼ����������\n", me);
	me->delete_temp("onbed");
	me->start_busy((: exercising :), (:halt_exercise:));
    
	return 1;
}

int exercising(object me)
{
	int exercise_cost = (int)me->query_temp("exercise_cost");
        int neili_gain = 1 + (int)me->query_skill("force") / 5;
	if (exercise_cost < 1) return 0;
	
	me->add("neili", neili_gain);
    me->set_temp("exercise_cost", exercise_cost -= neili_gain/2);

	me->receive_damage("qi", neili_gain/2, "�����߻���ħ����");

    if (exercise_cost > 0) return 1;

	me->delete_temp("pending/exercise_hanyu");
	me->start_busy(2);
	message_vision("$N�˹���ϣ��������˿��������´�����\n", me);
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else {
		if ((int)me->query("max_neili") > (int)me->query_skill("force") 
			* me->query("con") * 2 / 3 ) {
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
	me->delete_temp("pending/exercise_hanyu");
	message_vision("$N���������е�����ǿ��ѹ�ص���뿪�˺��񴲡�\n", me);
    return 1;
}

int do_tuna(string arg)
{
	object me = this_player();

	if (me->query_temp("onbed")){
		write("��ʵ�ڶ��ò��У������޷�����������\n");
		return 1;
	}

	return 0;
}


int leavebed()
{
	object pl = this_player();

	pl->delete_temp("onbed");
	remove_call_out("do_leavebed");
	message_vision("$N����ʵ���ܲ��ˣ���æ�����˺��񴲡�\n", pl);
	return 1;
}
