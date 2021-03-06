// shout.c
// Open to Players by Buwu.
#include <ansi.h>

inherit F_CLEAN_UP;

#define SHOUT_LIST      ({ })
int main(object me, string arg)
{
        if (!arg) return notify_fail("你想要大叫什么？\n");
	if (!wizardp(me)) 
		{
		if ((me->query("jingli") < 3000) || (me->query("neili") < 4000))
			return notify_fail("你试图纵身长啸，却发现自己连吃奶的力气都没有。\n");
                me->set("jingli",random(500));
                me->set("neili",random(500));
	    shout(HIW + "★"+me->name() + "使出吃奶的力气大声喊道：" + arg + "\n" + NOR);
	    write(HIW +"★你使出吃奶的力气大声喊道：" + arg + "\n" + NOR);
		}
	if (wizardp(me)) 
		{
	shout(HIY + "★"+ me->name() + "纵声长啸：" + arg + "\n" + NOR);
    write(HIY +"★你纵声长啸：" + arg + "\n" + NOR);
		}
        return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : shout <讯息>
 
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话。玩家需要具备至少三千精力、四千内力。
并且使用后，将消耗掉绝大部分的精力与内力。
 
HELP
    );
    return 1;
}
