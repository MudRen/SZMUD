// zhaixing.c ����ժ��

/**************************************************
�����Ṧ--ժ�ǹ�
   ԭ�й��ܣ���
   �޸Ĺ��ܣ�perform zhaixing ������ժ�ǣ�
      ������ժ�ǹ���Ч�ȼ�100����������Ч�ȼ�100��
      ���ܣ������ʱjifa dodge 10 %��
      ���ƣ��˹�ʱ����5-10 tick��ս��������
            ������yun huaͬʱʹ�á�
            ������yun maxsuck ͬʱʹ�á�
            ������perform sanyinͬʱʹ�á�
            ������pxj perform guimeiͬʱʹ�á�
*************************************************/

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int dex, skill;
	
	if(!target) target = offensive_target(me);
    
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����ժ������ս����ʹ�ã�\n");
	
	if(me->query_temp("zhaixing") )
		return notify_fail("���Ѿ���ʹ������ժ���ˣ�\n");

	if( me->query_skill_mapped("dodge") != "zhaixinggong" )
		return notify_fail("�����õĲ���ժ�ǹ�������ʩչ����ժ�ǣ�\n");
	
	if( me->query_skill_mapped("force") != "huagong-dafa" )
		return notify_fail("�����õĲ��ǻ����󷨣�ʩչ��������ժ�ǣ�\n");

    if( me->query_temp("yun hua") )
		return notify_fail("����ժ�ǲ����뻯������ͬʱ���á�\n");
	
	if( me->query_temp("yun maxsuck") )
		return notify_fail("����ժ�ǲ�������������ͬʱ���á�\n");
	
	if( me->query_temp("perfrom sanyin") )
		return notify_fail("����ժ�ǲ�������������ͬʱ���á�\n");

	if( me->query_temp("pxj/guimei") )
		return notify_fail("����ժ�ǲ��������ͬʱ���á�\n");

	if( me->query_skill("dodge",1) < 100 )
		return notify_fail("��Ļ�������������ʵ��\n");
    
	if( me->query_skill("huagong-dafa") < 100 )
		return notify_fail("��Ļ����󷨹����������޷�ʩչ����ժ�ǣ�\n");
	 
	if( me->query("jingli") <= 500  )
		return notify_fail("��ľ�������������ʹ�á�����ժ�ǡ���\n");
	
	if( me->query("neili") <= 500  )
		return notify_fail("�����������������ʹ�á�����ժ�ǡ���\n");
    if( me->query_temp( "zhaixing") )
        return notify_fail("���Ѿ���ʹ�á�����ժ�ǡ���\n");
        me->set_temp( "zhaixing", 1 );        
    message_vision(BLU "$N��Хһ��������ժ�ǡ��������ſ����ż�һ�㡣ֻ���á�ಡ���һ�������Ѹ߸�Ծ�������⣡\n" NOR, me, target);
	
	dex = me->query_skill( "dodge" );
        dex = dex / 2;
	me->add("neili",-50);
    me->add_temp("apply/dodge",dex);

    skill = (me->query_skill("zhaixinggong",1))/ 2;
	me->start_call_out( (: call_other, __FILE__, "end_perform", me, dex :),skill/8);
	me->add("neili", -50);
	me->add("jingli", -50);
	return 1;
}

void end_perform( object me, int dex)
{
	me->add_temp("apply/dodge", -dex);
	me->delete_temp( "zhaixing" );
	tell_object(me, HIY "�㻺����ס���Σ�����һ�������������ջص��\n" NOR);
}
