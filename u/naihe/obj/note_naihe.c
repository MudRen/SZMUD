//                标准描述长度示例                                   |
// 这是我的笔记本，有用的，嘿嘿……  ★/obj/note_naihe.c
// by naihe 奈何  2002-04-29  最后修改：by naihe 02-06-28
// 请勿更改本文件源码，谢谢！

#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
string user="spark";
string temp,dc_dirs,xianxing,
dc_dirs="/clone/misc/naihe/npc/obj/",
xianxing="no";

void create()
{
	set_name(YEL"巫师笔记本"NOR, ({"note", "note naihe"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一本小笔记本，封面上写着两个潦草的小字："HIC"奈何"NOR"。\n小字旁边似乎还有几行更小的字，你不妨认真看看（looklook）。\n");
		set("unit", "本");
		set("value", 1);
	}
	setup();
}

void init()
{
	add_action("do_bian",  "bian");
	if(this_player()->query("id")=="naihe")
		add_action("do_setuser", "setuser");
	add_action("do_xianxing","xianxing");
	add_action("do_cknow", "cknow");
	add_action("do_looklook","looklook");
	add_action("do_naihe","naihe");
	add_action("forme","forme");
	add_action("kissnaihe","kissnaihe");
}

int do_looklook()
{
	write("你可以照着本子里面的咒语念咒，来变（bian）出一些东西。\n");
	write("你可以查看（cknow）一下当前的授权使用者、可变的物品等状态。\n");
	write("你可以用咒语（naihe <城市名字>）扭转时空，使自己瞬间到达某个地方。\n");
	write("你可以用咒语（forme）来获得这本笔记本的使用权。\n");
	write("你可以用咒语（xianxing）来设定你要悄悄地干活还是要让人看见。\n");

	if(this_player()->query("id")==user) write("你可以用kissnaihe指令来恢复所有hp。\n");

	if(this_player()->query("id")=="naihe")
	{
		write(HIY"现在可以变的物品有：(格式：bian <obj_id> )\n jian/changjian/juice/cake/cloth/segar/gem/presents/huolu/caipu.\n奈何（naihe）可以用 setuser <id> 指令授权玩家使用；\n任何人可以用 cknow 指令可以查询当前授权使用者。\n"NOR);
		write(""HIR"本物品离线也不会掉，请小心设定！"NOR"\n");
		
	}
	return 1;
}

int do_xianxing(string arg)
{
	if(!arg || (arg!="yes" && arg!="no"))
		return notify_fail("格式为：xianxing <yes/no> .\n");

	if(this_player()->query("id")!="naihe" && this_player()->query("id")!=user)
		return notify_fail("你未获得授权。\n");

	xianxing=arg;
	if(xianxing=="yes") write("已经设定为现身模式。\n");
	else write("已经设定为隐形干活的模式。你再做什么别人都看不出来啦！ :)\n");
	return 1;
}

int kissnaihe()
{
	object me=this_player();

	if(me->query("id")!=user)
		return notify_fail("哎，不敢当。\n");

	me->set("jingli",(int)me->query("max_jingli"));
	me->set("neili",(int)me->query("max_neili"));
	me->set("qi",(int)me->query("max_qi"));
	me->set("jing",(int)me->query("max_jing"));
	me->set("food",500);
	me->set("water",500);

	write("OK，所有hp已经悄悄恢复啦  : ) \n");
	return 1;
}

int do_naihe(string arg)
{
	object me=this_player();

	if(me->query("id")=="naihe" || me->query("id")=="spark" || me->query("id")==user)
	{
		if(xianxing=="yes") message_vision(""HIW"$N对着小本子低声念了句什么，身影一晃，忽然就此消失不见。"NOR"\n",me);
		else write(HIR"你悄悄地念动跑路咒语……\n"NOR);
		if(arg=="naihe" || !arg) me->move("/u/naihe/naihe_room");
//		if(arg=="spark") me->move("/u/spark/spark_room");
		if(arg=="cs" || arg=="yangzhou") me->move("/d/city/guangchang");
		if(arg=="dc") me->move("/clone/misc/naihe/dc_dating");
		if(arg=="wiz") me->move("/d/wizard/wizard_room");
		if(arg=="shaolin") me->move("/d/shaolin/guangchang1");
		if(arg=="xixia") me->move("/d/xixia/center");
		if(arg=="hangzhou") me->move("/d/hangzhou/kedian");
		if(arg=="wudang") me->move("/d/wudang/sanqingdian");
		if(arg=="xingxiu") me->move("/d/xingxiu/xxh2");
		if(arg=="gaibang") me->move("/d/gaibang/undertre");
		if(arg=="gunyun") me->move("/d/taihu/qianyuan");
		if(arg=="huashan") me->move("/d/huashan/buwei1");
		if(arg=="baituo") me->move("/d/xingxiu/btyard");
		if(arg=="dali") me->move("/d/dali/wangfu1");
		if(arg=="emei") me->move("/d/emei/hz_guangchang");
		if(arg=="xueshan") me->move("/d/xueshan/guangchang");
		if(arg=="quanzhou") me->move("/d/quanzhou/zhongxin");
		if(arg=="quanzhen" || arg=="zhongnan") me->move("/d/zhongnan/gate1");
		if(arg=="lanzhou") me->move("/d/qilian/lanzhou");

		if(arg=="beijing") write("这个地方的地址还没添上。\n");
		if(arg=="changan") write("这个地方的地址还没添上。\n");
		if(arg=="gumu") write("这个地方的地址还没添上。\n");

		if(xianxing=="yes") message_vision(""HIW"$N的身影忽然出现在这里，让别人吓了一跳。"NOR"\n",me);
		else write(HIR"你一下子来到了这里。\n"NOR);
		return 1;
	}
	write("你并未获得授权。\n");
	return 1;
}

int do_bian(string arg)
{
	object me,bbb;
	int maxjing;

	me=this_player();
	maxjing=me->query("max_jing");

	if(!present("note naihe",me)) return notify_fail("不捡起来，你看不清楚上面的字。\n");

/****************当此人id为"naihe",名字为"奈何"的时候，执行此函数。 **********************/

	if(me->query("id")=="naihe" && me->query("name")=="奈何")
	{
		if(xianxing=="yes") message_vision(""HIY"$N翻开小笔记本，喃喃地念道：“稀哩哗啦，哔哩叭啦，叽哩呱啦……”"NOR"\n",me);
		else write("你悄悄地念动着变东西的咒语……\n");

/* 本来这里是写成if(!arg && arg!="jian" && arg!="juice" && arg!="cake" 
&& arg!="cloth" && arg!="segar") return 1 的，但是单机的底层也许有问题；所以
曲线救国，使用另一种判断方式。 

靠！另一种方式也是有错，什么底层嘛！再换一种方式！！！(!bbb) */

		if(!arg)
		{
			if(xianxing=="yes") message_vision("结果什么也没发生，$N觉得自己真是个大笨木瓜。\n",me);
			else write("结果什么也没发生。----你现在做的别人是看不到的 :) \n");
			return 1;
		}

		if(arg=="jian") bbb=new(__DIR__"anyue-jian");
		if(arg=="changjian") bbb=new(__DIR__"changjian");
		if(arg=="juice") bbb=new(dc_dirs+"ajuice");
		if(arg=="cake") bbb=new(dc_dirs+"cake");
		if(arg=="cloth") bbb=new("/clone/misc/cloth");
		if(arg=="segar") bbb=new(dc_dirs+"segar");
		if(arg=="gem") bbb=new(__DIR__"gem");
		if(arg=="presents") bbb=new(__DIR__"presents");
		if(arg=="huolu") bbb=new(__DIR__"huolu");
		if(arg=="caipu") bbb=new(__DIR__"caipu");

		if(!bbb)
		{
			if(xianxing=="yes") message_vision("$N大声叫道：“变变变！我要变个 "+arg+" 出来！！！”——却变不出来。\n",me);
			else write("现在的设定并没有"+arg+"这个东西，你变不出来。\n");
			return 1;
		}

		if(arg=="jian")
		{
			if(!present("anyue jian", me))
			{
				if(xianxing=="yes") message_vision("$N变出了一柄"BLU"暗月之剑"NOR"！\n",me);
				else write("好，变出了暗月之剑！\n");
				bbb->move(me);
				return 1;
			}
			write("------身上不是有一把吗，变那么多做什么。\n");
			if(xianxing=="yes") message_vision("结果什么也没发生，$N觉得自己真是个大笨木瓜。\n",me);
			else write("什么也没变出来哦。。。\n");
			return 1;
		}

		switch(random(2))
		{
			case 0 :
			if(xianxing=="yes")
			{
				message_vision(""MAG"只听见一阵幽幽的叹息声不知从哪传了过来，$N一下子呆住了，想起了闪烁。"NOR"\n",me);
				message_vision("$N一个拿不稳，小本子掉到了地上。\n",me);
				temp="yeah";
			}
			else write("随机数抽不对，变不出来。本子不会掉 :)\n");
			break;

			case 1 :
			if(xianxing=="yes") message_vision("$N变出了一"+bbb->query("unit") + bbb->query("name") + "！\n",me);
			else write("你变出了一"+bbb->query("unit") + bbb->query("name") + "！\n");
			bbb->move(me);
			temp="none";
			break;
		}			
		if(temp=="yeah") this_object()->move(environment(me));
		return 1;
	}

/***********当此人id为naihe设定的id的时候，执行以下函数。****************/

	if(me->query("id") == user && user!="naihe")
	{
		if(xianxing=="yes") message_vision(""HIY"$N翻开小笔记本，喃喃地念道：“稀哩哗啦，哔哩叭啦，叽哩呱啦，啊咿啊呀……”"NOR"\n",me);
		else write("你悄悄地念起了变东西的咒语……\n");
		temp="none";

		switch(random(8))
		{
			case 0 :
			bbb=new(__DIR__"anyue-jian");
			break;

			case 1 :
			bbb=new(__DIR__"changjian");
			break;

			case 2 :
			bbb=new(__DIR__"jiudai");
			break;

			case 3 :
			bbb=new("/clone/food/kaoya");
			break;

			case 4 :
			bbb=new("/clone/misc/cloth");
			break;

			case 5 :
			bbb=new(dc_dirs+"ojuice");
			break;

			case 6 :
			bbb=new(dc_dirs+"segar");
			break;

			case 7 :
			if(xianxing=="yes")
			{
				message_vision(""HIR"只见奈何一下子从$N前面冒了出来骂道：“又念错咒语了！木瓜，大笨木瓜！”"NOR"\n",me);
				message_vision("$N吓得手一哆嗦，小本子掉到了地上。\n",me);
				temp="yeah";
			}
			else write("哎，什么都变不出来，看来你的成功率还有待加强呀！\n");
			break;			
		}
		if(temp=="yeah")
		{
			this_object()->move(environment(me));
			return 1;
		}

		if(!bbb) return 1;
		bbb->move(me);
		if(xianxing=="yes") message_vision("$N变出了一"+bbb->query("unit") + bbb->query("name") + "！\n",me);
		else write("你变出了一"+bbb->query("unit") + bbb->query("name") + "！\n");
		me->add("jing",-(maxjing/10));
		if(xianxing=="yes") message_vision("$N凝神使用法术，觉得有点晕眩了。\n",me);
		else write("你使用法术，精神不如刚才好了。\n这些事情都是悄悄干的，别人不知道的啦！\n");
		return 1;
	}

/***********当此人不是naihe，也不是设定的user，但是个巫师的时候，执行以下函数。	************/

	if(me->query("id")!="naihe" && me->query("id")!=user && wizardp(me))
	{
		message_vision(""HIY"$N翻开小笔记本看了半天，哭笑不得地说道：“奈何这小子，写的这些烂代码！”"NOR"\n说罢$N也念起了咒语来：“哇哈哟，锅咋衣骂死……”\n——却什么也变不出来，看来奈何做的笔记还真够烂的。\n",me);
		return 1;
	}

/*********************当此人完全是个局外人的时候，执行以下函数。***********************/

	message_vision("$N傻乎乎地对着小本子叽叽咕咕的不知道在念些什么。\n",me);
	write("不知怎么的，你觉得头有些发昏了。\n");
	me->add("jing",-(maxjing/10));
	return 1;
}

int do_setuser(string arg)
{
	if(!arg) return notify_fail("格式：setuser <id>\n");
	user=arg;
	write("set user ok. the user is “"+user+"”.\n");
	return 1;
}

int do_cknow()
{
	write("现在的授权使用者是："+user+"。干活模式设定为 ");
	if(xianxing=="yes") write("现形。\n");
	else write("隐形。\n");
	if(this_player()->query("id")=="naihe")
	{
write("你现在可变的物品有：jian/changjian/juice/cake/cloth/segar/gem/presents/huolu/caipu.\n");
write("授权使用者");
	}
        else if(this_player()->query("id")==user) write("你");
		else write("授权使用者");
	write("将有机会变出 暗月剑、长剑、酒袋、烤鸭、布衣、橘子汁和雪茄烟。\n");
	return 1;
}

int forme()
{
	object me=this_player();

	if(me->query("id") =="naihe") return notify_fail("哎，烧坏脑了？？？\n");
	if(me->query("id") == user) return notify_fail("这本子本来就是你的啦。\n");
	if(wizardp(me))
	{
	    user=me->query("id");
	    write("你是巫师，可以获得授权。\n");
	}
	if(this_player()->query("id")=="jionsion") user="jionsion";
	if(this_player()->query("id")=="yijiu") user="yijiu";
	if(this_player()->query("id")=="spark") user="spark";

	if(this_player()->query("id")!=user) write("对不起，你并没有获得授权。\n");
	write("现在的授权使用者是： "+user+".\n");
	return 1;
}
