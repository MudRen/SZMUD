//                标准描述长度示例                                   |
// 单间，让玩家玩赌场的经典游戏！  ★adj.c
// by naihe  2002-04-23  于茂名
// naihe 于2002-05-17继续修改完善本文件
// 02-05-18继续修改，简直是吐血！！！ 版本3.0~~
// 02-05-20 从根本上更改了赔率方式，现在不会输钱，也不会赢玩家的钱啦。
// 赌场各游戏赔率均经过严格测试，修改本文件赔率等代码请慎重！
// 本文件从原dc_dating.c 改编而来。

#include <ansi.h>
inherit ROOM;

int t_playtimes,t_bets,t_betg,t_wins,t_wing,leiji,t_leiji,level,
level=1;
// 以上变量分别是：
// 总游戏次数，总白银押注额，总黄金押注额，总白银中奖数，总黄金中奖数，
// 当前累积奖金，历史累积奖金，当前游戏难度。

void create()
{
        set("short", HIG"一号小单间"NOR);
	set("long", "这是一个小单间，由于有几块豪华的厢板把它和大厅隔离了开来，你觉得挺
幽静的，可以舒舒服服地玩游戏了。这里只摆着一部机器（jiqi），与大厅的又
有所不同，它最大的特点就是可以累积奖金，你不禁跃跃欲试。\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up","1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "jiqi":"机器上写着两行说明：默认每次5两白银，输入(games)启动游戏。若要加注，输入:
games a--10两白银，games b--20两白银,games c--30两白银，games yeah--50两白银。
输入：cktop ，可以查询现在的累积大奖金额。\n",
	]));

	set("exits", ([
	    "out":__DIR__"dc_dating",
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
	add_action("do_games", "games");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
	add_action("do_food", "he");
	add_action("do_cktop","cktop");
}

  void reset() 
  { 
                ::reset(); 
                set("no_clean_up", 1); 
  } 

int do_cktop(object me)
{
	write("现在的累积大奖金额为： "+leiji+" 两白银。\n");
	write("你的押注额将决定你能够得到多少份额的累积奖金：
<games> 10% ；<games a> 20% ；<games b> 40% ；<games c> 60% ；<games yeah> 100%.\n");
	return 1;
}

int do_xxx(string arg)
{
	if(!arg)
	{
		int temps,tempg;
		temps = (t_bets-t_wins);
		tempg = (t_betg-t_wing);
     		write(""HIY"游戏次数："+t_playtimes+ "次  收入："+tempg+" 金 "+temps+" 银 。现在的难度为 "+level+".\n总押注："+t_betg+" 金 "+t_bets+" 银  总奖金："+t_wing+" 金 "+t_wins+" 银。\n历史累积大奖总额为： "+t_leiji+" 银  当前累积大奖： "+leiji+ " 银。"NOR"\n");
	}

	if(arg=="easy") level=1;
	if(arg=="hard") level=21;
	if(arg=="pro") level=51;

	if(arg && arg!="easy" && arg!="hard" && arg!="pro") write("指令格式：<xxx easy/hard/pro>\n");

	return 1;
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
	tell_object(this_player(), "读书考状元，不如赌钱赚银圆！\n");
	return 1;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$  开始游戏啦  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

int do_games(string arg)
{
	object s_qian,g_qian,s_jj,g_jj,me;
// 以上变量为：玩家身上的白银，玩家身上的黄金，系统调用的白银，系统调用的黄金，以及me.

	int games,plerbet,jjout,leiji_jjout,peilv,tempa,tempb,win_lose,nowrandom,tempp,tempq;
// 以上变量为：决定中奖的随机数，玩家押注数额，中的奖金额，
// 中的累积奖金额，中奖赔率，和临时变量两个，当前输赢额，
// 以及让巫师查看状态的数值，以及两个计算赔率时需要的临时变量。

	string winner="not";
// 此变量判断玩家是否中奖。

	me = this_player();

	s_qian = present("silver_money", me);
	g_qian=present("gold_money",me);

	s_jj= new("/clone/money/silver");
	g_jj= new("/clone/money/gold");

	if (time()-query_temp("playtime")<2)
	return notify_fail("这一轮刚完，还没复原呢。\n");

// 如果没银子也没黄金，不许游戏。
	if(!s_qian && !g_qian)
	return notify_fail("你摇出了1000倍的大奖！……可惜你没钱押。\n");

// 下面即将开始游戏。游戏方式改为：开始游戏后，若不中奖才会扣玩家的押注
// 额的钱；若中奖，则不用扣，直接给钱（当然，赔率已经相应减少）。

// 如果是直接输入“games”，进行这里面的判断。
	if(!arg)
	{
		plerbet=5;

// 如果玩家身上没有银子（一定要加这句，不然会有错误）或银子少过押注额，则进行黄金判断；
// 如果也没有黄金，不许游戏。如果有，可以开始游戏；但暂时不扣钱。
		if(!s_qian || (int)s_qian->query_amount() < plerbet)
		{
			if(!g_qian) return notify_fail("你摇出了1000倍的大奖！……可惜你不够钱，没押上。\n");
		}
	}

// 如果不是直接输入“games”，而是还有其他信息的话，进行这里面的判断。
	else
	{

// 如果不符合预设的几种信息之一，输出提示句，并不许游戏。
		if(arg!="a" && arg!="b" && arg!="c" && arg!="yeah")
			return notify_fail("格式：games <类型>\n");
		if(arg == "a") plerbet=10;
		if(arg == "b") plerbet=20;
		if(arg == "c") plerbet=30;
		if(arg == "yeah") plerbet=50;

// 同上面的判断程序，如果身上银子少过押注的金额，进行黄金判断。
		if(!s_qian || (int)s_qian->query_amount() < plerbet)
		{
			if(!g_qian) return notify_fail("你摇出了1000倍的大奖！……可惜你不够钱，没押上。\n");
		}
	}


// 总游戏次数累加一次；累积大奖累加押注额的1/5，历史累积大奖累加统计。
	t_playtimes++;
        leiji+=(plerbet/10);
        t_leiji+=(plerbet/10);

	message_vision("\n"HIG"$N掏出钱往机器里一塞，满怀希望地拉动了摇杆。"NOR"\n",me);

// 进行一些方便观看游戏总押注、总输出金额的计算，把银子数额换成黄金数额。
	if(t_bets>99)
	{
		tempp=(t_bets/100);
		tempq=(t_bets-tempp*100);
		t_bets=tempq;
		t_betg+=tempp;
	}

	if(t_wins>99)
	{
		tempp=(t_wins/100);
		tempq=(t_wins-tempp*100);
		t_wins=tempq;
		t_wing+=tempp;
	}

        win_lose=((t_wing-t_betg)*3);

// 最关键的地方！！！这里的数值，决定了赔率的大小！！！

	if(!me->query_temp("lucky/duchang"))
		nowrandom=(200+level+win_lose+plerbet+random(plerbet/2));
	else
nowrandom=(200-(int)me->query_temp("lucky/duchang")+level+plerbet+win_lose+random(plerbet/2));

	games=(random(nowrandom));
	if(wizardp(me)) write("现在的随机数上限制是： "+nowrandom+"，开的值是： "+games+" .\n");

// 各类摇奖判断。

// 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓  开始进行中奖判断  〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓

	if(games > 70 && games < 100)
	{
		tell_object(me,"你摇出了："HIM"㊣"NOR"\n"),
		peilv = 2;
		winner="yes";
		tell_room(environment(me),(string)me->query("name") + "中了个最小的奖！\n",me);
	}

	if(games < 10)
	{
		tell_object(me,"你摇出了："HIM"☆"NOR"\n"),
		peilv = 4;
		winner="yes";
		tell_room(environment(me),(string)me->query("name") + "中了个第二小的奖！\n",me);
	}

	if(games == 16 || games == 17 || games == 18 || games == 19)
	{
		tell_object(me,"你摇出了："HIM"△"NOR"\n"),
		peilv = 9;
		winner="yes";
		tell_room(environment(me),(string)me->query("name") + "中了个三等奖！\n",me);	
	}

	if(games == 21 || games == 22 || games == 23)
	{
		tell_object(me,"你摇出了："HIM"＄"NOR"\n"),
		peilv = 14;
		winner="yes";
		tell_room(environment(me),(string)me->query("name") + "中了二等奖！！！\n",me);	
	}

	if(games == 24 || games == 25)
	{
		tell_object(me,"你摇出了："HIM"○"NOR"\n"),
		peilv = 19;
		winner="yes";
		tell_room(environment(me),(string)me->query("name") + "中了大奖！！！\n",me);	
	}

	if(games == 28 && random(100) == 25)
	{
		tell_object(me,"你摇出了："HIR"★"NOR"\n"),
		peilv = 99;
		winner="yes";
		tell_room(environment(me),"哇！！！" + (string)me->query("name") + "中了最高的奖项！！！\n",me);
		CHANNEL_D->do_channel(me, "rumor", sprintf(""HIY"%s中了100倍的游戏大奖！"NOR"", me->query("name")));
		CHANNEL_D->do_channel(me, "rumor*", "yeah");
	}

// 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓  中奖判断到此完毕  〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓

// 无论中了与否，报告现在的累积大奖。如果是巫师，也报告历史累积大奖。

	if(wizardp(me)) write("当前累积奖： "+leiji+"白银；历史累积奖： "+t_leiji+"白银。\n");
	else write("现在的累积大奖为： "+leiji+" 两白银！\n");

// 如果玩家中奖了，先进行是否中累积大奖的判断！！！！！！

	if(winner=="yes")
	{
		if(peilv==99) tell_object(me,""HIG"中了大奖！！！！！！100倍！你太幸运了！"NOR"\n");
		else tell_object(me,""HIG"中奖了！"+(peilv+1)+"倍，"+(plerbet*(peilv+1))+"两银子！！！"NOR"\n");

// 开始判断是否中累积大奖！！！累积大奖的难度与押注额有点联系——即理论上来说，
// 押注额越大，中奖几率越小点。
		if(random(100+plerbet) == 88)
//		if(random(5)== 3)  // 本句是测试用的。
		{
			if(plerbet==5) leiji_jjout=(leiji/10);
			if(plerbet==10) leiji_jjout=(leiji/5);
			if(plerbet==20) leiji_jjout=(leiji*2/5);
			if(plerbet==30) leiji_jjout=(leiji*3/5);
			if(plerbet==50) leiji_jjout=(leiji);

// 这里要减掉“当前累积奖金”的值。
			leiji-=leiji_jjout;

			tell_object(me,""HIR"你中了累积大奖！！！奖金为 "+leiji_jjout+" 两白银！！！"NOR"\n");

// 中了累积大奖时，谣言频道会报道。加颜色是为了确定是系统所说；加多一句“yeah”，是
// 为了防止若连续两次会被系统以“相同的话不要说”而过滤掉的情况。

			CHANNEL_D->do_channel(me, "rumor", sprintf(HIG"%s中了"+leiji_jjout+"两银子的累积游戏奖金！"NOR, me->query("name")));
			CHANNEL_D->do_channel(me, "rumor*", "yeah");
  // log 文件记录。
                  log_file("duchang/DJ_GAME", sprintf("%s(%s)于%s玩一号单间游戏获得累积大奖 %d 两白银。\n",
                  me->query("name"), getuid(me), ctime(time()), leiji_jjout));
		}

// 以上判断，若中了累积奖，那么将会有个当前中奖值“leiji_jjout”。若没中，此值默认为0。


// 这里计算，总共中出的奖金(jjout)是：玩家押注额(plerbet)乘以赔率(peilv)再加上中
// 的累积奖金额(leiji_jjout)。若上面一段的累积奖金没中，这个leiji_jjout的值将为0。

		jjout=(plerbet*peilv+leiji_jjout);

// 如果款额大于99两银子，则支付对应数量的黄金；
// 为了避免系统出错，当恰好是整百数量的银子时，支付相应的黄金之外，还会
// 给多一两银子。
		if(jjout>99)
		{
			tempa=(jjout/100);
			tempb=(jjout-tempa*100);
			if(tempa>99)
			{
				if( (me->query("balance") + tempa*10000) >=10000000)
				{
					write("你的存款帐号已满，现在把现金支付给你。\n");
					g_jj->set_amount(tempa);
					g_jj->move(me);
				}

                                  else
                                  {
                                          me->add("balance",tempa*10000);
                                     write("你中了累积大奖，将直接转进你的钱庄帐号里。\n");
                                  }
			}
			else
			{
				g_jj->set_amount(tempa);
				g_jj->move(me);
			}
			if(tempb==0) tempb=1;
			s_jj->set_amount(tempb);
		}

		else s_jj->set_amount(jjout);

// 总输出金额统计（单位为银子）。
		t_wins+=jjout;

// 设置忙时，返回，函数结束。
		s_jj->move(me);
		set_temp("playtime",time());
		return 1;
	}

// 至此中奖判断结束，以下是随机的不中奖的描述。

	switch(random(15))
	{
		case 0 :
	tell_object(me,""HIG"你摇出了：◎ ，没有中奖。"NOR"\n");
		break;

		case 1 :
	tell_object(me,""HIG"你摇出了：□ ，没有中奖。"NOR"\n");
		break;

		case 2 :
	tell_object(me,""HIG"你摇出了：◇ ，没有中奖。"NOR"\n");
		break;

		case 3 :
	tell_object(me,""HIG"你摇出了：● ，没有中奖。"NOR"\n");
		break;

		case 4 :
	tell_object(me,""HIG"你摇出了：▲ ，没有中奖。"NOR"\n");
		break;

		case 5 :
	tell_object(me,""HIG"你摇出了：■ ，没有中奖。"NOR"\n");
		break;

		case 6 :
	tell_object(me,""HIG"你摇出了：※ ，没有中奖。"NOR"\n");
		break;

		case 7 :
	tell_object(me,""HIG"你摇出了：◆ ，没有中奖。"NOR"\n");
		break;

		case 8 :
	tell_object(me,""HIG"你摇出了：∷ ，没有中奖。"NOR"\n");
		break;

		case 9 :
	tell_object(me,""HIG"你摇出了：⊙ ，没有中奖。"NOR"\n");
		break;

		case 10 :
	tell_object(me,""HIG"你摇出了：¤ ，没有中奖。"NOR"\n");
		break;

		case 11 :
	tell_object(me,""HIG"你摇出了：Ж ，没有中奖。"NOR"\n");
		break;

		case 12 :
	tell_object(me,""HIG"你摇出了：Θ ，没有中奖。"NOR"\n");
		break;

		case 13 :
	tell_object(me,""HIG"你摇出了：Ω ，没有中奖。"NOR"\n");
		break;

		case 14 :
	tell_object(me,""HIG"你摇出了：Ф ，没有中奖。"NOR"\n");
		break;
	}

// 游戏没中奖！开始减掉玩家的钱。

// 如果没银子或银子不够，减少1两黄金，并给回相应银子。
	if(!s_qian || (int)s_qian->query_amount() < plerbet)
	{
		g_qian->add_amount(-1);
		if(!s_qian)
		{
			s_jj->set_amount(100-plerbet);
			s_jj->move(me);
		}
		else s_qian->add_amount(100-plerbet);
	}

// 否则直接扣。
	else s_qian->add_amount(-plerbet);

// 总押注统计。
	t_bets+=plerbet;

	set_temp("playtime",time());
	return 1;
}

