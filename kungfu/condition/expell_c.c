// Code of ShenZhou

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
                message_vision("大牢的门忽然开了，两名武林盟主座下的武士走了进来。\n", me);
                message_vision("对$N说道：“盟主让我送你出去。”说完带着$N走了出去。\n", me);
                me->move("/d/city/wumiao");
		message("vision",
                       HIY "只见两名武林盟主座下的武士带着一个人来到了这里。\n对"+HIY+me->name()+"说道：“你好自为知吧！”说完就向泰山方向走了。\n" NOR, environment(me), ({me}));

		tell_object(me, HIY "你跟着两名武士东拐西拐地来到了武庙，你的心情好了许多！\n" NOR);
		me->set("startroom", "/d/city/wumiao");
	        log_file("Expell",sprintf("[%s] %s(%s)　从武林大狱中释放\n",ctime(time())[0..15],me->query("name"),me->query("id"))); 
		return 0;
	}
	me->apply_condition("expell_c", duration - 1);
	return 1;
}
