//                标准描述长度示例                                   |
// 用于挂机器人开放游戏的房间，赛马房  ★dc_horse.c
// by naihe  2002-04-23  于茂名
// 请勿擅自更改本文件源码，谢谢！

#include <ansi.h>
inherit ROOM;

int t_time,t_gold;

void create()
{
	set("short", HIR"赛马房"NOR);
	set("long", "这里是一间赛马房，布置和大厅差不多，房间中央有一排围成圈子的石栏杆，
里面是一部奇怪模样的机器。进门左边的墙壁上帖着一张大大的纸，上面写着两
个大字：“说明”（shuoming）。房间两边还有几张石料做成的椅子。\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "shuoming":"“输入ask 机器人 about all 可获得相关比赛信息。”\n",
	    "说明":"“输入ask 机器人 about all 可获得相关比赛信息。”\n",
	]));

	set("objects", ([
	    __DIR__"obj/yizi" : 1,
	    ]));

	set("exits", ([
	    "west" : __DIR__"dc_dating",
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
	add_action("do_gmmn",  "gmmn");
	add_action("do_sumn", "sumn");
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
     	write("总调用命令次数："+t_time+ "次  现收支结算："+t_gold+"  。\n");
	return 1;
}

int do_food(string arg)
{
	tell_object(this_player(), "吃喝请到二楼茶座。\n");
	return 1;
}

int do_skills(string arg)
{
	tell_object(this_player(), "小心中奖了激动得走火入魔！\n");
	return 1;
}

int do_study(string arg)
{
	tell_object(this_player(), "在这里读书？！你读得进去吗……\n");
	return 1;
}

int do_gmmn(string arg)
{
	object qian,me,mygold,nowqian;
	me = this_player();
	qian = present("gold_money", me);
	nowqian = new("/clone/money/gold");
	nowqian->set_amount(200);

	if (me->query("id") == "szrobot")
	{
	if((int)qian->query_amount() > 299) return notify_fail("带那么多钱干嘛，输死你啊烂机器人！\n");

	nowqian->move(me);
	tell_object(me,"ok,添加了200GOLD。\n");
	t_time++;
	t_gold-=200;

//		log_file("DUCHANG", sprintf("%s(%s)于%s在赛马房提取200两黄金。（lost）\n",
//		me->query("name"), getuid(me), ctime(time())));

	return 1;
	}

	else
	return 0;
}

int do_sumn(string arg)
{
	object qian,me;
	me = this_player();
	if (me->query("id") == "szrobot")
	{
	qian = present("gold_money", me);

	if((int)qian->query_amount() < 300) return notify_fail("钱不够，还是省着吧，烂机器人！\n");

	qian->add_amount(-200);
	tell_object(me,"ok,减少了200GOLD。\n");
	t_time++;
	t_gold+=200;
//		log_file("DUCHANG", sprintf("%s(%s)于%s在赛马房收入200两黄金。（win）\n",
//		me->query("name"), getuid(me), ctime(time())));

	return 1;
	}

	else
	return 0;
}
