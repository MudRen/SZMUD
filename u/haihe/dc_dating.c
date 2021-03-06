//                标准描述长度示例                                   |
// 奈何的赌场大厅  ★dc_dating.c
// by naihe  2002-04-23  于茂名
// naihe 于2002-05-17继续修改完善本文件
// 赌场各游戏赔率均经过严格测试，修改本文件赔率等代码请慎重！

#include <ansi.h>
#include <room.h>
inherit ROOM;

int totalplay,totalbet,totalwin,t_betgold,t_wingold,topjj,toptopjj;

void create()
{
	set("short", HIY"赌场大厅"NOR);
	set("long", "这里是赌场的大厅，门口有一个可爱的小机器人在不断地和进来的客人打招
呼。大厅中央摆放着排成一圈的许多部新奇的机器（jiqi），只听见人们“咦”、
“啊”地不断发出惊奇的声音。大厅左侧的空处有一部 ATM柜员机，听说是最新
的机器，使用它时就像在钱庄里一样方便。大厅四周有几条小通道，东边的通往
赛马房，西边是机器人演示厅，大厅左侧的小门里面是贵宾房，东南位置的是偏
厅，而西南边则是洗手间。楼上是一间西洋风格的茶座，客人们玩累了都爱上去
吃点东西，休息一会。只见大厅正对门的墙壁上醒目的挂着一个小牌子（paizi）。\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up","1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "paizi":"“文明娱乐，输赢皆欣”\n",
	    "jiqi":"机器上写着两行说明：默认每次5两白银，输入(games)启动游戏。若要加注，输入:
games a--10两白银，games b--20两白银,games c--30两白银，games yeah--50两白银。
输入：cktop ，可以查询现在的累积大奖金额。\n",
	]));

	set("objects", ([
	    __DIR__"npc/atm" : 1,
	    __DIR__"obj/yizi" : 1,
	    ]));

	set("exits", ([
	    "east": __DIR__"dc_horse",
	    "west":__DIR__"dc_robot",
	    "southeast":__DIR__"dc_bigsm",
	    "southwest":__DIR__"dc_lav",
	    "vip":__DIR__"dc_vip",
	    "up":__DIR__"dc_chazuo",
//	    "out":__DIR__"dc_door",
	    ]));

	create_door("vip", "小门", "out", DOOR_CLOSED);

// 下面这个board需要在clone那边的目录下相应添加才行。
	setup();
	call_other("/clone/board/duchang_b","???");
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
	add_action("do_out", "out");
	add_action("do_note", "note");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
	add_action("do_cktop","cktop");
}

int do_cktop(object me)
{
	write("现在的累积大奖金额为： "+topjj+" 两白银。\n");
	write("你的押注额将决定你能够得到多少份额的累积奖金：
<games> 10% ；<games a> 20% ；<games b> 40% ；<games c> 60% ；<games yeah> 100%.\n");
	return 1;
}

int do_xxx()
{
	int temps,tempg;
	temps = (totalbet-totalwin);
	tempg = (t_betgold-t_wingold);
     	write(""HIY"游戏次数："+totalplay+ "次  收入："+tempg+" 金 "+temps+" 银 。\n总押注："+t_betgold+" 金 "+totalbet+" 银  总奖金："+t_wingold+" 金 "+totalwin+" 银。\n历史累积大奖总额为： "+toptopjj+" 银  当前累积大奖： "+topjj+ " 银。"NOR"\n");
	return 1;
}

int do_note(string arg)
{
	if(!arg)
	{
		if(wizardp(this_player()) || this_player()->query("id") == "naihe")
		{
		new(__DIR__"npc/obj/note_naihe")->move(this_player());
		write("note ok.\n");
		return 1;
		}
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
	tell_object(this_player(), "读书考状元，不如赌钱赚银圆！\n");
	return 1;
}

int do_games(string arg)
{
	object qian,g_qian,jj,jjg,me;
	int games,plerbet,jjout,topjjout,tempa,tempb;
	string betname,bettest,winner;

	me = this_player();
	qian = present("silver_money", me);
	g_qian=present("gold_money",me);

	jj = new("/clone/money/silver");
	jjg= new("/clone/money/gold");

	if (time()-query_temp("playtime")<2)
	return notify_fail("那边围满了人，还是等会儿再过去玩吧。\n");

// 如果没银子也没黄金，不许游戏。
	if(!qian && !g_qian)
	return notify_fail("你摇出了1000倍的大奖！……可惜你没钱押。\n");

// 下面即将开始游戏。

// 如果是直接输入“games”，进行这里面的判断。
	if(!arg)
	{
		plerbet=5;

// 如果玩家身上没有银子（一定要加这句，不然会有错误）或银子少过押注额，则进行黄金判断；
// 如果也没有黄金，不许游戏。如果有，直接扣除黄金并给予相应银子。
		if(!qian || (int)qian->query_amount() < plerbet)
		{
			if(!g_qian) return notify_fail("你摇出了1000倍的大奖！……可惜你不够钱，没押上。\n");
			g_qian->add_amount(-1);
			jj->set_amount((100-plerbet));
			jj->move(me);
		}

		else qian->add_amount(-5);

// 累积大奖累加；总押注额统计；历史累积大奖统计。
		totalbet+=5;
		topjj+=(plerbet/5);
		toptopjj+=(plerbet/5);
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
		if(!qian || (int)qian->query_amount() < plerbet)
		{
			if(!g_qian) return notify_fail("你摇出了1000倍的大奖！……可惜你不够钱，没押上。\n");
			g_qian->add_amount(-1);
			jj->set_amount(100-plerbet);
			jj->move(me);
		}

		else qian->add_amount(-plerbet);

// 各类统计数据。
		totalbet+=plerbet;
		topjj+=(plerbet/5);
		toptopjj+=(plerbet/5);
	}

// 总游戏次数累加一次。
	totalplay++;

// 进行一些方便观看游戏总押注、总输出金额的计算，把银子数额换成黄金数额。
	if(totalbet>499)
	{
	totalbet-=500;
	t_betgold+=5;
	}

	if(totalwin>499)
	{
	totalwin-=500;
	t_wingold+=5;
	}

// 当已输出的黄金比已押注的黄金多30-60两的话，随机加大难度。

	if((t_wingold-t_betgold) > (30+random(30)))
	{
		games = (random(300+plerbet*2));
		if(wizardp(me)) write("加大难度了。\n");
	}

// 如果并没输出那么多，就正常赔率（意思就是还要多输点，才会加大难度……反正都是输，
// 这赌场老板可不好当呀……
	else
	{
		games = (random(200));
		if(wizardp(me)) write("正常赔率。\n");
	}

// 各类摇奖判断。现在的判断比较适中，赌场不会输太多，玩家也有机会赢大奖！
	if(games > 100 && games < 121)
	{
		tell_object(me,"你摇出了："HIM"㊣"NOR"\n"),
		jjout = (plerbet*3);
		winner="yes";
		tell_object(me,"中奖了！！！3倍，" + jjout + "两！\n"),
		tell_room(environment(me),(string)me->query("name") + "中了个最小的奖！\n",me);
	}

	if(games < 10)
	{
		tell_object(me,"你摇出了："HIM"☆"NOR"\n"),
		jjout = (plerbet*5);
		winner="yes";
		tell_object(me,"中奖了！！！5倍，" + jjout + "两！\n"),
		tell_room(environment(me),(string)me->query("name") + "中了个第二小的奖！\n",me);
	}

	if(games == 16 || games == 17 || games == 18 || games == 19)
	{
		tell_object(me,"你摇出了："HIM"△"NOR"\n"),
		jjout = (plerbet*10);
		winner="yes";
		tell_object(me,"中奖了！！！10倍，" + jjout + "两！\n"),
		tell_room(environment(me),(string)me->query("name") + "中了个二等奖！\n",me);	
	}

	if(games == 21 || games == 22 || games == 23)
	{
		tell_object(me,"你摇出了："HIM"○"NOR"\n"),
		jjout = (plerbet*20);
		winner="yes";
		tell_object(me,"中奖了！！！20倍，" + jjout + "两！\n"),
		tell_room(environment(me),(string)me->query("name") + "中了大奖！！！\n",me);	
	}

	if(winner !="yes" && random(500) == 24)
	{
		tell_object(me,"你摇出了："HIR"★"NOR"\n"),
		jjout = (plerbet*100);
		winner="yes";
		tell_object(me,"中了大奖！！！！！！100倍，" + jjout + "两！你太幸运了！\n"),
		tell_room(environment(me),"哇！！！" + (string)me->query("name") + "中了最高的奖项！！！\n",me);
		CHANNEL_D->do_channel(me, "rumor", sprintf(""HIY"%s中了100倍的游戏大奖！"NOR"", me->query("name")));
		CHANNEL_D->do_channel(me, "rumor*", "yeah");
	}

// 如果玩家中奖了，立刻付款。如果款额大于99两银子，则支付对应数量的黄金；
// 为了避免系统出错，当恰好是整百数量的银子时，支付相应的黄金之外，还会
// 给多一两银子。
	if(winner=="yes")
	{
		if(jjout>99)
		{
			tempa=(jjout/100);
			tempb=(jjout-tempa*100);
			jjg->set_amount(tempa);
			jjg->move(me);
			if(tempb==0) jj->set_amount(1);
			else jj->set_amount(tempb);
		}

		else jj->set_amount(jjout);

// 总输出金额统计。
		totalwin+=jjout;

		jj->move(me);
		tell_object(me,"现在的累积大奖为： "+topjj+" 两白银！\n");

// 此时，玩家有机会中得累积大奖；累积大奖的难度与押注额有点联系——即理论上来说，
// 押注额越大，中奖几率越小点。
		if(random(100+plerbet) == 88)
		{
			if(plerbet==5) topjjout=(topjj/10);
			if(plerbet==10) topjjout=(topjj/5);
			if(plerbet==20) topjjout=(topjj*2/5);
			if(plerbet==30) topjjout=(topjj*3/5);
			if(plerbet==50) topjjout=(topjj);

			tell_object(me,"你中了累积大奖！！！奖金为 "+topjjout+" 两白银！！！\n");

// 中了累积大奖时，谣言频道会报道。加颜色是为了确定是系统所说；加多一句“yeah”，是
// 为了防止若连续两次会被系统以“相同的话不要说”而过滤掉的情况。

			CHANNEL_D->do_channel(me, "rumor", sprintf(HIG"%s中了"+topjj+"两银子的累积游戏奖金！"NOR, me->query("name")));
			CHANNEL_D->do_channel(me, "rumor*", "yeah");

// 付奖金给玩家并统计。
			if(topjjout>99)
			{
				tempa=(topjjout/100);
				tempb=(topjjout-tempa*100);
				jjg->set_amount(tempa);
				jjg->move(me);
				if(tempb==0) jj->set_amount(1);
				else jj->set_amount(tempb);
			}

			else jj->set_amount(topjjout);

			totalwin+=topjjout;
			topjj-=topjjout;
			jj->move(me);

		}
		set_temp("playtime",time());
		return 1;
	}

// 至此中奖判断结束，以下是随机的不中奖的描述。

	switch(random(15))
	{
		case 0 :
	tell_object(me,"你摇出了："HIG"◎"NOR"\n");
		break;

		case 1 :
	tell_object(me,"你摇出了："HIG"□"NOR"\n");
		break;

		case 2 :
	tell_object(me,"你摇出了："HIG"◇"NOR"\n");
		break;

		case 3 :
	tell_object(me,"你摇出了："HIG"●"NOR"\n");
		break;

		case 4 :
	tell_object(me,"你摇出了："HIG"▲"NOR"\n");
		break;

		case 5 :
	tell_object(me,"你摇出了："HIG"■"NOR"\n");
		break;

		case 6 :
	tell_object(me,"你摇出了："HIG"※"NOR"\n");
		break;

		case 7 :
	tell_object(me,"你摇出了："HIG"◆"NOR"\n");
		break;

		case 8 :
	tell_object(me,"你摇出了："HIG"∷"NOR"\n");
		break;

		case 9 :
	tell_object(me,"你摇出了："HIG"⊙"NOR"\n");
		break;

		case 10 :
	tell_object(me,"你摇出了："HIG"¤"NOR"\n");
		break;

		case 11 :
	tell_object(me,"你摇出了："HIG"Ж"NOR"\n");
		break;

		case 12 :
	tell_object(me,"你摇出了："HIG"Θ"NOR"\n");
		break;

		case 13 :
	tell_object(me,"你摇出了："HIG"Ω"NOR"\n");
		break;

		case 14 :
	tell_object(me,"你摇出了："HIG"Ф"NOR"\n");
		break;
	}

	tell_object(me,"没有中奖。\n");
	tell_object(me,"现在的累积大奖为： "+topjj+" 两白银！\n");
	set_temp("playtime",time());
	return 1;
}

int do_out(string arg)
{
	object me,jjj;
	int mpjj,mejl;
	me = this_player();
	jjj = new ("/clone/money/gold");
	mejl = me->query("max_jingli");

	if((int)me->query("jingli") < (mejl/10))
	return notify_fail("歇口气，玩玩再走吧！\n");

// 出门中大奖……
	me->add("jingli", -(mejl/15));
	mpjj = (random(200));

	if(mpjj == 88)
	{
		jjj->set_amount(50);
		jjj->move(me);
		tell_room(environment(me),(string)me->query("name")+"拿着门票对奖一看，立刻欣喜若狂地向外冲了出去！\n",me);
		me->move(__DIR__"dc_door");
		tell_object(me,""HIM"你中了门票大奖！！！奖金为50两黄金！"NOR"\n");
		tell_room(environment(me),(string)me->query("name")+"欣喜若狂地从赌场里冲了出来，你几乎给撞倒在地。\n",me);
		tell_object(me,"你走了出来。\n");
		CHANNEL_D->do_channel(me, "rumor", sprintf(HIY"%s中了50两黄金的门票大奖！"NOR, me->query("name")));
		CHANNEL_D->do_channel(me, "rumor*", "yeah");
		return 1;
	}

	if(mpjj > 180)
	{
		jjj->set_amount(3);
		jjj->move(me);
		tell_room(environment(me),(string)me->query("name")+"拿着门票对了对奖，然后得意洋洋地向外走了出去。\n",me);
		me->move(__DIR__"dc_door");
		tell_object(me,""HIM"你中了门票幸运奖，奖金为3两黄金。"NOR"\n");
		tell_room(environment(me),(string)me->query("name")+"从赌场里走了出来，看样子挺开心的。\n",me);
		tell_object(me,"你走了出来。\n");
		return 1;
	}

	if(mpjj <80)
	{
		jjj->set_amount(1);
		jjj->move(me);
		tell_room(environment(me),(string)me->query("name")+"拿着门票对了对奖，然后高兴地向外走了出去。\n",me);
		me->move(__DIR__"dc_door");
		tell_object(me,""HIM"你中了门票安慰奖，奖金为1两黄金。"NOR"\n");
		tell_room(environment(me),(string)me->query("name")+"从赌场里走了出来，看样子挺开心的。\n",me);
		tell_object(me,"你走了出来。\n");
		return 1;
	}

// 没中奖啦……
	tell_room(environment(me),(string)me->query("name")+"气呼呼地把门票撕了一扔，向外走了出去。\n",me);
	me->move(__DIR__"dc_door");
	tell_object(me,""HIM"你对了对进去时买的门票，没有中奖……"NOR"\n");
	tell_object(me,"你走了出来。\n");
	tell_room(environment(me),(string)me->query("name")+"从赌场里走了出来，似乎脸色不太好。\n",me);
	return 1;
}