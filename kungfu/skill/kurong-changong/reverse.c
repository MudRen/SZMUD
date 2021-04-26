// Code of ShenZhou
// reverse.c 
// cyz 2000.02.16
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me,object target)
{
	if (target != me)
		return notify_fail("�����ķ������˺������ã�\n");

	if (!(me->query_temp("kurong")))
		return notify_fail("�㲢δ��ת�����ķ���\n");

	if (me->query_skill("kurong-changong",1) < 100
		|| me->query_skill("force",1) < 100
		|| me->query_skill("buddhism",1) < 100 )
		return notify_fail("�����δ��ͨ��������ǿ�����˿����ķ������洦��\n");

	if (me->query("max_neili")<2000
		|| me->query("neili") < me->query("max_neili")/10)
		return notify_fail("��������������˿����ķ���\n");

 	
	message("vision", HIW "\n"+me->query("name")+"˫�ƺ�ʮ����Ϣ��ת�£�һ����Ƭ�̼��ú�ͨͨ�ģ���Ƭ�̣��ֻظ�������ģ����\n\n" NOR, environment(me), me);
	tell_object(me, HIW "\n��˫�ƺ�ʮ�����˿����ķ�������һ��һ�����֣�Ƭ�̼��ظ�������\n\n" NOR);

	me->delete_temp("kurong");

	me->add("neili", -100);

	return 1;
}
