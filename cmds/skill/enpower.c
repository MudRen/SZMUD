// Code of ShenZhou
// enpower.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || (arg!="basic" && arg != "max" && !sscanf(arg, "%d", pts)) )
	{
		return notify_fail("指令格式：enpower|jiajin <使出几分体力伤敌>|basic\n");
	}

	if(me->query_temp("n_Defensive_Combat_Mode"))
	{
		return notify_fail("你现在正在防守状态，不能这么做。\n");
	}

	if( arg=="basic" )
	{
		me->set("jiajin", 1);
	}
	else
	{
		if ( arg == "max" )
			pts = me->query("max_jingli")/20;
		if( pts < 1 || pts > (int)me->query("max_jingli")/20 )
			return notify_fail("你只能用 basic 表示只用一分体力，或数字表示每一击用几分体力，且不能超过最大体力值。\n");
		me->set("jiajin", pts);
	}

	write("设定完毕。\n");
	return 1;
}

int help (object me)
{
        write(@HELP
指令格式: enpower|jiajin <使出几分体力伤敌>|basic
 
这个指令让你指定每次击中敌人时，要发出几分体力伤敌。

enpower baisc 则表示你只用一分体力。 

HELP
        );
        return 1;
}
