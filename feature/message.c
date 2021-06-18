//Cracked by Kafei
// message.c

#include <ansi.h>
#include <dbase.h>
#include <localtime.h>

#define MAX_STRING_SIZE                 8000
#define MAX_MSG_BUFFER 500

nosave string *msg_buffer = ({});
nosave int written = 0;

// status of written
#define NONE                    0
#define PROMPT_WRITTEN          1
#define COMMAND_RCVD            2
nosave string log_in = 0;

// Should I be log ?
int is_loging_now()
{
    return log_in != 0;
}

int start_log()
{
    string file;
    mixed lt;

    if (log_in) return 0;

    lt = localtime(time());

    file = "user/" + sprintf("%d-%d-%d/", lt[LT_YEAR],
                   lt[LT_MON] + 1, lt[LT_MDAY]) +
         this_object()->query("id");

    log_file(file, sprintf("The system log the action of %s(%s) from %s on %s.\n\n",
                   this_object()->name(1), this_object()->query("id"),
                   query_ip_name(this_object()), ctime(time())));
    log_in = file;
    return 1;
}

void end_log()
{
    if (! log_in) return;

    log_file(log_in, sprintf("The system stop log at %s.\n\n",
         ctime(time())));
    log_in = 0;
}

void log_command(string msg)
{
    if (! log_in) return;

    log_file(log_in, HIC + ctime(time())[11..18] +
             HIY "> " + msg + NOR "\n");
}

void log_message(string msg)
{
    if (! log_in) return;

    msg = replace_string(msg, ESC "[256D" ESC "[K", "\n");
    msg = replace_string(msg, ESC "[1A", "");
    log_file(log_in, msg);
}

string prompt()
{
    string p;
    string prompt, path;
    mixed list;

    if (arrayp(list = query_temp("tell_list")) &&
        sizeof(list) > 1)
        p = HIG "> " NOR;
    else
        p = HIY "> " NOR;

    if (! stringp(prompt = query("env/prompt")))
        return p;

    switch (prompt)
    {
    case "time":
        p = HIC + ctime(time())[11..18] + p;
        break;
    case "date":
        p = HIC + ctime(time())[0..9] + p;
        break;
    case "mud":
        p = HIC + NATURE_D->game_time() + p;
        break;
    case "None":
        break;
    case "hp":
        p = HIG + sprintf("%d/%d", query("jing"), query("qi")) + p;
        break;
    case "hp2":
        p = HIG + sprintf("%d/%d", query("jingli"), query("neili")) + p;
        break;
    case "path":
        if (! wizardp(this_object()) || wiz_level(this_object()) < 3)
            break;
        if (! stringp(path = query("cwd")))
        {
            path = "/";
            set("cwd", path);
        }
        p = HIC + path[0..<2] + p;
        break;
    default:
        p = prompt + p;
        break;
    }

    return p;
}
void receive_message(string msgclass, string msg)
{
    string subclass, *ch;
    string trigger_cmd;

    if( !interactive(this_object()) && !this_object()->query( "scheming" ) ) {
        this_object()->relay_message(msgclass, msg);
        return;
    }

    if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 ) {
        switch(subclass) {
            case "channel":
                if( !pointerp(ch = query("channels"))
                ||      member_array(msgclass, ch)==-1 )
                    return;
                break;
            case "outdoor":
                if( !environment() || !environment()->query("outdoors") )
                    return;
                break;
            case "weather":
                if( !environment() || !environment()->query("weather") )
                    return;
                break;
            case "system":
                break;
            default:
                error("Message: Invalid Subclass " + subclass + ".\n");
        }
    }

    if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass) )
        return;
    if( objectp(this_object()) && userp(this_object()) && living(this_object()) )
        if ( random(this_object()->query_condition("blind")*2) >0 )return;

    if( objectp(this_object()) && this_object()->query("language") == "BIG5")
    msg = "/adm/daemons/languaged"->toBig5(msg);
    if( stringp(msg) && this_object()->query( "scheming" ))
    {
        trigger_cmd = this_object()->fire_trigger(msg);
        if ( trigger_cmd && trigger_cmd == "$gag" )
            return;
    }
    if (in_input(this_object()) || in_edit(this_object()) ||
        this_object()->is_attach_system() && msgclass != "system")
    {
        if (sizeof(msg_buffer) < MAX_MSG_BUFFER)
            msg_buffer += ({ msg });
    }
    else
    {
        log_message(msg);
        if (written && ! this_object()->is_attach_system())
        {
            if (written == COMMAND_RCVD)
            {
                written = NONE;
                msg = ESC "[256D" ESC "[K" + msg;
            } else
                msg = ESC "[256D" ESC "[K" + msg + prompt();
        }
        while (strlen(msg) > MAX_STRING_SIZE)
        {
            receive(msg[0..MAX_STRING_SIZE - 1]);
            msg = msg[MAX_STRING_SIZE..<1];
        }
        receive( msg );
    }
    call_out( "execute_tcmd", 1, trigger_cmd );
}

void execute_tcmd( string trigger_cmd )
{
    string *cmds;
    int i, len;
    if ( trigger_cmd )
    {
        tell_object(this_object(),"����ָ�"+trigger_cmd+"\n");
        cmds = explode( trigger_cmd, ";" );
        len = sizeof( cmds );
        if ( len > 10 ) len = 10;
        for ( i = 0; i < len; i ++ )
        {
            command( cmds[ i ] );
        }
    }
}

void clear_written()
{
    written = COMMAND_RCVD;
}

int is_waiting_command()
{
    return (written == PROMPT_WRITTEN);
}
void write_prompt()
{
    if( sizeof(msg_buffer) ) {
        receive(BOLD "[����ʱ�ݴ�ѶϢ]\n" NOR);
        for(int i=0; i<sizeof(msg_buffer); i++)
            receive(msg_buffer[i]);
        msg_buffer = ({});
    }
    if (! living(this_object()))
        return;

    if (this_object()->is_attach_system())
        receive(HIR "ִ����" HIY "> " NOR);
    else
        receive(ESC "[256D" + prompt());

    written = PROMPT_WRITTEN;
    //write("> ");
}

void receive_snoop(string msg)
{
	if ((msg[0..5] == ESC "[256D") && (msg[6..8] != ESC "[K"))
		// Don't snoop prompt
		return;
    msg = replace_string(msg, ESC "[1A", "");
    msg = replace_string(msg, NOR, NOR BBLU WHT);
    //msg = replace_string(msg, ESC "[K", NOR ESC "[K" BBLU WHT);
    msg = BBLU WHT + msg + BBLK NOR + " " + ESC "[1D";
//    msg = replace_string(msg, ESC "[1A", "");
//    msg = BBLU CYN + msg + NOR + " " + ESC "[1D";

    if (in_input(this_object()) || in_edit(this_object()) ||
        this_object()->is_attach_system())
    {
        if (sizeof(msg_buffer) < MAX_MSG_BUFFER)
            msg_buffer += ({ msg });
    } else
    {
        log_message(msg);
        if (written && ! this_object()->is_attach_system())
        {
            if (written == COMMAND_RCVD)
            {
                written = NONE;
                msg = ESC "[256D" ESC "[K" + msg;
            } else
                msg = ESC "[256D" ESC "[K" + msg + prompt();
        }
        while (strlen(msg) > MAX_STRING_SIZE)
        {
            receive(msg[0..MAX_STRING_SIZE - 1]);
            msg = msg[MAX_STRING_SIZE..<1];
        }
	    receive(msg);
    }
}
