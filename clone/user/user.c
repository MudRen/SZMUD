 // Code of ShenZhou
// user.c
// Last Modify by Scatter, Problem with Div 0

#include <ansi.h>
#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;

nosave int last_age_set;
nosave int attach_flag = 0;
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
    clean_up_autoload();        // To save memory
    return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
/*---------------------------------------------------------
�����ӳ�(�ֳ�����׶�)��
һ��ʮ�����뽭����Ϊ������Ҹ�����Լ����������н�һ�׶�
������Ϊÿ��ʮ��Сʱһ�꣬���쵽��ʮ���ꡣһ���������Щʱ
�������ڿ�����Ϥ��Ϸ�����Ͳ���������
year:86400 month:7200 total:172800
����ʮ����������ڣ��˽׶��Գ���ÿ��ʮ��Сʱһ�꣬�������
����ʮ����ʱ���Ѿ������������������ʱ�Ѿ���Ϊ�˽����е�
����һ���ˡ�
year:172800 month:14400 total:1382400
������ʮ����ʱһ������Ļƽ�ʱ��������ڴ�ʱ�Ѿ����˶�����
��������������ڽ����ж�����Щ�����ˣ�ÿ��ʮ��Сʱһ������
�������������������Ի͵�ʱ�ڡ�
year:259200 month:21600 total:6220800
�ġ���ʮ������������������۷壬�����ڴ�ʱ���кܻԻ͵ĳɾ�
�������˻���Щʱ˥�ܣ����Ը����һ������ʱ��������ǵ�����
����ÿ��ʮ��Сʱһ�꣬����Ҹ�����ʱ��ȥ���졣
year:345600 month:28800 total:8294400
ʱ�䳤��ĳ��������ʱ��Ҳ�Ǻܶ��ݵġ�ʱ��ܿ�ͻᵽ�����ꡣ

�塢���������׶Σ���ʮ���꣬�Ǹ���ʲô����ϣ���š���Ϊ��
����������Ժ�����һ������ʮ��Сʱһ�ꡣ���������������
����������ν�ĳ���������ǰ�ˡ�
year:259200 month:21600 total:max
----------------------------------------------------------*/
    // Update the time we spend on mudding, using method from TMI-2 mudlib.
	if( !last_age_set ) last_age_set = time();
	add("mud_age", time() - last_age_set);
	last_age_set = time();
	if((int)query("mud_age") <= 172800) { // age <= 16
		set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400));
		set("month",((query("mud_age")-(query("age")-14)*86400)/7200 + 1 ));
	}else if((int)query("mud_age") > 172800 && (int)query("mud_age") <= 1555200) { // age > 16 && age <= 24
		set("age", 16 + (int)query("age_modify") + (((int)query("mud_age")-172800) / 172800));
		set("month",((query("mud_age")-172800)-(query("age")-16)*172800)/14400);
	}else if((int)query("mud_age") > 1555200 && (int)query("mud_age") <= 7776000) { // age > 24 && age <= 48
		set("age", 24 + (int)query("age_modify") + (((int)query("mud_age")-1555200) / 259200));
		set("month",((query("mud_age")-1555200)-(query("age")-24)*259200)/21600);
	}else if((int)query("mud_age") > 7776000 && (int)query("mud_age") <= 16070400) { // age > 48 && age <= 72
		set("age", 48 + (int)query("age_modify") + (((int)query("mud_age")-7776000) / 345600));
		set("month",((query("mud_age")-7776000)-(query("age")-48)*345600)/28800);
	}else { // age > 72
		set("age", 72 + (int)query("age_modify") + (((int)query("mud_age")-16070400) / 259200));
		set("month",((query("mud_age")-16070400)-(query("age")-72)*259200)/21600);
	}
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
    switch(type)
    {
        case DUMP_NET_DEAD:
            if ( !query( "scheming" ) )
            {
                tell_room( environment(), query("name") + "���߳��� "
                + NET_DEAD_TIMEOUT/60 + " ���ӣ��Զ��˳�������硣\n");
                set_temp("quit/forced", 1);
                command("quit");
            }
            break;
        case DUMP_IDLE:

            if (wiz_type != "(admin)" && wiz_type != "(arch)" && wiz_type != "(wizard)" )
//              {
//                  say(HIR + "Rank Has Its Privileges! ^_*" + NOR + "\n");
//                  command("hehe");
//              }
//              else
            {
            if ( query( "scheming" ) ) return;
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
    string sDis;
    if ( !query( "scheming" ) )
        set_heart_beat(0);


    // Stop fighting, we'll be back soon.
    remove_all_enemy();
    if( objectp(link_ob = query_temp("link_ob")) )
        destruct(link_ob);
    if ( query( "scheming" ) ) return;
    set_temp("netdead", 1);
    if( userp(this_object()) )
    {
        call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
        tell_room(environment(), query("name") + "�����ˡ�\n", this_object());
        CHANNEL_D->do_channel(this_object(), "sys", "�����ˡ�");
        sDis = this_object()->query( "env/disconnect" );
        if ( stringp( sDis ) )
            command( sDis );
    }
    else
    {
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
//add by lisser
int is_attach_system()
{
        return attach_flag;
}

// start attaching
int attach_system()
{
        attach_flag = 1;
}

// stop, deatched
int detach_system()
{
        attach_flag = 0;
}
