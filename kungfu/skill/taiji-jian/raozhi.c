// Code of ShenZhou
// raozhi.c ����ָ�ὣ��
// xQin 10/98

/*
��·����ָ�ὣ��ȫ���Ի���������佣�У�ʹ������˸�޳����������Ե��ܡ�
��������δ������Ƚ�������æ������ܣ������һ�����죬�ǽ�����������
ֱ�����������ϱۡ�
*/

#include <ansi.h>
void remove_effect(object me, object weapon, int sword, int force);

int perform(object me)
{
	int force, sword;
	object weapon = me->query_temp("weapon");
	string shape = weapon->query("id");

	if( !me->is_fighting() )
		return notify_fail("����ָ�ὣ��ֻ����ս����ʹ�á�\n");

	if( !me->query("wudang/raozhi") )
		return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ����ָ�ὣ����\n");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽�������ʹ������ָ�ὣ������\n");

	if( me->query_temp("yield") )
		return notify_fail("�㲻���������ʹ������ָ�ὣ����\n");

	if( me->query_temp("wudang/raozhi") )
		return notify_fail("���Ѿ���������ע�뽣���ˣ���\n");

	if( me->query_skill_mapped("force") != "taiji-shengong" )
		return notify_fail("�����õ��ڹ��롸��ָ�ὣ���ķ���㣣�\n");

	if( (int)me->query_skill("sword", 1) < 179 )
		return notify_fail("��Ľ�����Ϊ������������ʩչ����ָ�ὣ����\n");

	if( (int)me->query_skill("force", 1) < 179 )
		return notify_fail("����ڹ���Ϊ���δ�㣬�޷����������佣�У�\n");

	if( me->query("max_neili") <= 1500 )
		return notify_fail("�������������񣬾��������Ա��佣�У�\n");

	if( me->query("neili") <= 500 )
		return notify_fail("����������������������Ա��佣�У�\n");

	if( me->query("jingli") <= 200 )
		return notify_fail("����������ޣ�����ʩչ����ָ�ὣ����\n");

	if( shape == "xuantie jian" )
		return notify_fail("������֮���ʵع�춼�Ӳ������������������䣡\n");

	if( shape == "tie di" || shape == "tie xiao" || shape == "zhu xiao"
	 || shape == "yu xiao")
		return notify_fail("�����״���ʺ�ʩչ����ָ�ὣ����\n");

	if( shape == "xiuhua zhen" || shape == "qijue zhen" || shape == "emei ci"
	 || shape == "duanjian" || shape == "bishou" )
		return notify_fail("������֮��̫�̣����ʺ�ʩչ����ָ�ὣ����\n");

	me->add("neili", -100);
	me->add("jingli", -150);

	if( (string)weapon->query("material") != "steel" )
	{
		message_vision(HIW "\n�͵���$Nһ����Х���������䡣��������"+ weapon->name() 
			+HIW"ȴ�Ѿ���ס����������ѳ���Ƭ����\n"NOR, me);
		destruct(weapon);
		me->set_temp("apply/damage", 0);
		me->reset_action();
		me->start_busy(1);

		return 1;
	}

	force = me->query_skill("force")/2;
	sword = me->query_skill("sword")/3;

	weapon->add("rigidity", force);
	me->add_temp("apply/attack", sword);
	me->set_temp("wudang/raozhi", sword);

	message_vision(HIG "\n�͵���$Nһ����Х���������䣬�Ǳ�"+ weapon->name()
		+HIG"���Ƴ���һ��������������ۣ�Ʈ��������\n�����䵱�ɾ���"+
		HIW +"����ָ�ὣ��"+ HIG +"��\n"NOR, me);

	call_out("checking", 1, me, weapon, sword, force);
	return 1;
}

void checking(object me, object weapon, int sword, int force)
{
	if( !me ) return;

	if( !living(me) || me->is_ghost() )
	{
		remove_effect(me, weapon, sword, force);
		return;
	}
	else if( !me->is_fighting() && !me->is_busy() )
	{
		remove_effect(me, weapon, sword, force);
		message_vision(HIG "\n$N��ָ�ڽ���������һ����ֻ����"
			+ weapon->name() + HIG"��������֮�죬����ͣ������\n"+NOR
			CYN+"$N˳������һ���������������ջء�\n"NOR, me);
		me->start_busy(1);
		return;
	}
	else if( environment(weapon) != me || weapon != me->query_temp("weapon") )
	{
		remove_effect(me, weapon, sword, force);
		message_vision(HIR "\n$N��������"+ weapon->name() +HIR"���������ջأ�\n"NOR, me);
		return;
        }
	else if( (int)me->query("neili") < (int)me->query("max_neili") / 5 ||
		(int)me->query("jingli") < (int)me->query("max_jingli") / 4 )
	{
	        remove_effect(me, weapon, sword, force);
        	tell_object(me, HIR "\n��΢����Ϣ���������ò��������ջأ�\n" NOR);
		message("vision", CYN+"\n"+ me->name() + weapon->name() +CYN
			"Ȧת���ջؽ��ơ������Ѳ���֮ǰ��˸�޳�����ò�����\n"NOR, environment(me), me);
		me->start_busy(2);
		return;
	}
	else if( me->query_skill_mapped("sword") != "taiji-jian" && !me->is_busy() )
	{
		remove_effect(me, weapon, sword, force);
		message_vision(CYN "\n$NȦת" + weapon->name()+ CYN
			"��ͻȻ���У�ʹ����"+ HIW +"����ָ�ὣ��"+ NOR + CYN"��ͬ�Ľ�����\n"NOR, me);
		return; 
	}
	else if( me->query_temp("wudang/raozhi") <= 50 )
	{
		remove_effect(me, weapon, sword, force);
		message_vision(HIC "\n$N" + weapon->name()+ HIC
			"Ȧת���ѿ�����һ·"+ HIW +"����ָ�ὣ��"+ HIC +"����ʹ����\n"NOR, me);
		return; 
	}

	call_out("checking", 1, me, weapon, sword, force);
} 

void remove_effect(object me, object weapon, int sword, int force)
{
	me->delete_temp("wudang/raozhi");
	me->add_temp("apply/attack", -sword);
	weapon->add("rigidity", -force);
}
