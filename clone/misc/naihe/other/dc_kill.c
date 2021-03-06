//                标准描述长度示例                                   |
// 赌场游戏最新力作，“虚拟战斗之王”游戏！ dc_kill.c
// by naihe 于茂名   2002-05-28始作，05-29初步完成！！！
// 06-01 修复了一些bug.  06-24 调整赔率。

#include <ansi.h>
inherit ROOM;

void times();
void ck_hp();
void atc_l();
void atc_k();
void atc_kk();
void atc_kill();
void atc_kill_yeah();
void atc_jianyi();
void win_lose();
void ob_atc();
void ob_k();
void ob_t();
void ob_l();
void games_free();
void top_win();
string look_pai();

int nowtime,mehp,obhp,me_busy,obtime,t_play,t_jj,t_jjs,
me_power,ob_busy,me_gjl,temp,top_high,top_times,level;

string mename,obname,games,time_goon,temp_id,temp_kill,top_name,auto_hp,
games="free";

void create()
{
	set("short", HIW"娱乐游戏大厅·虚拟战斗游戏"NOR);
	set("long", "这里是娱乐游戏大厅，迎门可见中央位置搭着个擂台，但似乎与普通的擂台
并不相同。娱乐类型的游戏与外边的赌博游戏不同的是，娱乐游戏的乐趣并不在
于奖金，而主要是在于游戏本身的乐趣。大厅里的游戏叫做“虚拟战斗”，门口
旁边有一张大大的纸，上书"HIW"“说明”（shuoming）"NOR"两个大字，纸边还悬挂着一个
小牌子（pai）。\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);
	set("no_clean_up",1);
	set("no_refresh",1);  // 这一句应该是用在NPC上的……但写了不知道会怎样？xixi
	set("item_desc",([
	    "shuoming":"
"HIG"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"NOR"
                           "HIG"游  戏  说  明"NOR"

"HIY"每次游戏需要1两黄金"NOR"，在游戏空闲时输入 "HIY"start auto"NOR" 表示使用自动显示状态模式；
若不需要自动显示状态，直接输入 start 即可。

在游戏里，玩家与模拟对手战斗，谁"HIY"在规定时间内把对方打倒"NOR"即为胜利。

若"HIY"时间到了"NOR"而两者都还有剩余气息，则以"HIY"气息高者为赢"NOR"。游戏指令如下：

"HIY"kk k"NOR" ---常规攻击 "HIY"kk t"NOR" ---突袭 "HIY"kk l"NOR" ---两败俱伤的攻击  "HIY"ck"NOR" ---查询当前状态

"HIY"kk kill"NOR" ---使用绝技攻击  "HIY"kk heal"NOR" ---使用绝技疗伤  "HIR"xxx"NOR" ---查询当前最高成绩记录

"HIG"（注意：使用绝技攻击时，会视力量值的不同而自动选择招式！）"NOR"

当玩家取得胜利的时候，将会"HIY"视时间、损伤及剩余力量"NOR"等情况，"HIY"获得不同程度的奖金"NOR"。

"HIG"注意：各攻击指令将需要不同的力量值，并且会产生不同的攻击力、
命中率以及不同的busy time等。选择技能请谨慎。
                                                   --by naihe 02-05-29"NOR"
"HIG"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"NOR"\n",
	    "pai":(: look_pai :),
	]));

	set("exits", ([
	    "east" : __DIR__"dc_dating",
	    "north":__DIR__"dc_huaquan",
	    "west":__DIR__"dc_fight",
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
//	add_action("do_yun","yun");  这个暂时可以考虑不要。
	add_action("do_start","start");
	add_action("do_kk","kk");
	add_action("do_ckhp","ck");
	add_action("do_xxx","xxx");
	if(wizardp(this_player())) add_action("do_powerup","powerup");
}

void reset() 
{ 
              ::reset(); 
              set("no_clean_up", 1); 
} 

string look_pai()
{
	if(wizardp(this_player())) write("巫师在游戏时可用 powerup <a/b/c>来补充力量值！\n");
	return "只见牌子上几个大字："HIC"机器人工厂荣誉出品"NOR" 。\n";
}

int do_xxx(string arg)
{
	int tempa,tempb;

	if(arg=="hp")
	{
		write(mename+"气息："HIR""+mehp+""NOR"/100，力量："HIY""+me_power+""NOR"/30，现在忙时："HIC""+me_busy+""NOR"，游戏人物气息："HIR""+obhp+" "NOR"，剩余时间："+nowtime+" 。\n");
		return 1;
	}

	write("\n 当前最高记录是由"HIG"第"+top_times+"代王者"NOR+HIY""+top_name+""NOR"创造的"HIY""+top_high+""NOR"点的成绩！\n");

	if(!wizardp(this_player())) return 1;
	if(t_jjs>99)
	{
		tempa=(t_jjs/100);
		tempb=(t_jjs-tempa*100);
		t_jjs=tempb;
		t_jj+=tempa;
	}
	write("总游戏次数："HIG""+t_play+""NOR" 总输出奖金："HIG""+t_jj+""NOR" 金 "HIG""+t_jjs+""NOR" 银 .\n");
	return 1;
}

int do_powerup(string arg)
{
	if(games!="busy") return notify_fail("现在并不在游戏中。\n");
	if(this_player()->query("id") !=temp_id)
		return notify_fail("又不是你比赛，巫师就能瞎搅和啦？\n");

	if(!arg) arg="a";
//		return notify_fail("意思是不要力量了？？？\n");

	if(arg!="a" && arg!="b" && arg!="c") return notify_fail("只能是powerup a或b或c ，a 16点；b 21点；c 31点。\n");
	if(games!="busy") return notify_fail("还没开始游戏呢，你想up了出去PK呀？\n");
	if(me_power>=30) return notify_fail("你还想up到什么地步？？？\n");
	message("vision",HIM"忽然只听得一声大叫：“我是巫师，太上老君赐我力量！”，只见"+mename+"似已浑身充满斗志！\n"NOR,this_object());
	if(arg=="a") me_power=16;
	if(arg=="b") me_power=21;
	if(arg=="c") me_power=31;
	me_busy=0;
	return 1;
}

int do_yun()
{
	write("这里是玩游戏的，你咋的还想真打？\n");
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

void times()
{
	if(time_goon!="yes") return;
	if(nowtime==60)
	{
		mehp=100;
		obhp=100;
		games="busy";
		me_busy=0;
		me_power=(5+random(11));
		ob_busy=2;
		obtime=0;
		message("vision",HIR"比赛开始！！！\n"NOR,this_object());
	}

	if(nowtime<=0)
	{
		message("vision",""HIM"时间到！！！结束比赛！！！"NOR"\n",this_object());
		win_lose();
		return;
	}

	me_busy--;
	if(me_busy<=0) me_busy=0;
	obtime++;
	if(mehp<=98)
	{
		if(level!=2) mehp+=(random(3));
		else mehp+=(random(2));
	}
	if(obhp<=98) obhp+=(random(2));

	if(me_power<=30 && temp_kill=="free")
	{
		if(level!=2) me_power+=(random(level));
		else if(random(4)!=0) me_power++;
	}

	if(me_power>=30)
	{
		if(random(3)==1) message("vision",HIC"只见"+mename+"双目一睁，隐隐似有光芒射来。\n"NOR,this_object());
	}

	nowtime--;
	write(HIG"\n                              【 "+nowtime+" 】\n"NOR"");

	if(obtime>ob_busy)
	{
		if(random(level)==1) ob_atc();
	}

	if(auto_hp=="yes")
		write(mename+"气息："HIR""+mehp+""NOR"/100，力量："HIY""+me_power+""NOR"/30，现在忙时："HIC""+me_busy+""NOR"，游戏人物气息："HIR""+obhp+" "NOR"，剩余时间："+nowtime+" 。\n");

	call_out("times",1);
}

void ob_atc()
{
	if(obhp<30 && random(5)==3)
	{
	    message("vision",""HIG""+obname+"深深地吸了一口气，看起来精神好多了。\n"NOR,this_object());
	    ob_busy=(5+random(3));
	    obhp+=(10+random(11));
	    obtime=0;
	    return;
	}

	switch(random(6))
	{
	    case 0:ob_l();
	    break;
	    case 1:ob_t();
	    break;
	    case 2:ob_t();
	    break;
	    default:ob_k();
	}

	obtime=0;
	ck_hp();
	ob_busy=(random(2)+random(level));
}

void ob_k()
{
	message("vision",CYN"只见"+obname+"平淡无奇地向"+mename+"攻出了一招！\n"NOR,this_object());
	switch(random(2))
	{
	    case 0:mehp-=(10+random(11)+((5-level)*3));
	    message("vision",""HIR""+mename+"欲闪不得，当胸正中了一掌！\n"NOR,this_object());
	    if(me_power<=29 && temp_kill=="free") me_power+=(1+random(3));
	    break;
	    case 1:
	    message("vision",""WHT""+mename+"极力躲避之下，才让过了这看来平淡实际凶险的一招！\n"NOR,this_object());
	    break;
	}
}

void ob_t()
{
	message("vision",""CYN""+obname+"忽然身形骤变，快似鬼魅般向着"+mename+"攻去！\n"NOR,this_object());
	switch(random(3))
	{
	    case 0:mehp-=(10+random(21)+((5-level)*3));
	    message("vision",""HIR""+mename+"还未看清，就已经着了道儿！\n"NOR,this_object());
	    if(me_power<=29 && temp_kill=="free") me_power+=(1+random(3));
	    break;
	    default:
	    message("vision",""WHT""+mename+"眼花缭乱之下舞剑乱挥，居然全数挡过了！\n"NOR,this_object());
	}
}

void ob_l()
{
	message("vision",CYN"忽然间只见"+obname+"狂性大作，连连向"+mename+"攻出数招！\n"NOR,this_object());
	switch(random(4))
	{
	    case 0:mehp-=(10+random(31)+((5-level)*3));
	    message("vision",""HIR""+mename+"一时间不知从何抵挡，唯有拼着全数受下！\n"NOR,this_object());
	    if(me_power<=29 && temp_kill=="free") me_power+=(2+random(3));
	    break;
	    default:
	    message("vision",""WHT""+mename+"情急之中就地打了几个滚，狼狈却非常凑效地躲过了攻击！\n"NOR,this_object());
	}
}

int do_start(string arg)
{
	object me,qian;
	string tempa,tempb;
	int tempc;

	me=this_player();
	qian=present("gold_money",me);

	if(games!="free") return notify_fail("有人正在游戏，请等待游戏结束后再试。\n");
	if(!qian) return notify_fail("本游戏只接受黄金报名，请携带1两以上金子再试。\n");

	if(!arg || arg!="auto")
	{
		auto_hp="no";
		write(HIG"你已选择手动查询状态方式，每次查询的间隔为3秒，请注意。\n"NOR);
	}

	else
	{
		auto_hp="yes";
		write(HIG"你已选择自动显示状态方式，你的状态将在每秒显示一次。游戏奖金将减少为原金额的9/10。\n"NOR);
	}

	qian->add_amount(-1);
	t_play++;
	games="baoming";

	mename=me->query("name");

	switch(random(10))
	{
		case 0:tempa="陈";
		break;
		case 1:tempa="李";
		break;
		case 2:tempa="张";
		break;
		case 3:tempa="黄";
		break;
		case 4:tempa="何";
		break;
		case 5:tempa="唐";
		break;
		case 6:tempa="杜";
		break;
		case 7:tempa="诸葛";
		break;
		case 8:tempa="梁";
		break;
		case 9:tempa="上官";
		break;
	}

	switch(random(10))
	{
		case 0:tempb="云";
		break;
		case 1:tempb="七";
		break;
		case 2:tempb="翎";
		break;
		case 3:tempb="煞";
		break;
		case 4:tempb="虬客";
		break;
		case 5:tempb="发";
		break;
		case 6:tempb="进";
		break;
		case 7:tempb="迎";
		break;
		case 8:tempb="森";
		break;
		case 9:tempb="然";
		break;
	}

	temp_id=this_player()->query("id");
	obname=tempa+tempb;
	message_vision(GRN"$N拿出一两黄金塞进机器里，游戏开始了！！！\n"NOR,this_player());
	message("vision",HIM"只见台上忽然现出两个人影，其中之一活生生的就是"+mename+"的模样！\n"NOR,this_object());
	write(""HIC"请使用指令 kk 进行指挥操作。"NOR"\n");
	message("vision",HIW"本场比赛即将开始！！！由玩家"NOR+HIY""+mename+""NOR+HIW"对游戏里的"NOR+HIY""+obname+""NOR+HIW"！！！"NOR"\n",this_object());
	call_out("times",3);
	time_goon="yes";
	temp_kill="free";
	temp=0;

// 每场比赛的时间设定，单位为秒。更改时，要相应更改void times() 首行对应数值。
	nowtime=60;

// 难度设置。
	tempc=(t_play-t_jj);
	if(tempc>=10) level=(3+random(4));
	if(tempc<10 && tempc>-10) level=3;
	if(tempc<=-10) level=2;

//	level=2;  这句是测试用的，当难度为最难时，赔率应该是 60%-80%左右。

	if(wizardp(this_player())) write("现在难度是（越小越难）："+level+".\n");
	return 1;
}

int do_kk(string arg)
{
	object ob=this_object();
	int me_mz;

	if(games!="busy") return notify_fail("现在并不在游戏中。\n");
	if(this_player()->query("id") !=temp_id)
	{
		message_vision(CYN"$N大声喊道：“"+mename+"，加油！"+mename+"，加油！”——倒比游戏中的"+mename+"还要紧张。\n"NOR,this_player());
		return 1;
	}

	if(!arg) return notify_fail("攻击指令：kk k / kk t / kk l / kk kill / kk heal.\n");
	if(temp_kill!="free") return notify_fail("你正在施展"+temp_kill+"，仍未结束！\n");
	if(me_busy>0)
	{
		if(wizardp(this_player())) write("你的姿势还没恢复过来呢，越急只会越手忙脚乱！忙时是："+me_busy+"秒。\n");
		else write("你的姿势还没恢复过来呢，越急只会越手忙脚乱！\n");
		me_busy+=(random(2));
		return 1;
	}

	if(arg!="k" && arg!="t" && arg!="l" && arg!="kill" && arg!="heal")
		return notify_fail("你要出什么招式去攻击？\n");

	if(arg=="k")
	{
		if(me_power<2) return notify_fail("你已无力出此招式，还是先歇歇吧！\n");
		me_busy=(1+random(3));
// 攻击将产生的忙时
		me_gjl=(5+random(11)+(level-2));
// 攻击力
		me_mz=3;
// 命中率
		me_power-=(1+random(2));
// 力气值减少

		switch(random(8))
		{
		    case 0:message("vision",GRN"只见"+mename+"缩剑出掌，直向"+obname+"左侧拍去！\n"NOR,ob);
		    break;
		    case 1:message("vision",GRN"只见"+mename+"左掌虚晃了一下，右手握剑向"+obname+"的头部削了过去！\n"NOR,ob);
		    break;
		    case 2:message("vision",GRN"只见"+mename+"挺剑斜刺，直向"+obname+"右侧攻去！\n"NOR,ob);
		    break;
		    case 3:message("vision",GRN"只见"+mename+"手中利剑晃了一下，原来却是攻向"+obname+"的左腿！\n"NOR,ob);
		    break;
		    case 4:message("vision",GRN"只见"+mename+"手中利剑晃了一下，原来却是攻向"+obname+"的右腿！\n"NOR,ob);
		    break;
		    case 5:message("vision",GRN"只见"+mename+"跨步旁移，趁"+obname+"尚未看清之时握掌为拳，挥向"+obname+"的头部！\n"NOR,ob);
		    break;
		    case 6:message("vision",GRN"只见"+mename+"忽地连刺几下，分别攻向"+obname+"的上中下三路！\n"NOR,ob);
		    break;
		    case 7:message("vision",GRN"只见"+mename+"剑光游移不定，却原来是虚招，其实乃是向着"+obname+"的胸膛拍出了一掌！\n"NOR,ob);
		    break;
		}
	}

	if(arg=="t")
	{
		if(me_power<3) return notify_fail("你已无力出此招式，还是先歇歇吧！\n");
		me_busy=(2+random(3));
		me_gjl=(15+random(11)+(level-2));
		me_mz=4;
		me_power-=3;

		switch(random(5))
		{
		    case 0:message("vision",HIB"忽地只见"+mename+"飞身跃起，自半空中向"+obname+"袭去，端的是其快无比！\n"NOR,ob);
		    break;
		    case 1:message("vision",HIB"忽地只见"+mename+"夺步抢前，两手交错间一剑一掌同时向"+obname+"攻去！\n"NOR,ob);
		    break;
		    case 2:message("vision",HIB"只见"+mename+"忽地矮身蹲下，出腿往"+obname+"下盘疾扫过去！\n"NOR,ob);
		    break;
		    case 3:message("vision",HIB"忽然之间"+mename+"身形一闪，却转到了"+obname+"的背后按出了一掌！\n"NOR,ob);
		    break;
		    case 4:message("vision",HIB"忽地只见"+mename+"挥剑如风，刹那间"+obname+"全身已在剑光笼罩之下！\n"NOR,ob);
		    break;
		}
	}

	if(arg=="l")
	{
		if(me_power<5) return notify_fail("你已无力出此招式，还是先歇歇吧！\n");
		me_busy=(3+random(3));
		me_gjl=(15+random(16)+(level-2));
		me_mz=3;
		me_power-=5;

		switch(random(3))
		{
		    case 0:message("vision",RED"忽地只听得"+mename+"大喝一声，不顾一切地挺剑直刺"+obname+"，却是拼命的打法！\n"NOR,ob);
		    break;
		    case 1:message("vision",""RED""+mename+"忽然之间剑招大乱，向着"+obname+"乱劈乱砍，招招都是拼命！\n"NOR,ob);
		    break;
		    case 2:message("vision",RED"只见"+mename+"忽地只是一昧抢攻，却完全不顾自身安全，使出的全是同归于尽的招式！\n"NOR,ob);
		    break;
		}
	}

	if(arg=="kill")
	{
		if(me_power<15) return notify_fail("你的力气还没蓄够呢。\n");
		atc_kill();
	}

	if(arg=="heal")
	{
		if(me_power<8) return notify_fail("你的力气还没蓄够呢。\n");
		if(mehp>90) return notify_fail("你现在状态还挺好嘛。\n");
		message("vision",""HIG""+mename+"深深地吸了一口气，看起来精神好多了。\n"NOR,ob);
		me_power-=8;
		me_busy=(1+random(3));
		mehp+=(15+random(6));
	}

	if(arg=="k" || arg=="t" || arg=="l")
	{
		switch(random(me_mz))
		{
			case 0:
			if(arg=="l") atc_l();
			if(arg=="k" || arg=="t") atc_k();
			break;

			case 1:
			if(arg=="l") atc_l();
			if(arg=="k") atc_kk();
			if(arg=="t") atc_k();
			break;

			default:
			switch(random(8))
			{
			    case 0:
			    message("vision",""WHT""+obname+"一惊之下急切闪躲，堪堪避过。\n"NOR,ob);
			    break;
			    case 1:
			    message("vision",""WHT""+obname+"反应奇快，闪身避过。\n"NOR,ob);
			    break;
			    case 2:
			    message("vision",WHT"只见"+obname+"身影一闪，已然躲过了"+mename+"的攻击。\n"NOR,ob);
			    break;
			    case 3:
			    message("vision",WHT"只见"+obname+"淡淡一笑，轻描淡写地闪了开去。\n"NOR,ob);
			    break;
			    case 4:
			    message("vision",""WHT""+obname+"似乎未曾动过，却不知怎的就化解了"+mename+"的攻势。\n"NOR,ob);
			    break;
			    case 5:
			    message("vision",""WHT""+obname+"口里叫道：“来得好！”，却一下子把攻向自己的招式化解掉了。\n"NOR,ob);
			    break;
			    case 6:
			    message("vision",""WHT""+obname+"极力相挡，勉力抵住了来势。\n"NOR,ob);
			    break;
			    case 7:
			    message("vision",""WHT""+obname+"嗤笑一声，随手就格开了"+mename+"的进攻。\n"NOR,ob);
			    break;
			}
		}
	}
	ck_hp();
	return 1;
}

void ck_hp()
{
	object ob=this_object();

// 这个设置，是使系统不会每回合都报状态而令屏幕花乱。
	if(random(3)==1)
	{
	if(mehp>=100) message("vision",HIW"（"+mename+"看起来健康极了。）\n"NOR,ob);
	if(mehp>90 && mehp<100) message("vision",HIW"（"+mename+"似乎受了点轻伤，但并不碍事。）\n"NOR,ob);
	if(mehp>70 && mehp<91) message("vision",HIW"（"+mename+"受了点伤，开始觉得有点吃力了。）\n"NOR,ob);
	if(mehp>50 && mehp<71) message("vision",HIW"（"+mename+"伤得厉害，模样显得有点狼狈。）\n"NOR,ob);
	if(mehp>20 && mehp<51) message("vision",HIW"（"+mename+"受伤严重，已经快要支持不住了。）\n"NOR,ob);
	if(mehp>10 && mehp<21) message("vision",HIW"（"+mename+"已经头昏眼花的快要倒下了。）\n"NOR,ob);
	if(mehp>0 && mehp<11) message("vision",HIW"（"+mename+"只剩最后一口气，仍在苦苦支撑着。）\n"NOR,ob);

	if(obhp>=100) message("vision",HIW"（"+obname+"看起来健康极了。）\n"NOR,ob);
	if(obhp>90 && obhp<100) message("vision",HIW"（"+obname+"似乎受了点轻伤，但并不碍事。）\n"NOR,ob);
	if(obhp>70 && obhp<91) message("vision",HIW"（"+obname+"受了点伤，开始觉得有点吃力了。）\n"NOR,ob);
	if(obhp>50 && obhp<71) message("vision",HIW"（"+obname+"伤得厉害，模样显得有点狼狈。）\n"NOR,ob);
	if(obhp>20 && obhp<51) message("vision",HIW"（"+obname+"受伤严重，已经快要支持不住了。）\n"NOR,ob);
	if(obhp>10 && obhp<21) message("vision",HIW"（"+obname+"已经头昏眼花的快要倒下了。）\n"NOR,ob);
	if(obhp>0 && obhp<11) message("vision",HIW"（"+obname+"只剩最后一口气，仍在苦苦支撑着。）\n"NOR,ob);
	}

	message("vision","\n",ob);
	if(mehp<1 || obhp<1) win_lose();
}

int do_ckhp()  // 这个是降低难度了的 状态查询函数。
{
	if(games!="busy") return notify_fail("游戏没开始呢，大家都精神得很。\n");

	if(this_player()->query("id") !=temp_id)
		return notify_fail("又不是你比赛，瞎搅和个啥？\n");

	if(auto_hp=="yes") return notify_fail("你已经选择了自动显示状态了。\n");
	if(time()-query_temp("cktime")<3) return notify_fail("老盯着状态看，你还顾不顾攻击防御？\n");
	write(mename+"气息："HIR""+mehp+""NOR"/100，力量："HIY""+me_power+""NOR"/30，现在忙时："HIC""+me_busy+""NOR"，游戏人物气息："HIR""+obhp+" "NOR"，剩余时间："+nowtime+" 。\n");
	set_temp("cktime",time());
	return 1;
}

void atc_k()
{
	object ob=this_object();
	switch(random(5))
	{
		case 0:message("vision",""HIR""+obname+"躲闪不及，被打个正着！\n"NOR,ob);
		break;
		case 1:message("vision",""HIR""+obname+"抽身想避，却迟了半步，被打了个全中！\n"NOR,ob);
		break;
		case 2:message("vision",HIR"只见"+obname+"还未反应过来，已经应声而中！\n"NOR,ob);
		break;
		case 3:message("vision",""HIR""+obname+"大惊之下未能闪开，结结实实地吃了一招！\n"NOR,ob);
		break;
		case 4:message("vision",""HIR""+obname+"避无可避，勉力想挡，却力不从心，顿时被打个正中！\n"NOR,ob);
		break;
	}
	obhp-=me_gjl;
}

void atc_kk()
{
	object ob=this_object();
	switch(random(5))
	{
		case 0:message("vision",""YEL""+obname+"突然惊觉，抽身急躲之下仍是受了伤。\n"NOR,ob);
		break;
		case 1:message("vision",""YEL""+obname+"堪堪躲过，但仍是受了伤。\n"NOR,ob);
		break;
		case 2:message("vision",YEL"只见"+obname+"急速扭转身子躲避，却在另一侧中了招。\n"NOR,ob);
		break;
		case 3:message("vision",YEL"只见"+obname+"奋力相格，虽然仍是中招，但总算受伤不大。\n"NOR,ob);
		break;
		case 4:message("vision",""YEL""+obname+"激起内力护身受了一招，似乎受伤不重。\n"NOR,ob);
		break;
	}
	obhp-=(me_gjl/2);
}

void atc_l()
{
	int tempme,tempob;
	object ob=this_object();
	switch(random(3))
	{
		case 0:message("vision",""HIR""+obname+"只觉无法躲闪，唯有奋力相迎！！！\n"NOR,ob);
		break;
		case 1:message("vision",""HIR""+obname+"被"+mename+"所逼，只能全力一搏，硬力相拼！！！\n"NOR,ob);
		break;
		case 2:message("vision",""HIR""+obname+"大惊之下无暇细想，唯有应招！！！\n"NOR,ob);
		break;
	}
	message("vision",HIR"两人同时闷哼一声，互受重创！\n"NOR,ob);
	tempme=((me_gjl*2/3)+random(me_gjl));
	tempob=((me_gjl*2/3)+random(me_gjl));
	mehp-=tempme;
	obhp-=tempob;
}

void atc_kill()
{
	object ob=this_object();

	if(me_power>=30)
	{
		temp_kill="剑意连绵十三式";
		temp=0;
		atc_jianyi();
		return;
	}

	if(me_power>=20)
	{
	    message("vision","\n"HIC"只见"+mename+"瞬间逼近"+obname+"，剑掌交错中向着"+obname+"奋力击出了"NOR+HIR"三剑两掌"NOR+HIC"！\n\n\n"NOR,this_object());
	    me_power-=(15+random(6));
	    me_busy=(5+random(4));
	    me_gjl=(10+level-2);

	    message("vision",""HIY""+mename+"驱剑直进，剑锋直逼"+obname+"眉间一点！\n"NOR,ob);
	    atc_kill_yeah();
	    message("vision",""HIY""+mename+"一剑击过，紧跟着左掌拍上，径向"+obname+"胸膛拍去！\n"NOR,ob);
	    atc_kill_yeah();
	    message("vision",HIY"一掌还未收势，"+mename+"右手之剑又复攻起，从右至左向着"+obname+"横拉而过！\n"NOR,ob);
	    atc_kill_yeah();
	    message("vision",""HIY""+mename+"右手剑意未尽，左手早已撤掌回力，向着"+obname+"再次拍出！\n"NOR,ob);
	    atc_kill_yeah();
	    message("vision",""HIY""+mename+"利剑自左向右斜拉而下，此招已是最强的杀着！\n"NOR,ob);
	    atc_kill_yeah();
	    return;
	}

	if(me_power>=15)
	{
	    message("vision","\n"HIC"只听得"+mename+"猛地大喝一声，剑交左手逼近"+obname+"，右掌急向"+obname+"天灵拍下！\n\n\n"NOR,ob);
	    me_power-=(10+random(6));
	    me_busy=(4+random(3));
	    me_gjl=(15+random(16)+(level-2));
	    obhp-=(me_gjl/2);  // 这个绝招使出，是绝对会让对方受点儿伤的 ：）
	    atc_kill_yeah();
	    message("vision",""HIC""+mename+"“天灵掌”施展完毕，当即收式回身，跃了开去。\n\n"NOR,ob);
	    return;
	}
}

void atc_jianyi()
{
	object ob=this_object();
	me_gjl=(5+random(6)+(level-2));
//	me_power=0;

	if(games!="busy")
	{
	    if(obhp<1) message("vision",""HIC""+mename+"「哈哈」大笑几声，收式回剑。\n"NOR,ob);
	    if(mehp<1 && obhp>0) message("vision",HIC"只见"+mename+"还未使完“剑意连绵十三式”，自己却已被打倒了。\n"NOR,ob);
	    if(mehp<1 && obhp<1) message("vision",HIC"只见"+mename+"和"+obname+"双双倒下，“剑意连绵十三式”嘎然而止！\n"NOR,ob);
	    if(mehp>1 && obhp>1) message("vision",HIC"比赛时间已到，"+mename+"硬生生地收住了“剑意连绵十三式”，回剑当胸而立。\n"NOR,ob);
	    return;
	}

	if(temp==0) message("vision",HIC"\n忽地只见"+mename+"清啸一声，剑转变幻，刹那间无尽剑意已将"+obname+"重重围绕！\n\n\n"NOR,ob);

	if(temp==12)
	{
		message("vision",HIC"\n"+mename+"手中之剑剑光陡长，只听得「唰唰」几声，已使出了“剑意连绵十三式”之最强一招！\n"NOR,ob);
		obhp-=(me_gjl*(1+random(3))+random(me_gjl+1));
		message("vision",""HIR""+obname+"被剑影笼罩，似已忘了躲闪，惨叫一声之下只见鲜血四溅，已然中招！\n"NOR,ob);
		ck_hp();
		temp_kill="free";
		temp=0;
		me_power=0;
		return;
	}

	if(temp>=0)
	{
		message("vision",HIY"只见"+mename+"手中剑意连绵不绝，变幻无方，直逼得"+obname+"喘不过气来！\n"NOR,ob);
		atc_kill_yeah();
		ck_hp();
		temp++;

		me_power=((13-temp)*2);
		call_out("atc_jianyi",1);
	}
}


void atc_kill_yeah()
{
	object ob=this_object();
	switch(random(4))
	{
		case 0:message("vision",""HIR""+obname+"只觉迫力重重，登时动弹不得，应招而中！\n\n"NOR,ob);
		obhp-=(me_gjl+random(me_gjl+1));
		break;
		case 1:message("vision",""YEL""+obname+"急切躲闪，总算卸去大半力道，但仍是颇受创伤！\n\n"NOR,ob);
		obhp-=((me_gjl+random(me_gjl+1))/2);
		break;
		case 2:message("vision",WHT"刹那间只见"+obname+"闪身躲过，身法之快简直匪夷所思！\n\n"NOR,ob);
		break;
		case 3:message("vision",""YEL""+obname+"急切躲闪，总算卸去大半力道，但仍是颇受创伤！\n\n"NOR,ob);
		obhp-=((me_gjl+random(me_gjl+1))/2);
		break;
	}
}

void games_free()
{
	games="free";
}

void win_lose()
{
	object jj_s,jj_g,ob,me;
	int jj_all,tempa,tempb,temp_time;

	ob=this_object();
	me=this_player();
	jj_s=new("/clone/money/silver");
	jj_g=new("/clone/money/gold");

	if(nowtime>0) message("vision",HIM"有人倒下了！比赛结束！！！\n"NOR,ob);
	message("vision",HIM"台上的人影渐渐朦胧，消失不见了。\n"NOR,ob);
	time_goon="no";
	games="wait";
	call_out("games_free",5);
	temp_time=nowtime;
	nowtime=0;
	obtime=0;
	temp_id="none";

	if(mehp<1 && obhp<1)
	{
		message("vision",HIW"本局比赛，"+mename+"及"+obname+"都被攻击致死了，是为平局。请"+mename+"取回报名时所交黄金。\n"NOR,ob);
		jj_g->set_amount(1);
// 描述更改。		message("vision",HIW"只见机器里“叮”地一声抛出了一两"NOR+HIY"黄金"NOR+HIW"。\n"NOR,ob);
		message("vision",HIW"只见机器里“叮”地一声抛出了一两"NOR+HIY"黄金"NOR+HIW"，"+mename+"乐滋滋地收了起来。\n"NOR,ob);
// 改为直接给钱给玩家及描述更改。		jj_g->move(environment(me));
		jj_g->move(me);  // 这句是直接给玩家奖金的。
		t_jj++;
		message("vision",HIW"希望本游戏给您带来快乐，谢谢！ ：） \n"NOR,ob);
		return;
	}
	
	if(mehp<1 && obhp>0)
	{
		message("vision",HIW"本局比赛，玩家"+mename+"被游戏人物"+obname+"打败了，欢迎下次再来！\n"NOR,ob);
		message("vision",HIW"希望本游戏给您带来快乐，谢谢！ ：） \n"NOR,ob);
		return;
	}

	if(mehp>0 && obhp<1)
	{
//		jj_all=((temp_time*((mehp+me_power)/2))*2/3+100); // 这是比较难的赔率 :)
		jj_all=((temp_time/2)*((mehp+me_power)/2)+100);
		if(auto_hp=="yes")
		{
			write(HIG"你本局比赛你选择了自动状态显示，总奖金为"+jj_all+"两的9/10。\n"NOR);
			jj_all=(jj_all*9/10);
		}

// 这是比较容易的赔率 :) 全满时为4000两银子： 即 60*((100+30)/2)+100 = 4000 .

		message("vision",HIW"本局比赛，玩家"+mename+"获得了胜利！！！\n"NOR,ob);
		message("vision",HIW"用时"+(60-temp_time)+"秒；剩余气息"+mehp+"点；剩余力量"+me_power+"点，奖金为"+jj_all+"两白银！！！\n"NOR,ob);
		message("vision",HIW"请"+mename+"拿取应得的奖金！祝贺你！\n"NOR,ob);
// 更改描述。		message("vision",HIW"只见机器里“叮”地一声抛出了一些"NOR+HIY"奖金"NOR+HIW"！\n"NOR,ob);
		message("vision",HIW"只见机器里“叮”地一声抛出了一些"NOR+HIY"奖金"NOR+HIW"，"+mename+"乐滋滋地收了起来。\n"NOR,ob);

// log 文件记录。
	        log_file("duchang/KILL_GAME", sprintf("%s(%s)于%s玩虚拟战斗游戏获得 %d 两白银。\n",
                me->query("name"), getuid(me), ctime(time()), jj_all));


		if(jj_all>top_high)
		{
			top_times++;
			message("vision",HIW"\n恭喜"+mename+"破了由"+top_name+"创造的"+top_high+" 点的最佳记录！"+mename+"的新记录是："+jj_all+"点，恭喜恭喜！\n\n"NOR,ob);
			CHANNEL_D->do_channel(me, "rumor", sprintf(HIY"%s以"NOR+HIG""+jj_all+""NOR+HIY"点的成绩，破了由"NOR+HIG""+top_name+""NOR+HIY"保持的"NOR+HIG""+top_high+""NOR+HIY"点的最佳记录！\n"NOR, me->query("name")));
			CHANNEL_D->do_channel(me, "rumor", sprintf(HIY"恭喜%s成为赌场虚拟战斗游戏中第"+top_times+"代王者！\n"NOR,me->query("name")));
			me->set_temp("duchang/king",top_times);
			top_high=jj_all;
			top_name=(me->query("name"));
			top_win();
		}

		if(jj_all>99)
		{
			tempa=(jj_all/100);
			tempb=(jj_all-tempa*100);
			jj_s->set_amount(tempb);
			jj_g->set_amount(tempa);
// 改为直接给玩家奖金。			jj_g->move(environment(me));
			jj_g->move(me); // 直接给奖金。
			t_jj+=tempa;
			t_jjs+=tempb;
		}

		else
		{
			jj_s->set_amount(jj_all);
			t_jjs+=jj_all;
		}

// 改为直接给玩家奖金。		jj_s->move(environment(me));
		jj_s->move(me); // 直接给奖金。
		return;
	}

	if(mehp>0 && obhp>0)
	{
		message("vision",HIW"本局比赛时间已到，" + mename + "及" + obname + "都未致死，将以气息高者为胜。\n"NOR,ob);

		if(mehp<obhp)
		{
		    message("vision",""HIW""+obname+"的气息较高，因此，本局比赛"+mename+"输了！\n"NOR,ob);
		    message("vision",HIW"希望本游戏给您带来快乐，谢谢！ ：） \n"NOR,ob);
		    return;
		}

		if(mehp==obhp)
		{
		    message("vision",HIW"两者气息值同样！是为平局。请取回报名时所交黄金。\n"NOR,ob);
		    jj_g->set_amount(1);

// 改描述。		    message("vision",HIW"只见机器里“叮”地一声抛出了一些"NOR+HIY"奖金"NOR+HIW"。\n"NOR,ob);
		    message("vision",HIW"只见机器里“叮”地一声抛出了一些"NOR+HIY"奖金"NOR+HIW"，"+mename+"乐滋滋地收了起来。\n"NOR,ob);
// 直接给玩家奖金。		    jj_g->move(environment(me));
		    jj_g->move(me); // 直接给奖金。
		    t_jj+=1;
		    message("vision",HIW"希望本游戏给您带来快乐，谢谢！ ：） \n"NOR,ob);
		    return;
		}

		if(mehp>obhp)
		{
		    jj_all=(mehp+me_power);
		    message("vision",""HIW""+mename+"的气息较高，取得了本局比赛的胜利！！奖金为安慰奖 "+jj_all+"两银子！\n"NOR,ob);
		    jj_s->set_amount(jj_all);
		    message("vision",HIW"只见机器里“叮”地一声抛出了一些"NOR+HIW"白银"NOR+HIW"。\n"NOR,ob);
		    jj_s->move(environment(me));
		    t_jjs+=jj_all;
		    message("vision",HIW"希望本游戏给您带来快乐，谢谢！ ：） \n"NOR,ob);
		    return;
		}

	}

}

void top_win()
{
	object me,win_ob,me_ring;
	me=this_player();
	win_ob=new(__DIR__"obj/ring_king");
	me_ring=present("wangzhe ring",me);

	if(!me_ring)
	{
		win_ob->set("long","这是一个流光四射的指环，上面刻着一圈极小的字：第"+(int)me->query_temp("duchang/king")+"代虚拟战斗之王"+me->query("name")+"。\n你可以对着它回忆（huiyi）取得戒指时的那种成就感。\n");
		win_ob->set("king_times",top_times);
		win_ob->move(me);
		message_vision(HIW"$N得到了一枚 "NOR+HIY"王者之戒"NOR+HIW" ！\n"NOR,me);
		return;
	}

	me_ring->set("long","这是一个流光四射的指环，上面刻着一圈极小的字：第"+(int)me->query_temp("duchang/king")+"代虚拟战斗之王"+me->query("name")+"。\n你可以对着它回忆（huiyi）取得戒指时的那种成就感。\n");
	me_ring->set("king_times",top_times);
	message_vision(HIW"$N身上的"NOR+HIY"王者之戒"NOR+HIW"似乎发出了一声欢呼！\n"NOR,me);
}
