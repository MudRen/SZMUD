 // Code of ShenZhou
// user.c
// Last Modify by Scatter, Problem with Div 0

#include <ansi.h>
#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
//inherit F_TRIGGER;

nosave int last_age_set;
nosave int attach_flag = 0;
void create()
{
    ::create();
    set_name("使用者物件", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
    set_temp("terminal_type", term_type);
    message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
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
年龄延长(分成五个阶段)：
一、十四岁入江湖，为了让玩家更快可以加入成熟的行列将一阶段
　　定为每二十四小时一岁，两天到达十六岁。一般的新手在些时
　　间内可以熟悉游戏环境和操作方法。
year:86400 month:7200 total:172800
二、十六岁的少年期，此阶段略长，每四十八小时一岁，当到达二
　　十四岁时，已经进入了青年的区域。这时已经成为了江湖中的
　　一份了。
year:172800 month:14400 total:1382400
三、二十四岁时一个青年的黄金时代，玩家在此时已经有了独自生
　　存的能力。在江湖中多少有些明堂了，每七十二小时一岁让玩
　　家来完成生命中最辉煌的时期。
year:259200 month:21600 total:6220800
四、四十八岁的中年是人生的巅峰，有人在此时会有很辉煌的成就
　　有人会在些时衰败，所以给玩家一个长的时间完成他们的理想
　　每九十六小时一岁，给玩家更长的时间去创造。
year:345600 month:28800 total:8294400
时间长，某种意义上时间也是很短暂的。时间很快就会到达老年。

五、人生的最后阶段：七十二岁，那个叫什么古来希来着。因为是
　　最后所以和三段一样，七十二小时一岁。最后加入老年随机死
　　亡。所谓的长江后浪推前浪。
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
    switch(type) {
        case DUMP_NET_DEAD:
            tell_room( environment(), query("name") + "断线超过 "
                + NET_DEAD_TIMEOUT/60 + " 分钟，自动退出这个世界。\n");
            set_temp("quit/forced", 1);
            command("quit");
            break;
        case DUMP_IDLE:

            if (wiz_type != "(admin)" && wiz_type != "(arch)" && wiz_type != "(wizard)" )
//              {
//                  say(HIR + "Rank Has Its Privileges! ^_*" + NOR + "\n");
//                  command("hehe");
//              }
//              else
            {
            tell_object( this_object(), "对不起，您已经发呆超过 "
                + IDLE_TIMEOUT/60 + " 分钟了，请下次再来。\n");
            tell_room( environment(), "一阵风吹来，将发呆中的" + query("name")
                + "化为一堆飞灰，消失了。\n", ({this_object()}));
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
    set_heart_beat(0);
    if( objectp(link_ob = query_temp("link_ob")) )
        destruct(link_ob);

    // Stop fighting, we'll be back soon.
    remove_all_enemy();

    set_temp("netdead", 1);
    if( userp(this_object()) ) {
        call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
        tell_room(environment(), query("name") + "断线了。\n", this_object());
        CHANNEL_D->do_channel(this_object(), "sys", "断线了。");
        sDis = this_object()->query( "env/disconnect" );
        if ( stringp( sDis ) )
            command( sDis );
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
    tell_object(this_object(), "重新连线完毕。\n");

    if (query_temp("sleep_type"))
        input_to("check_input",0,this_object());
}

//add by yujie

void check_input(string arg,object me)
{
    if (me->query_temp("sleep_now"))
    {       tell_object(me,"才刚刚睡着，再多睡一会儿吧。\n");
        input_to("check_input",0,me);
        return;
    }
    tell_room(environment(me), me->name()+"一觉醒来，精力充沛地活动了一下筋骨。\n" ,me);
    tell_object(me,"你活动了一下筋骨，只觉精力充沛。\n");
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
