// xiaoyao-piaopiao.c ��ңƮƮ��

inherit SKILL;

string *dodge_msg = ({    
"$nʹ����һԪ������������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�\n",    
"$nʹ�������ǲ���������Ȼ�������࣬���$N���˸��ա�\n",    
"$n����һҡ���ó�������Ӱ��һʽ�����Ų��������$N�Ĺ��ơ�\n",    
"$nʹ�������󲽷�������Ծ��ٿ��������$N���\n",    
"$n��һҡ����һ�Σ�һ�С����в���������������\n",    
"$n˫��һ�㣬бб����ʹ�������ϲ�����������$N��ࡣ\n",    
"$n����һ�Σ��Ų����ǣ�һʽ�����ǲ�����������������\n",	    
"$n����ͻ�ر��ȣ������Բ�������Ȼʹ����ٿ��������$N���\n",    
"$n������Ȼ��죬һʽ���Ź���������$N��ʱ��ʧ��$n����Ӱ��\n",
});

int valid_enable(string usage) 
{     
return (usage == "dodge") ;
}

int valid_learn(object me) 
{
return 1; 
}

string query_dodge_msg(string limb)
{	
return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{        
	if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");	
	if (me->query_skill("xiaoyao-piaopiao", 1) < 30)                
		me->receive_damage("jingli", 20, "����͸֧�������ˡ�");
		else
                me->receive_damage("jingli", 25, "����͸֧�������ˡ�");	
	return 1;
}