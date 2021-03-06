// trigger.c 
#include <ansi.h> 
inherit F_CLEAN_UP; 
 
int main(object me, string arg) 
{ 
        int i; 
        mapping trigger; 
        string verb, replace, *vrbs,cname; 
 
        if( !arg ) { 
                trigger = me->query_all_trigger(); 
                if( !sizeof(trigger) ) { 
                        write("你目前并没有设定任何 trigger。\n"); 
                        me->disable_trigger(); 
                } else  { 
                        i = me->query_trigger_enabled(); 
                        me->disable_trigger(); 
                        write("你目前设定的 trigger 有：\n"); 
                        vrbs = keys(trigger); 
                        for(i=0; i < sizeof(vrbs); i++) 
                                printf("%-40s 将触发如下命令:  %s\n", vrbs[i]+NOR, trigger[vrbs[i]]); 
                        write("\n你的触发器目前是"+(i?"打开的":"关闭的")+"。\n"); 
                        if( i ) me->enable_trigger(); 
                } 
                return 1; 
        } 
 
        if( arg=="on" ) 
        { 
                me->enable_trigger(); 
                write("打开trigger触发。\n"); 
                return 1; 
        } 
        if( arg=="off" ) 
        { 
                me->disable_trigger(); 
                write("关闭trigger触发。\n"); 
                return 1; 
        }                        
                cname = arg; 
                cname = replace_string(cname, "$BLK$", BLK); 
                cname = replace_string(cname, "$RED$", RED); 
                cname = replace_string(cname, "$GRN$", GRN); 
                cname = replace_string(cname, "$YEL$", YEL); 
                cname = replace_string(cname, "$BLU$", BLU); 
                cname = replace_string(cname, "$MAG$", MAG); 
                cname = replace_string(cname, "$CYN$", CYN); 
                cname = replace_string(cname, "$WHT$", WHT); 
                cname = replace_string(cname, "$HIR$", HIR); 
                cname = replace_string(cname, "$HIG$", HIG); 
                cname = replace_string(cname, "$HIY$", HIY); 
                cname = replace_string(cname, "$HIB$", HIB); 
                cname = replace_string(cname, "$HIM$", HIM); 
                cname = replace_string(cname, "$HIC$", HIC); 
                cname = replace_string(cname, "$HIW$", HIW); 
                cname = replace_string(cname, "$NOR$", NOR);          
                arg = cname; 
 
        if( sscanf(arg, "%s %s", verb, replace)!=2 ) 
                me->set_trigger(arg, 0); 
        else if( verb=="trigger" ) 
                return notify_fail("你不能将 \"trigger\" 指令设定为 pattern 。\n"); 
        else if( verb=="" )              
                return notify_fail("你要设什麽 trigger？\n"); 
        else 
        { 
                return me->set_trigger(verb, replace); 
        } 
 
        write("Ok.\n"); 
        return 1; 
} 
 
int help (object me) 
{ 
        write(@HELP 
指令格式 : trigger <触发消息> <触发后预定执行的命令>

trigger 潇洒人生快步走了过来。 kill ysyysy 
出现“潇洒人生快步走了过来。”的时候，系统自动执行 "kill ysyysy" 。
 'trigger' 后不加参数则列出你所有的 Trigger。
 "trigger 潇洒人生快步走了过来。" 会消除这个 Trigger。 
 'trigger on' 会打开所有 Trigger 的触发。
 'trigger off' 会关闭所有 Trigger 的触发。
 'trigger xxxx $gag' 会不显示所有包含xxxx的信息。
 比如 'trigger 龙龙子 $gag',这样你就看不到有关龙龙子的一切的信息了。

另外，玩家还可以设定 set disconnect quit 或者 set disconnect out，
这是系统判断玩家断线后，玩家自动执行的最后一个命令。为了避免聊天
频道中被触发，因此请用 " set " 来设定。

HELP 
); 
        return 1; 
} 
