// Code of ShenZhou
// channel block command..
// Modified by Marz, 04/18/96
// modifed by sdong to add xkx channel control, 12/25/98

inherit F_CLEAN_UP;
mapping pd=([
	"rumor":"谣言",
	"chat":"聊天",
	"menpai":"门派",
	"all":"所有公共聊天",
]);
int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	
	if (!arg)
		return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
		
	if (sscanf(arg, "%s %s", who, ch_name) != 2)
	{
		ch_name = "";
		if (sscanf(arg, "%s", who) != 1)
		{
		return	notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
		}		
	}

    if (who == "rumor")
    {
		CHANNEL_D->set_block(who, 0);
		CHANNEL_D->do_channel(me, "sys", "谣言频道ｏｋａｙ！\n");
        return 1;
    }

	 if (who == "chat")
	 {
		CHANNEL_D->set_block(who, 0);
		CHANNEL_D->do_channel(me, "sys", "聊天频道ｏｋａｙ！\n");
		  return 1;
	 }

	 if (who == "menpai")
	 {
		CHANNEL_D->set_block(who, 0);
		CHANNEL_D->do_channel(me, "sys", "门派频道ｏｋａｙ！\n");
		  return 1;
	 }

	ob = LOGIN_D->find_body(who);
	if (!ob) return notify_fail("这个人不在！\n");

	if (ch_name == ""||ch_name == " "||ch_name == "all")
	{
		if ((int)ob->query("chblk_on"))
			ob->delete("chblk_on");
		if ((int)ob->query("chblk_rumor"))
			ob->delete("chblk_rumor");
		if ((int)ob->query("chblk_chat"))
			ob->delete("chblk_chat");
		if ((int)ob->query("chblk_menpai"))
			ob->delete("chblk_menpai");
		if ((int)ob->query("chblk_jiaoyi"))
			ob->delete("chblk_jiaoyi");
		ob->clear_condition("chblk_c");
		tell_object(me, (string)ob->query("name")+"的频道被打开了。\n");
	} else if (ch_name == "rumor")
	{
		if ((int)ob->query("chblk_on"))
		{
			ob->delete("chblk_on");
			ob->set("chblk_chat", 1);
			ob->clear_condition("chblk_c");
			}
		if ((int)ob->query("chblk_rumor"))
		{
			ob->delete("chblk_rumor");
			ob->clear_condition("chblk_c");
			}
		tell_object(me, (string)ob->query("name")+"的谣言频道被打开了。\n");
	} else if (ch_name == "chat")
	{
		if ((int)ob->query("chblk_on"))
		{
			ob->delete("chblk_on");
			ob->set("chblk_rumor", 1);
			ob->clear_condition("chblk_c");
		}

		if ((int)ob->query("chblk_chat"))
		{
			ob->delete("chblk_chat");
			ob->clear_condition("chblk_c");
			}
		tell_object(me, (string)ob->query("name")+"的聊天频道被打开了。\n");
	} else if (ch_name == "menpai")
	{
		if ((int)ob->query("chblk_on"))
		{
			ob->delete("chblk_on");
			ob->set("chblk_menpai", 1);
			ob->clear_condition("chblk_c");
		}

		if ((int)ob->query("chblk_menpai"))
		{
			ob->delete("chblk_menpai");
			ob->clear_condition("chblk_c");
			}
		tell_object(me, (string)ob->query("name")+"的门派频道被打开了。\n");
	} else
	{
		return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
	}
        log_file("Chblk",sprintf("[%s] %s(%s) 的"+pd[ch_name]+"频道被 %s(%s) 打开了\n",ctime(time())[0..15],ob->query("name"),ob->query("id"),me->query("name"),me->query("id"))); 
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : unchblk <某人> <频道名>

此命令将打开某人的频道。如果没有频道名就打开所有合法频道。
<某人>　也可以是频道名。
<频道名> 可以是rumor 或 chat 

HELP
    );
    return 1;
}
