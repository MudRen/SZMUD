// last modified by buwu
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int wimpy;
    if( me->is_busy() )
		return notify_fail("������æ�ţ�����ֵó���װ����\n");
	if(me->query("shen") > -100000 )
		return notify_fail("����һ����������ͣ���ô���������ֲ���֮�£�\n");
        seteuid(getuid());
        if( !me->is_fighting() )
                return notify_fail("�㲻��ս���У�����Ҫװ����\n");
	wimpy = (int)me->query("env/wimpy");
	message_vision("$N����һ���ر������Ĳҽ�����һͷ���ڵ���װ����\n",me);
	me->set("qi",random(me->query("qi")/2));
	me->set("jing",random(me->query("jing")/2));
	me->set("jingli",random(me->query("jingli")/2));
	me->set("neili",random(me->query("neili")/2));
	me->set_temp("disable_inputs",1);
	me->set_temp("block_msg/all",1);
	me->disable_player(HIR " <װ����>" NOR);
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
   	message_vision("$NС��������������ۣ�һ��û�ж����������ĵط��˸�����վ�����ˡ�\n",me);
	me->move(environment(me),1);

}

int help(object me)
{
        write(@HELP
ָ���ʽ : zhuangsi

������ս����װ�������������Ļ��ᡣ
����ڸ�ʮ�����ң�������װ����

HELP
        );
        return 1;
}
 
