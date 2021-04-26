// xiuxi.c ��Ů�ľ���ϰexert
// by April 01/08/09
// update April 01/08/21

#include <ansi.h>

/*
$Nͬ$n��ϰ��Ů�ľ�һ���ʱ�䣬ͷ�ϵ������������ࡣ
$Nһ�߸�$n��������һ�߽��Լ�������������ȫ���Ⱥ���ͷ��һ��һ�����˳�����
$n��$N�����İ�������Ů�ľ��ľ�����������ߣ����屻��ͣ�����İ�������Χ�ˣ�
*/

string *phases_me = ({
	"������������Ů�ľ�������������������������̫�����ߡ������� \n",
	"�����ڹ�������������ͷ�ϲ���΢΢���������ڹ����˻��֮��\n",
	"��������Ů�ľ��Ѿ�����һ��ʱ���������˿˿���ƣ��������ۡ�\n",
	"��ӽ��˹��������б�ȫ������ʱ������������ɵİ������������������������������Ƽ���һ�㣡\n",
	"����ϰ��Ů�ľ�ʱ��Խ��Խ����ͷ�����۰���ҲԽ��Խ�࣬��ͬ����������֮�У�\n",
	"����������е�Խ��Խ���죬��������������ҲԽ��Խ�࣬�ѽ������Χ��������\n",
	"��ֻ����һ�ɹ�ů�����ڶ��⻺����ɢ���ĵ׸��ӳ��ţ�������ϲ��\n",
});

int exercising(object me);
int halt_exercise(object me);

int exert(object me, object target)
{
	object 	where = environment(me);
	int xj_lvl_me = (int)me->query_skill("yunu-xinjing", 1);	//��Ů�ľ��ȼ�me
	int force_lvl_me = (int)me->query_skill("force", 1);		//�����ڹ��ȼ�me
	int xj_lvl_target; 	//��Ů�ľ��ȼ�target
	int force_lvl_target;		//�����ڹ��ȼ�target
	int v,i,j,k;		// ��ʱ����
	string *sname;	// skill����
	object *inv;	// ���ϴ��Ķ���
	mapping skl;	// ����skill

	seteuid(getuid());

    if( !objectp(target) || target == me )
		return notify_fail("��Ҫ��˭һ����������\n");

	xj_lvl_target = (int)target->query_skill("yunu-xinjing", 1);	//��Ů�ľ��ȼ�
	force_lvl_target = (int)target->query_skill("force", 1);		//�����ڹ��ȼ�

	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (where->query("sleep_room"))
		return notify_fail("��˯���ﲻ������Ů�ľ������Ӱ�����ˡ�\n");

	if (where->query("no_fight"))
		return notify_fail("����������Ů�ľ�����ʼ���ķ����ң��޷����ƣ�ֻ�����ա�\n");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");
	if (target->is_busy() || target->query_temp("pending/exercising"))
		return notify_fail("��Ļ��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("ս���в�������Ů�ľ������߻���ħ��\n");
	if( target->is_fighting() )
		return notify_fail("����Ļ��������˵�ɡ�\n");

	if( !stringp(me->query_skill_mapped("force")) )
		return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");
	if( !stringp(target->query_skill_mapped("force")) )
		return notify_fail("��Ļ�����ϲ����Ů�ľ���\n");

	if( me->query("rided") )
		return notify_fail("���������˹������߻���ħ�ġ�\n");
	if( target->query("rided") )
		return notify_fail("����������Ļ��������������ɡ�\n");

	// �����ڹ�С����Ů�ľ�60%������
	if( force_lvl_me < xj_lvl_me*60/100)
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");
	if( force_lvl_target < xj_lvl_target*60/100)
		return notify_fail("��Ļ�������̫���ˡ�\n");

	// lvlС��30������
	if (xj_lvl_me<30)
		return notify_fail("����������һ��������������Ȼ��Ů�ľ���Ϊ�����������޷���ת��\n");
	if (xj_lvl_target<30)
		return notify_fail("��Ļ�鹦����������\n");

	// �������
	if ( me->query_temp("weapon") )
        return notify_fail("��ϰ��Ů�ľ�������֣��������ķ��ɡ�\n");
	if ( target->query_temp("weapon") )
        return notify_fail("������Ļ��ѱ������°ɡ�\n");

	// ��������
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("equipped") 
			&& inv[i]->query("armor_type")=="cloth")
			i = sizeof(inv)+1;
	if (i==sizeof(inv)+2)
        return notify_fail("��ϰ��Ů�ľ������½󳨿����ܼ�ʱɢ��������\n");
	inv = all_inventory(target);
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("equipped") 
			&& inv[i]->query("armor_type")=="cloth")
			i = sizeof(inv)+1;
	if (i==sizeof(inv)+2)
        return notify_fail("��Ļ�鿴����������������\n");

	// �ڹ�Ҫ�����������Ԫ��
	k=0;
	skl=me->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );
    for(v=0; v<sizeof(skl); v++) {
		if (SKILL_D(sname[v])->check() == "force")
			k++;  
    }
    if ( k >=2 ) {
		return notify_fail("��о����ڲ�ͬ���������ײ��ֻ�����ա�\n");
	}
	k=0;
	skl=target->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );
    for(v=0; v<sizeof(skl); v++) {
		if (SKILL_D(sname[v])->check() == "force")
			k++;  
    }
    if ( k >=2 ) {
		return notify_fail("��Ļ���ڹ���̫����!\n");
	}

	if( (int)me->query("neili") < (int)me->query("max_neili")*60/100 )
		return notify_fail("�����ڵ�����������ϰ��Ů�ľ���\n");
	if( (int)target->query("neili") < (int)target->query("max_neili")*60/100 )
		return notify_fail("��Ļ���������㡣\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi"))
		return notify_fail("���������ˣ�ֻ��һ��������������Σ�գ�\n");
	if( (int)target->query("eff_qi") < (int)target->query("max_qi"))
		return notify_fail("��Ļ���������ˣ��Ȱ������˰ɣ�\n");

	if( (int)me->query("eff_jing") < (int)me->query("max_jing"))
		return notify_fail("���еĶ�û��ȫ�ã�ֻ��һ��������������Σ�գ�\n");
	if( (int)target->query("eff_jing") < (int)target->query("max_jing"))
		return notify_fail("��Ļ���еĶ�û��ȫ�ã�\n");

	if( (int)me->query("jing") < (int)me->query("max_jing")*90/100 )
		return notify_fail("�����ھ��������޷�������Ϣ��������\n");
	if( (int)target->query("jing") < (int)target->query("max_jing")*90/100 )
		return notify_fail("��Ļ�����ھ��������޷�������Ϣ��������\n");

	if( (int)me->query("jingli") < (int)me->query("max_jingli")*60/100 )
		return notify_fail("�����ھ����������޷�������Ϣ��������\n");
	if( (int)target->query("jingli") < (int)target->query("max_jingli")*60/100 )
		return notify_fail("��Ļ�����ھ����������޷�������Ϣ��������\n");

	if( (int)me->query("qi") < (int)me->query("max_qi")*60/100 )
		return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");
	if( (int)target->query("qi") < (int)target->query("max_qi")*60/100 )
		return notify_fail("��Ļ�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

	// ���ܿ���ϰ���� ---- 30n-1ʱ�������
	if ( (xj_lvl_me<270) && ((xj_lvl_me+1)/30*30 == xj_lvl_me + 1) )
		return notify_fail("�������ϰ����Ů�ľ�����Ȼ��������һ��... \n"
			+"���ƺ��������޷�ͻ��ƿ����������ʱ������ˡ� \n");
	if ( (xj_lvl_target<270) && ((xj_lvl_target+1)/30*30 == xj_lvl_target +1 ) )
		return notify_fail("��Ļ��ù����ˡ�\n");

	if ( (object)target->query_temp("pending/xiuxi") != me )
	{
		me->set_temp("pending/xiuxi",target);
		message_vision("\n$N����$n˵����" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�������ܺ�"
			+ RANK_D->query_respect(target) + "һ����ϰ��Ů�ľ���\n\n", me, target);
		tell_object(target, YEL "�����Ը��ͶԷ�һ����ϰ��Ů�ľ�������Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� yun xiuxi2 ָ�\n" NOR);
		write(YEL "���ڶԷ�������ҿ��Ƶ���������ȶԷ�ͬ����ܹ�ͬ��ϰ��Ů�ľ���\n" NOR);
		return 1;
	}
	else
	{
		message_vision("\n$N��$n�⿪��������ϥ���£�������ԣ���ʼ��ͬ��ϰ��Ů�ľ���\n" , me, target);
		me->set_temp("pending/xiuxi",target);
		me->set_temp("pending/exercise", 2);
		me->start_busy((: exercising :), (:halt_exercise:));
		target->set_temp("pending/exercise", 2);
		target->start_busy((: exercising :), (:halt_exercise:));
	}
	
	return 1;
}

int exercising(object me)
{
	int qi_cost;	//������
	int jingli_cost;	//��������
	int neili_gain;		//��������
	int xj_gain;	//�ľ�����
	int love_gain;	//lovingness����
	int xj_lvl = (int)me->query_skill("yunu-xinjing",1);	//�ľ�����
	int force_lvl = (int)me->query_skill("force",1);	//�����ڹ�����
	float f,g,h;	//�ɱ����
	string wiz_report;	//��ʦ����
	object where = environment(me);	//������
	object target = (object)me->query_temp("pending/xiuxi");	//���
	int xj_lvl_target = (int)target->query_skill("yunu-xinjing",1);	//����ľ�����

	//���ͣ��ͣ
	if( target->query_temp("pending/exercise") != 2 )
	{
		me->set_temp("pending/exercise", 0);
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

	if( me->query_skill_mapped("force") != "yunu-xinjing" )
		return 0;
	
	//�������ĺ����ã����Ǹ��ӵ��㷨
	neili_gain = 1 + (int)me->query_skill("force") / 10;
	jingli_cost = to_int(sqrt((xj_lvl/to_float(150)))*60);
	qi_cost = jingli_cost + neili_gain;

	if( (int)me->query("qi") > (int)me->query("max_qi")*30/100 
		&& (int)me->query("jingli") > (int)me->query("max_jingli")*30/100
		&& 	((xj_lvl>270) || ((xj_lvl+1)/30*30 != xj_lvl+1)))
	{
		me->add("neili", neili_gain);
		f = to_float(target->query("combat_exp"))/me->query("combat_exp");
		if (f>=2) f=2;
		else if (f>=0.5) f = to_float(1.8*pow(f-0.5,0.25));
		else f=0;
		xj_gain = to_int(pow(force_lvl/4+1,1.1)*f);
		if (me->is_spouse_of(target)){
			xj_gain *= 1.5;
			love_gain =xj_gain*2;
		}
		else if (me->query("gender") != target->query("gender")) xj_gain *= 1.1;
		me->improve_skill("yunu-xinjing", xj_gain, 0);
		write(phases_me[random(6)]);
		me->receive_damage("qi", qi_cost, "���ڹ��߻���ħ����");
		me->receive_damage("jingli", jingli_cost, "���ڹ��߻���ħ����");

		wiz_report = "ÿ�ε�"+chinese_number(neili_gain)+"��������"
			+chinese_number(xj_gain)+"����Ů�ľ�";
		if (me->is_spouse_of(target)){
			wiz_report = wiz_report+chinese_number(love_gain)+"��˫��˫��";
			me->improve_skill("lovingness", love_gain, 0);
		}
		wiz_report = wiz_report + "; \n ����" + chinese_number(qi_cost) + "������"
			+chinese_number(jingli_cost)+"�㾫����\n";

  		if( wizardp(me) ) tell_object(me, wiz_report);

		return 1;
	}
	else {
		me->set_temp("pending/exercise", 0);
		message_vision("$N��$n�˹���ϣ���Ϣ���£���̬���ɵ�վ��������\n", me,target);
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
}

int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
	me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	return 1;
}

