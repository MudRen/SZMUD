//Cracked by Roath
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **\
 * heal.c �ڹ��������˹���						*
 *									*
 * �ڹ�Ӧ��ӵ�м��ֹ��еĹ��ܣ������еĴ��������š��������˾����˾����� *
 * �Լ������еı�ƴ������������ת��Ϣ��������ҲӦ���������ڹ���Ӧ���е� *
 * ���ܡ�								*
 * ���������е��˺�ϵͳ�������˺�������ȫû�����������������������£� *
 * �ڹ��ߣ�������Ȼ���׺á�����ȴδ�أ��ֲ�����һ�ˣ����������������� *
 * ����������ˡ����������ڴ󲿷������ֻ�ܽ��������ҩ��ĸ��������ơ�	*
 * ��������ͨ���˶�����ͨ����ת��Ϣ�����ƣ������߲���춲�ͬ�ڹ�������� *
 * ����Ч���ĺû��������������Խ�أ�Ч��ԽС��������ǰ������һ�ζ����� *
 * �����͹̶��ָ����١�ͨ�����˵Ŀ�����������ӿ������ٶȡ������˵Ŀ��� *
 * �ٶȣ������ȡ���������Ƶĳ̶ȣ�����ҩ���ҩ�ԣ��Լ�����ļ��⹹�죬 *
 * Ҳ���������������constitution��					*
 * ����������ֳ������˵Ĳ�ͬ�����������е��˺�ϵͳ���ø������ԣ���Щ�� *
 * �Ժ���Ҫ�ı�ģ�������Ҫ˵����ֻ�����¹���ֻ����������Ϊǰ�ῼ�ǣ��� *
 * �Ի�����������������е��˺�ϵͳ��������Ĳ������ԡ�			*
 *									*
 * Maco && xQin 11/99							*
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

#include <ansi.h>

int curing(object);
int halt_curing(object);
void remove_pending(object, object);

mapping eff_heal = ([
	"jiuyang-shengong"	: 9,	// �����������˷����Ч���޿����ɡ�
	"hunyuan-yiqi"		: 8,	// ����׽�Լ������������˷����Ч����
	"zixia-gong"		: 8,
// ��ϼ�񹦼���Ԫ�������Ʒ���û��ʲô�ἰ�������м�������˵�Ч�����Լ�����Ⱥ�������������
// ��ϰ��ϼ�����������ˣ��ɼ�����Ʒ����Ч��������������׽��������������������������
// �ǵ�������ϼ��û��ʲô�ر��exert��ҲӦ������ϼ�������Ʒ����Ч�����������ڹ����á�
	"taiji-shengong"	: 8,
	"xiantian-gong"		: 8,	// �������൱ƪ���ᵽ�䵱��������ȫ�������ڹ������ˡ�
	"kurong-changong"	: 6,	// �����ڹ������˷����Ч���ܺã����������Ʒ���ȴû
					// ��ʲô�ر�֮����
	"linji-zhuang"		: 6,	// �����ڹ������˷���û��ʲô�ر����������������Ǿ�
					// ��һϵ��
	"taixuan-gong"		: 5,
	"bitao-xuangong"	: 5,
	"yunu-xinjing"		: 5,
	"xiaowuxiang"		: 5,
	"huntian-qigong"	: 4,	// ���칦����󡹦������������ߵĶ��Ǹ���һ·���ڹ���
	"hamagong"		: 4,	// ��������˷���������Щ��
	"longxiang-banruo"	: 4,
	"beiming-shengong"	: 3,	// ��ڤ������������������������Ӱ������ʱ��Ч����
	"huagong-dafa"		: 2,	// �������Զ������������˷���Ч��Ӧ����Ϊ���á�
	"dulong-dafa"		: 2,
	"hongming-xuangong"	: 1,
	"ding-force"		: 1,	// ���������ڹ�����δ���ἰ������Ϊ���ɿ���
]);

int exert(object me, object target)
{
	string force_skill;
	mapping msg;
	int mode;

	if( !wizardp(me) || !wizardp(target)) return 0;
	if( !target ) target == me;
	if( target == me ) mode = 1;
	else mode = 2;
	
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if( me->is_busy() || me->query_temp("exit_blocked") )
		return notify_fail("��������æ���ء�\n");

	if( me->query_temp("cursed") )
		return notify_fail("ʲô��\n");

	if( me->query("rided") )
		return notify_fail("���������˹����ˣ����߻���ħ��\n");

	if( !(force_skill = me->query_skill_mapped("force")) )
		return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");

	if( me->query_skill("force", 1) < 50 )
		return notify_fail("����ڹ�����ʶ����������֪��ΰ�����Ϣ���ˡ�\n");

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("���������Ϊ̫�ͣ����޷�������Ϣ���ˡ�\n");

	msg = SKILL_D(force_skill)->curing_msg(me, target);

	if ( mode == 1 ) {			
		if( (int)me->query("neili") < 50 )
			return notify_fail("�����ڵ�����������\n");
	
		if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
			return notify_fail("�㲢δ�ܵ����ˡ�\n");
	
		if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
			return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
	
		if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
			return notify_fail("�����ھ��������޷�������Ϣ��������\n");
	
		if( !msg || undefinedp(msg["start_self"]) )
			tell_object(me, HIW"��ȫ����ɣ���������ʼ�˹����ˡ�\n"NOR);
		else	tell_object(me, msg["start_self"]);
	
		if( !msg || undefinedp(msg["start_other"]) )
			message("vision", me->name() +"��ϥ���£���ʼ�˹����ˡ�\n"NOR,
				environment(me), me);
		else	message("vision", msg["start_other"], environment(me), me);
	
		if( !msg || undefinedp(msg["apply_short"]) )
			me->set_temp("apply/short", ({ me->name() +"�����ڵ����˹����ˡ�"}));
		else	me->set_temp("apply/short", ({ msg["apply_short"] }));
	
		me->set_temp("pending/curing", 1);
		me->set_temp("pending/mode", 1);
		me->start_busy((: curing :), (: halt_curing :));
		me->set("jiali", 0);
		return 1;
	} else {
		if ( objectp(target->query_temp("pending/heal_other")) && target->query_temp("pending/heal_other") != me)
			return notify_fail((target->query_temp("pending/heal_other"))->name()+"����Ϊ"+target->name()+"���ˡ�\n");

		if ( (int)me->query_skill(force_skill , 1) < 50 )
			return notify_fail("��"+to_chinese(force_skill)+"������̫ǳ������Ϊ�����������ˣ�\n");

		if( (int)me->query("max_neili") < 300 )
			return notify_fail("���������Ϊ������\n");

		if( (int)me->query("neili") < 150 )
			return notify_fail("�������������Ϊ"+target->name()+"���ˡ�\n");

		if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
			return notify_fail( target->name() +"�Ѿ����˹��أ����ܲ�����������𵴣�\n");

		if( (int)target->query("eff_qi") >= (int)target->query("max_qi") )
			return notify_fail( target->name() +"û�����ˣ�������������ˣ�\n");

		if( !living(target) )
			return notify_fail("�����ѻ��������ˣ����ܾ��Σ�\n");

		if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
			return notify_fail("�����ھ��������޷�������Ϣ��������\n");
	
		if( !msg || undefinedp(msg["start_healother_self"]) ){
			tell_object(me, HIW"��ȫ����ɣ���������ʼΪ"+ target->name() +"�˹����ˡ�\n"NOR);
			tell_object(target, HIW"��ȫ����ɣ���������"+ me->name() +"Ϊ�Լ��˹����ˡ�\n"NOR);
		} else {
			tell_object(me, msg["start_healother_self"]["me"]);
			tell_object(target, msg["start_healother_self"]["target"]);
		}
			
		if( !msg || undefinedp(msg["start_healother_other"]) )
			message("vision", me->name() +"��ϥ���£���ʼΪ"+ target->name() +"�˹����ˡ�\n"NOR,
				environment(me), ({ me, target}));
		else	message("vision", msg["start_healother_other"], environment(me), ({ me, target}));
	
		if( !msg || undefinedp(msg["apply_short_other"]) ){
			me->set_temp("apply/short", ({ me->name() + "�����ڵ���Ϊ" + target->name() + "�˹����ˡ�"}));
			target->set_temp("apply/short", ({ target->name() + "�����ڵ��£�" + me->name() + "����Ϊ���˹����ˡ�"}));
		} else {
			me->set_temp("apply/short", ({ msg["apply_short_other"]["me"] }));
			target->set_temp("apply/short", ({ msg["apply_short_other"]["target"] }));
		}
		
		me->set_temp("pending/curing_other", 1);
		me->set_temp("pending/mode", 2);
		me->set_temp("pending/heal_other", target);
		target->set_temp("pending/mode", 3);
		target->set_temp("pending/heal_other", me);
		target->set_temp("pending/curing_other", 1);
		me->start_busy((: curing :), (: halt_curing :));
		target->start_busy((: curing :), (: halt_curing :));
		me->set("jiali", 0);
		return 1;
	}
}

int curing(object me)
{
	int effect, lvl, con, max, eff, mode = me->query_temp("pending/mode");
	string force_skill;
	mapping msg;
	object target = me->query_temp("pending/heal_other");

	if(mode == 1){
		if( !living(me) || me->is_ghost() || !(force_skill = me->query_skill_mapped("force")) )
		{
			remove_pending(me, target);
			return 0;
		}

		msg = SKILL_D(force_skill)->curing_msg(me);		

		if( me->query("jing") < 1 || me->query("jingli") < 1 )
		{
			remove_pending(me, target);
			me->unconcious();
			return 0;
		}
		else if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
		{
			if( !msg || undefinedp(msg["finish_self"]) )
				tell_object(me, HIY"���˹����ã��Ծ�����˳�������˾�ȥ����Ԫ�����վ��������\n"NOR);
			else	tell_object(me, msg["finish_self"]);
		
			if( !msg || undefinedp(msg["finish_other"]) )
				message("vision", me->name() +"�˹���ϣ�վ������������ȥ��ɫ�����������ӡ�\n"NOR,	environment(me), me);
			else	message("vision", msg["finish_other"], environment(me), me);
		
			remove_pending(me, target);
			return 0;
		}
		else if( (int)me->query("neili") < 50 )
		{
			if( !msg || undefinedp(msg["unfinish_self"]) )
				tell_object(me, "�������˹����ˣ�������Ϣ��̷���������ݻ����ˣ�վ��������\n"NOR);
			else	tell_object(me, msg["unfinish_self"]);
		
			if( !msg || undefinedp(msg["unfinish_other"]) )
				message("vision", me->name() +"�˹���ϣ�����վ����������ɫ������������ࡣ\n"NOR,environment(me), me);
			else	message("vision", msg["unfinish_other"], environment(me), me);
		
			remove_pending(me, target);
			return 0;
		}
		
		lvl = me->query_skill("force");	// my enable force level.
		max = me->query("max_neili");	// my max neili.
		con = me->query("con");		// my original constitution.
		eff = eff_heal[force_skill];	// my force's effect on heal.
		if( !eff ) eff = 1;
		
		effect = lvl * max/10 * eff / (2*lvl + lvl*con*2/30) / 10;
		
		con = me->query_con();		// use apply constitution instead of original here.
		effect = (effect+random(effect))/2 + (con+random(con))/4;
		effect = effect * ((int)me->query("eff_qi")*100 / (int)me->query("max_qi")) / 100;
		
		if( wizardp(me) ) tell_object(me, "ÿ������"+chinese_number(effect)+"�����ˡ�\n");
		me->receive_curing("qi", effect);
		me->receive_heal("qi", effect/2);
		me->add("neili", -50);
		return 1;
	} else if(mode == 2){
		if( !living(me) || me->is_ghost() || !(force_skill = me->query_skill_mapped("force"))
		 || !living(target) || target->is_ghost())
		{
			remove_pending(me, target);
			return 0;
		}

		msg = SKILL_D(force_skill)->curing_msg(me, target);
		
		if( me->query("jing") < 1 || me->query("jingli") < 1 )
		{
			remove_pending(me, target);
			me->unconcious();
			return 0;
		}
		else if( (int)target->query("eff_qi") >= (int)target->query("max_qi") )
		{
			if( !msg || undefinedp(msg["finish_healother_self"]) ){
				tell_object(me, HIY"���˹����ã�ֻ��"+target->name()+"����Ϣ���ȣ������Ѿ�Ȭ�����������ڹ�վ��������\n"NOR);
				tell_object(target, HIY"��ֻ����Ϣ���ȣ������Ѿ�Ȭ������ʱ"+me->name()+"�����ڹ�վ��������Ҳ����һ���ڹ���վ��������\n"NOR);
			} else {
				tell_object(me, msg["finish_healother_self"]["me"]);
				tell_object(target, msg["finish_healother_self"]["target"]);
			}
					
			if( !msg || undefinedp(msg["finish_healother_other"]) )
				message("vision", me->name() +"�о�"+target->name()+"����Ϣ���ȣ������Ѿ�Ȭ�����������ڹ�վ��������\n"NOR,	environment(me), me);
			else	message("vision", msg["finish_healother_other"], environment(me), ({ me, target}));
		
			remove_pending(me, target);
			return 0;
		}
		else if( (int)me->query("neili") < 50 )
		{
			if( !msg || undefinedp(msg["unfinish_healother_self"]) ){
				tell_object(me, "�������˹�Ϊ"+target->name()+"���ˣ�������Ϣ��̷���������ݻ����ˣ�վ��������\n"NOR);
				tell_object(target, "��ֻ����"+me->name()+"����Ϣʱ��ʱ���������������㣬�����"+me->name()+"�ݻ�Ϊ�����ˡ�\n"NOR);
			} else {
				tell_object(me, msg["unfinish_healother_self"]["me"]);
				tell_object(target, msg["unfinish_healother_self"]["target"]);
			}
				
			if( !msg || undefinedp(msg["unfinish_healother_other"]) )
				message("vision", me->name() +"�˹���ϣ�����վ��������"+target->name()+"����ɫ����������һЩ��\n"NOR,environment(me), me);
			else	message("vision", msg["unfinish_healother_other"], environment(me), ({ me, target}));
		
			remove_pending(me, target);
			return 0;
		}
		
		lvl = me->query_skill("force");	// my enable force level.
		max = me->query("max_neili");	// my max neili.
		con = me->query("con");		// my original constitution.
		eff = eff_heal[force_skill];	// my force's effect on heal.
		if( !eff ) eff = 1;
		
		effect = lvl * max/10 * eff / (2*lvl + lvl*con*2/30) / 15;
		
		con = target->query_con();		// use apply constitution instead of original here.
		effect = (effect+random(effect))/2 + (con+random(con))/4;
		effect = effect * ((int)target->query("eff_qi")*100 / (int)target->query("max_qi")) / 100;
		
		if( wizardp(me) ) tell_object(me, "ÿ������"+target->name()+chinese_number(effect)+"�����ˡ�\n");
		if( wizardp(me) ) tell_object(target, me->name()+"ÿ��������"+chinese_number(effect)+"�����ˡ�\n");
		target->receive_curing("qi", effect);
		target->receive_heal("qi", effect/2);
		me->add("neili", -(50 + random(con)));
		return 1;
	} else {
		if( !living(me) || me->is_ghost() || !living(target) || target->is_ghost() )
		{
			remove_pending(me, target);
			return 0;
		}
		return 1;		
	}
}

int halt_curing(object me)
{
	int mode = me->query_temp("pending/mode");
	string force_skill;
	mapping msg;
	object target = me->query_temp("pending/heal_other");
	
	force_skill = me->query_skill_mapped("force");
	if( force_skill ) msg = SKILL_D(force_skill)->curing_msg(me, target);

	me->receive_damage("qi", 50, "�ڹ��߻���ħ����");
	me->add("neili", -50);
	if( me->query("neili") < 0 ) me->set("neili", 0);

	if(mode == 1){
		if( !msg || undefinedp(msg["halt_self"]) )
			tell_object(me, "��������Ϣ��Ӳ�����ؽ���Ϣѹ����ȥ������վ��������\n");
		else	tell_object(me, msg["halt_self"]);
	
		if( !msg || undefinedp(msg["halt_other"]) )
			message("vision", me->name() +"����һ���³�һ����Ѫ������վ��������\n", environment(me), me);
		else	message("vision", msg["halt_other"], environment(me), me);
	
	       	remove_pending(me, target); 
		me->start_busy(1+random(3));
		return 1;
	} else if(mode == 2){
		if( !msg || undefinedp(msg["halt_healother_self"]) ){
			tell_object(me, "��������Ϣ�������ؽ���Ϣѹ����ȥ������վ��������\n");
			tell_object(target, "��ֻ��"+me->name()+"�����ؽ���Ϣ���˻�ȥ������û������Ϣ���㻺��վ��������\n");
		}else{
			tell_object(me, msg["halt_healother_self"]["me"]);
			tell_object(target, msg["halt_healother_self"]["target"]);
		}
			
		if( !msg || undefinedp(msg["halt_healother_other"]) )
			message("vision", target->name() +"����һ���³�һ����Ѫ��"+me->name()+"�����ڹ�����վ��������\n", environment(me), ({ me, target}));
		else	message("vision", msg["halt_healother_other"], environment(me), ({ me, target}));
	
	       	remove_pending(me, target); 
		me->start_busy(1+random(3));
		target->start_busy(1+random(3));
		return 1;
	} else {
		tell_object(me, "����"+target->name()+"��������˵��������Ϊ�������ˡ�\n����"+target->name()+"�ڹ��ջغ󻺻�վ��������\n");
		tell_object(target, me->name()+"�����������˵��������Ϊ�������ˡ�\n��֪��"+me->name()+"�����˺���һЩ���������ڹ�����վ��������\n");
		message("vision", me->name() +"��"+target->name()+"��������˵��Щʲô��"+target->name()+"�����ڹ���"+me->name()+"һ�𻺻�վ��������\n", environment(me), ({ me, target}));

	       	remove_pending(me, target); 
		me->start_busy(1+random(3));
		target->start_busy(1+random(3));
		return 1;
	}
}



void remove_pending(object me, object target)
{
	me->delete_temp("pending/curing");
	me->delete_temp("apply/short");
	me->delete_temp("pending/mode");
	me->delete_temp("pending/heal_other");
	if (objectp(target)){
		target->delete_temp("pending/curing");
		target->delete_temp("apply/short");
		target->delete_temp("pending/mode");
		target->delete_temp("pending/heal_other");
	}
}
