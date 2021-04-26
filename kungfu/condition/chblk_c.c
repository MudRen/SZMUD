// Code of ShenZhou

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		if ((int)me->query("chblk_on"))
			me->delete("chblk_on");
		if ((int)me->query("chblk_rumor"))
			me->delete("chblk_rumor");
		if ((int)me->query("chblk_chat"))
			me->delete("chblk_chat");
                if ((int)me->query("chblk_menpai"))
			me->delete("chblk_menpai");
		tell_object(me, HIC "你的频道已经打，请注意不要再犯！\n" NOR);
        log_file("Chblk",sprintf("[%s] %s(%s) 的频道被 系统 打开了\n",ctime(time())[0..15],me->query("name"),me->query("id"))); 
		return 0;
	}
	me->apply_condition("chblk_c", duration - 1);
	return 1;
}
