//longzhua-gong.c   ��צ��    

inherit SKILL;
#include <ansi.h> 

string *xue_name = ({  
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ", 
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",});  

mapping *action = ({ 
([        "action" :   "$N˫����������϶���ͬץ��ʹһ��"HIR"������ʽ��"NOR"��Ѹ��֮����ֱ����$n����̫��Ѩ",    
        "force" : 250,  
        "attack":this_player()->query_skill("longzhua-gong",1),  
        "dodge" : (int)this_player()->query_skill("dodge")/2,
        "damage" : (int)this_player()->query("str")*4, 
        "lvl" : 0,
        "damage_type" : "ץ��" 
]), 
([        "action" : "$N˫��һ��Ȧת��ʹ��"HIY"������ʽ��"NOR"������ٿ������������$n���ԡ��縮Ѩ��",    
        "attack":this_player()->query_skill("longzhua-gong",1),
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "force" : 250,  
        "damage" : (int)this_player()->query("str")*5,   
        "lvl" : 10,
        "damage_type" : "ץ��"  
]), 
([        "action" : "$Nʹ��һ��"HIW"������ʽ��"NOR"��������̽������Ю��һ�ɾ��磬ֱ����$n��硰ȱ��Ѩ��",     
        "force" : 250,  
        "dodge" : (int)this_player()->query_skill("dodge")/2,
        "attack":this_player()->query_skill("longzhua-gong",1), 
        "damage" : (int)this_player()->query("str")*6, 
        "lvl" : 20,  
        "damage_type" : "ץ��"
]), 
([        "action" : "$Nʹһ��"CYN"������ʽ��"NOR"��������ָ��$n��$l��ץ���£��ַ�������Ѹ�汸���Ƶ�����֮��", 
        "force" : 300,
        "damage" : (int)this_player()->query("str")*7,
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "attack":this_player()->query_skill("longzhua-gong",1),
        "lvl" : 30,  
        "damage_type" : "����"    
]), 
([        "action" : "$N�͵��������һ��"MAG"��׽Ӱʽ��"NOR"��$n�˽��������ý�Ѹ�ݣ����ƷǷ�",   
        "force" : 250,   
        "damage" : (int)this_player()->query("str")*8,  
        "attack":this_player()->query_skill("longzhua-gong",1),
        "dodge" : (int)this_player()->query_skill("dodge")/2,   
        "lvl" : 40, 
        "damage_type" : "ץ��" 
]), 
([        "action" :  "��������һ�죬$N�ұۼ����������ָ΢΢���²�����һ��"HIM"������ʽ��"NOR"ץ��$n��$l",    
        "force" : 250,
        "dodge" : (int)this_player()->query_skill("dodge")/2,
        "attack":this_player()->query_skill("longzhua-gong",1), 
        "damage" : (int)this_player()->query("str")*9, 
        "lvl" : 50, 
        "damage_type" : "ץ��" 
]),
([        "action" : "$N���������������ڻӣ�ʹ����צ���е�"YEL"����ɪʽ��"NOR"����Ȼץ����������ֱ��$n��ȥ",    
        "force" : 250, 
        "attack":this_player()->query_skill("longzhua-gong",1),  
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "damage" : (int)this_player()->query("str")*10,  
        "lvl" : 60,  
        "damage_type" : "ץ��" 
]),
([        "action" :  "$N˫��"HIB"������ʽ��"NOR"����������������Ӱ�ɿգ�˫צ���裬˲Ϣ֮�䣬�ѽ�$nѹ�Ƶ��޴�����",  
        "force" : 300, 
        "attack":this_player()->query_skill("longzhua-gong",1),   
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "damage" : (int)this_player()->query("str")*11,
        "lvl" : 70,  
        "damage_type" : "ץ��"     
]), 
([        "action" :  "$N̤�ϼ���������һ��"BLU"������ʽ��"NOR"��������$n$lץ����������һץ������ָ��ñ�ֱ�����������Ѽ�",   
        "force" : 300, 
        "dodge" : (int)this_player()->query_skill("dodge")/2,  
        "attack":this_player()->query_skill("longzhua-gong",1), 
        "damage" : (int)this_player()->query("str")*12,
        "lvl" : 80, 
        "damage_type" : "ץ��"   
]),   
([        "action" : "$N����һ������������ʵ����������׾��"RED"������ʽ��"NOR"������ɽ��ʹ������",
        "force" : 300,
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "attack":this_player()->query_skill("longzhua-gong",1), 
        "damage" : (int)this_player()->query("str")*13,
        "lvl" : 90,  
        "damage_type" : "ץ��" 
]),  
([        "action" : "$Nһ��ԭ�ȸ���·�ӣ�����"HIC"����ȱʽ��"NOR"��צ·�����а������ᣬʵ�ѵ��˷�豹��棬¯����ľ���",  
        "force" : 350, 
        "dodge" : (int)this_player()->query_skill("dodge")/2,
        "attack":this_player()->query_skill("longzhua-gong",1), 
        "damage" : (int)this_player()->query("str")*14,   
        "lvl" : 100, 
        "damage_type" : "ץ��"  
]),
([        "action" : "$N˫��΢�ţ�ʮ������ָ��ӳ���Ұ׹�æ��ͻȻ�����צ����ָ�͵ز���",  
        "force" : 400, 
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "attack":this_player()->query_skill("longzhua-gong",1), 
        "damage" : (int)this_player()->query("str")*15, 
        "lvl" : 110,  
        "damage_type" : "ץ��" 
]), 
([        "action" :  "$n�Ŷ�����У�$N����������ץ���켫�ݼ���", 
        "force" : 450, 
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "attack":this_player()->query_skill("longzhua-gong",1),
        "damage" : (int)this_player()->query("str")*16,  
        "lvl" : 120, 
        "damage_type" : "ץ��"  
]),   
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; } 

int valid_combine(string combo) { return combo=="longzhua-gong"; } 

int valid_learn(object me) 
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
                return notify_fail("����צ��������֡�\n");  
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 20) 
                return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ��צ����\n");
        if ((int)me->query("max_neili") < 100)  
                return notify_fail("�������̫�����޷�����צ����\n"); 
        if ((int)me->query_str()< 25) 
                return notify_fail("��ı���̫�����޷�����צ����\n");
        return 1;
}

mapping query_action(object me)   
{
        int i, level; 
        level = (int) me->query_skill("longzhua-gong",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])  
                        return action[NewRandom(i, 20, level)];  
}

int practice_skill(object me) 
{
        if ((int)me->query("jingli") < 60)   
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 50) 
                return notify_fail("���������������צ����\n");
        me->receive_damage("jingli", 20);
        me->add("neili", -20);
        return 1;    
}

string perform_action_file(string action) 
{
        return __DIR__"longzhua-gong/" + action; 
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    int j;   
    string name;
    j = me->query_skill("longzhua-gong",1);
    name = xue_name[random(sizeof(xue_name))];

        if( j > 100  
       && me->query("neili") > 500 
       && me->query_skill_mapped("parry") == "longzhua-gong" 
       && victim->query("neili") > 100){ 
         victim->add("neili", -random(20)); 
        } 
    if(victim->is_busy()) return 0;   
        if((me->query("neili")>200) &&  j > 120) 
      {    
                victim->start_busy(2);
                me->add("neili",-30); 
                if (victim->query("qi") <=(damage_bonus/2+30))  
                victim->set("qi",0); 
                else 
                victim->receive_damage("qi", j+damage_bonus/2); 
                victim->receive_wound("qi", j+damage_bonus/2);  
                return HIY"ͻȻ��Ӱ������$N�ȵ�$n�����������֣������ָ��$n"RED+name+HIY"������ȥ��\n" NOR;   
        }  
         else  
        {      
          if((!random(2)) && (me->query("neili")>500) && j > 140)  
           {  
                victim->start_busy(2);
                me->add("neili",-30);  
                victim->add("neili",-30); 
                victim->receive_damage("qi", j*2+damage_bonus/2);     
                victim->receive_wound("qi", j*2+damage_bonus/2);  
                return HIR "$N��צ��ԴԴ������һ����գ��ּ�����������\n" NOR; 
        }  
        }  
}
