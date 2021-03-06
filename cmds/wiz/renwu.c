//renwu.c 
//keyboy@shiji
#include <ansi.h>
inherit F_CLEAN_UP;

string replace_color(string, int);

int main(object me, string arg)
{
        int i, flag = 0;
        object ob;
        string mission, bm, sb;
        if( me!=this_player(1) ) return 0;

        if( !arg)
                return notify_fail("指令格式：renwu [<巫师名> <新任务>]|[list]\n");

	if(arg == "list")
	{
		write( SECURITY_D->query_renwu());
		return 1;
	}

        if( sscanf(arg, "%s %s %s", sb, bm, mission)!=3 )
        	if( sscanf(arg, "%s %s", sb, mission)!=2 )
                	return notify_fail("指令格式：renwu <巫师名> <部门代码> (目前任务)\n");

        if( strlen(mission) > 100 )
		return notify_fail("你写的任务太长了，精简一些吧！\n");

        if( !objectp(ob = present(sb, environment(me))))
		ob = find_player(sb);

	if( ob && !userp(ob) )
		return notify_fail("你只能改变使用者的任务。\n");

	if(!ob)
	{
		seteuid(getuid());
		ob = new("/clone/test/dummy");
		ob->set("id", sb);
		if ( !ob->restore() )
		{
			notify_fail("没有这个玩家。\n");
		}
		seteuid(getuid());
	}
                
//        if( ob && !wizardp(ob) && mission != "del")
//                 return notify_fail("你只能改变在职巫师的任务。\n");

	seteuid(getuid());

	if (bm && bm != "GLB" && bm != "SWB" && bm != "KFB")
			return notify_fail("部门代码错误。\n代码分别是：GLB 管理部、KFB 开发部、SWB 玩家事务部。\n");
	
	if( !(SECURITY_D->set_renwu(ob, mission, bm)) )
		return notify_fail("修改失败。\n");
          
	if( mission != "del")
        	message_vision("$N将$n的工作任务改为 " + mission + " 。\n", me, ob);
	else message_vision("$N将$n的工作任务取消了。\n", me, ob);
	seteuid(getuid());
	ob->setup();
        return 1;
}
        
string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        if(flag) arg+=NOR;
        return arg;
}

int help(object me)
{
        write(@HELP
指令格式 : renwu <巫师名> <部门代码> (目前任务)

代码有三个：GLB 管理部、KFB 开发部、SWB 玩家事务部
用来改变巫师当前工作任务的说明。
取消任务用 renwu del 命令。
HELP
        );
        return 1;
}




