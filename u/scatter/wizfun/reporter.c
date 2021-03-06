 // Code of ShenZhou
// Interp. By Scatter
#include <ansi.h>
//inherit ITEM;
inherit NPC;

void create()
{
        set_name("新闻人员", ({ "news reporter", "reporter" }) );
        set("long", "他是巫师电台的新闻人员。\n");
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
                write("LOG 都还没启动怎么关闭\n");
                return 1;
        }

        delete("logpos");
        write(HIR"LOG 关闭\n"NOR);
        delete("startlog");
        return 1;

}


int do_slog(string arg)
{
        if(!arg)
        {
                write("请输入档案名称\n");
                return 1;
        }

        if(query("startlog"))
        {
                write("LOG 已经启动了, 请先关闭\n");
                return 1;
        }

        set("logpos", arg);
        write(HIC"LOG 启动 (档案位置 /log/autolog/"+arg+")\n"NOR);
        set("startlog", 1);
        return 1;

}


int do_kill(string arg)
{
        if(arg == "news reporter" || arg == "reporter")
        {
                write("你突然发现手软出不了手");
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

        if (msg[0..0] != "\n")msg = GRN"【"+where+"】"NOR + msg;
        else msg = replace_string(msg, "\n", "\n"GRN"【"+where+"】"NOR);
        //tell_room(exits["down"], msg+"\n", this_object());
                tell_room("/u/scatter/workroom", msg+"\n", this_object());
                

                if(query("startlog"))
                {
                        logpos = "autolog/"+ query("logpos");
                        log_file(logpos,msg + "  " + ctime(time())+"\n");  
                }

}
