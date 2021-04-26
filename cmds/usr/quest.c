#include <ansi.h>

int main(object me)
{
	string output;
	if(!find_object(TASK_D)) 
		return notify_fail("任务精灵并未载入。\n");
	output=sprintf(HIY"		江湖恩怨传书\n\n\n"NOR);
	output+=TASK_D->query_task_list();
	write(output);
	return 1;
}

int help(object me)
{
        write(@HELP
        神州新增的Quest系统。quest 命令用于列出系统中的所有江湖恩怨，
        可用命令比如 questobj 朱熹的孔孟之书 打听传书中的任务物品所
        在位置的消息，物品一般在这个房间的 NPC 身上。找到相应物品后
        将其交给其主人，就可以得到奖励以及进一步的任务。经验高于 4m 
        的玩家，进一步任务中只能得到潜能，而没有经验。
        该 job 的帮助请查看 help questjob。
HELP
    );
    return 1;
}
