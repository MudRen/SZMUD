// zhaixing.c 天外摘星

/**************************************************
基本轻功--摘星功
   原有功能：无
   修改功能：perform zhaixing （天外摘星）
      条件：摘星功有效等级100，化功大法有效等级100。
      功能：提高临时jifa dodge 10 %。
      限制：运功时长：5-10 tick或战斗结束。
            不可与yun hua同时使用。
            不可与yun maxsuck 同时使用。
            不可与perform sanyin同时使用。
            不可与pxj perform guimei同时使用。
*************************************************/

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int dex, skill;
	
	if(!target) target = offensive_target(me);
    
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("天外摘星能在战斗中使用！\n");
	
	if(me->query_temp("zhaixing") )
		return notify_fail("你已经在使用天外摘星了！\n");

	if( me->query_skill_mapped("dodge") != "zhaixinggong" )
		return notify_fail("你所用的并非摘星功，不能施展天外摘星！\n");
	
	if( me->query_skill_mapped("force") != "huagong-dafa" )
		return notify_fail("你所用的并非化功大法，施展不出天外摘星！\n");

    if( me->query_temp("yun hua") )
		return notify_fail("天外摘星不可与化功护体同时运用。\n");
	
	if( me->query_temp("yun maxsuck") )
		return notify_fail("天外摘星不可与吸永久力同时运用。\n");
	
	if( me->query_temp("perfrom sanyin") )
		return notify_fail("天外摘星不可与三阴化功同时运用。\n");

	if( me->query_temp("pxj/guimei") )
		return notify_fail("天外摘星不可与鬼魅同时运用。\n");

	if( me->query_skill("dodge",1) < 100 )
		return notify_fail("你的基本功还不够扎实。\n");
    
	if( me->query_skill("huagong-dafa") < 100 )
		return notify_fail("你的化功大法功力不够，无法施展天外摘星！\n");
	 
	if( me->query("jingli") <= 500  )
		return notify_fail("你的精力不够，不能使用「天外摘星」。\n");
	
	if( me->query("neili") <= 500  )
		return notify_fail("你的内力不够，不能使用「天外摘星」。\n");
    if( me->query_temp( "zhaixing") )
        return notify_fail("你已经再使用「天外摘星」。\n");
        me->set_temp( "zhaixing", 1 );        
    message_vision(BLU "$N轻啸一声“天外摘星”，两臂张开，脚尖一点。只听得“嗖”的一声，人已高高跃出几丈外！\n" NOR, me, target);
	
	dex = me->query_skill( "dodge" );
        dex = dex / 2;
	me->add("neili",-50);
    me->add_temp("apply/dodge",dex);

    skill = (me->query_skill("zhaixinggong",1))/ 2;
	me->start_call_out( (: call_other, __FILE__, "end_perform", me, dex :),skill/8);
	me->add("neili", -50);
	me->add("jingli", -50);
	return 1;
}

void end_perform( object me, int dex)
{
	me->add_temp("apply/dodge", -dex);
	me->delete_temp( "zhaixing" );
	tell_object(me, HIY "你缓缓收住身形，轻吁一口气，将内力收回丹田。\n" NOR);
}
