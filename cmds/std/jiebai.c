// jiebai.c
// by lisser
#include <ansi.h>
#include <dbase.h>
inherit F_CLEAN_UP;
int help(object me);
/*int is_jiebai();
int is_jiebai_of(object ob);*/
int main(object me, string arg)
{
        object obj, old_target;
	mapping my;
	string x, title, title1;
	my = me->query_entire_dbase();

	if (me->query("title")) title = me->query("title");
	else title = "普通百姓";

        if(me->query("age") < 16)
                return notify_fail("小孩子一边玩儿去。\n");

        if(!arg ) { help(me); return 1;}
	
	if( sscanf(arg, "%s %s", arg, x)==2 ) {
		if(x != "/f")
			return notify_fail("如果你想放弃这个朋友，请输入"+HIR+"jiebai <ID> /f。"+NOR+"\n");

		if(!objectp(obj = present(arg, environment(me))))
	        	return notify_fail("你想和谁反目？\n");
	
	        if( !userp(obj) )
	                return notify_fail("你只能和已经拜把子的玩家反目成仇。\n");
	
	        if( !living(obj) )
	                return notify_fail("嗯...你还是先把"+obj->name()+"弄醒吧。\n");
	
	        if(obj==me)
	                return notify_fail("和自己反目？\n");
		
                if ( !me->is_jiebaied()) return notify_fail("你还没有结拜，要和谁反目？\n");
	
		if ( !me->is_jiebai_of(obj)) return notify_fail("你还没有和人家结拜，就要和他反目？\n");
		else{
			if (obj->query("title")) title1 = obj->query("title");
			else title1 = "普通百姓";

		        message("channel:chat",HIR"【反目成仇】"HIC + title + HIC + me->query("name") +"从此与"+HIC+  title1 +HIC+ obj->query("name")
		                 + "恩断意绝！\n\n"NOR,users());
			me->delete("jiebai/"+obj->query("id"));
			obj->delete("jiebai/"+me->query("id"));
			me->add("fanmu",1);
			return 1;
		}
	}

        if( me->jiebai_cnt() >= 3 ) 
                return notify_fail("你结拜人数已经有太多了。\n"); 

	if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("你想和谁结拜？\n");

        if( !obj->is_character() )
                return notify_fail("看清楚一点，那并不是生物。\n");

        if( !userp(obj) )
                return notify_fail("你只能和玩家拜把子。\n");

        if( !living(obj) )
                return notify_fail("嗯...你还是先把"+obj->name()+"弄醒吧。\n");

        if( me->is_spouse_of(obj))
                return notify_fail("夫妻之间还要结拜吗？\n");

        if( me->is_marry_of(obj))
                return notify_fail("你们俩已经订婚了，不用结拜了吧！\n");
                
	if( me->is_jiebai_of(obj) )
                return notify_fail("你已经和人家结拜过了。\n");

        if(obj==me)
                return notify_fail("你不能和自己结拜。\n");

        if(me->query_temp("pending/jiebai") == obj)
                return notify_fail("你已经向他发出请求，等他同意吧！\n");

        if( userp(obj) && (object)obj->query_temp("pending/jiebai")!=me ) {
                message_vision(HIC "\n$N对著$n说道：" 
                        + RANK_D->query_self(me) 
                        + me->name() + "，对"
                        + RANK_D->query_respect(obj) + "心仪已久，愿彼此生死与共，肝胆相照！\n\n"NOR, me, obj);
                if( objectp(old_target = me->query_temp("pending/jiebai")) )
                        tell_object(old_target, RED + me->name() + "取消了和你结拜的念头。\n" NOR);
                me->set_temp("pending/jiebai", obj);
                tell_object(obj, YEL "如果你愿意和对方结为异性骨肉，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 jiebai 指令。\n" NOR);
                write(RED "对方必须同意才能结拜。你等着吧。\n" NOR);
                return 1;
        }

	if (obj->query("title")) title1 = obj->query("title");
	else title1 = "普通百姓";

        message_vision(HIC"\n$N对着$n高声说道：不求同年同月同日生，但愿同年同月同日死！\n\n"NOR, me, obj);
        message("channel:chat",HIR"【结义金兰】"HIC + title + HIC + me->query("name") +"愿与"+HIC+  title1 +HIC+ obj->query("name")
                 + "结义金兰！\n\n            不求同年同月同日生，但愿同年同月同日死！\n"NOR,users());

        obj->delete_temp("pending/jiebai");
        me->set("jiebai/"+obj->query("id"),obj->query("name"));
        obj->set("jiebai/"+me->query("id"),me->query("name"));
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : jiebai <玩家ID> [/f]
 
这个指令用来和别人的结拜，当然对方必须也同意。
如果加入 /f  参数就是要和玩家决裂，请慎用！
HELP
    );
    return 1;
}

