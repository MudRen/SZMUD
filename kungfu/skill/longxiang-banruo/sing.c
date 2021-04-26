// Code of ShenZhou
// fanchang.c ��
// Summer 9/29/96.
// snowbird 9 1999
// 1.1.1.2

#include <ansi.h>

//inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
	object obj, weapon;
	int xf, af, sp, ap, sucess, j;  
	if( !target ) target = offensive_target(me);
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("id") != "lubo")
                return notify_fail("��δִ���������������󳪡�\n");
	if ((!objectp(obj = present("kulou guan", me)) ) ||
               (!obj->query("equipped") )) 
		return notify_fail("��δ�����ùڣ����������󳪡�\n");
	if ((!objectp(obj = present("rentou lian", me)) ) ||
               (!obj->query("equipped") ))
                return notify_fail("��δ����ͷ�������������󳪡�\n");

	if( !objectp(target) || target == me)
		return notify_fail("����Ҫ����˭����\n");

	if( !target->is_character() || target->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if( target->query("race") != "����")
		return notify_fail(target->query("name") + "������������\n");

    if ((int)me->query("jingli") < 300)
                return notify_fail("��ľ���������\n");

	if( (int)me->query("neili") < 600 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("necromancy",1) < 30 )
                return notify_fail("��Ľ���������������\n");

	if( (int)me->query_skill("lamaism", 1) < 30 )
                return notify_fail("��������ķ�����������\n");

	if( (int)me->query_skill("longxiang-banruo", 1) < 30 )
		return notify_fail("����������������������\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܳ���\n");
	
	// use condition instead to avoid temp variables
    if( target->query_condition("xs_necromancy") > 0 || target->query_temp("block_msg/all", 1) )
/*	if( target->query_temp("cursed", 1) || target->query_temp("block_msg/all", 1)) */
		return notify_fail("�����ѱ�������\n");

	// allow more than one target
/*	if( (int)me->query_temp("curser") )
                return notify_fail("�㽵������һ���ˣ�\n"); */

	me->add("neili", -400 + me->query_skill("necromancy"));
	me->receive_damage("jingli",  50);

	message_vision(
		BLU "$Nҡͷ���ԣ����б��д�˷𾭣����������������䡣���������ٴ죬�����з����������ɡ�\n" NOR, me);

			tell_object(target,  "�����������ȹ�޻��������Դ���һ�����ң���ǰһ�ѹ�Ӱ��������������������֫��������Ȼ��˯��\n");

	// also take my jing level into effect	
	xf = (me->query_skill("necromancy", 1) + me->query_skill("lamaism", 1));
	ap = target->query("jing")/10 + target->query_skill("force") + target->query("con")  + target->query("int") ; 
	sp = me->query_skill("force") + me->query("jing")/20 + xf;
	sp *= me->query("combat_exp")/1000;
    ap *= target->query("combat_exp")/1000;
	sucess = 0;
	// make sing player a lot tougher
	if (userp(target)) {
		if (random(sp) > (ap*2.5))
		  sucess = 1;
    }  
	else {
		if (random(sp) > (ap*1.2))
		  sucess = 1;
    }
	// victim will lose some jing each time trying to resist the sing
	j = target->query("jing");
	j = j - me->query_skill("necromancy",1);
	if (j<0)
	    j=0;
	target->set("jing",j);

	if( sucess && !target->query("no_sing")){
	  tell_object(target, HIR "��ֻ������ǰ��һ����������Զȥ����Ļ�����Ҫ���ϣ������������ס�\n" NOR);
	  message_vision("�㿴��" +target->query("name") +"ͻȻ��ʼ���۷�ֱ������������ǰ����\n", me);
	  target->remove_all_killer();
      target->apply_condition("xs_necromancy", (int)(me->query_skill("necromancy", 1)/20));

	  target->set("xueshan/necromancy_singer", me->query("id"));
//	  me->set_temp("curser", 1);
      target->set_temp("block_msg/all", 1);
	  if((int)target->query("combat_exp") > me->query("combat_exp")/2
	  && userp(target)){
		me->improve_skill("necromancy", me->query("int"));
		me->add("combat_exp", 1);
	  }
	  return 1;
	}
	else{
	  me->start_busy(random(7));
	  if( !target->is_killing(me) ) target->kill_ob(me);	
	  return 1;
	}
}

