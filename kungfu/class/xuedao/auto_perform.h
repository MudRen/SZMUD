// Code of ShenZhou
// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");

	if ( !objectp(target)
	  || !random( (int)me->query("combat_exp") * 2
		   / (int)target->query("combat_exp") + 1) ) return 0;
	
	if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "blade" )
			return perform_action("blade.shendao");
	}
	else if( present("xue dao", me)){
	command("wield dao");
	return 1;
	}	
}
