// shutdown.c with time loop.

#include <ansi.h>
#include <mudlib.h>
#include <net/daemons.h>

inherit F_CLEAN_UP;

int counting = 0;

int help (object me)
{
        write(@HELP
ָ���ʽ: reboot < min|now >
 
����
    reboot      :  ��ʾ�����Ϣ��
    reboot now  :  ������������Ϸ��
    reboot 3    :  �������ӣ�Ȼ����������Ϸ��
    
HELP
);
        return 1;
}

int start_shutdown(int i)
{
        if( !intp(i) ) i = 3; 
        message("system",RED"\n\t"+HIR+CHINESE_MUD_NAME+HIR"���� "RED+chinese_number(i)+HIR" ���Ӻ������������������������׼����\n\n" NOR, users() );
        call_out("countdown", 60, i);
        counting = 1;
        return 1;
}


int main(object me, string arg)
{
        string wiz_status;
        object *user, link_ob;
        int i, time;

        if( me != this_player(1) ) return 0;
        
        wiz_status = SECURITY_D->get_status(me);
        if( wiz_status != "(admin)" && wiz_status != "(sage)" && wiz_status != "(arch)" )
                return notify_fail("ֻ�� (arch) ���ϵ���ʦ������������"+CHINESE_MUD_NAME+"��\n");

        user = filter_array(objects(), (: userp :));
        for(i=0; i<sizeof(user); i++) {
                if( !environment(user[i]) ) continue;
                user[i]->save();
                link_ob = user[i]->query_temp("link_ob");
                if( objectp(link_ob) ) link_ob->save();
        }

        log_file("static/CRASHES", geteuid(me) + " reboot "+CHINESE_MUD_NAME+" on: "
                + ctime(time()) + "\n");
        write_file("/log/static/LASTCRASH", me->query("name")+ " ���� "+CHINESE_MUD_NAME+" ��: "
                + ctime(time()) + "\n", 1);

        seteuid(getuid());
        
        if (!arg) return help(me);
        
        if (arg == "now") {
                message("system","\n\n\t"+HIR+CHINESE_MUD_NAME+HIR"��������������������˳������Ժ�һ�����ٳ������ߡ�\n\n"NOR,users() );
                if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
                shutdown(0);
        }
        
        if (sscanf(arg,"%d", time) != 1) return help(me);
        
        if( !intp(time) || time < 1) return help(me);
        
        if(counting != 0) return notify_fail(HIW"MUD�Ѿ��� shutdown �ˡ�\n"NOR);
        
        if(start_shutdown(time))
           write("Starting shutdown... \n");

        else return notify_fail ("��ʱReboot�����⣬���� /cmds/arch/reboot.c  \n");
        return 1;
}

void countdown(int min)
{
        min--;
        if( min ) {
                message("system","\n\t"+HIR+CHINESE_MUD_NAME+HIR"���� "HIR+ chinese_number(min) + HIR" ���Ӻ���������������������˳����Ժ������ߡ�\n\n"NOR, users() );
                call_out("countdown", 60, min);
        } else {
                message("system","\n\n\t"+HIR+CHINESE_MUD_NAME+HIR"��������������������˳����Ժ�һ�����ٳ������ߡ�\n\n"NOR,users() );
                call_out("do_shutdown", 3);
        }
}

void do_shutdown()
{
        if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
        shutdown(0);
}



