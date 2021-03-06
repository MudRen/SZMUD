//                标准描述长度示例                                   |
// 赌场虚拟战斗游戏又一力作，双人版“虚拟战斗之王”！ dc_fight.c
// by naihe 于茂名   2002-06-22始作，2002-06-22 初步完成！！！

/*****************************************************

判断方式写得相当繁琐！

*****************************************************/

#include <ansi.h>
inherit ROOM;

string last_winner,last_loser,games,temp_winner,attacker,
plera_name,plerb_name,plera_id,plerb_id,ause,buse,
games="free",
plera_id="no",
plerb_id="no";

int last_bet,t_times,t_bets,now_bet,now_time,a_sword,b_sword,
a_hp,b_hp,a_gjl,b_gjl,a_busy,b_busy,a_power,b_power,
atk_timesa,atk_timesb;

string look_pai();
void games_free();
void times();
void halt();
void check_hp();

void atk_k();
void atka_killa();
void atkb_killa();
void ause_free();
void buse_free();
void check_sword();

void create()
{
	set("short", HIG"娱乐游戏偏厅"NOR);
	set("long", "这里是娱乐游戏偏厅，房间布置和东边的大厅几乎一模一样，也在中央位置
搭了个擂台，台边竖着一个大大的牌子（pai）。\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);
	set("no_clean_up",1);
	set("item_desc",([
	    "pai":(: look_pai :),
	]));

	set("exits", ([
	    "east" : __DIR__"dc_kill",
	    ]));

	setup();
}

void init()
{
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
	add_action("do_yun","yun");
	add_action("do_chang","chang");
	add_action("do_start","start");
	add_action("do_kk","kk");
	add_action("do_xxx","xxx");

	if(wizardp(this_player()))
	{
		add_action("do_mewiz","mewiz");
		add_action("do_outhere","goto");
		add_action("do_outhere","home");
		add_action("do_test","test");
	}
}

void reset() 
{ 
              ::reset(); 
              set("no_clean_up", 1); 
} 

int do_test()
{
	object gold=new("/clone/money/gold");
	gold->set_amount(100);
	gold->move(this_player());

	write("You taked 100 gold , ok.\n");
	return 1;
}

string look_pai()
{
	message_vision(CYN"$N往牌子上看去，一副恍然大悟的样子。\n"NOR,this_player());
	return "
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
                       "HIG"双人虚拟战斗游戏说明"NOR"

    本游戏由两位玩家同时进行，模拟两人战斗的形式，在规定时间内能够
把对方打倒，或是在时间结束后气息高者将获得胜利。报名时需要至少2两黄
金，胜利者将可得到所有押注金额。游戏指令有：
"HIY"
start , kk <k / up / heal / killa / killb / killc> "NOR", 以及查询记录的
指令 "HIY"xxx"NOR" .

    在打成平局的时候，本系统将会收取每人1 两的手续费用；其它情况不
收费。

    祝各位玩得开心！ :)

                                    "HIG"--by naihe  2002-06-22"NOR"
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
}

int outhere()
{
	if(this_player()->query_temp("duchang/fighting"))
	{
		write("你还在游戏呢，这么跑掉岂不是要害游戏出BUG？！\n");
		return 1;
	}

	return 0;
}

int do_mewiz(string arg)
{
	if(!arg || (arg!="free" && arg!="close")) return notify_fail("格式：mewiz <free/close> 开放或关闭本游戏。\n");
	
	if(arg=="free")
	{
		if(games!="close") return notify_fail("游戏现在正常开放着呢。\n");
		message_vision(HIW"$N站在擂台中央喃喃念了几句咒语，围在台边的浓雾渐渐散开了。\n"NOR,this_player());
		games="free";
		return 1;
	}

	if(arg=="close")
	{
		if(games=="close") return notify_fail("游戏已经是关闭的了。\n");
		if(games!="free") return notify_fail("要关闭游戏也总得让人玩完这一局吧！\n");
		message_vision(HIW"$N站在擂台中央喃喃念了几句咒语，只见台边浓雾骤起，把擂台围了起来。\n"NOR,this_player());
		games="close";
	}

	return 1;
}

int do_xxx()
{
	write("\n最后一局由 "HIG""+last_winner+""NOR" 战胜了 "HIG""+last_loser+""NOR" ，彩金为 "HIG""+last_bet+""NOR" 两黄金。\n总游戏次数："HIG""+t_times+""NOR" 总交易量："HIG""+t_bets+""NOR" 两黄金。\n");
	return 1;
}

int do_yun()
{
	if(random(3)>0)
	{
		write("专心打架，莫要捣乱。\n");
		return 1;
	}

	return 0;
}

int do_chang()
{
	write("专心打架，莫要捣乱。\n");
	return 1;
}

int do_food()
{
	write("吃喝请到二楼茶座。\n");
	return 1;
}

int do_skills()
{
	write("练功？还不如练练玩游戏的技术呢。\n");
	return 1;
}

int do_study()
{
	write("读书？还不如仔细看看游戏的说明呢。\n");
	return 1;
}

int do_start(string arg)
{
	object me,qian;
	string temp;

	me=this_player();
	qian=present("gold_money",me);

	if(games=="close") return notify_fail("本游戏现在不开放，请改天再来。\n");
	if(games!="free" && games!="wait")
		return notify_fail("现在有人在游戏，请稍后再试。\n");

	if(games=="free")
	{
		if (!arg || sscanf(arg, "%d %s", now_bet ,temp) !=2)
		return notify_fail("启动游戏指令格式： start <数量> <货币单位>   例如：start 1 gold \n");

		if(temp!="gold") return notify_fail("现在只接受黄金的赌注。\n");
		if(now_bet<2 || now_bet>100)
			return notify_fail("赌金押注范围是 2-100 两黄金。\n");

		if(!qian || (int)qian->query_amount() < now_bet)
			return notify_fail("你带的钱不够，还是省省吧。\n");
		qian->add_amount(-now_bet);
		me->set_temp("duchang/fighting",1);
		message_vision(sprintf(HIW"\n$N拿出%s两黄金往台边一抛，大声说道：“谁敢来和我比一局？”\n\n"NOR,chinese_number(now_bet)),me);
		games="wait";
		tell_object(me,"请等待20秒让别的玩家加入。\n");
		message("vision","如要应战，直接输入 start 即可！\n", environment(me),me);
		plera_name=me->query("name");
		plera_id=me->query("id");
		call_out("games_free",20);
		return 1;
	}

	if(games=="wait")
	{
		if(me->query("id")==plera_id)
			return notify_fail("你已经划下道儿来了，耐心等等罢。\n");

		if(!qian || (int)qian->query_amount() < now_bet)
		{
		    message_vision(CYN"$N大声叫道：“我不是不敢，我只是没有钱！”\n"NOR,me);
		    return 1;
		}

		plerb_id=me->query("id");
		plerb_name=me->query("name");
		games="wait_start";
		me->set_temp("duchang/fighting",1);
		message_vision(HIW"\n$N也掏出了一些黄金往台边一抛，大声说道：“我来跟你比一局！”\n\n"NOR,me);
		qian->add_amount(-now_bet);
		message("vision",HIW"只见两人同时跳上擂台，比赛即将开始了！\n"NOR,this_object());

// 各类记录文件。
		t_times++;
		t_bets+=now_bet;
	        log_file("duchang/FIGHT_GAME", sprintf("%s(%s) VS %s(%s)于%s ，%d gold 赌注。\n",
                plera_name,plera_id,plerb_name,plerb_id,ctime(time()),now_bet));

		call_out("times",3);
		return 1;
	}

	return 1;
}

void games_free()
{
	object duzhu,tempa,tempb,ob;

	ob=this_object();
	duzhu=new("/clone/money/gold");
	tempa=find_player(plera_id);
	if(plerb_id!="no") tempb=find_player(plerb_id);

	if(games=="fighting" || games=="wait_start") return;

	if(games=="wait")
	{
		if(!tempa) message("vision",""HIW""+plera_name+"扔下黄金摆下战局，自己却偷偷溜掉了。\n"NOR,ob);

		else
		{
		    message_vision(HIW"$N等了一会仍不见有人应战，失望地把黄金收了起来。\n"NOR,tempa);
		    duzhu->set_amount(now_bet);
		    if(!present("gold_money",tempa)) duzhu->move(tempa);
		    else present("gold_money",tempa)->add_amount(now_bet);
		    tempa->delete_temp("duchang/fighting");
		}
	}

	if(games=="finish")
	{
		if(now_time<=0) message("vision",HIW"\n时间到！！！比试结束了。\n"NOR,ob);
		else message("vision",HIW"\n有人倒下了！！！比试结束！\n"NOR,ob);
		if(temp_winner==plera_id)
		{
		    message("vision",HIW"本次比试的胜利者是"+plera_name+"！将获得所有的赌金！\n\n"NOR,ob);
		    last_winner=plera_name;
		    last_loser=plerb_name;
		    last_bet=now_bet;
		    log_file("duchang/FIGHT_GAME", sprintf("%s(%s) 获胜。\n\n",plera_name,plera_id));
		    duzhu->set_amount(now_bet*2);
		    if(!present("gold_money",tempa)) 
duzhu->move(tempa);
		    else present("gold_money",tempa)->add_amount(now_bet*2);
		}

		if(temp_winner==plerb_id)
		{
		    message("vision",HIW"本次比试的胜利者是"+plerb_name+"！将获得所有的赌金！\n\n"NOR,ob);
		    last_winner=plerb_name;
		    last_loser=plera_name;
		    last_bet=now_bet;
		    log_file("duchang/FIGHT_GAME", sprintf("%s(%s) 获胜。\n\n",plerb_name,plerb_id));
		    duzhu->set_amount(now_bet*2);
		    if(!present("gold_money",tempb)) duzhu->move(tempb);
		    else present("gold_money",tempb)->add_amount(now_bet*2);
		}

		if(temp_winner=="none")
		{
		    if(a_hp>0 || b_hp>0) message("vision",HIW"本次比试双方剩余气息值一样，不分胜负！\n赌金将由两位各自取回。\n"NOR,ob);
		    else message("vision",HIW"两人都倒下了！比试不分胜负，赌金由两位各自取回。\n"NOR,ob);
		    message("vision",HIW"本系统将收取每位一两黄金的手续费。\n\n"NOR,ob);
		    log_file("duchang/FIGHT_GAME", sprintf("不分胜负。\n\n"));
		    now_bet--;
		    duzhu->set_amount(now_bet);
		    if(!present("gold_money",tempa)) duzhu->move(tempa);
		    else present("gold_money",tempa)->add_amount(now_bet);
		    if(!present("gold_money",tempb)) duzhu->move(tempb);
		    else present("gold_money",tempb)->add_amount(now_bet);
		}
	}

	if(tempa) tempa->delete_temp("duchang/fighting");
	if(tempb) tempb->delete_temp("duchang/fighting");
	games="free";
	plera_id="no";
	plerb_id="no";
	plera_name="none";
	plerb_name="none";
	now_bet=0;
}

void times()
{
	object tempa,tempb,ob;

	ob=this_object();

	if(games!="fighting" && games!="wait_start") return;

	tempa=find_player(plera_id);
	tempb=find_player(plerb_id);

	if(!tempa || !tempb)
	{
		halt();
		return;
	}

	if(games=="wait_start")
	{
		message("vision",HIY"比赛开始！！！\n"NOR,this_object());
		now_time=60;
		games="fighting";
		a_hp=100;
		b_hp=100;
		a_busy=0;
		b_busy=0;
		a_gjl=0;
		b_gjl=0;
		a_sword=100;
		b_sword=100;
		a_power=(5+random(6));
		b_power=(5+random(6));
		temp_winner="no";
		ause="ok";
		buse="ok";
	}

	now_time--;
	if(a_hp<=98) a_hp+=(random(3));
	if(b_hp<=98) b_hp+=(random(3));
	if(a_power<=30 && ause=="ok") a_power+=(random(3));
	if(b_power<=30 && buse=="ok") b_power+=(random(3));
	a_busy--;
	if(a_busy<=0) a_busy=0;
	b_busy--;
	if(b_busy<=0) b_busy=0;

	if(now_time<=0)
	{
		games="finish";
		check_hp();
		return;
	}

	tell_object(tempa,HIG"【 "+now_time+" 】"NOR"  你的气息："HIC""+a_hp+""NOR"/100 力量："HIY""+a_power+""NOR"/30 忙时："HIR""+a_busy+""NOR" .\n\n");
	tell_object(tempb,HIG"【 "+now_time+" 】"NOR"  你的气息："HIC""+b_hp+""NOR"/100 力量："HIY""+b_power+""NOR"/30 忙时："HIR""+b_busy+""NOR" .\n\n");

// 这个设置，是使系统不会每回合都报状态而令屏幕花乱。
    if(random(5)==1)
    {
	if(a_hp>=100)
		message("vision",HIW"（"+plera_name+"看起来健康极了。）\n"NOR,ob);
	if(a_hp>90 && a_hp<100)
		message("vision",HIW"（"+plera_name+"似乎受了点轻伤，但并不碍事。）\n"NOR,ob);
	if(a_hp>70 && a_hp<91)
		message("vision",HIW"（"+plera_name+"受了点伤，开始觉得有点吃力了。）\n"NOR,ob);
	if(a_hp>50 && a_hp<71)
		message("vision",HIW"（"+plera_name+"伤得厉害，模样显得有点狼狈。）\n"NOR,ob);
	if(a_hp>20 && a_hp<51)
		message("vision",HIW"（"+plera_name+"受伤严重，已经快要支持不住了。）\n"NOR,ob);
	if(a_hp>10 && a_hp<21)
		message("vision",HIW"（"+plera_name+"已经头昏眼花的快要倒下了。）\n"NOR,ob);
	if(a_hp>1 && a_hp<11)
		message("vision",HIW"（"+plera_name+"只剩最后一口气，仍在苦苦支撑着。）\n"NOR,ob);

	if(b_hp>=100)
		message("vision",HIW"（"+plerb_name+"看起来健康极了。）\n"NOR,ob);
	if(b_hp>90 && b_hp<100)
		message("vision",HIW"（"+plerb_name+"似乎受了点轻伤，但并不碍事。）\n"NOR,ob);
	if(b_hp>70 && b_hp<91)
		message("vision",HIW"（"+plerb_name+"受了点伤，开始觉得有点吃力了。）\n"NOR,ob);
	if(b_hp>50 && b_hp<71)
		message("vision",HIW"（"+plerb_name+"伤得厉害，模样显得有点狼狈。）\n"NOR,ob);
	if(b_hp>20 && b_hp<51)
		message("vision",HIW"（"+plerb_name+"受伤严重，已经快要支持不住了。）\n"NOR,ob);
	if(b_hp>10 && b_hp<21)
		message("vision",HIW"（"+plerb_name+"已经头昏眼花的快要倒下了。）\n"NOR,ob);
	if(b_hp>1 && b_hp<11)
		message("vision",HIW"（"+plerb_name+"只剩最后一口气，仍在苦苦支撑着。）\n"NOR,ob);

	message("vision","\n",ob);
    }

	call_out("times",1);
}

void check_hp()
{
	if(games=="finish")
	{
		if(a_hp>b_hp) temp_winner=plera_id;
		if(a_hp<b_hp) temp_winner=plerb_id;
		if(a_hp==b_hp) temp_winner="none";
		games_free();
		return;
	}		

	if(a_hp<1 || b_hp<1)
	{
		if(a_hp<1 && b_hp>0) temp_winner=plerb_id;
		if(a_hp>0 && b_hp<1) temp_winner=plera_id;
		if(a_hp<1 && b_hp<1) temp_winner="none";
		games="finish";
		games_free();
		return;
	}
}

void halt()
{
	message("vision",HIW"不知道是谁赌品那么差，打着打着居然跑掉了。\n本次游戏强迫结束，赌注作为手续费将被系统收取。\n"NOR,this_object());

// 记录于历史文件。
	log_file("duchang/FIGHT_GAME", sprintf("某一方离开了MUD，游戏强迫结束。\n\n"));

// 重置状态。
	games_free();
}

int do_kk(string arg)
{
	object me;

	me=this_player();

	if(games!="fighting") return notify_fail("游戏还没开始呢。\n");

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
// ■■■■■■■■■■■■ 第一玩家的出招 ■■■■■■■■■■■■
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■

	if(me->query("id") == plera_id)
	{
		if(!arg) return notify_fail("格式：kk <k / up / heal / killa / killb / killc> \n");
		if(a_busy>0)
		{
			tell_object(me,"你的上一个动作还没有完成，越急只会越乱！\n");
			a_busy+=(random(2));
			return 1;
		}

		if(a_power<=0 && arg!="up") return notify_fail("你已无力出任何招式！\n");

		if(arg=="k")
		{
			if(a_power<2) return notify_fail("你已无力攻击！\n");
			a_power--;
			a_busy+=(1+random(2));
			a_gjl=(3+random(8));
			attacker="aaa";
			atk_k();
			return 1;
		}

		if(arg=="up")
		{
			if(a_power>=25) return notify_fail("你的力量已满！\n");
			if(ause!="ok") return notify_fail("你穴道被封，无法提升力量！\n");
			message_vision(HIC"$N大喝一声，双眼突然精光一闪，全身似有隐隐杀气散射而出！\n"NOR,me);
			a_power+=(3+random(3));
			a_busy+=(2+random(4));
			return 1;
		}

		if(arg=="heal")
		{
			if(a_hp>=80) return notify_fail("你现在还健康得很！\n");
			if(a_power<10) return notify_fail("你的力量不足，无法恢复气息！\n");
			message_vision(HIG"$N深深地吸了一口气，精神看起来好多了。\n"NOR,me);
			a_hp+=(10+random(11));
			a_power-=(5+random(6));
			a_busy+=(1+random(2));
			return 1;
		}

		if(arg=="killa")
		{
			if(a_power<15) return notify_fail("你现在无力出此招式！\n");
			if(ause!="ok") return notify_fail("你穴道被封，无法施展绝技！\n");
			message_vision(HIC"\n$N清啸一声，拔身跃起，正是绝技“踏风连环腿”！\n",me);
			a_busy+=(3+random(3));
			atk_timesa=(((a_power-15)/3)+3);
			a_power=0;
			atka_killa();
			return 1;
		}

		if(arg=="killb")
		{
			if(a_power<10) return notify_fail("你现在无力出此招式！\n");
			if(ause!="ok") return notify_fail("你穴道被封，无法施展绝技！\n");
                        if(buse!="ok") return notify_fail("对方的穴道还没解呢。\n");

			a_power-=10;
			a_busy+=2;
			message("vision",HIB"\n众人眼前一花，只见"+plera_name+"突然形似鬼魅，欺身逼近"+plerb_name+"，施展出了“魅影拂穴手”！\n"NOR,this_object(),({me,find_player(plerb_id)}));
			tell_object(me,HIB"\n你瞬间逼近"+plerb_name+"，已然施展出了“魅影拂穴手”！\n"NOR);
			tell_object(find_player(plerb_id),HIB"\n你眼前一花，只见"+plera_name+"逼到你的身前，已然施展出了“魅影拂穴手”！\n"NOR);

			switch(random(3))
			{
			    case 0:message_vision(HIR"$N一下子被点中穴道，只觉得全身血脉似已冻结，急欲动弹不得。\n"NOR,find_player(plerb_id));
			    buse="cannot";
                            call_out("buse_free",10+random(6));
			    break;
			    case 1:message_vision(WHT"$N大惊之下急忙闪开，当真是有惊无险！\n"NOR,find_player(plerb_id));
			    break;
			    case 2:message_vision(HIR"$N一下子被点中穴道，只觉得全身血脉似已冻结，急欲动弹不得。\n"NOR,find_player(plerb_id));
			    buse="cannot";
                            call_out("buse_free",10+random(6));
			    break;
			}	
			return 1;
		}

		if(arg=="killc")
		{
			if(a_power<5) return notify_fail("你已无力出此招式！\n");
			if(ause!="ok")  return notify_fail("你穴道被封，无法施展绝技！\n");
			if(a_sword<=0) return notify_fail("你手中已无剑，如何出招？\n");

			a_power-=5;
			a_busy+=(2+random(3));
			if(b_sword>=1)
			{
			    message_vision(HIY"\n$N长呼一声，剑光闪动，正是一式“破剑霜华”，绞向对方手中长剑！\n"NOR,me);
			    switch(random(3))
			    {
				case 0:
				message("vision",WHT"只见"+plerb_name+"毫不慌乱，闪身避过。\n",this_object(),find_player(plerb_id));
				tell_object(find_player(plerb_id),WHT"你轻笑一声，闪身避过。\n"NOR);
				break;

				case 1:
				message_vision(HIC"$N迎剑奋力相抗，「锵」地一声，两人手中长剑同时受损！\n"NOR,find_player(plerb_id));
				a_sword-=(5+random(6));
				b_sword-=(10+random(11));
				check_sword();
				break;

				case 2:
				message_vision(HIB"只听得「锵」地一声，$N手中长剑已被砍裂一道口子！\n"NOR,find_player(plerb_id));
				b_sword-=(30+random(21));
				check_sword();
				break;
			    }
			}

			else
			{
			    message_vision(HIY"\n$N长呼一声，竟然以对方手臂作剑，施展出“破剑霜华”凌厉攻去！\n"NOR,me);
			    switch(random(3))
			    {
				case 0:
				message("vision",WHT"只见"+plerb_name+"毫不慌乱，闪身避过。\n",this_object(),find_player(plerb_id));
				tell_object(find_player(plerb_id),WHT"你轻笑一声，闪身避过。\n"NOR);
				break;

				case 1:
				message_vision(HIR"$N无法相抗，只听得「噗噗」几声，手上已然中招，顿时鲜血四溅！\n"NOR,find_player(plerb_id));
                                b_hp-=(15+random(16));
				check_hp();
				break;

				case 2:
				message_vision(YEL"$N无法相抗，勉力想躲，却始终是着了道儿！\n"NOR,find_player(plerb_id));
				b_hp-=(10+random(6));
				check_hp();
				break;
			    }
			}
			return 1;
		}

		write(plera_name+"，你要出什么招式？\n");
		return 1;
	}

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
// ■■■■■■■■■■■■ 第二玩家的出招 ■■■■■■■■■■■■
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■


	if(me->query("id") == plerb_id)
	{
		if(!arg) return notify_fail("格式：kk <k / up / heal / killa / killb / killc> \n");
		if(b_busy>0)
		{
			tell_object(me,"你的上一个动作还没有完成，越急只会越乱！\n");
			b_busy+=(random(2));
			return 1;
		}

		if(b_power<=0 && arg!="up") return notify_fail("你已无力出任何招式！\n");

		if(arg=="k")
		{
			if(b_power<2) return notify_fail("你已无力攻击！\n");
			b_power--;
			b_busy+=(1+random(2));
			b_gjl=(3+random(8));
			attacker="bbb";
			atk_k();
			return 1;
		}

		if(arg=="up")
		{
			if(b_power>=25) return notify_fail("你的力量已满！\n");
			if(buse!="ok") return notify_fail("你穴道被封，无法提升力量！\n");
			message_vision(HIC"$N大喝一声，双眼突然精光一闪，全身似有隐隐杀气散射而出！\n"NOR,me);
			b_power+=(3+random(3));
			b_busy+=(2+random(4));
			return 1;
		}

		if(arg=="heal")
		{
			if(b_hp>=80) return notify_fail("你现在还健康得很！\n");
			if(b_power<10) return notify_fail("你的力量不足，无法恢复气息！\n");
			message_vision(HIG"$N深深地吸了一口气，精神看起来好多了。\n"NOR,me);
			b_hp+=(10+random(11));
			b_power-=(5+random(6));
			b_busy+=(1+random(2));
			return 1;
		}

		if(arg=="killa")
		{
			if(b_power<15) return notify_fail("你现在无力出此招式！\n");
			message_vision(HIC"\n$N清啸一声，拔身跃起，正是绝技“踏风连环腿”！\n",me);
			b_busy+=(3+random(3));
			atk_timesb=(((b_power-15)/3)+3);
			b_power=0;
			atkb_killa();
			return 1;
		}

		if(arg=="killb")
		{
			if(b_power<10) return notify_fail("你现在无力出此招式！\n");
			if(buse!="ok") return notify_fail("你穴道被封，无法施展绝技！\n");
                        if(ause!="ok") return notify_fail("对方的穴道还没解呢。\n");

			b_power-=10;
			b_busy+=2;
			message("vision",HIB"\n众人眼前一花，只见"+plerb_name+"突然形似鬼魅，欺身逼近"+plera_name+"，施展出了“魅影拂穴手”！\n"NOR,this_object(),({me,find_player(plera_id)}));
			tell_object(me,HIB"\n你瞬间逼近"+plera_name+"，已然施展出了“魅影拂穴手”！\n"NOR);
			tell_object(find_player(plera_id),HIB"\n你眼前一花，只见"+plerb_name+"逼到你的身前，已然施展出了“魅影拂穴手”！\n"NOR);

			switch(random(3))
			{
			    case 0:message_vision(HIR"$N一下子被点中穴道，只觉得全身血脉似已冻结，急欲动弹不得。\n"NOR,find_player(plera_id));
			    ause="cannot";
                            call_out("ause_free",10+random(6));
			    break;
			    case 1:message_vision(WHT"$N大惊之下急忙闪开，当真是有惊无险！\n"NOR,find_player(plera_id));
			    break;
			    case 2:message_vision(HIR"$N一下子被点中穴道，只觉得全身血脉似已冻结，急欲动弹不得。\n"NOR,find_player(plera_id));
			    ause="cannot";
                            call_out("ause_free",10+random(6));
			    break;
			}	
			return 1;
		}

		if(arg=="killc")
		{
			if(b_power<5) return notify_fail("你已无力出此招式！\n");
			if(buse!="ok")  return notify_fail("你穴道被封，无法施展绝技！\n");
			if(b_sword<=0) return notify_fail("你手中已无剑，如何出招？\n");

			b_power-=5;
			b_busy+=(2+random(3));
			if(a_sword>=1)
			{
			    message_vision(HIY"\n$N长呼一声，剑光闪动，正是一式“破剑霜华”，绞向对方手中长剑！\n"NOR,me);
			    switch(random(3))
			    {
				case 0:
				message("vision",WHT"只见"+plera_name+"毫不慌乱，闪身避过。\n",this_object(),find_player(plera_id));
				tell_object(find_player(plera_id),WHT"你轻笑一声，闪身避过。\n"NOR);
				break;

				case 1:
				message_vision(HIC"$N迎剑奋力相抗，「锵」地一声，两人手中长剑同时受损！\n"NOR,find_player(plera_id));
				b_sword-=(5+random(6));
				a_sword-=(10+random(11));
				check_sword();
				break;

				case 2:
				message_vision(HIB"只听得「锵」地一声，$N手中长剑已被砍裂一道口子！\n"NOR,find_player(plera_id));
				a_sword-=(30+random(21));
				check_sword();
				break;
			    }
			}

			else
			{
			    message_vision(HIY"\n$N长呼一声，竟然以对方手臂作剑，施展出“破剑霜华”凌厉攻去！\n"NOR,me);
			    switch(random(3))
			    {
				case 0:
				message("vision",WHT"只见"+plera_name+"毫不慌乱，闪身避过。\n",this_object(),find_player(plera_id));
				tell_object(find_player(plera_id),WHT"你轻笑一声，闪身避过。\n"NOR);
				break;

				case 1:
				message_vision(HIR"$N无法相抗，只听得「噗噗」几声，手上已然中招，顿时鲜血四溅！\n"NOR,find_player(plera_id));
                                a_hp-=(15+random(16));
				check_hp();
				break;

				case 2:
				message_vision(YEL"$N无法相抗，勉力想躲，却始终是着了道儿！\n"NOR,find_player(plera_id));
				a_hp-=(10+random(6));
				check_hp();
				break;
			    }
			}
			return 1;
		}
		write(plerb_name+"，你要出什么招式？\n");
		return 1;
	}

	message_vision(CYN"$N紧张地大声叫喊着“加油！加油！”，像是恨不得要冲上台去帮忙似的。\n"NOR,me);
	return 1;
}

void atk_k()
{
	object temp_a,temp_b,ob;
	string temp_namea,temp_nameb;
	int temp_hp,temp_sword,temp_gjl;

	ob=this_object();

	if(attacker=="aaa")
	{
		temp_a=find_player(plera_id);
		temp_b=find_player(plerb_id);
		temp_namea=plera_name;
		temp_nameb=plerb_name;
		temp_sword=a_sword;
		temp_hp=b_hp;
		temp_gjl=a_gjl;
	}

	else
	{
		temp_a=find_player(plerb_id);
		temp_b=find_player(plera_id);
		temp_namea=plerb_name;
		temp_nameb=plera_name;
		temp_sword=b_sword;
		temp_hp=a_hp;
		temp_gjl=b_gjl;
	}

	if(!temp_a || !temp_b) return;

	if(temp_sword<=0)
	{
		switch(random(2))
		{
		    case 0:
		    message("vision",CYN"只见"+temp_namea+"忽然欺身逼近"+temp_nameb+"，双掌翻飞向其急攻而去！\n"NOR,ob,({temp_a,temp_b}));
		    tell_object(temp_a,"你欺身逼近"+temp_nameb+"，双掌
翻飞向其急攻而去！\n");
		    tell_object(temp_b,temp_namea+"忽然欺身逼近你，双掌翻飞向你急攻而来！\n");
		    break;

		    case 1:
		    message("vision",CYN"只见"+temp_namea+"左手护身，右手握拳，忽地逼近"+temp_nameb+"，向其当胸击出一拳！\n"NOR,ob,({temp_a,temp_b}));
		    tell_object(temp_a,"你欺身逼近"+temp_nameb+"，右手握拳对其当胸挥去！\n");
		    tell_object(temp_b,temp_namea+"忽然欺身逼近你，右手握拳向你急攻而来！\n");
		    break;
		}
	}

	else
	{
		temp_gjl+=((temp_sword/10)+1);

		switch(random(3))
		{
		    case 0:
		    message("vision",CYN"只见"+temp_namea+"剑花纷飞，霎时间已将"+temp_nameb+"笼罩在剑影之下！\n"NOR,ob,({temp_a,temp_b}));
		    tell_object(temp_a,"你舞起剑花，点点指向"+temp_nameb+"的周身大穴！\n");
		    tell_object(temp_b,temp_namea+"舞起剑花，刹那间剑光已笼罩你周身大穴！\n");
		    break;

		    case 1:
		    message("vision",CYN"只见"+temp_namea+"忽地一剑刺出，这一剑看似平淡，"+temp_nameb+"却竟然无法看出任何破绽！\n"NOR,ob,({temp_a,temp_b}));
		    tell_object(temp_a,"你挺剑向着"+temp_nameb+"疾刺而出！\n");
		    tell_object(temp_b,temp_namea+"忽地挺剑向你疾刺而来！\n");
		    break;

		    case 2:
		    message("vision",CYN"只见"+temp_namea+"剑招变幻，忽地向着"+temp_nameb+"横剑划去！\n"NOR,ob,({temp_a,temp_b}));
		    tell_object(temp_a,"你握剑横拉，向着"+temp_nameb+"急攻而去！\n");
		    tell_object(temp_b,temp_namea+"忽地变招握剑，一道剑影对着你横划而来！\n");
		    break;
		}
	}

	switch(random(3))
	{
		case 0:
		message("vision",""WHT""+temp_nameb+"悠然一晃，不知怎么的就已躲过了"+temp_namea+"的攻击。\n"NOR,ob,({temp_a,temp_b}));
		tell_object(temp_a,WHT"只见"+temp_nameb+"悠然一晃，不知怎么的就已躲过了你的攻击。\n"NOR);
		tell_object(temp_b,WHT"你悠然一晃，轻松地闪过了"+temp_namea+"的攻击。\n"NOR);
		break;

		case 1:
		message("vision",""YEL""+temp_nameb+"大惊之下尽力相格，但仍是慢了一步，被"+temp_namea+"堪堪击中！\n"NOR,ob,({temp_a,temp_b}));
		tell_object(temp_a,YEL"只见"+temp_nameb+"虽然尽力躲闪，但仍被你所伤。\n"NOR);
		tell_object(temp_b,YEL"你虽然尽力躲闪，但由于慢了一步，仍是受了点伤。\n"NOR);
		temp_hp-=(temp_gjl/2);
		break;

		case 2:
		message("vision",""HIR""+temp_nameb+"挡无可挡，避无可避，唯有应声中招！\n"NOR,ob,({temp_a,temp_b}));
		tell_object(temp_a,HIR"只见"+temp_nameb+"挡无可挡，避无可避，应声中招！\n"NOR);
		tell_object(temp_b,HIR"你不及阻挡，大呼一声，已然中招！\n"NOR);
		temp_hp-=(temp_gjl);
		break;
	}

	if(attacker=="aaa") b_hp=temp_hp;
	else a_hp=temp_hp;

	check_hp();
}

void atka_killa()
{
	object ob,me,whoa;

	ob=this_object();
	me=this_player();
	whoa=find_player(plerb_id);

	message("vision",""HIY""+plera_name+"身在半空，脚下却快如闪电地向着"+plerb_name+"踢去！\n"NOR,this_object(),({me,whoa}));
	tell_object(whoa,""HIY""+plera_name+"身在半空，脚下却快如闪电地向着你胸膛踢来！\n"NOR);
	tell_object(me,HIY"你身在半空，脚下却快如闪电地向着"+plerb_name+"踢去！\n"NOR);

	switch(random(3))
	{
		case 0:b_hp-=(10+random(5));
		message_vision(HIR"$N躲闪不得，当胸正中一脚！\n"NOR,whoa);
		break;
		case 1:b_hp-=(5+random(6));
		message_vision(YEL"$N勉强卸去一些力道，但仍是被踢个正着！\n"NOR,whoa);
		break;
		case 2:message_vision(WHT"$N连连后退，勉力躲过了这一脚！\n"NOR,whoa);
		break;
	}

	atk_timesa--;
	if(atk_timesa<=0)
	{
		message("vision",""HIC""+plera_name+"后力已完，飘然下地。\n\n"NOR,this_object(),me);
		tell_object(me,HIC"你后力已完，飘然下地。\n\n"NOR);
		check_hp();
		return;
	}
	else atka_killa();
}


void atkb_killa()
{
	object ob,me,whob;

	ob=this_object();
	me=this_player();
	whob=find_player(plera_id);

	message("vision",""HIY""+plerb_name+"身在半空，脚下却快如闪电地向着"+plera_name+"踢去！\n"NOR,this_object(),({me,whob}));
	tell_object(whob,""HIY""+plerb_name+"身在半空，脚下却快如闪电地向着你胸膛踢来！\n"NOR);
	tell_object(me,HIY"你身在半空，脚下却快如闪电地向着"+plera_name+"踢去！\n"NOR);

	switch(random(3))
	{
		case 0:a_hp-=(10+random(5));
		message_vision(HIR"$N躲闪不得，当胸正中一脚！\n"NOR,whob);
		break;
		case 1:a_hp-=(5+random(6));
		message_vision(YEL"$N勉强卸去一些力道，但仍是被踢个正着！\n"NOR,whob);
		break;
		case 2:message_vision(WHT"$N连连后退，勉力躲过了这一脚！\n"NOR,whob);
		break;
	}

	atk_timesb--;
	if(atk_timesb<=0)
	{
		message("vision",""HIC""+plerb_name+"后力已完，飘然下地。\n\n"NOR,this_object(),me);
		tell_object(me,HIC"你后力已完，飘然下地。\n\n"NOR);
		check_hp();
		return;
	}
	else atkb_killa();
}

void ause_free()
{
	if(games!="fighting" && games!="wait_start") return;
	ause="ok";
	message_vision(HIG"$N渐觉筋脉舒畅，穴道终于解开了。\n"NOR,find_player(plera_id));
}

void buse_free()
{
	if(games!="fighting" && games!="wait_start") return;
	buse="ok";
	message_vision(HIG"$N渐觉筋脉舒畅，穴道终于解开了。\n"NOR,find_player(plerb_id));
}

void check_sword()
{
	if(games!="fighting" && games!="wait_start") return;
	if(a_sword<=0)
                message_vision(HIM"\n$N看到手中长剑已成废物，只好抛到一旁，赤手再战！\n\n"NOR,find_player(plera_id));
	if(b_sword<=0)
                message_vision(HIM"\n$N看到手中长剑已成废物，只好抛到一旁，赤手再战！\n\n"NOR,find_player(plerb_id));
}

int valid_leave(object me, string dir)
{
	if(this_player()->query_temp("duchang/fighting"))
		return notify_fail("你还在玩游戏呢，这么跑掉可不好吧。\n");
        return ::valid_leave(me, dir);
}
