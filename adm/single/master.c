// Code of ShenZhou
//
// master.c
//
// for ES II mudlib
// original from Lil
// rewritten by Annihilator (11/07/94)
// modified by Xiang for XKX (12/15/95
// modified by Xuy for XKX (08/21/97)
#include <runtime_config.h>

object connect()
{
    object login_ob;
    mixed err;

    err = catch(login_ob = new(LOGIN_OB));

    if (err) {
        write("�������������޸�ʹ�������߲��ݵĳ�ʽ�������������\n");
        write(err);
        destruct(this_object());
    }
    return login_ob;
}

// compile_object: This is used for loading MudOS "virtual" objects.
// It should return the object the mudlib wishes to associate with the
// filename named by 'file'.  It should return 0 if no object is to be
// associated.
mixed compile_object(string file)
{
    object daemon;

    if( daemon = find_object(VIRTUAL_D) )
        return daemon->compile_object(file);
    else
        return 0;
}

// This is called when there is a driver segmentation fault or a bus error,
// etc.  As it's static it can't be called by anything but the driver (and
// master).
protected void crash(string error, object command_giver, object current_object)
{
#if INSTALL_CRASH_SAVE
        object ob;
        string dump_dir;
        string user;
        string flogin, fuser;
        mixed lt;
#endif

        efun::shout("ϵͳ���ķ���һ���ҽУ��ۡ������֡�\n");
        efun::shout("ϵͳ���ĸ����㣺Ҫ�����ˣ��Լ����ذɣ�\n");
        log_file("static/CRASHES", MUD_NAME + " crashed on: " + ctime(time()) +
             ", error: " + error + "\n");
        if (command_giver)
                log_file("static/CRASHES",
                         sprintf( "this_player: %O\n", command_giver));
        if (current_object)
                log_file("static/CRASHES",
                         sprintf( "this_object: %O\n", current_object));

#if INSTALL_CRASH_SAVE
        lt = localtime(time());
        lt[LT_MON]++;
        dump_dir = sprintf(DUMP_DIR "%d-%d-%d/", lt[LT_YEAR], lt[LT_MON], lt[LT_MDAY]);
        foreach (ob in users())
        {
                reset_eval_cost();

                // backup user data to dump
                user = geteuid(ob);
                if (! stringp(user))
                        continue;
                flogin = "login/" + user[0..0] + "/" + user + __SAVE_EXTENSION__;
                fuser  = "user/"  + user[0..0] + "/" + user + __SAVE_EXTENSION__;
                if (file_size(DATA_DIR + flogin) > 0 &&
                    file_size(DATA_DIR + fuser) > 0)
                {
                        // exist in data, I will backup it to dump
                        assure_file(dump_dir + flogin);
                        assure_file(dump_dir + fuser);
                        cp(DATA_DIR + flogin, dump_dir + flogin);
                        cp(DATA_DIR + fuser,  dump_dir + fuser);
                        log_file("static/dump",
                                 sprintf("backup user(%s) to dump\n", user));
                }
                ob->save();
        }
#endif
}// �˲�����ȫ����hellcode by Karlopex@sz at 06/03/2002
// Function name:   update_file
// Description:     reads in a file, ignoring lines that begin with '#'
// Arguements:      file: a string that shows what file to read in.
// Return:          Array of nonblank lines that don't begin with '#'
// Note:            must be declared static (else a security hole)
protected string *update_file(string file)
{
    string *list;
    string str;
    int i;

    str = read_file(file);
    if (!str)
        return ({});
    list = explode(str, "\n");
    for (i = 0; i < sizeof(list); i++)
        if (list[i][0] == '#')
            list[i] = 0;

        list -= ({ 0 });
    return list;
}

// Function name:       epilog
// Return:              List of files to preload
string *epilog(int load_empty)
{
    string *items;

    items = update_file(CONFIG_DIR + "preload");
    return items;
}

// preload an object
void preload(string file)
{
    int t1;
    string err;

    if (file_size(file + ".c") == -1)
        return;

    t1 = time();
    write("Preloading : " + file );
    err = catch(call_other(file, "??"));
    if (err)
        write(" -> Error " + err + " when loading " + file + "\n");
    else
        write(".... Done.\n");

}

// Write an error message into a log file. The error occured in the object
// 'file', giving the error message 'message'.
void log_error(string file, string message)
{
    if (strsrch(message, "Warning") == -1)
    {
        if (this_player(1))
        {
            efun::write(get_config(__DEFAULT_ERROR_MESSAGE__) + "\n");
        }
        // ��¼������־
        efun::write_file(LOG_DIR + "log_error", message);
    }
    else
    {
        // ��¼������־
        efun::write_file(LOG_DIR + "log", message);
    }
}

// save_ed_setup and restore_ed_setup are called by the ed to maintain
// individual options settings. These functions are located in the master
// object so that the local admins can decide what strategy they want to use.
int save_ed_setup(object who, int code)
{
    string file;

    if (!intp(code))
        return 0;
    file = user_path(getuid(who)) + ".edrc";
    rm(file);
    return write_file(file, code + "");
}

// Retrieve the ed setup. No meaning to defend this file read from
// unauthorized access.
int retrieve_ed_setup(object who)
{
    string file;
    int code;

    file = user_path(getuid(who)) + ".edrc";
    if (file_size(file) <= 0) {
        return 0;
    }
    sscanf(read_file(file), "%d", code);
    return code;
}

// When an object is destructed, this function is called with every
// item in that room.  We get the chance to save users from being destructed.
void destruct_env_of(object ob)
{
    if (!interactive(ob))
        return;
    tell_object(ob, "�������ڵĿռ䱻�����ˡ�\n");
    ob->move(VOID_OB);
}

// make_path_absolute: This is called by the driver to resolve path names in ed.
string make_path_absolute(string file)
{
    file = resolve_path((string)this_player()->query("cwd"), file);
    return file;
}

// called if a user connection is broken while in the editor; allows
// the mudlib to save the changes in an alternate file without modifying
// the original
string get_save_file_name(string fname)
{
    return fname + "." + time();
}

string get_root_uid()
{
    return ROOT_UID;
}

string get_bb_uid()
{
    return BACKBONE_UID;
}

string creator_file(string str)
{
    return (string)call_other(SIMUL_EFUN_OB, "creator_file", str);
}

string domain_file(string str)
{
    return (string)call_other(SIMUL_EFUN_OB, "domain_file", str);
}

string author_file(string str)
{
    return (string)call_other(SIMUL_EFUN_OB, "author_file", str);
}

// simulate the old behavior of the driver
string standard_trace(mapping error, int caught)
{
    int i, s;
    string res;
    object me;
    mixed *cmds;
    /* keep track of number of errors per object...if you're into that */

    res = (caught) ? "����ѶϢ������: " : "";
    res = sprintf("%s\nִ��ʱ�δ���%s\n��ʽ��%s �� %i ��\n���: %O\n",
    res, error["error"],
    error["program"], error["line"],
    error["object"]);

    if (! error["object"] && (me = this_player()))
    {
        res += sprintf("��ǰ��ң�%s(%s) - %O  ���ڻ�����%O\n",
            me->name(1), me->query("id"), me, environment(me));
        cmds = me->query_commands();
        res += me->name(1) + "���ϼ����ܵ���Ʒ�����ڵĻ����ṩ����ָ�\n";
        for(i = 0; i<sizeof(cmds); i++)
            res += sprintf("%-15s  %2d %O\n",
                   cmds[i][0], cmds[i][1], cmds[i][2]);

        res += sprintf("��ǰ�����%O\n", me->query_last_input());
    }

    for (i=0, s = sizeof(error["trace"]); i < s; i++) {
        res = sprintf("%s�������ԣ�%s �� %s() �� %i �У������ %O\n",
            res,
            error["trace"][i]["program"],
            error["trace"][i]["function"],
            error["trace"][i]["line"],
            error["trace"][i]["object"] );
    }
    return res;
}

// The mudlib runtime error handler.
void error_handler( mapping error, int caught )
{
    string bugs =  standard_trace(error, caught);
    object ob = new ( CHANNEL_D );
    ob->set( "channel_id", "Bugs");
    CHANNEL_D->do_channel( ob, "sys", bugs);
    destruct( ob );
    if (this_player(1)) {
        tell_object(this_player(1), "[1;33m�㷢�����鲻����ˣ�������˵��������[2;37;0m\n");
        log_file("error_alias", (string)ALIAS_D->get_current_alias() + "\n");
    }

    // whatever we return goes to the debug.log
    efun::write_file(LOG_DIR + "error_handler", sprintf("%O\n", error));
}

// valid_shadow: controls whether an object may be shadowed or not
int valid_shadow( object ob ) { return 0; }

// valid_override: controls which simul_efuns may be overridden with
//   efun:: prefix and which may not.  This function is only called at
//   object compile-time
int valid_override( string file, string name )
{
    // simul_efun can override any simul_efun by Annihilator
    if (file == SIMUL_EFUN_OB || file==MASTER_OB)
        return 1;

    // Must use the move() defined in F_MOVE.
    if((name == "move_object") && file != F_MOVE && file != F_COMMAND)
        return 0;
    // add by Karlopex@sz at 06/03/2002
    if ((name == "destruct") && ! sscanf(file, "/adm/simul_efun/%s", file))
        return 0;

    //  may also wish to protect destruct, shutdown, snoop, and exec.
    return 1;
}

// valid_seteuid: determines whether an object ob can become euid str
int valid_seteuid( object ob, string str )
{
    return (int)SECURITY_D->valid_seteuid( ob, str );
}

// valid_socket: controls access to socket efunctions
int valid_socket( object eff_user, string fun, mixed *info )
{
    return 1;
}

// valid_asm: controls whether or not an LPC->C compiled object can use
//   asm { }
int valid_asm( string file )
{
    return 1;
}

// valid_compile_to_c: controls whether or not an object may be compiled
//   via LPC->C
int valid_compile_to_c( string file )
{
    return 1;
}

// valid_hide: controls the use of the set_hide() efun, to hide objects or
//   see hidden objects
int valid_hide( object who )
{
    return 1;
}

// valid_object: controls whether an object loaded by the driver should
//   exist
int valid_object( object ob )
{
    return (!clonep(ob)) || inherits(F_MOVE, ob);
}

// valid_link: controls use of the link() efun for creating hard links
//   between paths
int valid_link( string original, string reference )
{
    return 0;
}

// valid_save_binary: controls whether an object can save a binary
//   image of itself to the specified "save binaries directory"
//   (see config file)
int valid_save_binary( string filename )
{
    return 1;
}

// valid_write: write privileges; called with the file name, the object
//   initiating the call, and the function by which they called it.
int valid_write( string file, mixed user, string func )
{
    object ob;

    if( ob = find_object(SECURITY_D) )
        return (int)SECURITY_D->valid_write(file, user, func);

    return 0;
}

// valid_read: read privileges; called exactly the same as valid_write()
int valid_read( string file, mixed user, string func )
{
/*        object ob;

        if (ob = find_object(SECURITY_D))
                return (int)ob->valid_read(file, user, func);*/

    return 1;
}

string object_name(object ob)
{
    if( ob ) return ob->name();
}

void create()
{
    write("master: loaded successfully.\n");
}

int valid_bind(object binder, object old_owner, object new_owner)
{
    if( userp(new_owner) ) return 0;
    if( geteuid(binder)==ROOT_UID ) return 1;
    if( clonep(new_owner) ) return 1;
    return 0;
}
/*------------------------------------------------------------------------
// �Ƿ�ֱ������BINARY���������ļ���
int direct_run_binary(string file)
{
        object ob;
        object vob;

        if (sscanf(file, DATA_DIR "%*s"))
                // �����DATA������ļ�������ֱ������BIN���룬
                // ��Ҫ���г���İ汾��Ч��顣
                return 0;

        if (objectp(ob = find_object(CONFIG_D)) &&
            objectp(vob = find_object(VERSION_D)))
        {
                // �ҵ���CONFIG_D���鿴�����Ƿ��ǰ汾����վ
                // �㣬����ǣ���鿴�Ƿ��Ƿ�����Դ������
                // �򷵻ط񣬱�ʾ��Ҫ���BIN��
                return ob->query("release server") != "local" &&
                       ! VERSION_D->is_need_release_source(file);
        }

        // û���ҵ�CONFIG_D && VERSION_D�������룬ֱ������
        // BIN���롣
        return 1;
}
------------------------���ǲ����б��룬�����ò���--------------------*/
