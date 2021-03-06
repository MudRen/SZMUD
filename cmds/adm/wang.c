#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string file)
{

        int i, bri=0;
        object *inv,env;
        mapping exits;
        string str, *dirs;
        if(!file)    return notify_fail("你想看什么地方或是什么玩家？\n");
        if(file_size(file+".c")==-1)    {
        env=find_player(file);
	if ( env && file == "mariner" && env->query( "env/invisibility" ) > 0 )
		return notify_fail("没有这个地方或玩家！\n");
    if( env && file == "buwu" && env->query( "env/invisibility" )>100 )
                return notify_fail("没有这个地方或玩家！\n");     
	
        if(!env)        env=find_living(file);
        if(!env)
                return notify_fail("没有这个地方或玩家！\n");
                 if( !me->visible(env) )
               return notify_fail("没有这个地方或玩家！\n");
                env=environment(env);
                if(!env)        return notify_fail("这个环境不存在！\n");
        }
        else    {
        if(!env=find_object(file))      env=load_object(file);
        }
        str = sprintf( "%s - %s\n    %s%s",
                env->query("short"),
                wizardp(me)? file_name(env): "",
                bri ? "\n":env->query("long"),
        env->query("outdoors")?
           NATURE_D->outdoor_room_description() : "" );
        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if( sizeof(dirs)==0 )
                        str += "    这里没有任何明显的出路。\n";
                else if( sizeof(dirs)==1 )
                str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR
+"。\n";
                else
                 str += sprintf("    这里明显的出口是 " + BOLD + "%s" +
NOR + "和 " + BOLD + "%s" + NOR + "。\n",
                implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
        }
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( !me->visible(inv[i]) ) continue;
          //      if( inv[i]->query("no_shown")  ) continue;
                str += "  " + inv[i]->short() + "\n";
                }

        write(str);
        return 1;


}

int help (object me)
{
        write(@HELP
指令格式: wang [place or sb.]

这个指令让你查看远处景物。

HELP
);
        return 1;
}
