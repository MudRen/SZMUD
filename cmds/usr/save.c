// Code of ShenZhou
// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;
//            tell_object(me,HIG"现在系统使用自动存储系统，在进行中和退出时对玩家数据进行存储。\n"NOR);
//            return 1;

	seteuid(getuid());

    if (me->query_temp("saved")) return notify_fail("档案储存完毕。\n");
    me->set_temp("saved", 1);
    me->start_call_out( (: call_other, me, "delete_temp", "saved" :), 300 + random(90));

	if( !objectp(link_ob = me->query_temp("link_ob")) )
		return notify_fail("你不是经由正常连线进入，不能储存。\n");

	if( environment(me)->query("valid_startroom") ) {
		write("当你下次连线进来时，会从这里开始。\n");
	}

	if( (int)link_ob->save() && (int)me->save() ) {
	me->set("startroom", base_name(environment(me)));
        write("档案储存完毕。\n");
		return 1;
	} else {
		write("储存失败。\n");
		return 0;
	}
}

int help(object me)
{
	write(@HELP
指令格式：save

把你辛苦奋斗的结果存起来。
HELP
	);
	return 1;
}
