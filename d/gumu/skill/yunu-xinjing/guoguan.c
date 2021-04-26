// xiuxi.c ��Ů�ľ�����exert
// by April 01/08/21

#include <ansi.h>

/*
$nһ����Х��������������˫�ְ���$N���ϣ�����$N���أ�
$N���岻ͣ�Ĳ����Ⱥ�������һ��һ���ð�˳�������ɫҲ����ˣ����������ڹ��ڹ��������ѹأ�
$N�������£�һ����ɫ��ĺ���һ���ֱ�����ף�ȫ��$n�������ŵ��Լ���ά��ͻ����Ů�ľ����ѹأ�
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
		return notify_fail("����Ҫ˭������ذ���\n");

	if ( (xj_lvl_me>=270) && ((object)target->query_temp("pending/guoguan") != me ) )
		return notify_fail("�����Ů�ľ��Ѿ���ɣ���Ҳû�йؿɹ��ˡ� \n");

	if ( (xj_lvl_me+1)/30*30 != xj_lvl_me+1 
		&& (object)target->query_temp("pending/guoguan") != me )
		return notify_fail("�����û�����ص�ʱ��\n");

	xj_lvl_target = (int)target->query_skill("yunu-xinjing", 1);	//��Ů�ľ��ȼ�
	force_lvl_target = (int)target->query_skill("force", 1);		//�����ڹ��ȼ�

	if ( target->query("combat_exp") < me->query("combat_exp")/2 )
		return notify_fail("�������书���̫���ˣ�\n");

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
		return notify_fail("ս���й��أ�����������\n");
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
        return notify_fail("�����·����أ��������ܼ�ʱ��ɢ��̫�����ˡ�\n");
	inv = all_inventory(target);
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("equipped") 
			&& inv[i]->query("armor_type")=="cloth")
			i = sizeof(inv)+1;
	if (i==sizeof(inv)+2)
        return notify_fail("��Ļ�鿴������������㡣\n");

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

	if( (int)me->query("neili") < (int)me->query("max_neili") )
		return notify_fail("�����ڵ�����������ϰ��Ů�ľ���\n");
	if( (int)target->query("neili") < (int)target->query("max_neili") )
		return notify_fail("��Ļ���������㡣\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi"))
		return notify_fail("���������ˣ�ֻ��һ��������������Σ�գ�\n");
	if( (int)target->query("eff_qi") < (int)target->query("max_qi"))
		return notify_fail("��Ļ���������ˣ��Ȱ������˰ɣ�\n");

	if( (int)me->query("eff_jing") < (int)me->query("max_jing"))
		return notify_fail("���еĶ�û��ȫ�ã�ֻ��һ��������������Σ�գ�\n");
	if( (int)target->query("eff_jing") < (int)target->query("max_jing"))
		return notify_fail("��Ļ���еĶ�û��ȫ�ã�\n");

	if( (int)me->query("jing") < (int)me->query("max_jing") )
		return notify_fail("�����ھ��������޷�������Ϣ��������\n");
	if( (int)target->query("jing") < (int)target->query("max_jing") )
		return notify_fail("��Ļ�����ھ��������޷�������Ϣ��������\n");

	if( (int)me->query("jingli") < (int)me->query("max_jingli") )
		return notify_fail("�����ھ����������޷�������Ϣ��������\n");
	if( (int)target->query("jingli") < (int)target->query("max_jingli") )
		return notify_fail("��Ļ�����ھ����������޷�������Ϣ��������\n");

	if( (int)me->query("qi") < (int)me->query("max_qi") )
		return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");
	if( (int)target->query("qi") < (int)target->query("max_qi") )
		return notify_fail("��Ļ�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");


	if ( (object)target->query_temp("pending/guoguan") != me )
	{
		me->set_temp("pending/guoguan",target);
		message_vision("\n$N���ֶ���$n˵����" 
			+ RANK_D->query_self(me) 
			+ me->name() + "������"
			+ RANK_D->query_respect(target) + "�ܰ��ҹ�����\n\n", me, target);
		tell_object(target, YEL "�����Ը���Է����أ�����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� yun guoguan ָ�\n" NOR);
		return 1;
	}
	else
	{
		message_vision("\n$N�⿪��������ϥ���£���$n������ԣ���ʼ��$n���ء�\n" , me, target);
		me->set_temp("pending/guoguan",target);
		me->set_temp("pending/exercise", 3);
		me->start_busy((: exercising :), (:halt_exercise:));
		target->set_temp("pending/exercise", 4);
		target->start_busy((: exercising :), (:halt_exercise:));
	}
	
	return 1;
}

int exercising(object me)
{
	string wiz_report;	//��ʦ����
	object where = environment(me);	//������
	object target = (object)me->query_temp("pending/guoguan");	//���
	int xj_lvl_target = (int)target->query_skill("yunu-xinjing",1);	//����ľ�����
	int xj_lvl = (int)me->query_skill("yunu-xinjing",1);	//�ľ�����
	int time;	//����ʱ��
	int i;

	if( wizardp(me) ) tell_object(me, "pending/exercise=me" +chinese_number(me->query_temp("pending/exercise"))+"\n");
	if( wizardp(me) ) tell_object(me, "pending/exercise=target" +chinese_number(target->query_temp("pending/exercise"))+"\n");

	//���ͣ��ͣ
	if( target->query_temp("pending/exercise") < 3 )
	{
		me->set_temp("pending/exercise", 0);
		me->set_temp("pending/guoguan", me);
		return 0;
	}

	if( me->query_skill_mapped("force") != "yunu-xinjing" )
		return 0;
	
	time = to_int(sqrt(xj_lvl)*10);

	if (me->query_temp("pending/exercise") > 3 ){
		if (me->query_temp("pending/exercise") < time){
			me->set_temp("pending/exercise", me->query_temp("pending/exercise") +1);
	  		if( wizardp(me) ) tell_object(me, "����ɰٷ�֮"+chinese_number(me->query_temp("pending/exercise")*100/time) +" \n");

		}
		else{
			me->set("max_neili",me->query("max_neili")+(xj_lvl+1)/2);
			target->set("max_neili",target->query("max_neili")+(xj_lvl_target+1)/4);

			me->set_skill("yunu-xinjing",xj_lvl+1);
			i= xj_lvl_target;
			i= i*i/2;
			target->improve_skill("yunu-xinjing", i, 0);

			me->set("neili",0);
			me->set("qi",me->query("max_qi")/5);
			me->set("jingli",me->query("max_jingli")/5);
			me->set("jing",me->query("max_jing")/5);

			target->set("neili",target->query("max_neili")/4);
			target->set("qi",target->query("max_qi")/2);
			target->set("jingli",target->query("max_jingli")/2);
			target->set("jing",target->query("max_jing")/2);

			if (me->is_spouse_of(target)){
				me->set_skill("lovingness",me->query_skill("lovingness",1)+1);
				target->set_skill("lovingness",target->query_skill("lovingness",1)+1);
			}

			me->set_temp("pending/guoguan",me);
			me->set_temp("pending/exercise",0);
			message_vision("$N��$n�˹���ϣ���Ϣ���£����ص�ϲ��������$N�����ϡ�\n", me,target);
			return 0;
		}
	}

	return 1;

}

int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
	me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	me->set_temp("pendinf/guoguan",me);
	return 1;
}

