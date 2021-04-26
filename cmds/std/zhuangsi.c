// last modified by buwu
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int wimpy;
    if( me->is_busy() )
		return notify_fail("你正在忙着，哪里分得出身装死？\n");
	if(me->query("shen") > -100000 )
		return notify_fail("你是一个正义的侠客，怎么可以做这种不齿之事？\n");
        seteuid(getuid());
        if( !me->is_fighting() )
                return notify_fail("你不在战斗中，不需要装死。\n");
	wimpy = (int)me->query("env/wimpy");
	message_vision("$N发出一阵特别凄厉的惨叫声，一头栽在地下装死。\n",me);
	me->set("qi",random(me->query("qi")/2));
	me->set("jing",random(me->query("jing")/2));
	me->set("jingli",random(me->query("jingli")/2));
	me->set("neili",random(me->query("neili")/2));
	me->set_temp("disable_inputs",1);
	me->set_temp("block_msg/all",1);
	me->disable_player(HIR " <装死中>" NOR);
        me->remove_all_killer();
	me->remove_all_enemy();
	me->delete("env/wimpy");
        me->start_call_out( (: call_other, __FILE__, "remove_jiasi", me, wimpy :), 
random(80 - (int) me->query_con()));
	return 1;
}

void remove_jiasi(object me, int wimpy)
{
	me->delete_temp("disable_inputs");
	me->enable_player();
	me->delete_temp("block_msg/all");
	me->set("env/wimpy",wimpy);
   	message_vision("$N小心翼翼地睁开了眼，一看没有动静，便悄悄地翻了个身又站起来了。\n",me);
	me->move(environment(me),1);

}

int help(object me)
{
        write(@HELP
指令格式 : zhuangsi

让你在战斗中装死，创造逃生的机会。
神高于负十万的玩家，不可以装死。

HELP
        );
        return 1;
}
 
