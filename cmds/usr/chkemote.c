// function:    display emote
// update by:   ken@mud.szptt.net.cn
// update time: 1998-03-13

#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
inherit EMOTE_D;

int main(object me, string arg)
{
        mapping point;
        string *emotes, msg, str;
        int i;
        if( !arg || lower_case(arg) == "all") {
                emotes = sort_array(query_all_emote(), 1);
                if( !emotes ) {
                        msg = MUD_NAME+"当前没有任何 emote。\n";
                        return notify_fail(msg);
                }
        }
        else {
                point = EMOTE_D->query_emote(arg);
                if( !point["updated"] ) {
                        msg = sprintf("%s当前没有 %s 这个 emote。\n",MUD_NAME,arg);
                        return notify_fail(msg);
                }
        }
	msg = "\n";
        if( ! arg || lower_case(arg) == "all") 
                        return notify_fail("请指定emote的命令！\n");		
                str = point["target"];
                str = replace_string(str, "$n", "你");
                str = replace_string(str, "$p", "你");
                str = replace_string(str, "$R", "(你的尊称)");
                str = replace_string(str, "$r", "(你的辱称)");
                msg += sprintf(WHT"\nemote 名称："CYN"%s\n"WHT
                	"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"CYN
                        "自己看见：\n无使用对像：      %s使用对像是自己：  %s使用对像是他人：  %s\n\n"
                        CYN"对方看见：\n%s\n"
                        CYN"其他人看见：\n无使用对像：      %s使用对像是自己：  %s使用对像是他人：  %s\n"
                        WHT"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR,
                        arg,
                        point["myself"], point["myself_self"],point["myself_target"],
                        str,
                        point["others_self"],
                        point["others"],
                        point["others_target"] );
                        msg = replace_string(msg, "$n", "(对方)");
                        msg = replace_string(msg, "$N", me->name(1));
                        msg = replace_string(msg, "$P", "你");
                        msg = replace_string(msg, "$p", "(他/她)");
                        msg = replace_string(msg, "$S", RANK_D->query_self(me));
                        msg = replace_string(msg, "$s", RANK_D->query_self_rude(me));
                        msg = replace_string(msg, "$R", "(对方的尊称)");
                        msg = replace_string(msg, "$r", "(对方的辱称)");
                        msg = replace_string(msg, "$C", "(自己的呢称)");
                        msg = replace_string(msg, "$c", "(对方的呢称)");
        me->start_more(msg);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : chkemote [表情动作名]。

这个指令可以列出目前所能使用的 emote 或者单独列出
某个 emote 的内容。

HELP
);
return 1;
}



