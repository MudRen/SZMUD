//                标准描述长度示例                                   |
// 赌大小的房间，偏厅！！！  ★dc_bigsm.c
// by naihe  2002-04-28  于茂名
// 请勿擅自更改本文件源码，谢谢！

#include <ansi.h>
#include <room.h>
inherit ROOM;

int totalplay,totalbet,totalwin;

void create()
{
	set("short", YEL"赌场偏厅"NOR);
	set("long", "这里是赌场的偏厅，摆设一如大厅里一般，在中央的位置围着一圈机器。这
里的机器是用来玩“大小”游戏的，人要比大厅里少些，但气氛依然非常的热烈。
机器上面都有游戏的说明（shuoming）。\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);

	set("item_desc",([
    "shuoming":"每次1-50两白银，输入(bet <大/小> <数量>)启动游戏。4-10为小，11-17为大。\n",
    "shuoming":"每次1-50两白银，输入(bet <大/小> <数量>)启动游戏。4-10为小，11-17为大。\n",
	]));

	set("objects", ([
	    __DIR__"obj/yizi" : 1,
	    ]));

	set("exits", ([
	    "northwest":__DIR__"dc_dating",
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
	add_action("do_bet", "bet");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
        add_action("do_food", "he");
}

  void reset() 
  { 
                ::reset(); 
                set("no_clean_up", 1); 
  } 

int do_xxx()
{
	int temp =(totalbet-totalwin);
	write("总游戏次数："+totalplay+"  总收入："+totalbet+" 总奖金："+totalwin+" 利润："+temp+" 。\n");
	return 1;
}

int do_food(string arg)
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

int do_bet(string arg)
{
	object qian,jj,me;
	int gamea,gameb,gamec,gameall,betmoney;
	string betname,gamename;

	me = this_player();
	qian = present("silver_money", me);
	jj = new("/clone/money/silver");

	if (time()-query_temp("playtime")<1)
	return notify_fail("那边围满了人，还是等会儿再过去玩吧。\n");

	if(!qian)
	return notify_fail("你天真地对着机器说：“我没银子，押个注行吗？”……机器没有任何反应。\n");

	if (!arg || sscanf(arg, "%s %d", betname, betmoney) !=2)
	return notify_fail("你要押什么？ （bet <大/小> <数量>）\n");
//第100行。
	if((int)qian->query_amount() < betmoney)
	return notify_fail("你天真地对着机器说：“我银子不够，押个注行吗？”……机器没有任何反应。\n");

	if(betmoney<1)
	return notify_fail("你的意思是想要准备抢钱？\n");

        if(betmoney>50)
        return notify_fail("这里只接受1-50两银子的押注。\n");

	if(betname == "大" || betname == "小")
	{
		totalplay++;
		totalbet+=betmoney;
		qian->add_amount(-betmoney);
		jj->set_amount(betmoney*2);

		gamea = (1+random(6));
		gameb = (1+random(6));
		gamec = (1+random(6));

		tell_object(me,"你把银子塞进机器里一拉摇杆，开出了：" + gamea + "、" + gameb + "、" + gamec +  "。\n");
		tell_room(environment(me),(string)me->query("name")+"把银子往机器里一塞，满怀希望地拉动了摇杆。\n",me);

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
		set_temp("playtime",time());
		return 1;
	}
	else tell_object(me,"你要押什么？ （bet <大/小> <数量>）\n");
	return 1;
}
