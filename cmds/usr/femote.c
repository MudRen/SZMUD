/* grep.c
 * 98-10-26
 * modify name to femote.c
 * make code less
 * by ken@XAJH
 */

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
int help(object me);
int check(string msg, string arg);
int main(object me, string arg)
{
        mapping emote;
        string *e, *loop;
        string result="", msg2, msg;
        int i,count=0;

        loop = ({ "others_target", "others_self", "others" });
        if( !arg )
                return help(me);

	if(me->query_temp("femote_time") + 120 > time() && !wizardp(me))
                return notify_fail("让系统歇会儿。。。\n");	

        if( strlen(arg) < 4 || sizeof(explode( arg, "\*" )) > strlen(arg) / 4)
                return notify_fail("你指定的关键字多一些才好找，请重新定义关键字。\n");	

        e = sort_array( EMOTE_D->query_all_emote(), 1);
        for(i=0; i<sizeof(e); i++) {
                emote = EMOTE_D->query_emote(e[i]);
                for( int j=0; j<sizeof(loop); j++ ) {
                        msg = emote[ loop[j] ];
                        if( msg && check(msg,arg)) {
                                result += sprintf(CYN + "emote 名: %s\n" + CYN + "动作: %s\n" + NOR, e[i], msg);
                                count ++;
                        }
                }
        }
        if(  result == "" )
                return notify_fail(MUD_NAME" 中无符合查询条件的 emote.\n");
        else
		if (strlen(arg) > 20)
                        msg2 = arg[0..24-(sizeof(explode( arg[0..23], "\*" ))%2)] + "...";
              if (!msg2) msg2 = arg;
              msg2 = replace_string(msg2, "*", " "); 
                result = WHT"\n查询结果"NOR
                                "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
                                +result;
        result = replace_string(result, "$n", "(对方)");
        result = replace_string(result, "$N", me->name(1));
        result = replace_string(result, "$P", "你");
        result = replace_string(result, "$p", "(他/她)");
        result = replace_string(result, "$S", RANK_D->query_self(me));
        result = replace_string(result, "$s", RANK_D->query_self_rude(me));
        result = replace_string(result, "$R", "(对方的尊称)");
        result = replace_string(result, "$r", "(对方的辱称)");
        result = replace_string(result, "$C", "(自己的呢称)");
        result = replace_string(result, "$c", "(对方的呢称)");
        result += NOR"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
        result += sprintf("在%s中，包含“%s”的 emote 共有 %s 个。\n如果想知道使用后的效果请使用"HIG"chkemote <emote名>"NOR"命令查询。",
                                        MUD_NAME, msg2, chinese_number(count) );
        me->start_more(result);
	me->add("jingli",-10);
	me->set_temp("femote_time",time());
        return 1;
}

int check(string msg, string arg)
{
	int j = 0, x = 0;
        msg = replace_string(msg, "$n", "");
        msg = replace_string(msg, "$N", "");
        msg = replace_string(msg, "$P", "");
        msg = replace_string(msg, "$p", "");
        msg = replace_string(msg, "$S", "");
        msg = replace_string(msg, "$s", "");
        msg = replace_string(msg, "$R", "");
        msg = replace_string(msg, "$r", "");
        msg = replace_string(msg, "$C", "");
        msg = replace_string(msg, "$c", "");
	if (!sizeof(explode( arg, "\*" ))
	 && strsrch(msg, arg) >= 0 )
	 	return 1;
	for(int i=0;i<sizeof(explode( arg, "\*" ));i++)
	{
		if(stringp(explode(arg,"\*")[i])
		 && strsrch(msg, explode(arg,"\*")[i]) >=0 )
			j++;
		if(explode(arg,"\*")[i] == "") x++;
		}
	if (j + x == sizeof(explode( arg, "\*" )) ) return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : femote 关键字
功能：列出目前所有含指定关键字的 emote.

注：关键字中可以加入*做为代替姓名，称谓等不定的文字。
例：femote *手舞木棒，对准*的后脑一记闷棍，*哼也没哼一声，软软的摔倒在地。
就会查找到 club 这个emote。

HELP
    );
    return 1;
}

