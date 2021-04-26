// Code of ShenZhou
// douzhuan-xingyi  ��ת����
// arthurgu 1999.9

#include <ansi.h>;
inherit FORCE;
inherit SKILL;
void interrupt_me(object who);

int valid_enable(string usage) { return usage == "force" ; }

int valid_learn(object me)
{
	
	int i = (int)me->query_skill("douzhuan-xingyi", 1);
        int t = 1, j;
        for (j = 1; j < i / 10; j++) t*= 2;
        if ((int)me->query_skill("force", 1) < 10
          ||(int)me->query_skill("force", 1)/2 < i/3 )
                return notify_fail("��Ļ����ڹ�����㣬����ѧ��ת�����񹦡�\n");         
        if ( me->query("gender") == "����" )
                return notify_fail("̫�಻��ѧ��ת�����񹦡�\n");
        if ( me->query("class") == "bonze" )
                return notify_fail("����Ľ�ݲ��ճ�����Ϊ����.");  
                
         if ((int)me->query_skill("literate", 1) < 220 
         && (int)me->query_skill("literate",1) < ((int)me->query_skill("douzhuan-xingyi",1) - 30)) 
                    return notify_fail("��Ķ���д��ˮƽ�������޷���һ����߶�ת�����񹦡�\n");
                             
        
        if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1)
          || me->query_skill("mahayana",1) || me->query_skill("lamaism", 1))
                return notify_fail("������ͺ¿ţ�����ǵ��ķ�����ѧ��ת������ʲ�ᣡ\n");
        if ( me->query_skill("hunyuan-yiqi",1) || me->query_skill("linji-zhuang", 1)
        || me->query_skill("huntian-qigong",1) || me->query_skill("longxiang-banruo", 1)
        || me->query_skill("taiji-shengong",1) || me->query_skill("zixia-gong",1)    
        || me->query_skill("dulong-dafa", 1) || me->query_skill("kurong-changong", 1)
        || me->query_skill("bitao-xuangong", 1) || me->query_skill("xiantian-gong",1)  
        || me->query_skill("huagong-dafa",1))  
                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ת�����񹦣���\n");
        return 1;
	
}


int practice_skill(object me)
{
  return notify_fail("��ת����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
  return __DIR__"douzhuan-xingyi/" + func;
}




 
 
