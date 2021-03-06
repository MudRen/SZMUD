//longzhua-gong.c   龙爪功    

inherit SKILL;
#include <ansi.h> 

string *xue_name = ({  
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴", 
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",});  

mapping *action = ({ 
([        "action" :   "$N双手齐出，自上而下同抓，使一招"HIR"「抢珠式」"NOR"，迅猛之至，直拿向$n左右太阳穴",    
        "force" : 250,  
        "attack":this_player()->query_skill("longzhua-gong",1),  
        "dodge" : (int)this_player()->query_skill("dodge")/2,
        "damage" : (int)this_player()->query("str")*4, 
        "lvl" : 0,
        "damage_type" : "抓伤" 
]), 
([        "action" : "$N双手一个圈转，使招"HIY"「捞月式」"NOR"，右手倏忽而出，虚拿$n后脑“风府穴”",    
        "attack":this_player()->query_skill("longzhua-gong",1),
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "force" : 250,  
        "damage" : (int)this_player()->query("str")*5,   
        "lvl" : 10,
        "damage_type" : "抓伤"  
]), 
([        "action" : "$N使出一招"HIW"「拿云式」"NOR"，左手虚探，右手挟着一股劲风，直拿向$n左肩“缺盆穴”",     
        "force" : 250,  
        "dodge" : (int)this_player()->query_skill("dodge")/2,
        "attack":this_player()->query_skill("longzhua-gong",1), 
        "damage" : (int)this_player()->query("str")*6, 
        "lvl" : 20,  
        "damage_type" : "抓伤"
]), 
([        "action" : "$N使一招"CYN"「捕风式」"NOR"，左手五指朝$n的$l急抓而下，手法劲力稳迅兼备，势道凌厉之极", 
        "force" : 300,
        "damage" : (int)this_player()->query("str")*7,
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "attack":this_player()->query_skill("longzhua-gong",1),
        "lvl" : 30,  
        "damage_type" : "震伤"    
]), 
([        "action" : "$N猛地纵身而起，一招"MAG"「捉影式」"NOR"向$n扑将下来，矫健迅捷，威势非凡",   
        "force" : 250,   
        "damage" : (int)this_player()->query("str")*8,  
        "attack":this_player()->query_skill("longzhua-gong",1),
        "dodge" : (int)this_player()->query_skill("dodge")/2,   
        "lvl" : 40, 
        "damage_type" : "抓伤" 
]), 
([        "action" :  "祗听呼地一响，$N右臂疾伸而出，五指微微上下颤动，一招"HIM"「抚琴式」"NOR"抓向$n的$l",    
        "force" : 250,
        "dodge" : (int)this_player()->query_skill("dodge")/2,
        "attack":this_player()->query_skill("longzhua-gong",1), 
        "damage" : (int)this_player()->query("str")*9, 
        "lvl" : 50, 
        "damage_type" : "抓伤" 
]),
([        "action" : "$N左手上拦，右手内挥，使出龙爪功中的"YEL"「鼓瑟式」"NOR"，陡然抓出，将力道直向$n送去",    
        "force" : 250, 
        "attack":this_player()->query_skill("longzhua-gong",1),  
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "damage" : (int)this_player()->query("str")*10,  
        "lvl" : 60,  
        "damage_type" : "抓伤" 
]),
([        "action" :  "$N双手"HIB"「批亢式」"NOR"疾攻而出，犹如龙影飞空，双爪急舞，瞬息之间，已将$n压制得无处躲闪",  
        "force" : 300, 
        "attack":this_player()->query_skill("longzhua-gong",1),   
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "damage" : (int)this_player()->query("str")*11,
        "lvl" : 70,  
        "damage_type" : "抓伤"     
]), 
([        "action" :  "$N踏上几步，化做一招"BLU"「掏虚式」"NOR"，右手向$n$l抓将下来，这一抓自腕至指伸得笔直，劲道凌厉已极",   
        "force" : 300, 
        "dodge" : (int)this_player()->query_skill("dodge")/2,  
        "attack":this_player()->query_skill("longzhua-gong",1), 
        "damage" : (int)this_player()->query("str")*12,
        "lvl" : 80, 
        "damage_type" : "抓伤"   
]),   
([        "action" : "$N退後一步，架势似守实攻，大巧若拙，"RED"「抱残式」"NOR"稳凝如山般使将出来",
        "force" : 300,
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "attack":this_player()->query_skill("longzhua-gong",1), 
        "damage" : (int)this_player()->query("str")*13,
        "lvl" : 90,  
        "damage_type" : "抓伤" 
]),  
([        "action" : "$N一改原先刚猛路子，化做"HIC"「守缺式」"NOR"，爪路刚猛中暗藏阴柔，实已到了返璞归真，炉火纯青的境界",  
        "force" : 350, 
        "dodge" : (int)this_player()->query_skill("dodge")/2,
        "attack":this_player()->query_skill("longzhua-gong",1), 
        "damage" : (int)this_player()->query("str")*14,   
        "lvl" : 100, 
        "damage_type" : "抓伤"  
]),
([        "action" : "$N双手微张，十根尖尖的指甲映出灰白光忙，突然翻腕出爪，五指猛地插落",  
        "force" : 400, 
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "attack":this_player()->query_skill("longzhua-gong",1), 
        "damage" : (int)this_player()->query("str")*15, 
        "lvl" : 110,  
        "damage_type" : "抓伤" 
]), 
([        "action" :  "$n才躲过这招，$N次招又至，抓法快极狠极！", 
        "force" : 450, 
        "dodge" : (int)this_player()->query_skill("dodge")/2, 
        "attack":this_player()->query_skill("longzhua-gong",1),
        "damage" : (int)this_player()->query("str")*16,  
        "lvl" : 120, 
        "damage_type" : "抓伤"  
]),   
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; } 

int valid_combine(string combo) { return combo=="longzhua-gong"; } 

int valid_learn(object me) 
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
                return notify_fail("练龙爪功必须空手。\n");  
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 20) 
                return notify_fail("你的混元一气功火候不够，无法学龙爪功。\n");
        if ((int)me->query("max_neili") < 100)  
                return notify_fail("你的内力太弱，无法练龙爪功。\n"); 
        if ((int)me->query_str()< 25) 
                return notify_fail("你的臂力太弱，无法练龙爪功。\n");
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
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 50) 
                return notify_fail("你的内力不够练龙爪功。\n");
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
                return HIY"突然人影闪动，$N迫到$n身后，袖中伸出手，五根手指向$n"RED+name+HIY"插了下去！\n" NOR;   
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
                return HIR "$N龙爪手源源而出，一招落空，又即连续急攻！\n" NOR; 
        }  
        }  
}
