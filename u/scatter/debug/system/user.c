 // Code of ShenZhou
// user.c
// Last Modify by Scatter, Problem with Div 0

#include <ansi.h>
#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;

static int last_age_set;

void create()
{
        ::create();
        set_name("ʹ�������", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
        set_temp("terminal_type", term_type);
        message("system", "�ն˻���̬�趨Ϊ " + term_type + "��\n", this_object());
}

void reset()
{
        int c = (int)query("combat_exp") - (int)query("combat_exp_last");
        int m = (int)query("mud_age") - (int)query("mud_age_last"); 

                if( m == 0 )
                {
                        m = m + 1;
                }

        if( (int)query("potential") < (int)query("max_potential") )
                add("potential", 1);
        if( (int)query("thief") > 0 )
                add("thief", -1 );
        if (3*c > m) log_file("CombatExp", sprintf("%s(%s) got %d combat_exp in %d seconds: %s\n", 
                        query("name"), getuid(this_object()), c, m, ctime(time())));
        set("combat_exp_last", query("combat_exp"));
        set("mud_age_last", query("mud_age"));
        if ( c/m*3600 > 10000 ) 
                log_file( "abnormalExp", sprintf("%s(%s) got %d combat_exp in%d seconds: %s\n", query("name"), getuid(this_object()), c, m, ctime(time())));
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
        string id;

        id = query("id", 1);
        if( !id ) id = geteuid();
        if( !id ) id = getuid();
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

int save()
{
        int res;

        save_autoload();
        res = ::save();
        clean_up_autoload();            // To save memory
        return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
        // Update the time we spend on mudding, using method from TMI-2 mudlib.
        if( !last_age_set ) last_age_set = time();
        add("mud_age", time() - last_age_set);
        last_age_set = time();
        if((int)query("mud_age") <= 864000) { // age <= 24 
        set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400)); 
        set("month",((query("mud_age")-(query("age")-14)*86400)/7200 + 1 )); }
        else { // age > 24 
        set("age", 24 + (int)query("age_modify") + (((int)query("mud_age")-864000) / 259200));
        set("month",((query("mud_age")-864000)-(query("age")-24)*259200)/21600); }
}

void setup()
{
        // We want set age first before new player got initialized with
        // random age.
        update_age();

        ::setup();
        restore_autoload();
}

private void user_dump(int type)
{
        string wiz_type;
        wiz_type = wizhood(this_object());
        switch(type) {
                case DUMP_NET_DEAD:
                        tell_room( environment(), query("name") + "���߳��� "
                                + NET_DEAD_TIMEOUT/60 + " ���ӣ��Զ��˳�������硣\n");
                        set_temp("quit/forced", 1);
                        command("quit");
                        break;
                case DUMP_IDLE:
           
                        if (wiz_type != "(admin)" && wiz_type != "(arch)" && wiz_type != "(wizard)" )
//                      {
//                              say(HIR + "Rank Has Its Privileges! ^_*" + NOR + "\n");
//                              command("hehe");        
//                      }
//                      else    
                        {
                        tell_object( this_object(), "�Բ������Ѿ��������� " 
                                + IDLE_TIMEOUT/60 + " �����ˣ����´�������\n");
                        tell_room( environment(), "һ��紵�����������е�" + query("name")
                                + "��Ϊһ�ѷɻң���ʧ�ˡ�\n", ({this_object()}));
                        set_temp("quit/forced", 1);
                        command("quit");
                        }
                        break;
                default: return;
        }
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
private void net_dead()
{
        object link_ob;

        set_heart_beat(0);
        if( objectp(link_ob = query_temp("link_ob")) )
                destruct(link_ob);

        // Stop fighting, we'll be back soon.
        remove_all_enemy();

        set_temp("netdead", 1);
        if( userp(this_object()) ) {
                call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
            tell_room(environment(), query("name") + "�����ˡ�\n", this_object());
            CHANNEL_D->do_channel(this_object(), "sys", "�����ˡ�");
        } else {
                set_temp("quit/forced", 1);
                command("quit");
        }
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
        set_heart_beat(1);
        set_temp("netdead",0);
        remove_call_out("user_dump");
        tell_object(this_object(), "����������ϡ�\n");
        
        if (query_temp("sleep_type"))
                input_to("check_input",0,this_object());
}

//add by yujie

void check_input(string arg,object me)
{
        if (me->query_temp("sleep_now"))
        {       tell_object(me,"�Ÿո�˯�ţ��ٶ�˯һ����ɡ�\n");
                input_to("check_input",0,me);
                return;
        }
        tell_room(environment(me), me->name()+"һ����������������ػ��һ�½�ǡ�\n" ,me);
        tell_object(me,"����һ�½�ǣ�ֻ���������档\n");
        me->delete_temp("sleep_type");
        return;
}
