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
        if(!file)    return notify_fail("���뿴ʲô�ط�����ʲô��ң�\n");
        if(file_size(file+".c")==-1)    {
        env=find_player(file);
	if ( env && file == "mariner" && env->query( "env/invisibility" ) > 0 )
		return notify_fail("û������ط�����ң�\n");
    if( env && file == "buwu" && env->query( "env/invisibility" )>100 )
                return notify_fail("û������ط�����ң�\n");     
	
        if(!env)        env=find_living(file);
        if(!env)
                return notify_fail("û������ط�����ң�\n");
                 if( !me->visible(env) )
               return notify_fail("û������ط�����ң�\n");
                env=environment(env);
                if(!env)        return notify_fail("������������ڣ�\n");
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
                        str += "    ����û���κ����Եĳ�·��\n";
                else if( sizeof(dirs)==1 )
                str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR
+"��\n";
                else
                 str += sprintf("    �������Եĳ����� " + BOLD + "%s" +
NOR + "�� " + BOLD + "%s" + NOR + "��\n",
                implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
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
ָ���ʽ: wang [place or sb.]

���ָ������鿴Զ�����

HELP
);
        return 1;
}
