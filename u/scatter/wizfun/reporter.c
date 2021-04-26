 // Code of ShenZhou
// Interp. By Scatter
#include <ansi.h>
//inherit ITEM;
inherit NPC;

void create()
{
        set_name("������Ա", ({ "news reporter", "reporter" }) );
        set("long", "������ʦ��̨��������Ա��\n");
                set("max_qi", 10000);
                set("qi", 10000);
                set("max_jingli", 10000);
                set("jingli", 10000);
        enable_commands();

        setup();
}

void init() 
{
        add_action("do_scmds", "scmds");
        add_action("do_kill", "kill");
        add_action("do_slog", "slog");
        add_action("do_elog", "elog");
}

int do_elog(string arg)
{
        if(!query("startlog"))
        {
                write("LOG ����û������ô�ر�\n");
                return 1;
        }

        delete("logpos");
        write(HIR"LOG �ر�\n"NOR);
        delete("startlog");
        return 1;

}


int do_slog(string arg)
{
        if(!arg)
        {
                write("�����뵵������\n");
                return 1;
        }

        if(query("startlog"))
        {
                write("LOG �Ѿ�������, ���ȹر�\n");
                return 1;
        }

        set("logpos", arg);
        write(HIC"LOG ���� (����λ�� /log/autolog/"+arg+")\n"NOR);
        set("startlog", 1);
        return 1;

}


int do_kill(string arg)
{
        if(arg == "news reporter" || arg == "reporter")
        {
                write("��ͻȻ���������������");
                return 1;
        }
        return 0;
}

int do_scmds(string arg)
{
        command(arg);
        return 1;
}

void receive_message(string msgclass, string msg)
{
        int last = strsrch(msg, '\n', -1);
        mapping exits= environment(this_object())->query("exits");
        string where = environment(this_object())->query("short");
                string logpos;

        if(last != -1 ) 
                msg = msg[0..(last-1)];

        if (msg[0..0] != "\n")msg = GRN"��"+where+"��"NOR + msg;
        else msg = replace_string(msg, "\n", "\n"GRN"��"+where+"��"NOR);
        //tell_room(exits["down"], msg+"\n", this_object());
                tell_room("/u/scatter/workroom", msg+"\n", this_object());
                

                if(query("startlog"))
                {
                        logpos = "autolog/"+ query("logpos");
                        log_file(logpos,msg + "  " + ctime(time())+"\n");  
                }

}
