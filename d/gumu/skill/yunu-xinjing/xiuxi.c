// xiuxi.c ��Ů�ľ���ϰexert
// by April 01/08/09
// update April 01/08/21

string *phases = ({
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

int exert(object me)
{
	object 	where = environment(me);
	int xj_lvl = (int)me->query_skill("yunu-xinjing", 1);	//��Ů�ľ��ȼ�
	int force_lvl = (int)me->query_skill("force", 1);		//�����ڹ��ȼ�
	int v,i,j,k;		// ��ʱ����
	string *sname;	// skill����
	object *inv;	// ���ϴ��Ķ���
	mapping skl;	// ����skill

	seteuid(getuid());

	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (where->query("sleep_room"))
		return notify_fail("��˯���ﲻ������Ů�ľ������Ӱ�����ˡ�\n");

	if (where->query("no_fight"))
		return notify_fail("����������Ů�ľ�����ʼ���ķ����ң��޷����ƣ�ֻ�����ա�\n");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("ս���в�������Ů�ľ������߻���ħ��\n");

	if( !stringp(me->query_skill_mapped("force")) )
		return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");

	if( me->query("rided") )
		return notify_fail("���������˹������߻���ħ�ġ�\n");

	// �����ڹ�С����Ů�ľ�60%������
	if( force_lvl < xj_lvl*60/100)
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

	if( me->query_skill_mapped("force") != "yunu-xinjing" )
		return 0;

	// lvlС��30������
	if (xj_lvl<30)
		return notify_fail("����������һ��������������Ȼ��Ů�ľ���Ϊ�����������޷���ת��\n");

	// �������
	if ( me->query_temp("weapon") )
        return notify_fail("��ϰ��Ů�ľ�������֣��������ķ��ɡ�\n");

	// ��������
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("equipped") 
			&& inv[i]->query("armor_type")=="cloth")
			i = sizeof(inv)+1;
	if (i==sizeof(inv)+2)
        return notify_fail("��ϰ��Ů�ľ������½󳨿����ܼ�ʱɢ��������\n");

	// �ڹ�Ҫ�����������Ԫ��
	skl=this_player()->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );
    for(v=0; v<sizeof(skl); v++) {
		if (SKILL_D(sname[v])->check() == "force")
			k++;  
    }
    if ( k >=2 ) {
		// ������˺�
        me->set("neili", 0);
        me->set("jingli", 50);
        me->set("qi", 50);
		i=(int)(me->query("max_jing")*65/100);
		me->set("eff_jing",i);
		return notify_fail("�����ڲ�ͬ���������ײ���������������Կ��ơ� \n"
			+"����һҧ��������һ����Ѫ���Ų������߻���ħ��\n");
	}

	if( (int)me->query("neili") < (int)me->query("max_neili")*60/100 )
		return notify_fail("�����ڵ�����������ϰ��Ů�ľ���\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi"))
		return notify_fail("���������ˣ�ֻ��һ��������������Σ�գ�\n");

	if( (int)me->query("eff_jing") < (int)me->query("max_jing"))
		return notify_fail("���еĶ�û��ȫ�ã�ֻ��һ��������������Σ�գ�\n");

	if( (int)me->query("jing") < (int)me->query("max_jing")*90/100 )
		return notify_fail("�����ھ��������޷�������Ϣ��������\n");

	if( (int)me->query("qi") < (int)me->query("max_qi")*60/100 )
		return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

	// ���ܿ���ϰ���� ---- 30n-1ʱ�������
	if ( (xj_lvl<270) && ((xj_lvl+1)/30*30 == xj_lvl + 1) )
		return notify_fail("�������ϰ����Ů�ľ�����Ȼ��������һ��... \n"
			+"���ƺ��������޷�ͻ��ƿ����������ʱ������ˡ� \n");

	write("����ϥ���£������س���һ������һ��ů����ʼ������������\n");

	me->set_temp("pending/exercise", 1);
	message_vision("$N��ϥ���£���ʼ�����ϳ��ڹ���\n", me);
	me->start_busy((: exercising :), (:halt_exercise:));
	
	return 1;
}

int exercising(object me)
{
	int qi_cost;	//������
	int jingli_cost;	//��������
	int neili_gain;		//��������
	int xj_gain;	//�ľ�����
	int sx_gain;	//���ľ�����
	int xj_lvl = (int)me->query_skill("yunu-xinjing",1);	//�ľ�����
	int force_lvl = (int)me->query_skill("force",1);	//�����ڹ�����
	object  where = environment(me);

	if( me->query_skill_mapped("force") != "yunu-xinjing" )
		return 0;
	
	//��������
	neili_gain = 1 + (int)me->query_skill("force") / 10;
	jingli_cost = to_int(sqrt(xj_lvl/to_float(150))*60);
	qi_cost = jingli_cost + neili_gain;

	if( (int)me->query("qi") > (int)me->query("max_qi")*30/100 
		&& (int)me->query("jingli") > (int)me->query("max_jingli")*30/100
		&& (xj_lvl>270 || (xj_lvl+1)/30*30 != xj_lvl+1) )
	{
		me->add("neili", neili_gain);
		xj_gain = to_int(pow(force_lvl/4+1,1.1));
		sx_gain = xj_gain;
		if (!me->is_married()) sx_gain = sx_gain * (1+to_int(sqrt(me->query_skill("lovingness",1)/xj_lvl)));
		me->improve_skill("yunu-xinjing", xj_gain, 0);
		me->improve_skill("suxin-jue", sx_gain, 0);
		write(phases[random(6)]);
		me->receive_damage("qi", qi_cost, "���ڹ��߻���ħ����");
		me->receive_damage("jingli", jingli_cost, "���ڹ��߻���ħ����");

  		if( wizardp(me) ) tell_object(me, "ÿ�ε�"+chinese_number(neili_gain)+"��������"
			+chinese_number(xj_gain)+"����Ů�ľ���"
			+chinese_number(sx_gain)+"�����ľ���\n"
			+"����"+chinese_number(qi_cost)+"������"
			+chinese_number(jingli_cost)+"�㾫����\n");

		return 1;
	}
	else {
		me->set_temp("pending/exercise", 0);
		message_vision("$N�˹���ϣ���Ϣ���£�������Į��վ��������\n", me);
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

