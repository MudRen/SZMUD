#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
    object weapon;
    int myatt, myexp, targexp, damage, skill, myskill, att, targrand, targneili,time,i;
    string str,*limb,type;
    mapping myfam;
    string * messages = ({ 
            HIB"$N轻轻的对着$n脸上吹了一口气，$n瞬间方寸大乱，$N借机连向$n胸前抓了数下。\n"NOR,
            HIB"尖叫声中，$N脸上隐隐泛出绿色，一显即逝，右爪猛地探向$n的头部。\n"NOR,
            HIB"$N扑地而倒，宛若一条蜈蚣，在地上快速爬了几步，绕到$n身后，一爪抓下\n"NOR,
            HIB"$N绕着$n快速的转了几圈，暴喝一声，掌爪互逆，几道冷风从指端射出，袭向$n\n"NOR,
            HIB"$N使出一招「抽髓手」，十指泛出隐隐的蓝色光芒，搭住$n身躯，有如附骨之蛆\n"NOR,
            HIB"$N身影忽前忽後，身形飘忽不定，突然一转身左手往$n拢去\n"NOR
            });    

    if( !target ) target = offensive_target(me);

    if( !target
    ||      !target->is_character()
    ||      !me->is_fighting(target) )
        return notify_fail("追魂爪只能对战斗中的对手使用。\n");


    if( objectp(me->query_temp("weapon")) )
        return notify_fail("空手才能施展追魂爪！\n");

    if( me->query_skill_mapped("claw") != "sanyin-zhua" )
        return notify_fail("你所用的并非三阴蜈蚣爪，不能施展追魂爪！\n");

    if( me->query_skill_prepared("claw") != "sanyin-zhua" )
        return notify_fail("你所备的并非三阴蜈蚣爪，不能施展追魂爪！\n");

    if( me->query_skill_mapped("force") != "huagong-dafa" )
        return notify_fail("你所用的并非化功大法，施展不出追魂爪！\n");

    if( (int)me->query_skill("huagong-dafa",1) < 120 )
        return notify_fail("你化功大法修为太差，不能运用追魂爪！\n");

    if( me->query_skill("sanyin-zhua",1) < 120 )
        return notify_fail("你三阴蜈蚣爪修为太差，不能运用追魂爪！\n");

    if( me->query("neili") <= 300 )
        return notify_fail("你的内力不够使用追魂爪！\n");
    if( me->query("jingli") <= 200 )
        return notify_fail("你的精力不够使用追魂爪！\n");     
    if( me->query("jing") <= 200 )
        return notify_fail("你的精不够使用追魂爪！\n");

    message_vision( HIB"$N忽然嘿嘿干笑几声，双袖狂舞卷起地上黄沙飞扬令人看不出要从何处出招，\n"+
                    "突然$N尖叫一声，声未停影先至向着$n扑来，双爪连抓数爪，其速之快令$n无从躲闪。\n"NOR, me, target );
    myskill = me->query_skill( "claw" ); 
    if ( myskill > 700 ) myskill = 700;
    myatt = myskill * ( 30 + random( 40 ) ) /100;
    if ( myskill > 400 )
        myatt = myatt + (myskill-400)*myatt/1500;
    me->add_temp( "apply/attack", myatt );
    me->add_temp( "apply/damage", myatt/2 );
    me->add_temp( "apply/speed", 120 );
    if ( wizardp( me ) ) tell_object( me, sprintf( "myatt is %d.\n", myatt ) );
    for ( i = 0; i < 2 + random( 2 );i++ )
    {
        COMBAT_D->do_attack(me, target, weapon);
    }
    me->add_temp( "apply/attack", -myatt );
    me->add_temp( "apply/damage", -myatt/2 );
    me->add_temp( "apply/speed", -120 );   
    me->start_busy( 2 + random( 2 ) );
    return 1;
}
