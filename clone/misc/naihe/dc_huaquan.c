//                标准描述长度示例                                   |
// 娱乐游戏项目  划拳  ★dc_huaquan.c
// by naihe  2002-06-02  于茂名

/****************************************************************

        巫师注意：参与游戏时，请勿离开本房间以及送、抓任何
                  游戏内玩家离开！否则将有未知错误，或者未
                  知笑话出现！！！

        本游戏所有判断程式，并不考虑巫师扰乱的特殊情况，任何由
        巫师抓人、枪毙、smash等造成的错误或笑话，naihe概不负责  : )
*****************************************************************/


#include <ansi.h>
inherit ROOM;

string look_paizi();
void one_player();
void two_player();
void win_lose();
void money_jisuan();
void reset_games();


string pler_a,pler_b,tempnamea,tempnameb,tempida,tempidb,tempusea,tempuseb,games,winner,
tempusea="none",
tempuseb="none",
tempnamea="none",
tempnameb="none",
winner="none",
games="free";

int one_times,two_times,one_bet,two_bet,t_out,wait_time,temp,bet,same_times,
wait_time=10;


void create()
{
	set("short", HIC"娱乐游戏间·划拳游戏"NOR);
	set("long", "这是个小房间，空空的只见房间里头摆放着一部不知什么作用的机器，而机
器前边有着一张桌子，感觉那机器就像普通赌场的庄家一般，却不知道是赌什么。
机器旁边墙上挂着的小牌子（paizi） 上写着一些密密麻麻的小字，你好奇心大
作，忍不住想去看看它。\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up","1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "paizi": (: look_paizi :),
	]));

	set("exits", ([
	    "south": __DIR__"dc_kill",
	    ]));

	setup();
}

void init()
{
	if (wizardp(this_player()))  add_action("do_xxx", "xxx"); // wiz 可以查询总值。
	add_action("do_skills",  "exercise");
	add_action("do_skills",  "dazuo");
	add_action("do_skills",  "respirate");
	add_action("do_skills",  "tuna");
	add_action("do_skills",  "practice");
	add_action("do_skills",  "lian");
	add_action("do_study",  "study");
	add_action("do_study",  "du");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
	add_action("do_food", "he");
	add_action("do_huaquan","huaquan");
	add_action("do_ck","ck");
	add_action("do_chu","chu");
	add_action("do_quit","quit");
	if(wizardp(this_player())) add_action("cannot_goto","goto");
}

  void reset() 
  { 
                ::reset(); 
                set("no_clean_up", 1); 
  } 

string look_paizi()
{
	write("
"HIY"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"NOR"
                               "HIW"划拳游戏规则说明"NOR"

    输入 "HIY"huaquan <数值> <货币>"NOR" 开始游戏。本游戏只接受1-10 gold的押注。

"HIG"双人对决"NOR"：第一位玩家在启动了游戏之后，请等待"+wait_time+"秒以接受另一玩家的报名。
第二位玩家可以输入"HIY"<ck>"NOR"查询当前的挑战局以及金额。这时候，只要输入"HIY"<huaquan>"NOR"，
即表示接受此金额并开始对决。（要注意两者身上的黄金都不得少于自定数）

"HIG"单人游戏"NOR"：第一位游戏者在等待"+wait_time+"秒后仍无人应局，即会自动开始单人游戏模式。

    游戏开始后，输入 "HIY"chu <锤/剑/盾>"NOR" 来出你想出的招式。各招相互克制，"HIY"锤砸剑，
剑破盾，盾挡锤"NOR"，就看你的灵感啦。单人游戏时赔率为1赔1，双人游戏时，将在玩家
间互相自动转帐。

"HIR"注意："NOR"
游戏中，不得离开本房间；开始出招后若"+wait_time+"秒内仍不出招，将由系统自动抽取招式。
本游戏不抽红利，但若连续5局都出招相同时，将把当局押注额收取作手续费用。

                                                   "HIG"--by naihe  2002-06-02"NOR"
"NOR+HIY"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"NOR"\n");
	if(wizardp(this_player())) write("巫师可以用<xxx>指令查看现在的游戏统计。\n");
	message_vision(CYN"$N往墙上挂着的说明看去，一副恍然大悟的样子。\n"NOR,this_player());
	return "最后一局对决游戏，"HIW""+pler_a+""NOR"战胜了"HIW""+pler_b+""NOR"，金额为"HIW""+bet+""NOR"两黄金。\n";
}

int do_xxx()
{
	write("总单人游戏次数："HIW""+one_times+""NOR"，押注总额："HIW""+one_bet+""NOR"，奖金总额："HIW""+t_out+""NOR"。\n总双人游戏次数："HIW""+two_times+""NOR"，总交易额："HIW""+two_bet+""NOR"。\n最后一局由"HIW""+pler_a+""NOR"战胜了"HIW""+pler_b+""NOR"，金额为"HIW""+bet+""NOR"两黄金。\n");
	return 1;
}

int cannot_goto()
{
	if(this_player()->query_temp("duchang/huaquan"))
	{
		write("你还在玩游戏，想往哪去？你这不是存心害游戏要出BUG吗？\n");
		return 1;
	}

	return 0;
}

int do_quit()
{
	if(this_player()->query_temp("duchang/huaquan"))
	{
		write("你还在赌钱呢，这么跑掉可不好吧。\n");
		return 1;
	}

	return 0;
}

int do_food()
{
	tell_object(this_player(), "吃喝请到二楼茶座。\n");
	return 1;
}

int do_skills(string arg)
{
	tell_object(this_player(), "那么勤练功做什么，来玩一把再说吧。\n");
	return 1;
}

int do_study(string arg)
{
	tell_object(this_player(), "读书考状元，不如跟人玩划拳！\n");
	return 1;
}

int do_huaquan(string arg)
{
	object me,qian;
	int temp_herea;
	string temp_hereb;

	me=this_player();
	qian=present("gold_money",me);

	if(games!="free" && games!="wait")
		return notify_fail("别人正在游戏，等会儿吧。\n");

	if(tempnamea=="none")
	{
	        if (!arg || sscanf(arg, "%d %s", temp_herea, temp_hereb) != 2)
			return notify_fail("指令：huaquan <数量> <货币>\n");

		if(temp_hereb!="gold") return notify_fail("现在只能用黄金(gold)来进行游戏。\n");
		if(temp_herea<0 || temp_herea>10) return notify_fail("最少1，最多10。你想干嘛？\n");
		if(!qian || (int)qian->query_amount()<temp) return notify_fail("你并没有带着这么多钱罢！既然来赌博，赌品还是老实点好。\n");

		same_times=0;
		temp=temp_herea;
		tempnamea=me->query("name");
		tempida=me->query("id");
		me->set_temp("duchang/huaquan","yes");
		message_vision(HIW"$N掏出"+temp+"两黄金往桌上一扔，大声嚷道：“谁敢来跟我划个拳？”\n"NOR,me);
		qian->add_amount(-temp);
// 第一位玩家身上的钱已经减少了；未统计入历史记录。

		games="wait";
		write("请等待"+wait_time+"秒以便其他玩家加入。\n");
		call_out("one_player",wait_time);
		return 1;
	}

	if(me->query("id")==tempida) return notify_fail("你已经划下道儿来了，等一会儿吧。\n");
	if(!qian || (int)qian->query_amount()<temp) return notify_fail("你并没有带着这么多钱罢！既然来赌博，赌品还是老实点好。\n");

	tempnameb=me->query("name");
	tempidb=me->query("id");
	me->set_temp("duchang/huaquan","yes");
	message_vision(HIW"$N掏出了"+temp+"两黄金往桌上一扔，也大声嚷道：“"+tempnamea+"，让我来会会你！”\n\n"NOR,me);
	qian->add_amount(-temp);
// 第二位玩家身上的钱减少了。暂时不加入记录，到后面函数里一起再加。
	games="two_playing";
	message("vision",HIW"本局游戏由"+tempnamea+"对"+tempnameb+"，请在"+wait_time+"秒内出招吧！\n"NOR,this_object());
	message("vision",HIW"请在"+wait_time+"秒内输入：chu <锤/剑/盾> ！\n"NOR,this_object());
	call_out("two_player",wait_time);
	return 1;
}

int do_ck()
{
	if(games=="wait")
	{
		write("现在是"+tempnamea+"划下的道儿，赌"+temp+"两黄金。要迎战就输入<huaquan>吧！\n");
		return 1;
	}

	write("现在没有人在游戏。最后一局由"HIW""+pler_a+""NOR"战胜了"HIW""+pler_b+""NOR"，金额为"HIW""+bet+""NOR"两黄金。\n");
	return 1;
}

int do_chu(string arg)
{
	object me=this_player();

	if(games=="free" || games=="wait") return notify_fail("别急，游戏还没开始呢。\n");

	if(!arg || (arg!="锤" && arg!="剑" && arg!="盾"))
		return notify_fail("你要出什么？   chu <锤/剑/盾>  .\n");

	if(me->query("id")==tempida)
	{
		if(tempusea!="none") return notify_fail("你不是想好了吗，那么婆婆妈妈的。\n");

		message_vision(WHT"$N想好了要出什么招式了，心中一阵暗笑。\n",me);
		tempusea=arg;
		return 1;
	}

	if(me->query("id")==tempidb)
	{
		if(tempuseb!="none") return notify_fail("你不是想好了吗，那么婆婆妈妈的。\n");

		message_vision(WHT"$N想好了要出什么招式了，心中一阵暗笑。\n"NOR,me);
		tempuseb=arg;
		return 1;
	}

	message_vision(WHT"$N大声嚷着：“出"+arg+"，出"+arg+"！”，也不知道是在对谁说的。\n"NOR,me);
	return 1;
}

void one_player()
{
	if(games!="wait")
	{
		if(games!="one_playing") return;

		if(tempusea=="none")
		{
                // 这是玩家超时了，系统自动代其出招。
			message_vision(WHT"$N想来想去仍在犹豫不决，眼看时间要到了，才慌慌张张地决定了一招。\n"NOR,this_player());
			switch(random(3))
			{
			    case 0:tempusea="锤";
			    break;
			    case 1:tempusea="剑";
			    break;
			    case 2:tempusea="盾";
			    break;
			}
		}

// 这是系统自动出招。
		switch(random(3))
		{
		    case 0:tempuseb="锤";
		    break;
		    case 1:tempuseb="剑";
		    break;
		    case 2:tempuseb="盾";
		    break;
		}

		message_vision(HIY"机器里发出一个声音："+tempuseb+"！\n"NOR,this_player());
		message_vision(HIY"$N大声叫道：我出"+tempusea+"！\n"NOR,this_player());
		call_out("win_lose",1);
		return;
	}

	else
	{
		message("vision",HIW"只听见一个声音响起：“我来会会你吧。”——原来却是机器里面的声音。\n"NOR,this_object());
	games="one_playing";
	write("请在"+wait_time+"秒内输入：chu <锤/剑/盾> ！\n");
	call_out("one_player",wait_time);
	}
}

void two_player()
{
	object plera,plerb;

	if(games!="two_playing") return; // 这句似乎没必要，但加上也没关系啦。

// 奈何的判断程式似乎嫌罗嗦了，但我只能这样写，算是曲线救国吧。
	if(!this_player())
	{
		message("vision",HIW"\n不知道哪个赌品那么烂，赌到一半居然跑掉了，本局比赛强迫终止。\n\n押注金额由本机器收取作手续费用。\n"NOR,this_object());
		one_bet+=(temp*2); // one_bet 的具体含义是：系统收入，并不只代表“单人押注额”。
		reset_games();
		return;
	}

// 玩家a超时了，系统自动代其出招。

	plera=present(tempida,environment(this_player()));
	plerb=present(tempidb,environment(this_player()));

// 为了防止有未知的错误出现，当双人游戏时，他们若不同时存在此处（确切说，
// 应该是“他们若不同时存在同一房间”，即强迫终止游戏。
	if(!plera || !plerb)
	{
		message("vision",HIW"\n不知道哪个赌品那么烂，赌到一半居然跑掉了，本局比赛强迫终止。\n\n押注金额由本机器收取作手续费用。\n"NOR,this_object());
		one_bet+=(temp*2); // one_bet 的具体含义是：系统收入，并不只代表“单人押注额”。
		reset_games();
		return;
	}

	if(tempusea=="none")
	{
		message_vision(WHT"$N想来想去仍在犹豫不决，眼看时间要到了，才慌慌张张地决定了一招。\n"NOR,plera);
		switch(random(3))
		{
		    case 0:tempusea="锤";
		    break;
		    case 1:tempusea="剑";
		    break;
		    case 2:tempusea="盾";
		    break;
		}
	}

// 玩家b超时了，系统自动代其出招。
	if(tempuseb=="none")
	{
		message_vision(WHT"$N想来想去仍在犹豫不决，眼看时间要到了，才慌慌张张地决定了一招。\n"NOR,plerb);
		switch(random(3))
		{
		    case 0:tempuseb="锤";
		    break;
		    case 1:tempuseb="剑";
		    break;
		    case 2:tempuseb="盾";
		    break;
		}
	}
	message_vision(HIY"$N大声叫道：我出"+tempusea+"！\n"NOR,plera);
	message_vision(HIY"$N大声叫道：我出"+tempuseb+"！\n"NOR,plerb);
	call_out("win_lose",1);
	return;
}

void win_lose()
{
	object ob=this_object();
	string temp_miaoshu,winner_name;

	message("vision",HIW"出招了！！！\n"NOR,ob);

	if(games=="one_playing") tempidb="robot_naihe";

	if(tempusea==tempuseb)
	{
		same_times++;
		if(same_times>=5)
		{
			message("vision",HIW"第"+same_times+"局，两者的招式依然一样！本次游戏强迫结束，所有押注将由机器收取作手续费用，谢谢。\n"NOR,ob);
			if(games=="one_playing") one_bet+=temp;
			if(games=="two_playing") one_bet+=(temp*2);
			reset_games();
			return;
		}

		message("vision",HIW"两者出的招式都一样！请在5秒内决定，再比一次！！！\n"NOR,ob);
		tempusea="none";
		tempuseb="none";

		if(games=="one_playing")
		{
			call_out("one_player",5);
			return;
		}

		if(games=="two_playing")
		{
			call_out("two_player",5);
			return;
		}
	}

	if(tempusea=="锤" && tempuseb=="剑")
	{
		temp_miaoshu="锤砸剑";
		winner=tempida;
	}

	if(tempusea=="锤" && tempuseb=="盾")
	{
		temp_miaoshu="盾挡锤";
		winner=tempidb;
	}

	if(tempusea=="剑" && tempuseb=="锤")
	{
		temp_miaoshu="锤砸剑";
		winner=tempidb;
	}

	if(tempusea=="剑" && tempuseb=="盾")
	{
		temp_miaoshu="剑破盾";
		winner=tempida;
	}

	if(tempusea=="盾" && tempuseb=="剑")
	{
		temp_miaoshu="剑破盾";
		winner=tempidb;
	}

	if(tempusea=="盾" && tempuseb=="锤")
	{
		temp_miaoshu="盾挡锤";
		winner=tempida;
	}

// 以上执行了胜负判断。以下将调用另一函数进行付款判断。

	if(winner==tempida) winner_name=tempnamea;
	if(winner=="robot_naihe") winner_name="本机器获";
	else if(winner==tempidb) winner_name=tempnameb;

	message("vision",""HIW""+temp_miaoshu+"！本局比赛"+winner_name+"胜！赌金是"+temp+"两黄金。\n"NOR,ob);

	money_jisuan();
}

void money_jisuan()
{
	object plera,plerb,jiangjin,qiana,qianb;

	jiangjin=new("/clone/money/gold");

	if(!this_player())
	{
		message("vision",HIW"\n不知道哪个赌品那么烂，赌到一半居然跑掉了，本局比赛强迫终止。\n\n押注金额由本机器收取作手续费用。\n"NOR,this_object());
		one_bet+=(temp); // one_bet 的具体含义是：系统收入，并不只代表“单人押注额”。
		reset_games();
		return;
	}

	plera=present(tempida,environment(this_player()));
	plerb=present(tempidb,environment(this_player()));

	jiangjin->set_amount(temp*2);
	if(plera) qiana=present("gold_money",plera);
	if(plerb) qianb=present("gold_money",plerb);

// 单人游戏时作的判断。
	if(games=="one_playing")
	{
		one_times++;
		one_bet+=temp;  // 这句，先不管输赢，把单人游戏的压注记录累加。
// 玩家胜利。
		if(winner==tempida)
		{
		    t_out+=(temp*2); // 这句，统计单人游戏的奖金累加。



  // log 文件记录。
                  log_file("duchang/HUAQUAN_GAME", sprintf("%s(%s)于%s玩划拳游戏赢得奖金 %d 两黄金。\n",
                  this_player()->query("name"), getuid(this_player()), ctime(time()), temp));


// 付款，若没钱就直接move，有钱在身就加上得了。这个判断式是为了防止
// 未知错误的。

		    if(!plera)
		    {
			message("vision",""HIW""+tempnamea+"不知道跑哪去了，意思就是不要奖金了。\n奖金将用于支持“没希望工程”，由本机器代劳，谢谢。\n"NOR,this_object());
			one_bet+=temp;
			reset_games();
			return;
		    }

		    if(!qiana) jiangjin->move(plera);
		    else qiana->add_amount(temp*2);
		}
		reset_games();
		return;
	}

	if(games=="two_playing")
	{
		two_times++;
		two_bet+=temp;

		if(winner==tempida)
		{
		    if(!plera)
		    {
			message("vision",""HIW""+tempnamea+"不知道跑哪去了，意思就是不要奖金了。\n奖金将用于支持“没希望工程”，由本机器代劳，谢谢。\n"NOR,this_object());
			one_bet+=(temp*2);
			reset_games();
			return;
		    }
		    if(!qiana) jiangjin->move(plera);
		    else qiana->add_amount(temp*2);
		    pler_a=tempnamea;
		    pler_b=tempnameb;
		}

		else
		{
		    if(!plerb)
		    {
			message("vision",""HIW""+tempnameb+"不知道跑哪去了，意思就是不要奖金了。\n奖金将用于支持“没希望工程”，由本机器代劳，谢谢。\n"NOR,this_object());
			one_bet+=(temp*2);
			reset_games();
			return;
		    }
		    if(!qianb) jiangjin->move(plerb);
		    else qianb->add_amount(temp*2);
		    pler_a=tempnameb;
		    pler_b=tempnamea;
		}

		bet=temp;
		message("vision",""HIW""+pler_a+"「哈哈」大笑几声，把桌面上的黄金扫入袋中。\n"NOR,this_object());
		reset_games();
	}
}

void reset_games()
{
	object plera,plerb;

	plera=present(tempida,environment(this_player()));
	plerb=present(tempidb,environment(this_player()));

	if(plera) plera->delete_temp("duchang/huaquan");
	if(plerb) plerb->delete_temp("duchang/huaquan");
	games="free";
	tempnamea="none";
	tempnameb="none";
	tempida="1";
	tempidb="1";
	tempusea="none";
	tempuseb="none";
	winner="none";
	same_times=0;
	temp=0;
	message("vision",HIW"游戏结束了。\n"NOR,this_object());
	return;
}

int valid_leave(object me, string dir)
{
	if(this_player()->query_temp("duchang/huaquan"))
		return notify_fail("你还在赌钱呢，这么跑掉可不好吧。\n");
        return ::valid_leave(me, dir);
}

