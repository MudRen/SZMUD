// Code of ShenZhou
// Code of ShenZhou
// attack.c 
// arthurgu 1999/10

#include <ansi.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int exert(object me, object target)
{
	object weapon, ob;
    string msg, string1;
    int count;
 
    if( !me->is_fighting() )
	    return notify_fail("�㲻��ս���С�\n");

	if((int)me->query_int() < 27)
		return notify_fail("������Բ���, Ŀǰ������ʹ���������! \n");

	if((int)me->query_skill("douzhuan-xingyi",1) < 100)
		return notify_fail("����ڹ�����Ϊ����, ����ʹ����һ���� !\n");

	if((int)me->query_skill("literate",1) < 80)
		return notify_fail("���ѧ��̫��, �޷���ȷʹ�ô˹���\n");
 
    if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

     if( me->query("family/family_name") != "����Ľ��" )
                return notify_fail("�㲻��Ľ�ݵ��ӣ��޷�ʹ�ô˹���\n");

     message("vision", HIW "\n"+me->query("name")+"����һ��������ת��ת�����񹦣������ֵĹ���������������ٲȻ�ǹ���Ľ�ݵġ��Ա�֮������ʩ������\n" NOR, environment(me), me);
        tell_object(me, HIR "����ת��ת�����񹦣������ֵĹ�������������\n" NOR);

	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(ob, ob, ob->query_temp("weapon"), 0);
	COMBAT_D->do_attack(ob, ob, ob->query_temp("weapon"), 0);
	

	me->add("neili", -200);
	me->start_busy(random(3));

    return 1;
}