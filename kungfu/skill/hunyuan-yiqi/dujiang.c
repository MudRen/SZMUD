// Code of ShenZhou
// dujiang.c 一苇渡江
// by Felix 5/2002

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_SSERVER;

void remove_effect(object me, int dh);

int exert(object me, object target)
{
	int dh, time;

	if( me->query("family/family_name") != "少林派")
		return notify_fail("你不是少林弟子如何能施展一苇渡江？\n");

	if( me->query("family/generation") != 35)
		return notify_fail("你的辈分不够，还无法领会一苇渡江的真悟！\n");

	if( me->query_skill("shaolin-shenfa", 1) < 200)
		return notify_fail("你的少林身法火候未到，无法施展一苇渡江！\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 200)
		return notify_fail("你的混元一气修为还不够，无法施展一苇渡江！\n");
	
	if( me->query_skill_mapped("force") != "hunyuan-yiqi" )
		return notify_fail("你所用的并非混元一气功，无法施展一苇渡江！\n");

	if( (int)me->query_temp("jingang") )
		return notify_fail("你已经发动了金刚伏魔神通，不能同时施展一苇渡江！\n");

	if( (int)me->query_temp("dujiang") )
		return notify_fail("你已经在施展一苇渡江！\n");

	if( !me->is_fighting() )
		return notify_fail("你必须在战斗中才能使用一苇渡江！\n");

	dh = (me->query_skill("dodge") + me->query_skill("force"))/5;

	time = me->query_skill("shaolin-shenfa", 1)/10;
	if ( time < 10) time = 10;

	message_vision(HIC
	"\n$N忽然身子斜斜跃起丈高，势如苍龙如水直击高空，速度之快出人意料。\n"
	"还未看清去势，就见如疾风暴雨般的招式已倾头泄下。\n"NOR, me);

	me->add_temp("apply/defense", dh);

	me->add_temp("apply/speed", dh);

	me->add("neili", -200);

	me->set_temp("dujiang", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, dh :),time );

	return 1;
}

void remove_effect(object me, int dh)
{
	message_vision(HIC
		"\n$N深深吸了口气，疾风过去，收起了「一苇渡江」的架势。\n"NOR, me);

	me->add_temp("apply/defense", -dh);

	me->add_temp("apply/speed", -dh);

	me->delete_temp("dujiang");
}