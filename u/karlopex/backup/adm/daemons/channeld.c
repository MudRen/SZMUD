// Code of ShenZhou
// channeld.c
//lisser add wiz use menpai channel 1.0 at 15/01/02
#include <ansi.h>
#include <mudlib.h>
#include <net/dns.h>
inherit F_DBASE;

#define BLOCK_CHAT      0
#define BLOCK_RUMOR     0
#define ALLOW_LIST ({ "sad" })
string remove_addresses(string, int);
int if_mp(string menpaix)
{
	if( menpaix == "星宿派" || menpaix == "雪山派" || menpaix == "白驼山")
		return 1;
	else return 0;
}
string *mp1 = ({
	"hs","xx","wd","dl","gb","xs","th","gm","sl","qz","em","bt","mj","xy","ry","ts","kl","lj","mr"
});
mapping mp = ([
	"hs":(["name":"华山派",]),
	"xx":(["name":"星宿派"]),
	"wd":(["name":"武当派"]),
	"dl":(["name":"大理段家"]),
	"gb":(["name":"丐帮"]),
	"xs":(["name":"雪山派"]),
	"th":(["name":"桃花岛"]),
	"gm":(["name":"古墓派"]),
	"sl":(["name":"少林派"]),
	"qz":(["name":"全真教"]),
	"em":(["name":"峨嵋派"]),
	"bt":(["name":"白驼山"]),
	"mj":(["name":"明教"]),
	"xy":(["name":"逍遥派"]),
	"ry":(["name":"日月神教"]),
	"ts":(["name":"天山派"]),
	"kl":(["name":"昆仑派"]),
	"lj":(["name":"灵鹫宫"]),
	"mr":(["name":"姑苏慕容"]),
]);
mapping channels = ([
        "sys":  ([      "msg_speak": YEL "【系统】%s：%s\n" NOR, "wiz_only": 1 ]),
/*        "wiz":  ([      "msg_speak": HIY "【巫师】%s：%s\n" NOR,
                        "msg_emote": HIY "【巫师】%s" NOR,
                        "wiz_only": 1
                                     ]),
*/
        "alarm":  ([      "msg_speak": HIR "【提示信息】%s：%s\n" NOR,
                        "msg_emote": HIR "【提示信息】%s" NOR,
                        "wiz_only": 1
                ]),
        "chat": ([      "msg_speak": HIW "【闲聊】%s：%s\n" NOR,
                        "msg_emote": HIW "【闲聊】%s" NOR,
                        "omit_address": 1,
                        "filter": 1
                 ]),
        "jiaoyi": ([      "msg_speak": HIY "【交易】%s："HIC"%s\n" NOR,
                        "msg_emote": HIC "【交易】%s" NOR,
                        "anonymous": "代理人",
                 ]),             
        "rumor":([      "msg_speak": HIM "【谣言】%s：%s\n" NOR,
                        "msg_emote": HIM "【谣言】%s" NOR,
                        "anonymous": "某人"
                ]),
        "menpai":([     "msg_speak": HIC "【门派】%s：%s\n" NOR,
                        "msg_emote": HIC "【门派】%s" NOR,
                        "menpai_only": 1
                        ]),
        "gwiz": ([      "msg_speak": HIY "【巫师】%s：%s\n" NOR,
                        "msg_emote": HIY "【巫师】%s\n" NOR,
                        "wiz_only": 1, "intermud": GWIZ, "channel": "CREATOR",
                        "filter": 1,
                        "omit_address": 0,
                        "intermud_emote": 1
                ]),
        "sz":  ([      "msg_speak": GRN "【凡界】%s：%s\n" NOR,
                        "msg_emote": GRN "【凡界】%s" NOR,
                       "intermud": GCHANNEL, "channel": "sz",
                        "intermud_emote": 1,
                        "omit_address": 1,
                        "filter": (: $1["MUDLIB"]=="Shen Zhou" :)
                ]),
]);

void create()
{
        seteuid(getuid());      // This is required to pass intermud access check.
        set("channel_id", "频道精灵");
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
        object *ob;
        string *tuned_ch, who, menpai, mps;
        // for debug
    	int wizmp;
	    int pts = 0, chatpts = 0;
        // Check if this is a channel emote.
        if( verb[sizeof(verb)-1] == '*' ) {
                emote = 1;
                verb = verb[0..<2];
        }
	    if (wizardp(me) && member_array(verb[sizeof(verb)-2..sizeof(verb)], mp1) != -1) {
		    wizmp = 1;
		    mps = verb[sizeof(verb)-2..sizeof(verb)];
		    verb = verb[0..<3];
	    }
        // Check if this is a channel messsage.
        if( !mapp(channels) || undefinedp(channels[verb]) ) return 0;

        //now we can be sure it's indeed a channel message:
        if (!stringp(arg) || arg == "" || arg == " ") arg = "...";

        // check if one can write to channels
        //only block rumor or chat...
        if ( me->query("chblk_on") )
        {
                me->set("chblk_rumor", 1);
                me->set("chblk_chat", 1);
                me->set("chblk_xkx", 1);
                me->set("chblk_menpai", 1);
        }

        //player broadcasting need consume jingli
        if( userp(me) && !wizardp(me) && verb == "rumor" )
                if(me->query("jingli") > 50) me->add("jingli", -50);
                else    return notify_fail("你已经没力气散播谣言了！\n");

        if( (!userp(me) || (userp(me) && !wizardp(me))) && verb == "chat" ){
                channels[verb]["msg_speak"] = HIC "【闲聊】%s：%s\n" NOR;
                channels[verb]["msg_emote"] = HIC "【闲聊】%s" NOR;
	}else if( userp(me) && wizardp(me) && verb == "chat" ){
                 channels[verb]["msg_emote"] = HIG "【闲聊】" HIC "%s" NOR;
                 channels[verb]["msg_speak"] = HIG "【闲聊】" HIC "%s：%s\n" NOR; 
        }
        if (channels[verb]["menpai_only"]) {
		if(wizmp && wizardp(me)) menpai = mp[mps]["name"]; // 加入巫师用门派频道。
		else
			if(channels[verb]["menpai_only"] && !me->query("family/family_name"))
				menpai = "无门派";
                	else menpai = me->query("family/family_name");
                channels[verb]["msg_speak"] = HIW "【"NOR HIW +menpai+ NOR HIW"】"HIW"%s：%s\n" NOR; 
                channels[verb]["msg_emote"] = HIW "【"NOR HIW +menpai+ NOR HIW"】"HIW"%s" NOR; 
        }
        
        // add points for chat
        //if ( verb == "chat" || verb == "menpai" )
        // check if rumor or chat is blocked
        if ((me->query("chblk_rumor") && (verb == "rumor"))||
                ((verb == "rumor") && BLOCK_RUMOR))
                return notify_fail("ｏｏｐｓ！你的谣言频道被关闭了！\n");

        if ((me->query("chblk_chat") && (verb == "chat"))||
                ((verb == "chat") && BLOCK_CHAT))
                return notify_fail("ｏｏｐｓ！你的聊天频道被关闭了！\n");

        if ((me->query("chblk_sz") && (verb == "sz"))||
                ((verb == "xkx") && BLOCK_CHAT))
                return notify_fail("ｏｏｐｓ！你的【神州】频道被关闭了！\n");

        if ((me->query("chblk_menpai") && (verb == "menpai"))||
                ((verb == "menpai") && BLOCK_CHAT))
                return notify_fail("ｏｏｐｓ！你的门派频道被关闭了！\n");

        if( userp(me) ) {
                if(channels[verb]["wiz_only"] && !wizardp(me))
                        return 0;

		if( arg==(string)me->query_temp("last_channel_msg") )
			return notify_fail("用交谈频道说话请不要重复相同的讯息。\n");

		if ( userp( me ) && ( verb == "chat" || verb == "menpai" ) && !emote ) 
        {
            if ( !chatpts = me->query( "chatpts" ) )
                chatpts = 0;
            chatpts = chatpts + 1;
            if ( chatpts > 30 )
            {
                if ( !pts = me->query( "shenzhou/pts" ) )
                    pts = 0;
                pts = pts + 1;
                chatpts = chatpts - 30;
                me->set( "shenzhou/pts", pts );
            }
            me->set( "chatpts", chatpts );
            me->save();
        }        

		
		if( living(me) ) 
		{
			me->set_temp("last_channel_msg", arg);
			me->add_temp("channel_msg_cnt", 1);
		}		

                // If we speaks something in this channel, then must tune it in.
                tuned_ch = me->query("channels");
                if( !pointerp(tuned_ch) )
                        me->set("channels", ({ verb }) );
                else if( member_array(verb, tuned_ch)==-1 )
                        me->set("channels", tuned_ch + ({ verb }) );
        }
  
        // Support of channel emote
        if( emote && me->is_character() ) {
                string vb, emote_arg, myinfo, id, mud;

                if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
                        vb = arg;
                        emote_arg = "";
                }

                if( channels[verb]["intermud_emote"]
                 && sscanf(emote_arg, "%s@%s", id, mud)==2 ) {
                        myinfo = sprintf("%s(%s@%s):%s:%s:%s:%d:%d", me->name(),
                                                capitalize((string)me->query("id")),
                                                INTERMUD_MUD_NAME,
                                                (string)me->query("gender"),
                                                RANK_D->query_self(me),
                                                RANK_D->query_self_rude(me),
                                                (int)me->query("age"),
                                                (int)me->query("mud_age"));
                        REMOTE_Q->send_remote_q(mud, myinfo, verb, vb, id);
                        write("网路讯息已送出，请稍候。\n");
                        return 1;
                }

                if( channels[verb]["intermud_emote"] )
                        arg = EMOTE_D->do_emote(me, vb, emote_arg, 3);
                else if( verb == "rumor" )
                        arg = EMOTE_D->do_emote(me, vb, emote_arg, 2);
                else
                        arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);

                if( !arg )
                {
                        // we should only allow chinese emote.
                        if( vb[0] < 128 ) return 0;
                        if( channels[verb]["anonymous"] )
                                arg = channels[verb]["anonymous"]+vb+" "+emote_arg+"\n";
                        else if( channels[verb]["intermud_emote"] )
                                arg = sprintf("%s(%s@%s)%s %s\n", me->name(), capitalize(me->query("id")), INTERMUD_MUD_NAME, vb, emote_arg);
                        else
                                arg = me->name()+vb+" "+emote_arg+"\n";
                }
        }

        // Make the identity of speaker.
        if( channels[verb]["anonymous"] ) {
                who = channels[verb]["anonymous"];
                if (userp(me))
                do_channel( this_object(), "sys", sprintf("谣言：%s(%s)。", me->query("name"), me->query("id")));
        }
        else if( userp(me) || !stringp(who = me->query("channel_id")) )
                who = me->name() + "(" + capitalize(me->query("id")) + ")";

        // Ok, now send the message to those people listening us.
	ob = filter_array( users(), "filter_listener", this_object(), channels[verb], menpai);
        if( !arg || arg == "" || arg == " " ) arg = "...";

        if( emote ) {
                string localmsg = arg;

                if(!stringp(arg)) return;
                if( channels[verb]["omit_address"] ) localmsg = remove_addresses(arg, 1);
                else if( channels[verb]["intermud_emote"] ) localmsg = remove_addresses(arg, 0);
                if(!stringp(localmsg)) return;
                message( "channel:" + verb,
                        sprintf( channels[verb]["msg_emote"], localmsg ), ob );
        } else
                message( "channel:" + verb,
                        sprintf( channels[verb]["msg_speak"], who, arg ), ob );

        if( arrayp(channels[verb]["extra_listener"]) ) {
                channels[verb]["extra_listener"] -= ({ 0 });
                if( sizeof(channels[verb]["extra_listener"]) )
                        channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
        }

        if( !undefinedp(channels[verb]["intermud"])
        &&      me->is_character() )
                channels[verb]["intermud"]->send_msg(
                        channels[verb]["channel"], me->query("id"), me->name(1), arg, emote,
                        channels[verb]["filter"] );
        return 1;
}

int filter_listener(object ppl, mapping ch, string menpaix)
{
	int menpai;
        // Don't bother those in the login limbo.
        if( !environment(ppl) ) return 0;
        if( ch["wiz_only"] ) return wizardp(ppl);
        if( ch["menpai_only"] ) return wizardp(ppl) || (if_mp(menpaix) == if_mp(ppl->query("family/family_name")));
        return 1;
}

void register_relay_channel(string channel)
{
        object ob;

        ob = previous_object();
        if( undefinedp(channels[channel]) || !ob) return;
        if( arrayp(channels[channel]["extra_listener"]) ) {
                if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
                channels[channel]["extra_listener"] += ({ ob });
        } else
                channels[channel]["extra_listener"] = ({ ob });
}

string remove_addresses(string msg, int all)
{
        int i;
        mixed tmp;
        string pattern;

        if(!stringp(msg)) return msg;

        if(all)
                pattern = "[(][A-Z][a-z ]+@[a-zA-Z]+[)]";
        else
                pattern = "[(][A-Z][a-z ]+@"+INTERMUD_MUD_NAME+"[)]";

        tmp = reg_assoc(msg, ({pattern}), ({1}));
                
        if(!arrayp(tmp)) return msg;

        msg = "";
        for(i=0; i< sizeof(tmp[0]); i++)
                if( tmp[1][i] == 0 ) msg += tmp[0][i];

        return msg;
}
