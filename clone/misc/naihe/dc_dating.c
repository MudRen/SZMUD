//                标准描述长度示例                                   |
// 奈何的赌场大厅  ★dc_dating.c
// by naihe  2002-05-20  于茂名
// 赌场各游戏赔率均经过严格测试，修改本文件赔率等代码请慎重！
// 赌场全新改版  :)

#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_pai();
int totalplay,totalbet,totalwin;

void create()
{
	set("short", HIY"赌场大厅"NOR);
	set("long", "这里是赌场的大厅，门口有一个可爱的小机器人在不断地和进来的客人打招
呼。大厅中央摆放着排成一圈的许多部新奇的机器（jiqi），只听见人们“咦”、
“啊”地不断发出惊奇的声音。大厅左侧的空处有一部 ATM柜员机，听说是最新
的机器，使用它时就像在钱庄里一样方便。大厅四周有几条小通道，东边的通往
赛马房，西边是娱乐游戏大厅，这里左侧的小门里面是贵宾房，东南方向的小通
道通向几个小单间，客人们可以到那里玩赌场的招牌游戏，而那边也有个洗手间，
听说人们输了就爱去洗个手转转运气，名曰“洗衰”，也不知是真是假。楼上是
一间西洋风格的茶座，客人们玩累了都爱上去吃点东西，休息一会。只见大厅正
对门的墙壁上醒目的挂着一个小牌子（paizi）。\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up","1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "paizi": (: look_pai :),
	    "jiqi":"每次1-50两白银，输入(bet <大/小> <数量>)启动游戏。4-10为小，11-17为大。\n当身上没有白银而有黄金时，机器会自动折算，请直接游戏即可。\n",
	]));

	set("objects", ([
	    __DIR__"npc/atm" : 1,
	    __DIR__"obj/yizi" : 1,
	    ]));

	set("exits", ([
	    "east": __DIR__"dc_horse",
	    "west":__DIR__"dc_kill",
	    "vip":__DIR__"dc_vip",
	    "up":__DIR__"dc_chazuo",
	    "out":__DIR__"dc_door",
	    "southeast":__DIR__"dc_tongdao",
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
//	add_action("do_outhere", "out");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
	add_action("do_food", "he");
	add_action("do_bet","bet");
}

void reset() 
{ 
              ::reset(); 
              set("no_clean_up", 1); 
} 

string look_pai()
{
	if(wizardp(this_player())) write("巫师可以用<xxx>指令查看现在的游戏统计。\n");
	return "“文明娱乐，输赢皆欣”\n";
}

int do_xxx()
{
	int temp =(totalbet-totalwin);
	write("总游戏次数："+totalplay+"  总收入："+totalbet+" 总奖金："+totalwin+" 利润："+temp+" 。 以上单位皆为白银。\n");
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

int do_outhere()
{
	object me,jjj;
	int mpjj,mejl;
	me = this_player();
	jjj = new ("/clone/money/gold");
	mejl = me->query("max_jingli");

	if((int)me->query("jingli") < (mejl/10))
	{
		write("歇口气，玩玩再走吧！\n");
		return 1;
	}

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

int do_bet(string arg)
{
	object qian,g_qian,jj,g_jj,me;
	int gamea,gameb,gamec,gameall,betmoney,game_temp;
	string betname,gamename,temp;

	me = this_player();
	qian = present("silver_money", me);
	g_qian=present("gold_money",me);
	g_jj=new("/clone/money/gold");
	jj = new("/clone/money/silver");
	game_temp=(totalwin-totalbet);

	if (time()-query_temp("playtime")<1)
	return notify_fail("那边围满了人，还是等会儿再过去玩吧。\n");

	if (!arg || sscanf(arg, "%s %d", betname, betmoney) !=2)
	return notify_fail("你要押什么？ （bet <大/小> <数量>）\n");

	if(betmoney<1)
	return notify_fail("你的意思是想要准备抢钱？\n");

	if(betmoney>50)
	return notify_fail("这里只接受1-50两银子的押注。\n");

	if(!qian || (int)qian->query_amount() < betmoney)
	{
		if(!g_qian)
		{
			message_vision("$N天真地对着机器说：“我钱不够，押个注行吗？”……机器没有任何反应。\n",me);
			return 1;
		}
	}

	if(betname == "大" || betname == "小")
	{
		totalplay++;
		totalbet+=betmoney;
		jj->set_amount(betmoney);

		if(game_temp>1000 && random(2)==1)
		{
			temp="特殊";
			if(betname=="大")
			{
			    gamea = (1+random(4));
			    gameb = (1+random(5));
			    gamec = (1+random(6));
			}

			if(betname=="小")
			{
			    gamea = (3+random(4));
			    gameb = (2+random(5));
			    gamec = (1+random(6));
			}
		}
		else
		{
			temp="正常";
			gamea = (1+random(6));
			gameb = (1+random(6));
			gamec = (1+random(6));
		}

		tell_object(me,"你把银子塞进机器里一拉摇杆，开出了：" + gamea + "、" + gameb + "、" + gamec +  "。");
		if(wizardp(me)) tell_object(me,temp+"几率。\n");
		else tell_object(me,"\n");

		tell_room(environment(me),(string)me->query("name")+"把银子往机器里一塞，一边叫道：“"+betname+"！"+betname+"！"+betname+"！！！”\n",me);

		if(gamea == gameb && gamea == gamec)
		{
			tell_object(me,"三个一样！无论你押的是大还是小，都有奖！\n");
			message_vision("$N中了奖，笑咪咪地把奖金收了起来。\n",me);
			jj->move(me);
			totalwin+=(betmoney*2);
			set_temp("playtime",time());
			return 1;
		}

		gameall =(gamea+gameb+gamec);
		if(gameall > 10)
			gamename = "大";
		if(gameall < 11)
			gamename = "小";

		tell_object(me,"开的是" + gameall + "点，" + gamename + "！\n");

		if(betname == gamename)
		{
			tell_object(me,"你押的是" + betname + "，中奖了！！！\n");
			message_vision("$N中了奖，笑咪咪地把奖金收了起来。\n",me);
			jj->move(me);
			totalwin+=(betmoney*2);
			set_temp("playtime",time());
			return 1;
		}

		message_vision("没有中奖！$N磨了磨牙。\n",me);
		if(!qian || (int)qian->query_amount() < betmoney)
		{
			g_qian->add_amount(-1);
			jj->set_amount(100-betmoney);
			if(!qian) jj->move(me);
			else qian->add_amount(100-betmoney);

			set_temp("playtime",time());
			return 1;
		}

		qian->add_amount(-betmoney);
		set_temp("playtime",time());
		return 1;
	}

	write("你要押什么？ （bet <大/小> <数量>）\n");
	return 1;
}
