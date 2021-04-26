// Code of ShenZhou
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **\
 * heal.c �ڹ��������˹���						*
 *									*
 * �ڹ�Ӧ��ӵ�м��ֹ��еĹ��ܣ������еĴ��������š��������˾����˾����� *
 * �Լ������еı�ƴ������������ת��Ϣ��������ҲӦ���������ڹ���Ӧ���е� *
 * ���ܡ�								*
 * �����ݡ����е��˺�ϵͳ�������˺�������ȫû�����������������������£� *
 * �ڹ��ߣ�������Ȼ���׺á�����ȴδ�أ��ֲ�����һ�ˣ����������������� *
 * ����������ˡ����������ڴ󲿷������ֻ�ܽ��������ҩ��ĸ��������ơ�	*
 * ��������ͨ���˶�����ͨ����ת��Ϣ�����ƣ������߲���춲�ͬ�ڹ�������� *
 * ����Ч���ĺû��������������Խ�أ�Ч��ԽС��������ǰ�����ݡ�һ�ζ����� *
 * �����͹̶��ָ����١�ͨ�����˵Ŀ�����������ӿ������ٶȡ������˵Ŀ��� *
 * �ٶȣ������ȡ���������Ƶĳ̶ȣ�����ҩ���ҩ�ԣ��Լ�����ļ��⹹�죬 *
 * Ҳ���ǡ����ݡ������constitution��					*
 * ����������ֳ������˵Ĳ�ͬ�����������ݡ����˺�ϵͳ���ø������ԣ���Щ�� *
 * �Ժ���Ҫ�ı�ģ�������Ҫ˵����ֻ�����¹���ֻ����������Ϊǰ�ῼ�ǣ��� *
 * �Ի�������֡����ݡ����е��˺�ϵͳ��������Ĳ������ԡ�			*
 *									*
 * Maco && xQin 11/99							*
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

#include <ansi.h>

int curing(object);
int halt_curing(object);
void remove_pending(object);

mapping eff_heal = ([
	"jiuyang-shengong"	: 9,	// �����������˷����Ч���޿����ɡ�
	"hunyuan-yiqi"		: 8,	// ����׽�Լ������������˷����Ч����
	"zixia-gong"		: 8,
// ��ϼ�񹦼���Ԫ�������Ʒ���û��ʲô�ἰ�������м�������˵�Ч�����Լ�����Ⱥ�������������
// ��ϰ��ϼ�����������ˣ��ɼ�����Ʒ����Ч��������������׽��������������������������
// �ǵ�������ϼ��û��ʲô�ر��exert��ҲӦ������ϼ�������Ʒ����Ч�����������ڹ����á�
	"taiji-shengong"	: 7,
        "xuantian-wuji"        : 6,
	"xiantian-gong"		: 7,	// �������൱ƪ���ᵽ�䵱��������ȫ�������ڹ������ˡ�
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

int exert(object me)
{
	string force_skill;
	mapping msg;

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

	if( (int)me->query("neili") < 50 )
		return notify_fail("�����ڵ�����������\n");

	if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
		return notify_fail("�㲢δ�ܵ����ˡ�\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("�����ھ��������޷�������Ϣ��������\n");

	msg = SKILL_D(force_skill)->curing_msg(me);

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
	me->start_busy((: curing :), (: halt_curing :));
	me->set("jiali", 0);
	return 1;
}

int curing(object me)
{
	int effect, lvl, con, max, eff;
	string force_skill;
	mapping msg;
        
	if( !living(me) || me->is_ghost() || !(force_skill = me->query_skill_mapped("force")) )
	{
		remove_pending(me);
		return 0;
	}

	msg = SKILL_D(force_skill)->curing_msg(me);

	if( me->query("jing") < 1 || me->query("jingli") < 1 )
	{
		remove_pending(me);
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

		remove_pending(me);
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

		remove_pending(me);
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
}

int halt_curing(object me)
{
	string force_skill;
	mapping msg;

	force_skill = me->query_skill_mapped("force");
	if( force_skill ) msg = SKILL_D(force_skill)->curing_msg(me);

	me->receive_damage("qi", 50, "�ڹ��߻���ħ����");
	me->add("neili", -50);
	if( me->query("neili") < 0 ) me->set("neili", 0);

	if( !msg || undefinedp(msg["halt_self"]) )
		tell_object(me, "��������Ϣ��Ӳ�����ؽ���Ϣѹ����ȥ������վ��������\n");
	else	tell_object(me, msg["halt_self"]);

	if( !msg || undefinedp(msg["halt_other"]) )
		message("vision", me->name() +"����һ���³�һ����Ѫ������վ��������\n", environment(me), me);
	else	message("vision", msg["halt_other"], environment(me), me);

       	remove_pending(me); 
	me->start_busy(1+random(3));
	return 1;
}

void remove_pending(object me)
{
	me->delete_temp("pending/curing");
	me->delete_temp("apply/short");
}
