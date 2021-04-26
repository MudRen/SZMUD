//Modify by Karlopex@sz
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
	string strID, outmsg, strRes, strID2, msgvalue;

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
		outmsg = sprintf("%s(%s) 因为 %s 奖励给 %s(%s) %s 点贡献度", me->query("name"), getuid(me), strRes, ob->query("name"), getuid(ob), chinese_number(addvalue)); 
		log_file("awards/gxadd",sprintf("[%s]  %s(%s) 因为 %s 奖励给 %s(%s) %s 点贡献度。\n",
			ctime(time())[0..15], me->query("name"), getuid(me), strRes, ob->query("name"), getuid(ob), chinese_number(addvalue))); 
        	ob->add("shenzhou/pts", addvalue);
		tell_object(ob, HIG"你的贡献度增加了 "+chinese_number(addvalue)+" 点。\n");
	}else{
		outmsg = sprintf("%s(%s) 将 %s(%s) 的 %s 点贡献度转给 %s(%s) ", me->query("name"), getuid(me), ob->query("name"), getuid(ob), chinese_number(addvalue), ob2->query("name"), getuid(ob2));
		log_file("awards/gxadd",sprintf("[%s]  %s(%s) 将 %s(%s) 的 %s 点贡献度转给 %s(%s)。\n ",
			ctime(time())[0..15], me->query("name"), getuid(me), ob->query("name"), getuid(ob), chinese_number(addvalue), ob2->query("name"), getuid(ob2))); 
	        ob->add("shenzhou/pts", -addvalue);
	        ob2->add("shenzhou/pts", addvalue);
		tell_object(ob, HIG"你的 "+chinese_number(addvalue)+" 点贡献度已经转移给"+ob2->name()+" 。\n");
		tell_object(ob2, HIG+ob2->name()+"的 "+chinese_number(addvalue)+" 点贡献度已经转移给你 。\n");
	}
        shout( HIG "【系统】公告：" + outmsg + "\n" NOR );
        write( HIG "【系统】公告：" + outmsg + "\n" NOR );
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