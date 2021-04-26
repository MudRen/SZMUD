 // Code of ShenZhou
// Interp. By Scatter
#include <ansi.h>
//inherit ITEM;
inherit NPC;

void create()
{
        set_name("DV ��Ӱ��", ({ "dvcam", "cam" }) );
        set("long", "��ʦʵ�� SNG ��Ӱת������\n");
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
        add_action("do_slog", "cstart");
        add_action("do_elog", "cend");
}

int do_elog(string arg)
{
        if(!query("startlog"))
        {
                write("LOG ����û������ô�ر�\n");
                return 1;
        }
        
        write(HIR"DV �ر�\n"NOR);
        shout(CYN"��ڤ�Ӱ���Ӱ����������, ����ʱ��ת��������\n" + NOR);
        write(CYN"��ڤ�Ӱ���Ӱ����������, ����ʱ��ת��������\n" + NOR);
        delete("startlog");
        return 1;

}


int do_slog(string arg)
{
        if(query("startlog"))
        {
                write("DV �Ѿ�������, ���ȹر�\n");
                return 1;
        }
        
        write(HIC"DV ����\n"NOR);
        shout(CYN"��ڤ�Ӱ���Ӱ���ܺ���, ����ʱ��ת��Ҫ��ʼ��\n" + NOR);
        write(CYN"��ڤ�Ӱ���Ӱ���ܺ���, ����ʱ��ת��Ҫ��ʼ��\n" + NOR);
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
                
                if(query("startlog"))
                {
                        shout(NOR"ʵ��ת�� - " + msg + "\n" + NOR);
                        write(NOR"ʵ��ת�� - " + msg + "\n" + NOR);
                }
}
