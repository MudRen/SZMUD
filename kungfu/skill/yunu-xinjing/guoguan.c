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

int xiuxi(object me);
int halt_xiuxi(object me);

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

	//�ǻ���Ůֻ���ڻ�����������
	if( target->query("gender") != me->query("gender")
		&& !me->is_spouse_of(target)
		&& where->query("short") != "��������" )
		return notify_fail("��������һ���������߲��߰���\n");

	if ( (xj_lvl_me>=270) && ((object)target->query_temp("pending/guoguan") != me ) )
		return notify_fail("�����Ů�ľ��Ѿ���ɣ���Ҳû�йؿɹ��ˡ� \n");

	if ( (xj_lvl_me+1)/30*30 != xj_lvl_me+1 
		&& (object)target->query_temp("pending/guoguan") != me )
		return notify_fail("�����û�����ص�ʱ��\n");

	xj_lvl_target = (int)target->query_skill("yunu-xinjing", 1);	//��Ů�ľ��ȼ�
	force_lvl_target = (int)target->query_skill("force", 1);		//�����ڹ��ȼ�

	if ( (object)target->query_temp("pending/guoguan") != me ){
		if ( xj_lvl_target < xj_lvl_me/2 ) return notify_fail("�������书���̫���ˣ�\n");
		else if ( xj_lvl_target < xj_lvl_me *2/3 && !me->is_spouse_of(target))
			return notify_fail("�������书���̫���ˣ�\n");
	}

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

	// ���ܱ���������
	inv = all_inventory(environment(me));
	for (i=0; i<sizeof(inv); i++) 
		if ( (string)inv[i]->query("race") == "����" 
			&& inv[i] != me && inv[i] != target
			&& !me->is_spouse_of(inv[i]) 
			&& inv[i]->query("gender") != me->query("gender") )
		return notify_fail("��Ŀ��֮���ѹ������������㲻�Ӻ����𣿣�\n");


	// �����ڹ�С����Ů�ľ�60%������
	if( force_lvl_me < xj_lvl_me*60/100)
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");
	if( force_lvl_target < xj_lvl_target*60/100)
		return notify_fail("��Ļ�������̫���ˡ�\n");

	// lvlС��30������
	if (xj_lvl_target<25)
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
		me->set_temp("pending/target",target);
		me->set_temp("pending/xiuxi", 3);
		me->start_busy((: xiuxi :), (:halt_xiuxi:));
		target->set_temp("pending/xiuxi", 4);
		target->set_temp("pending/target",me);
		target->start_busy((: xiuxi :), (:halt_xiuxi:));
	}
	
	return 1;
}

int xiuxi(object me)
{
	string wiz_report;	//��ʦ����
	object where = environment(me);	//������
	object target = (object)me->query_temp("pending/target");	//���
	int xj_lvl_target = (int)target->query_skill("yunu-xinjing",1);	//����ľ�����
	int xj_lvl = (int)me->query_skill("yunu-xinjing",1);	//�ľ�����
	int time;	//����ʱ��
	object *inv;
	int i;

//	if( wizardp(me) ) tell_object(me, "pending/exercise=me" +chinese_number(me->query_temp("pending/exercise"))+"\n");
//	if( wizardp(me) ) tell_object(me, "pending/exercise=target" +chinese_number(target->query_temp("pending/exercise"))+"\n");

	//���ͣ��ͣ
	if( target->query_temp("pending/xiuxi") < 3 )
	{
		me->set_temp("pending/xiuxi", 0);
		me->set_temp("pending/target", me);
//		write(HIR"\nͻȻ���㷢���Ѿ�û��ͬ��İ����ˣ�����������ܿ��ƣ����ˮ�����������ȥ��\n\n"NOR
//			+HIR"���߻���ħ�ˣ���\n"NOR);
//		me->apply_condition("zouhuo_damage",100);
		return 0;
	}

	if( me->query_skill_mapped("force") != "yunu-xinjing" ){
		me->set_temp("pending/xiuxi", 0);
		me->set_temp("pending/target", me);
		return 0;
	}
	
/*
	if( target->is_fighting() ){
		write("ͻȻ���㷢����Ļ�����ں��˴򶷣���æͣ��������\n");
		me->set_temp("pending/xiuxi", 0);
		me->set_temp("pending/target", me);
		return 0;
	}
*/

	if( me->is_fighting() ){
		if( me->query_temp("pending/xiuxi")>3 ){
			write(HIR"\nͻȻ�����⵽Ϯ��������������ܿ��ƣ����ˮ�����������ȥ��\n\n"NOR
				+HIR"���߻���ħ�ˣ���\n"NOR);
			me->apply_condition("zouhuo_damage",100);
		}
		else{
			write(HIR"\nͻȻ�����⵽Ϯ����\n"NOR
				+HIR"�����޷��ٰ���ͬ������ˣ���\n"NOR);
		}
		me->set_temp("pending/xiuxi", 0);
		me->set_temp("pending/target", me);
		return 0;
	}

	// ��������
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("equipped") 
			&& inv[i]->query("armor_type")=="cloth")
			i = sizeof(inv)+1;
	if (i==sizeof(inv)+2){
		write(HIR"ͻȻ�������������𽥻��ۣ��޷���ɢ��������ʱ�����������������������Կ��ơ� \n"NOR
			+HIR"���߻���ħ�ˣ���\n"NOR);
		me->set_temp("pending/xiuxi", 0);
		me->set_temp("pending/target",me);
		me->apply_condition("zouhuo_damage",100);
		return 0;
	}

	inv = all_inventory(environment(me));
	for (i=0; i<sizeof(inv); i++) 
		if ( (string)inv[i]->query("race") == "����" 
			&& inv[i] != me && inv[i] != target
			&& !me->is_spouse_of(inv[i]) 
			&& inv[i]->query("gender") != me->query("gender") ){
			if( me->query("gender") == "Ů��") {
				write("ͻȻ���㷢�������������㿴��\n");
				if( inv[i]->query("family/family_name")=="��Ĺ��"){
					write("�㲻����Ȼ��ŭ��\n");
					command("say �㾹��͵�����������Ҹ���ʦ��ȥ��");
				}
				else{
					write(HIR"\n�������ּ�����Ҳ���ܼ��о����������������\n\n"NOR
						+HIR"���߻���ħ�ˣ���\n"NOR);
					me->apply_condition("zouhuo_damage",100);
				}
			}
			else write("ͻȻ���㷢���������˹�����\n���ǻ�æ��ֹ������\n");

			me->set_temp("pending/xiuxi", 0);
			me->set_temp("pending/target",me);
			return 0;
		}

	time = to_int(sqrt(xj_lvl)*10);

	if (me->query_temp("pending/xiuxi") > 3 ){
		if (me->query_temp("pending/xiuxi") < time){
			me->set_temp("pending/xiuxi", me->query_temp("pending/xiuxi") +1);
//	  		if( wizardp(me) ) tell_object(me, "����ɰٷ�֮"+chinese_number(me->query_temp("pending/xiuxi")*100/time) +" \n");
//	  		tell_object(me, "����ɰٷ�֮"+chinese_number(me->query_temp("pending/xiuxi")*100/time) +" \n");
	  		tell_object(me, "�����"+chinese_number(me->query_temp("pending/xiuxi")*10/time) +"�ɡ� \n");

		}
		else{
			if ( me->query("has_xinjing") < (xj_lvl +1)/30 ) {
				me->set("max_neili",me->query("max_neili")+(xj_lvl+1)/2);
				me->set("has_xinjing",(xj_lvl+1)/30);
			}
//			target->set("max_neili",target->query("max_neili")+(xj_lvl_target+1)/4);
			target->add("max_neili",2);

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

			me->set_temp("pending/target",me);
			me->set_temp("pending/xiuxi",0);
			message_vision("$N��$n�˹���ϣ���Ϣ���£����ص�ϲ��������$N�����ϡ�\n", me,target);
			return 0;
		}
	}

	return 1;

}

int halt_xiuxi(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
	me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/xiuxi", 0);
	me->set_temp("pendinf/target",me);
	return 1;
}

