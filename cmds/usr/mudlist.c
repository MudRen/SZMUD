// Code of ShenZhou
// mudlist.c

#include <net/daemons.h>
#include <net/macros.h>
#include <net/dns.h>
#include <ansi.h>

inherit F_CLEAN_UP;

#define SYNTAX  "指令格式：mudlist [<Mud 名称>]\n"

int isPlayer( object obj )
{
    if ( userp( obj ) ) return 1;
    if ( interactive( obj ) ) return 1;
    if ( environment( obj ) && obj->query( "scheming" ) ) return 1;
    return 0;
}

void create() { seteuid(getuid()); }

string cuptime(int t)
{
        int d, h, m;
        string time;

        if (t<100) return "<失去连络中>     ";

        t /= 60;
        m = t % 60; t /= 60;
        h = t % 24; t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";

        return time;
}

int main(object me, string arg)
{
        object *usr;
        mapping mud_list;
        mapping mud_svc;
        mixed *muds;
        string output, ips;
        int i, loop, size, usernum, wiznum, total=0, uptime;

        if( !find_object(DNS_MASTER) )
                return notify_fail("网路精灵并没有被载入，请先将网路精灵载入。\n");

        //      Obtain mapping containing mud data
        mud_list = (mapping)DNS_MASTER->query_muds();

        // so we recognise ourselves as a DNS mud
        mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

        if(!mud_list)
                return notify_fail( MUD_NAME + "目前并没有跟网路上其他 Mud 取得联系。\n");

        //      Get list of all mud names within name server
        muds = keys( mud_list ) - ({ "DEFAULT" });

        if (!wizardp(me)) muds -= ({ "dv" });

        //      Place mudlist into alphabetical format
        muds = sort_array(muds, 1);

        //      If mudname provided, search server's database for a match
        //      and display its cooresponding address
        if(arg && arg != "" && wizardp(me)) {
                arg = htonn(arg);

                if(!mapp( mud_list[arg] )) {
                        write(MUD_NAME + "并没有和这个 Mud 取得联系。\n");
                        return 1;
                }
                printf("有关 %s 的资讯：\n%O\n", arg, mud_list[arg]);
                return 1;
        }

        output = CYN"   站点名称\t  国际网路位址\t  埠号\t       运行时间\t\t  玩家人数\n===============  ===============  ====\t======================\t============\n"NOR;

        //      Loop through mud list and store one by one
        for(loop = 0, size = sizeof(muds); loop<size; loop++) {
                if(muds[loop] == lower_case(Mud_name())) {
				usr = filter_array( children(USER_OB), (:isPlayer :) );
                                usernum = 0;
                                wiznum = 0;                             
                                for(i=0; i<sizeof(usr); i++) {
                                        if( !environment(usr[i]) ) usernum++;
                                        else if( wizardp(usr[i]) ) wiznum++;
                                        else usernum++;
                                        }
                        if(wizardp(me))usernum += wiznum;
//                      usernum = sizeof(users());
//                      wiznum = sizeof(wizardp(users()));
//                      usernum = usernum - wiznum;
                        total += usernum;
                        uptime = uptime();
                } else {
                        usernum = (int)(AUX_PATH+DNS_RWHO_A)->query(mud_list[muds[loop]]["NAME"]+"/USERNUM");
                        total += usernum;
                        uptime = (int)(AUX_PATH+DNS_RWHO_A)->query(mud_list[muds[loop]]["NAME"]+"/UPTIME");
                }
                if( htonn(upper_case(muds[loop])) == htonn(upper_case(INTERMUD_MUD_NAME)) )
                        output += BBLU;
                else
                        output += NOR;
                        if ( mud_list[muds[loop]]["NAME"] == "OPN" ) usernum = usernum+20;
			if ( mud_list[muds[loop]]["NAME"] == "NEW" ) usernum = usernum+20;
			if ( mud_list[muds[loop]]["NAME"] == "OPN" ) ips = "211.91.27.134";
			if ( mud_list[muds[loop]]["NAME"] == "TST" ) ips = "211.91.27.134";
			if ( mud_list[muds[loop]]["NAME"] == "NEW" ) ips = "61.241.107.7";
			output += sprintf(HIC"%-17s"HIG"%-16s%5s\t"HIW"%22s \t%10s位\n"NOR, mud_list[muds[loop]]["CNAME"]+"("+mud_list[muds[loop]]["NAME"]+")", 
                        ips,
                        mud_list[muds[loop]]["PORT"],
                        cuptime(uptime),
                        chinese_number(usernum) );
        }
     output += CYN"===============  ===============  ====\t======================\t============\n"YEL"本游戏世界共有"+chinese_number(total+20)+"位玩家连线中。\n\n"NOR;

        //      Display dumped mudlist output through user's more pager
        if (userp(me) ) this_player()->start_more( output );
        else write(output);

        return 1;
}

string do_mudlist(string arg)
{
        object *usr;
        mapping mud_list;
        mapping mud_svc;
        mixed *muds;
        string output, ips;
        int i, loop, size, usernum, wiznum, total=0, uptime;
        object me=this_object();

        if( !find_object(DNS_MASTER) )
                return "网路精灵并没有被载入，请先将网路精灵载入。\n";

        //      Obtain mapping containing mud data
        mud_list = (mapping)DNS_MASTER->query_muds();

        // so we recognise ourselves as a DNS mud
        mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

        if(!mud_list)
                return MUD_NAME + "目前并没有跟网路上其他 Mud 取得联系。\n";

        //      Get list of all mud names within name server
        muds = keys( mud_list ) - ({ "DEFAULT" });

        if (!wizardp(me)) muds -= ({ "dv" });

        //      Place mudlist into alphabetical format
        muds = sort_array(muds, 1);

        //      If mudname provided, search server's database for a match
        //      and display its cooresponding address
        if(arg && arg != "" && wizardp(me)) {
                arg = htonn(arg);

                if(!mapp( mud_list[arg] )) {
                        return MUD_NAME + "并没有和这个 Mud 取得联系。\n";
                }
                
                return sprintf("有关 %s 的资讯：\n%O\n", arg, mud_list[arg]);
        }

        output = CYN"   站点名称\t  国际网路位址\t  埠号\t       运行时间\t\t  玩家人数\n===============  ===============  ====\t======================\t============\n"NOR;

        //      Loop through mud list and store one by one
        for(loop = 0, size = sizeof(muds); loop<size; loop++) {
                if(muds[loop] == lower_case(Mud_name())) {
				usr = filter_array( children(USER_OB), (:isPlayer :) );
                                usernum = 0;
                                wiznum = 0;                             
                                for(i=0; i<sizeof(usr); i++) {
                                        if( !environment(usr[i]) ) usernum++;
                                        else if( wizardp(usr[i]) ) wiznum++;
                                        else usernum++;
                                        }
                        if(wizardp(me))usernum += wiznum;
//                      usernum = sizeof(users());
//                      wiznum = sizeof(wizardp(users()));
//                      usernum = usernum - wiznum;
                        total += usernum;
                        uptime = uptime();
                } else {
                        usernum = (int)(AUX_PATH+DNS_RWHO_A)->query(mud_list[muds[loop]]["NAME"]+"/USERNUM");
                        total += usernum;
                        uptime = (int)(AUX_PATH+DNS_RWHO_A)->query(mud_list[muds[loop]]["NAME"]+"/UPTIME");
                }
                if( htonn(upper_case(muds[loop])) == htonn(upper_case(INTERMUD_MUD_NAME)) )
                        output += BBLU;
                else
                        output += NOR;
                        if ( mud_list[muds[loop]]["NAME"] == "OPN" ) usernum = usernum+20;
			if ( mud_list[muds[loop]]["NAME"] == "NEW" ) usernum = usernum+20;
			if ( mud_list[muds[loop]]["NAME"] == "OPN" ) ips = "211.91.27.134";
			if ( mud_list[muds[loop]]["NAME"] == "TST" ) ips = "211.91.27.134";
			if ( mud_list[muds[loop]]["NAME"] == "NEW" ) ips = "61.241.107.7";
			output += sprintf(HIC"%-17s"HIG"%-16s%5s\t"HIW"%22s \t%10s位\n"NOR, mud_list[muds[loop]]["CNAME"]+"("+mud_list[muds[loop]]["NAME"]+")", 
                        ips,
                        mud_list[muds[loop]]["PORT"],
                        cuptime(uptime),
                        chinese_number(usernum) );
        }
        output += CYN"===============  ===============  ====\t======================\t============\n"YEL"本游戏世界共有"+chinese_number(total)+"位玩家连线中。\n\n"NOR;

        return output;
}

int help()
{
        write( SYNTAX + "\n"
                "这个指令让你列出目前跟"+Mud_cname()+"取得联系中的其他站点。\n"
        );
        return 1;
}

