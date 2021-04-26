// NPC版老虎机！！！  ★/npc/npcmoney.c
// by naihe  2002-04-09
// 请勿更改本文件源码，谢谢！
// 4-26 完成游戏"kick". 4-27 完成游戏"yazhu".
// 4-29 日完成游戏！！！从一无所知到做了这个NPC，哈哈

#include <ansi.h>
inherit NPC;

int t_bet,t_play,t_win;

void create()
{
	set_name(HIG"老虎机"NOR,({"npc money","money"}));
	set("long","\n这是一台人形的机器，又如Q版状的小老虎模样，非常可爱。隔着玻璃可以
看到它胸腔位置里有好多的"HIW"银币"NOR"(silvers)。只要用力"HIR"踢"NOR""HIW"（kick money）"NOR"它，
将会启动游戏。每次自动收取玩家一两白银。\n\n");
	set("nickname",HIR"摇滚式"NOR);
	set("title",HIC"机器人工厂荣誉出品"NOR);
	set("gender","铁性");
	set("age",19);
	set("attitude","friendly");
	set("str",60);
	set("int",30);
	set("con",60);
	set("dex",30);
	set("qi",100000);
	set("max_qi",100000);
	set("max_jing",100000);
	set("jing",100000);
	set("jingli",100000);
	set("max_jingli",100000);
	set("neili",100000);
	set("max_neili",100000);
	set("jiali",1);
	set("combat_exp",52013140);
	set_skill("force",401);
	set_skill("dodge",401);
	set_skill("parry",401);
	set_skill("literate",401);
	set_skill("music",401);
        set("no_refresh",1);
	set("inquiry",([
	    "作者":"老虎机由华山派奈何所作。\n老虎机望着远方的天空，静静地出神。",
	    "摇滚式":"
为什么机器那么摇，\n因为你就在旁边叫，\n为什么你在旁边叫，\n因为你输钱了我在笑。\n摇滚式，我摇，你滚  ：）",
	    "play":"本机有kick 和 yazhu 两个游戏！你可以询问 <规则>得到详细介绍！",
	    "规则":"kick 游戏：只要用力踢（"HIW"kick money"NOR"，用力地按下回车键），你将会中奖。\n yazhu游戏：输入 "HIW"yazhu <傻瓜> <数量>"NOR"，如果是傻瓜，你将会中奖。",
	    ]));
	set("chat_chance",1);
	set("chat_msg",({
	    "老虎机大声嚷着：“不骗钱，不抢钱，中了一定会赔钱！大家来玩老虎机呀！”\n",
	    "老虎机大声嚷着：“只要踢一脚（"HIW"kick money"NOR"）就有机会获得大奖啦！大家来玩呀！”\n",
	    "老虎机大声嚷着：“来押注（"HIW"yazhu <傻瓜> <数量>"NOR"），就有机会获大奖啦！大家来玩呀！”\n",
	}));
	setup();
	add_money("coin",1);
}

void init()
{
        ::init();  // 我实在不明白这句有什么用啊
	if (wizardp(this_player()))  add_action("do_xxxxx", "xxxxx"); // wiz 可以查询总值。
        add_action("do_kick", "kick");
	add_action("do_killme", "kill");
	add_action("do_yazhu", "yazhu");
	add_action("do_throw", "throw");

}


int do_xxxxx()
{
	int temps;
	temps = (t_bet-t_win);
     	write("游戏次数："+t_play+ "次  收入："+temps+" 银 。\n总押注："+t_bet+" 银  总奖金："+t_win+" 银。\n");
	return 1;
}

int do_throw(string arg)
{
	tell_object(this_player(),"不要乱扔东西，一不小心砸到老虎机可不好……\n");
	return 1;
}

int do_killme(string arg)
{
	object me;
	me = this_player();
	if(arg == "money" || arg == "npc money")
	{
	tell_object(me,"你突然发觉老虎机太可爱了，不由得心软了下来。\n");
	return 1;
	}

	return 0;
}

int do_kick(string arg)
{
	object me,qian,jjout,lkout;
	int gamea,gameb,gamec,lucka,luckb,luckc,jj;
	me = this_player();
	qian = present("silver_money", me);
	jjout = new("/clone/money/silver");
	lkout = new("/clone/money/silver");

	if (time()-query_temp("playtime")<2)
	{
	tell_object(me,"上一次游戏还没完呢，等等吧。\n");
	return 1;
	}

	if(!arg || arg !="money")
	return 0;

	if(!qian)
	{
	tell_object(me,"别踢，踢坏了可没钱赔。\n");
	return 1;
	}

	tell_object(me,"你对着老虎机一脚踢了过去……哐铛……游戏启动了……\n");
	tell_room(environment(me),(string)me->query("name")+"飞起一脚，正好踢中老虎机的屁股！\n",me);


// 下面是游戏开始的部分。 第100行。
	qian->add_amount(-1);
	t_play++;
	t_bet++;

// 取第一个的值。
	switch(random(3))
	{
		case 0 :
	tell_object(me,"1--"HIG"★"NOR"\n");
	gamea = 1;
		break;

		case 1:
	tell_object(me,"1--"HIY"●"NOR"\n");
	gamea = 2;
		break;

		case 2:
	tell_object(me,"1--"HIM"◆"NOR"\n");
	gamea = 3;
		break;

/*		case 3:
	tell_object(me,"1--"HIW"■"NOR"\n");
	gamea = 4;
		break; */
	}

// 取第二个的值。
	switch(random(3))
	{
		case 0 :
	tell_object(me,"2--"HIG"★"NOR"\n");
	gameb = 1;
		break;

		case 1:
	tell_object(me,"2--"HIY"●"NOR"\n");
	gameb = 2;
		break;

		case 2:
	tell_object(me,"2--"HIM"◆"NOR"\n");
	gameb = 3;
		break;

/*		case 3:
	tell_object(me,"2--"HIW"■"NOR"\n");
	gameb = 4;
		break; */
	}
	
// 取第三个的值。
	switch(random(3))
	{
		case 0 :
	tell_object(me,"3--"HIG"★"NOR"\n");
	gamec = 1;
		break;

		case 1:
	tell_object(me,"3--"HIY"●"NOR"\n");
	gamec = 2;
		break;

		case 2:
	tell_object(me,"3--"HIM"◆"NOR"\n");
	gamec = 3;
		break;

/*		case 3:
	tell_object(me,"3--"HIW"■"NOR"\n");
	gamec = 4;
		break; */
	}

	if(gamea == gameb && gamea == gamec)
	{
	jj = 5 + (random(6));
	jjout->set_amount(jj);
	tell_object(me,"中奖了！！！奖金为" + jj + "个银币！！！\n");
	tell_object(me,"老虎机“稀哩哗啦”地吐出一堆"HIW"银币"NOR"，你乐滋滋地收了起来。\n");
	tell_room(environment(me),"老虎机“稀哩哗啦”地吐出一堆"HIW"银币"NOR"，" + (string)me->query("name") + "乐滋滋地收了起来。\n",me);
	jjout->move(me);
	t_win+=jj;

		if(jj > 7)
		{
		tell_object(me,""HIY"你将有机会中得幸运奖……"NOR"\n");
		lucka = (random(5));
		luckb = (random(5));
			if (lucka == luckb)
			{
			luckc = (lucka*2 + 5);
			lkout->set_amount(luckc);
			t_win+=luckc;
			lkout->move(me);
			tell_object(me,"你中了幸运奖！\n");
			tell_object(me,"老虎机“稀哩哗啦”地又吐出" + luckc + "个"HIW"银币"NOR"，你高兴得唱起歌来。\n");
			tell_room(environment(me),"老虎机“稀哩哗啦”地又吐出一堆"HIW"银币"NOR"，原来" + (string)me->query("name") + "顺便中了幸运奖！\n",me);
			}

			else
			tell_object(me,"没有中到幸运奖。\n");  //第200行。
		}

	set_temp("playtime",time());
	return 1;
	}

	tell_object(me,"没有中奖。 :P\n");
	set_temp("playtime",time());
	return 1;
}


int do_yazhu(string arg)
{
	object me,qian,jj;
	string game,betname;
	int jjout,betmoney;
	me = this_player();
	qian = present("silver_money", me);
	jj = new("/clone/money/silver");

	if (time()-query_temp("playtime")<2)
	{
	tell_object(me,"上一次游戏还没完呢，等等吧。\n");
	return 1;
	}

	if(!qian)
	return notify_fail("你都没银子押什么注？？？赌命呀？……\n");

	if (!arg || sscanf(arg, "%s %d", betname, betmoney) !=2) 
	return notify_fail("你要押什么？（傻瓜 木瓜 超级傻瓜 笨蛋 坏蛋 超级笨蛋）\n格式：yazhu <名字> <数量>\n");

	if(betmoney<1 || betmoney>20)
	return notify_fail("本机只接受1两以上、20两以下的银子押注。\n");

	if((int)qian->query_amount() < betmoney)
	return notify_fail("你的钱都不够押什么注？？？是不是准备抢钱啊……\n");

	if(betname == "傻瓜" || betname == "木瓜" || betname == "超级傻瓜" || betname == "笨蛋" || betname == "坏蛋" || betname == "超级笨蛋")
	{
	qian->add_amount(-betmoney);
	tell_room(environment(me),"只见" + (string)me->query("name") + "拿出一些银子，咬牙切齿地押了个什么。\n",me);	
	tell_object(me,"你押的是：" + betname + "！\n");
	}

	else
	return notify_fail("你要押什么？（傻瓜 木瓜 超级傻瓜 笨蛋 坏蛋 超级笨蛋）\n格式：yazhu <名字> <数量>\n");

// 下面开始游戏。这里大概是289--271行左右。
	t_play++;
	t_bet+=betmoney;

	switch(random(6))
	{
		case 0 :
	game = "傻瓜";
		break;

		case 1 :
	game = "木瓜";
		break;

		case 2 :
	game = "超级傻瓜";
		break;
		
		case 3 :
	game = "笨蛋";
		break;

		case 4 :
	game = "坏蛋";
		break;

		case 5 :
	game = "超级笨蛋";
		break;
	}

	tell_object(me,"老虎机是个" + game + "！\n");
	if(game == betname)
	{
	tell_object(me,"你押的" + betname + "中奖了！\n");
		if(game == "超级傻瓜" || game == "超级笨蛋")
		{
		jjout = ((1+random(9))*betmoney);
		jj->set_amount(jjout);
		t_win+=jjout;
		jj->move(me);
		}

		else
		{
		jjout = (5*betmoney);
		jj->set_amount(jjout);
		t_win+=jjout;
		jj->move(me);
		}

		tell_object(me,"奖金为" + jjout + "两！欢迎下次再来呀  ：）\n");
		tell_room(environment(me),(string)me->query("name") + "押的" + betname + "中奖了！\n",me);
		set_temp("playtime",time());
		return 1;
	}

	tell_object(me,"你押的是" + betname + "，开的是" + game + "，没有中奖！欢迎下次再来呀 ：）\n");
	command("kiss");
	set_temp("playtime",time());
	return 1;
}
