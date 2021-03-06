//                标准描述长度示例                                   |
// 赌场大门  ★dc_door.c
// by naihe  2002-04-16

#include <ansi.h>
//#include <room.h>
inherit ROOM;

string temphere="open";
int t_enter;

void create()
{
	set("short",HIY"赌场大门"NOR);
	set("long","你站在赌场大门前面，这里面就是近日来闻名全城的新赌场了。听说这个赌
场是一个西洋人开的，却不像城里原本的赌场那样与闲家赌牌九、色子之类，而
是有着许多新奇的机器，使用这些机器来进行赌博。你从未听闻过如此新鲜的东
西，有种强烈的想进去看看的欲望。气派的琉璃大门上方有一块金字招牌（pai），
门边上还帖着一张"HIW"“入场须知”"NOR"（xuzhi）。\n");
	set("valid_startroom", 1);

	set("item_desc",([
	    "pai":""HIY"
┏━━━━┓
┃泊来赌场┃
┗━━━━┛
"NOR"\n",
/*	    "xuzhi":"进入本赌场者须买门票一张（每张1 GOLD），出门时可以对奖（最高奖50 GOLD）。
买了门票即可入内。（直接输入 enter 即买门票并进入。）\n",
*/
	    "xuzhi":"赌场游戏最新强烈推介：虚拟战斗游戏！！！\n",
	]));

	set("objects", ([
	    __DIR__"npc/npcmoney" : 1,
	    ]));

	set("exits",([
	    "east":"/d/city/nandajie1",
	    "enter":__DIR__"dc_dating",
	    "south":"/d/city/duchang",
	]));


	setup();
}

void init()
{
	if(wizardp(this_player()))  add_action("do_mewiz", "mewiz");
// wiz 可以开放或关闭入口，输入 <mewiz open> ，开放赌场；输入 <mewiz close> ，关闭赌场。
	if(wizardp(this_player()))  add_action("do_xxx","xxx");
	add_action("do_enter",  "enter");
}

  void reset() 
  { 
                ::reset(); 
                set("no_clean_up", 1); 
  } 

int do_mewiz(string arg)
{
	if(!arg) return notify_fail("格式：<mewiz open> 开放赌场；<mewiz close> 关闭赌场。\n");
	if(arg=="open" || arg=="close")
	{
		if(arg=="close")
		{
		    if(temphere=="close") return notify_fail("现在赌场已经是停止营业的了。\n");
		    message_vision(""HIW"$N低声念了几句咒语，就见地上随即冒起缕缕薄雾，渐渐把赌场大门掩了起来。"NOR"\n",this_player());
		}
		if(arg=="open")
		{
		    if(temphere=="open") return notify_fail("现在赌场已经是正常营业的了。\n");
		    message_vision(""HIW"$N低声念了几句咒语，浓雾散开，赌场大门重新呈现出来了。"NOR"\n",this_player());
		}
	temphere=arg;
	return 1;
	}

	write("格式：<mewiz open> 开放赌场；<mewiz close> 关闭赌场。\n");
	return 1;
}

int do_xxx()
{
	write(HIW"现在赌场状态为："+temphere+"，巫师可以使用 <mewiz> 指令开放或关闭赌场。\n总进场人数："+t_enter+" 人。\n"NOR);
	return 1;
}

/*
int do_enter()
{
	object me,qian;
	me = this_player();
	qian = present("gold_money", me);

	if(temphere=="close")
	{
		write("赌场暂时停止营业，请改天再来。\n");
		return 1;
	}

	if(me->query("jingli") < 40)
	{
		write("你累得快走不动了，还是歇歇再进去吧！\n");
		return 1;
	}

	if(!qian)
	{
		write("你连门票都买不起，进去莫非是想偷摸骗抢？……\n");
		return 1;
	}

	qian->add_amount(-1);
	tell_room(environment(me),(string)me->query("name")+"买了一张门票，走了进去。\n",me);
	me->move(__DIR__"dc_dating");
	tell_object(me,""HIM"你买了门票，走了进来。"NOR"\n");
	tell_room(environment(me),(string)me->query("name")+"从大门口走了进来。\n",me);
	me->add("jingli", -30);

	return 1;
}
*/

int do_enter()
{
	if(temphere!="open")
	{
		write(HIW"赌场暂时停止营业，请改天再来。\n"NOR);
		return 1;
	}

	t_enter++;
	return 0;
}

