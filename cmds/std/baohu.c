//Bula 3.18
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object who,obj;


        if( !arg ) {
		if(me->query_temp("protecting") ) {
			if( objectp(obj=find_living(me->query_temp("protecting")) )){
				tell_object(me, "你现在正在保护"+obj->query("name")+"。\n");
				return 1;
			}
		}
		tell_object(me,"你要保护什么人？\n");
		return 1;
	}
	
	if( arg=="me" || arg == me->query("id") )  
                return notify_fail("你要保护什么人？\n");

        if( arg=="none") {
		if( !me->query_temp("protecting") ){
			tell_object(me, "你并没有保护任何人。\n");
			return 1;
		}
                if( objectp(obj=find_living(me->query_temp("protecting")) )) {
                        tell_object(obj, me->query("name")+"放弃保护你了。\n");
			tell_object(me, "你放弃保护"+obj->query("name")+"。\n");
			me->delete_temp("protecting");
			return 1;
		}
		tell_object(me, "你放弃保护别人。\n");                
		me->delete_temp("protecting");                
		return 1;
        }     

	if( !objectp(who=present(arg, environment(me))))
		return notify_fail("你要保护什么人？\n");

	if( !living(who) )
		return notify_fail("你不能保护"+who->query("name")+"。\n");

	if( me->query_temp("protecting") == who->query("id") )
		return notify_fail("你已经在保护这个人了。\n");

	if((int)me->query_condition("no_pk_time") > 480 )
		return notify_fail("你最近杀人太多。。。\n");

        if( who->query("combat_exp") - me->query("combat_exp") > me->query("combat_exp") / 20 )
                return notify_fail("你这点微末的功夫还要保护"+who->query("name")+"，真是自不量力！\n");

	if( me->query("combat_exp") - who->query("combat_exp") < who->query("combat_exp") / 20 )
                return notify_fail("你和"+who->query("name")+"半斤八两，还是自保吧！\n");
		
	if( me->query_temp("protecting") ) {
                if( objectp(obj=find_living(me->query_temp("protecting")) )) {
                        tell_object(obj, me->query("name")+"放弃保护你了。\n");
			tell_object(me, "你放弃保护"+obj->query("name")+"。\n");
		}
        }

	message_vision(HIC"$N开始保护$n。\n"NOR, me, who);

	who->set_temp("protected", 1);
	who->set_temp("protect_ob", me->query("id"));
        me->set_leader(who);
	me->set_temp("protecting", who->query("id"));
	return 1;

}

int help(object me)
{
   write( @HELP
指令格式: baohu [<人物>|<NPC>|none]

开始保护／放弃保护某人。
当开始保护后会自动跟随被保护人。
HELP
   );
   return 1;
}
