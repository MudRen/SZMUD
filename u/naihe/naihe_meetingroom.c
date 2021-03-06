//                标准描述长度示例                                   |
// 私人聊天室，请勿snoop聊天中人。
// by naihe  2002-07-04

#include <ansi.h>
inherit ROOM;

string welcome,host1,host2,now,
welcome="no",
host1="naihe",
host2="spark",
now="close";

void create()
{
	set("short", HIW"私人聊天室"NOR);
	set("long", HIR"\n这是奈何的私人聊天室，非请勿进！在这里你会完全脱离与外界的联系。\n\n"NOR"结束聊天输入 out ；补充体能输入 heal hp ；补充食物输入 heal food 。\n邀请客人用 welcome <id> ，踢出聊客用 kickout <id> ，\n设置房间状态用 sethere <open/close>.\n\n");
	set("invalid_startroom",1);

	set("exits", ([
//	    "out": __DIR__"naihe_room",
	    ]));

	setup();
}

void init()
{
//	::init();

	object me=this_player();
	if(me->query("id")=="naihe" || me->query("id")=="spark")
	{
		add_action("do_welcome","welcome");
		add_action("do_kickout","kickout");
		add_action("do_sethere","sethere");
	}

	add_action("do_out","out");
	add_action("do_heal","heal");	

	add_action("do_grope","grope");
	add_action("no_allchat","chat");
	add_action("no_allchat","chat*");
	add_action("no_allchat","rumor");
	add_action("no_allchat","rumor*");
	add_action("no_allchat","wiz");
	add_action("no_allchat","wiz*");
	add_action("no_allchat","gwiz");
	add_action("no_allchat","gwiz*");
	add_action("no_allchat","sz");
	add_action("no_allchat","sz*");
	add_action("no_allchat","jiaoyi");
	add_action("no_allchat","jiaoyi*");
	add_action("no_allchat","menpai");
	add_action("no_allchat","menpai*");
	add_action("no_allchat","tell");
	add_action("no_allchat","paimai");
	add_action("no_allchat","paimai*");
	add_action("no_allchat","to");
	add_action("no_allchat","tune");

	add_action("no_wiz","shout");
	add_action("no_wiz","goto");
	add_action("no_wiz","summon");
	if(this_player()->query("id")!="naihe")
        {
		add_action("no_wiz","update");
	add_action("no_wiz","more");
	add_action("no_wiz","cat");
                add_action("no_allchat","reply");
        }
	add_action("no_wiz","home");
	add_action("no_wiz","snoop");
	add_action("no_wiz","call");
	add_action("no_wiz","smash");
	add_action("no_wiz","destroy");
	add_action("no_wiz","clone");
	add_action("no_wiz","info");
	add_action("no_wiz","localcmds");
	add_action("no_wiz","tail");
	add_action("no_wiz","data");
	add_action("no_wiz","dest");
	add_action("no_wiz","possess");

/* 随时添加有遗漏的部分。
	add_action("no_wiz","
	add_action("no_wiz","
	add_action("no_wiz","
	add_action("no_wiz","
*/

	if(me->query("id")!=host1 && me->query("id")!=host2)
	{
		remove_call_out("greeting");
		call_out("greeting",0,this_object());
	}
	else
	{
		message("vision",HIW"房主到！("+me->query("id")+")\n"NOR,this_object());
		tell_object(me,"你来到这里，突然觉得一片寂静，外面的声音丝毫都听不见了。\n");
		me->delete("channels");
	}
}

void greeting()
{
	object me=this_player();

	if(now=="open" || me->query("id")==welcome)
	{
		message("vision",HIW"有客到！("+me->query("id")+")\n"NOR,this_object());
		tell_object(me,"你来到这里，突然觉得一片寂静，外面的声音丝毫都听不见了。\n");
		me->delete("channels");
		return;
	}

	message_vision("$N懵懵懂懂地撞进这里，却被系统请了出去。\n",me);
	me->move(__DIR__"naihe_room");
	tell_object(me,"你被赶了出来。\n");
	message("vision",(string)me->query("name")+"从私人聊天室里被赶了出来。\n",environment(me),me);
	return;
}

int no_wiz()
{
	write("既然来到这里，就别使用巫师手段了吧！\n");
	return 1;
}

int no_allchat()
{
	write("在这里你无法和外界作任何交谈。\n");
	return 1;
}

int do_heal(string arg)
{
	object me=this_player();

	if(arg=="hp")
	{
		me->set("jing",(int)me->query("max_jing"));
		me->set("qi",(int)me->query("max_qi"));
		me->set("jingli",(int)me->query("max_jingli"));
		me->set("neili",(int)me->query("max_neili"));
		write("ok,hp已经恢复。\n");
		return 1;
	}

	if(arg=="food")
	{
		me->set("food",500);
		me->set("water",500);
		write("ok,food已经恢复。\n");
		return 1;
	}
	write("你要恢复什么？ heal <hp/food>\n");
	return 1;
}

int do_welcome(string arg)
{
	object who,me;
	me=this_player();

	if(!arg) return notify_fail("要邀请谁哪？\n");

	if(present(arg,environment(me)))
	{
		write(arg+"已经在这里啦。\n");
		return 1;
	}

	who=find_player(arg);
	if(!who) return notify_fail("你要邀请的"+arg+"现在不在线呢。\n");

	if((string)who->query_temp("last_channel_msg")=="okokok")
	{
		welcome=who->query("id");
		who->move(this_object());
		message("vision",HIW"贵客到，欢迎欢迎！\n"NOR,this_object());
		return 1;
	}

	if((string)who->query_temp("last_channel_msg")=="nonono")
	{
		tell_object(me,"你想要邀请的"+arg+"拒绝了。\n");
		welcome="no";
		return 1;
	}

	tell_object(who,HIY"\n你好，"+me->query("name")+"想要邀请你到私人聊天室聊聊天。如果你同意，请复制以下字符输入并等待：\nrumor* okokok ，那么下一次再邀请你的时候，将可以直接移动你过去。\n如果你现在不想去，请复制以下字符输入：rumor* nonono ，作为一个礼貌性答复。\n或者你也可以在奈何的房间里(/u/naihe/naihe_room.c)直接输入： meeting 进入聊天室。\n\n"NOR);
	tell_object(me,"已经发出邀请了，稍后可再重复一次本指令把对方移动过来。\n");
	welcome=who->query("id");
	return 1;
}

int do_kickout(string arg)
{
	object who;

	if(!arg) return notify_fail("你要踢谁呀。。。\n");
	who=present(arg,environment(this_player()));
	if(!who) return notify_fail("这里没有这个人呀。。。\n");
	message("vision",this_player()->query("name")+"向"+who->query("name")+"下了逐客令。\n",this_object());
	who->move(__DIR__"naihe_room");
	message_vision("$N被"+this_player()->query("name")+"从聊天室里赶了出来。\n",who);
	return 1;
}

int do_sethere(string arg)
{
	if(!arg || (arg!="open" && arg!="close"))
		return notify_fail("用 sethere <open/close> 指令来设定为隐蔽或开放模式。\n");
	now=arg;
	message("vision",HIW"房间被"+this_player()->query("name")+"设定为"+now+"的形式。\n"NOR,this_object());
	return 1;
}

int do_out()
{
	object me=this_player();
	me->delete_temp("last_channel_msg");
	message_vision("$N离开了聊天室。\n",me);
	me->move(__DIR__"naihe_room");
	message_vision("$N从聊天室里走了出来。\n",me);
	if(me->query("id")==welcome) welcome="no";
	return 1;
}
