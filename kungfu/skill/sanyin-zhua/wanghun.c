// /u/final/kungfu/skill/sanyin-zhua/wanghun.c
// final

/*  ####################################################################################
    为了维护门派的平衡，我不想把xingxiu变得很厉害，不过为了让player感到好玩，就做了这个pfm
    这个pfm 不是很厉害  但需要要求特别多，这样就增加了xingxiu这个邪恶门派的真实性
    比如必须要xingxiu弟子 必须要很多-shen 而且需要杀很多人 必须死过多少次.....等
<<----------------------------------------------------------------------------------->>
                这个pfm只供参考
                匹配的多了  也许玩家会认为有意思吧？
                :P
<<----------------------------------------------------------------------------------->>
    
*/



#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int myexp, targexp, damage, merand, targrand, targneili, time, i, whatt, skill, dodge, fk, fl, aaa;
        string str,*limb,type;
        string msg;
        mapping myfam;
        msg="";

        if( !target ) target = offensive_target(me);    if( !objectp(target) || target == me || target->query("id") == "mu ren"      || target->query("id") == "shangshan"      || target->query("id") == "mengzhu"     || target->query("id") == "fae" 
        || target->query("id") == "final" )             return notify_fail("你要对谁使用亡魂？\n");
        

     /*   if( !target
       ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("亡魂只能对战斗中的对手使用。\n");

*/
//              if (!wizardp(me))
  //      return notify_fail("这功能目前还不对玩家开放。\n");
        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "星宿派") && me->query("id")!="kies")
                  return notify_fail("你不是星宿弟子,怎么使出如此狠毒的武功。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("拿着武器？\n");

        if( me->query_skill_mapped("claw") != "sanyin-zhua" )
                return notify_fail("你所用的并非三阴蜈蚣爪，不能施展亡魂！\n");

        if( me->query_skill_prepared("claw") != "sanyin-zhua" )
                return notify_fail("你所备的并非三阴蜈蚣爪，不能施展亡魂！\n");
        
        if( me->query_skill("qianzhu-wandu" ,1) < 100 )
                return notify_fail("你感觉凭你现在的用毒技巧还不能用出亡魂！\n");

        if( me->query_skill_mapped("force") != "huagong-dafa" )
                return notify_fail("你的内功无法与亡魂相融合！\n");

        if( (int)me->query_skill("huagong-dafa",1) < 120 )
                return notify_fail("你本门内功还不足以用亡魂！\n");

        if( me->query_skill("sanyin-zhua",1) < 120 )
                return notify_fail("你的武功招式还不到家！\n");
        
        if( me->query("shen") >= -10000 )
                return notify_fail("你能忍心下手吗？！\n");
        if( me->query("PKS") <= 15 )
                                return notify_fail("你还没到杀人不见血的程度不会使出亡魂的!\n");
                if( me->query("MKS") <= 1000 )
                                return notify_fail("你还没到杀人不见血的程度不会使出亡魂的!\n");
                if( me->query("death_count") <= 20 )
                                return notify_fail("你死的次数太少了，亡魂需要充满怨灵的愤怒!\n");
        if( me->query("neili") <= 500 )
                return notify_fail("你体内真气不够，如何使用亡魂！\n");
        if( me->query("jingli") <= 300 )
                return notify_fail("你浑身无力，怎能使用亡魂！\n");     
        if( me->query("jing") <= 300 )
                return notify_fail("你浑身无力，怎能使用亡魂！\n");

        message_vision(HIB"\n$N突然神情大变,想起曾经遇见的无数冤魂顿时冒出恨意!”\n"NOR,me);
        message_vision(HIM"\n$N头上似乎出现一些怨灵,你似乎都看傻了!”\n"NOR,me);        
                
        me->start_busy(2);
        fk = ( me->query_skill("poison",1) + me->query_skill("sanyin-zhua",1) + me->query_skill("qianzhu-wandu",1))/3;
        whatt = ( me->query("PKS") + me->query_skill("poison")/10 + me->query_skill("qianzhu-wandu",1) / 10 ) / 3; 
        fl = target->query_skill("dodge", 1);
        message_vision(HIW"\n$N突然一招亡魂,爪向$n抓去!”\n"NOR,me,target);
        skill=random(whatt+random(50));
        
        if (skill>150) skill=200;
        if (skill<150) skill=100;
        aaa = skill*fk/10;
        dodge = target->query_skill("dodge", 1);
        if (fk<fl) {
                msg += HIG"$p轻功了得，说时迟，那时快,已经闪了过去。\n" NOR;            me->start_busy(3 + random(1));
}
        else {        msg += HIR "$n惊呆中,已经被$N的爪抓到心窝。\n"NOR;                                         target->add("eff_qi",-aaa);                                     target->add("qi",-aaa);                                 target->add("jingli",-aaa/2);  }message_vision(msg, me, target);  return 1;}

