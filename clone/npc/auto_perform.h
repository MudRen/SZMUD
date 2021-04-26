// Code of ShenZhou
// /kungfu/class/quanzhen/autoperform.h
// for quanzhen npc's autoperform
// by sdong 08/01/98
// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");

	if ( !me->is_fighting() ) {
		if ( me->query("eff_qi") < me->query("max_qi") )
			exert_function("heal");
		me->set("jiali", 300);
		return 1;
	}

	if ( !objectp(target)
	  || !random( (int)me->query("combat_exp") * 2
		   / (int)target->query("combat_exp") + 1) ) return 0;

	if ( objectp(weapon) && weapon->query("skill_type") == "sword")
	{
		  if( me->query("eff_qi",1) > me->query("max_qi",1)*2/3 )
			return perform_action("sword.sanqing");
		  else perform_action("sword.tonggui");
	}
	else
	{
		if( !me->query_temp("sanhua",1) )
			return perform_action("strike.sanhua");
		else
			return perform_action("cuff.lianhuan");
	}
}
