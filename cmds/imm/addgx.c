//Modify by Karlopex@sz
// Modify by felix
#include <ansi.h>
int help(object me);
void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        int addvalue;
        object ob, ob2;
        string strID, outmsg, outmsg2, strRes, strID2, msgvalue;

        if( !arg || arg == "") return help(me);

        if( sscanf(arg, "%s to %s %s", strID, strID2, msgvalue) !=3
            && sscanf(arg, "%s %s %s", strID, msgvalue, strRes) !=3 )
                return help(me);
        addvalue = atoi(msgvalue);
        ob = find_player(strID);

        if ( !objectp( ob ) ) return notify_fail( "No such guy online.\n" );

        if ( stringp(strID2) ){
                ob2 = find_player(strID2);
                if (!objectp( ob2 )) return notify_fail( "No such guy online.\n" );
                if ( ob->query("shenzhou/pts") < addvalue )
                        return notify_fail( ob->query("id")+"'s Gxd no enough.\n" );
                if ( addvalue%100 != 0 )
                        return notify_fail( "贡献度转移只能以百为单位。\n" );
                }

        if ( !this_player()->visible( ob ) && strID == "mariner" )
                return notify_fail( "No such guy online.\n" );

        if (!objectp( ob2 )){
                outmsg = sprintf("%s(%s)因为%s奖励给%s(%s)%s点贡献度", me->query("name"), getuid(me), strRes, ob->query("name"), getuid(ob), chinese_number(addvalue)); 
                outmsg2 = sprintf("一阵惬意舒爽的微风拂过%s(%s)的面颊。", ob->query("name"), getuid(ob)); 
                log_file("awards/gxadd",sprintf("[%s]  %s(%s) 因为 %s 奖励给 %s(%s) %s 点贡献度。\n",
                        ctime(time())[0..15], me->query("name"), getuid(me), strRes, ob->query("name"), getuid(ob), chinese_number(addvalue))); 
                ob->add("shenzhou/pts", addvalue);
                tell_object(ob, MAG"\n\n\n一阵清风拂面，你感到你为神州多做了 "+chinese_number(addvalue)+"点 贡献。\n\n");
                tell_object(ob, HIW"为了我们大家的"HIR"【 神州 】"HIW"持续发展，继续加油吧。(详情请查阅 help gongxian)\n\n"NOR);
        }else{
                outmsg = sprintf("%s(%s) 将 %s(%s) 的 %s 点贡献度转给 %s(%s) ", me->query("name"), getuid(me), ob->query("name"), getuid(ob), chinese_number(addvalue), ob2->query("name"), getuid(ob2));
                outmsg2 = sprintf("一阵惬意舒爽的微风拂过%s(%s)和%s(%s)的面颊。", ob->query("name"), getuid(ob), ob2->query("name"), getuid(ob2)); 
                log_file("awards/gxadd",sprintf("[%s]  %s(%s) 将 %s(%s) 的 %s 点贡献度转给 %s(%s)。\n ",
                        ctime(time())[0..15], me->query("name"), getuid(me), ob->query("name"), getuid(ob), chinese_number(addvalue), ob2->query("name"), getuid(ob2))); 
                ob->add("shenzhou/pts", -addvalue);
                ob2->add("shenzhou/pts", addvalue);
                tell_object(ob, HIG"你的 "+chinese_number(addvalue)+" 点贡献度已经转移给"+ob2->name()+" 。\n");
                tell_object(ob2, HIG+ob->name()+"的 "+chinese_number(addvalue)+" 点贡献度已经转移给你 。\n");
        }
         ob = find_player(strID);
        shout( HIY "【系统】"HIW"公告："MAG"" + outmsg2 + "\n" NOR );
        write( HIY "【系统】"HIW"公告："MAG"" + outmsg2 + "\n" NOR );
          CHANNEL_D->do_channel(me, "alarm", sprintf(outmsg));
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : addgx <对象名称> <贡献度数量> <原因>
           addgx <对象名称1> to <对象名称2> <贡献度数量>

see also : checkgx
HELP
    );
    return 1;
}
