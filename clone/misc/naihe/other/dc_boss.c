// 赌场的boss  :)  ★/npc/dc_boss.c
// by naihe  2002-04-30
// 最后修改：2002-05-12 naihe
// 请勿更改本文件源码，谢谢！
// 没钱时移动的位置所在行是：131、132、261、262、615、616

#include <ansi.h>
string ask_duju();
inherit NPC;

int t_beta,t_playa,t_wina,t_betb,t_playb,t_winb,t_betc,t_playc,t_winc;
string gtz="open";
string gdn="open";
string gyz="open";

void create()
{
	set_name("爱琳·聂",({"eileen nei","eileen","duchang boss"}));
	set("long","她就是这家赌场的老板，有着金黄色的卷头发和深邃的蓝眼珠，个子高佻，
衬着身上华贵的露背长裙，浑身都散发着成熟而妩媚的气息。你看了不禁
暗自赞叹，原来西洋的美女竟然如此艳丽动人。\n\n");
	set("gender","女性");
	set("title","泊来赌场");
	set("age",25);
	set("attitude","friendly");
	set("combat_exp",520);
	set_skill("literate",201);
	set_skill("force",20);
	set_skill("music",401);
set("no_refresh",1);
	set("inquiry",([
	    "name":"My name is Eileen nei. Hi~~",
	    "here":"呵呵，这儿可是贵宾房，有理没钱可不要进来哟。",
	    "rumors":"哎，赌场的生意比较忙，我没什么机会到处去走走，所以没听过什么新鲜的事。",
	    "赌场":"我在西方的时候就听说了神州里边的好多事情，觉得很有意思，
              就一直都想着要来这里生活。",
	    "丈夫":"我还没有结婚，但是有心爱的人了哟。",
	    "husband":"I'm not marry,but I have my sweet heart now.",
	    "生意":"输赢只是小事，能够结交朋友才是最重要的啊。",
    "赌局": (: ask_duju :),
	    "斗牛":"嗯，墙上帖着赌局的规矩，你看好了就开始吧！",
	    "骰子":"嗯，墙上帖着赌局的规矩，你看好了就开始吧！",
	    "一张定输赢":"嗯，墙上帖着赌局的规矩，你看好了就开始吧！",
	    ]));

	setup();
        carry_object(__DIR__"obj/dress")->wear();
}

  string ask_duju()
  {
          object me = this_player();

          if(wizardp(me))
          {
                  write("wiz可以用mewiz <游戏> <状态>来开放或关闭某项游戏。\n");
                  write("wiz可以用xxxxx 查询当前游戏进行状态。\n");
          }

          return "呵，你要来赌一局吗？骰子、斗牛、一张定输赢，随便你挑吧！\n";
  }
void init()
{
        ::init();
        if (wizardp(this_player()))  add_action("do_xxxxx", "xxxxx"); // wiz 可以查询总值。
	if (wizardp(this_player()))  add_action("do_mewiz", "mewiz"); 
// wiz 可以设定开放或关闭某个游戏。
        add_action("do_touzi", "touzi");
	add_action("do_douniu", "douniu");
	add_action("do_yizhang","yizhang");
}   // 这里是第50行。

int do_mewiz(string arg)
{
	string gname,gnow;
	if (!arg || sscanf(arg, "%s %s", gname, gnow) !=2)
	return notify_fail("格式：mewiz <touzi/douniu/yizhang> <open/close>\n");

	if(gnow!="open" && gnow!="close")
	return notify_fail("格式：mewiz <touzi/douniu/yizhang> <open/close>\n");

	if(gname == "touzi")
	{
		gtz=gnow;
		write("game 'touzi' is " + gnow + " .\n");
		return 1;
	}

	if(gname == "douniu")
	{
		gdn=gnow;
		write("game 'douniu' is " + gnow + " .\n");
		return 1;
	}

	if(gname == "yizhang")
	{
		gyz=gnow;
		write("game 'yizhang' is " + gnow + " .\n");
		return 1;
	}
	write("格式：mewiz <touzi/douniu/yizhang> <open/close>\n");
	return 1;
}

int do_xxxxx()
{
	int tempsa,tempsb,tempsc;
	tempsa = (t_beta-t_wina);
	tempsb = (t_betb-t_winb);
	tempsc = (t_betc-t_winc);
     	write(""HIG"骰子游戏次数："+t_playa+ "次  利润："+tempsa+" 金 。\n总收入："+t_beta+" 金  总支出："+t_wina+" 金。"NOR"\n");
     	write(""HIY"斗牛游戏次数："+t_playb+ "次  利润："+tempsb+" 金 。\n总收入："+t_betb+" 金  总支出："+t_winb+" 金。"NOR"\n");
     	write(""HIC"一张定输赢游戏次数："+t_playc+ "次  利润："+tempsc+" 金 。\n总收入："+t_betc+" 金  总支出："+t_winc+" 金。"NOR"\n");
	return 1;
}

int do_touzi(string arg)
{
	object me,qian,jj;
	int jjout,betmoney,mea,meb,mec,oba,obb,obc,meall,oball,mepower,obpower;
	string betname;
	me=this_player();
	qian=present("gold_money", me);
	jj=new("/clone/money/gold");

	if(gtz !="open")
		return notify_fail("嗯……今天我不想赌这些，还是赌点别的吧。\n");

	if (time()-query_temp("playtime")<3)
	{
	tell_object(me,"上一局赌局才刚完，先等一会吧。\n");
	return 1;
	}

	if(!qian)
	{
		command("say 开玩笑吧，没钱也来这里添乱？护卫！");
                message_vision(""HIY"只见两个护卫走了进来，把$N往外架了出去。"NOR"\n",me);
		me->set("jingli",1);
		me->set("neili",1);
		me->set("qi",1);
		me->set("jing",1);
		me->set("food",20);
//                me->set("water",20);
//                me->move("/d/city/dc_dating");
              me->move("/clone/misc/naihe/dc_dating");
            message_vision(""HIY"$N从贵宾房里给轰了出来。"NOR"\n",me);
		return 1;
	}

	if (!arg || sscanf(arg, "%d %s", betmoney,betname) !=2) 
	return notify_fail("请看看赌局的规矩再开始吧！\n");

	if(betname != "gold") return notify_fail("请看看赌局的规矩再开始吧！\n");

	if(betmoney<1) return notify_fail("怎么？你的意思是如果我赢就给钱给你？\n");
	if(betmoney>10) return notify_fail("啊，这赌注似乎大了点，我就怕您输不起哪。\n");

	if((int)qian->query_amount() < betmoney*5)
	return notify_fail("你带的钱好象不太够吧……摆阔气也要看实力嘛。\n");

	t_playa++;
	message_vision(""HIY"$N拿出"+betmoney+"两黄金往桌上一放，说道：“我和你来一局比骰子！”"NOR"\n",me);

	mea=(1+random(6));
	meb=(1+random(6));
	mec=(1+random(6));
	meall=(mea+meb+mec);
	write("闲家开的点数为："+mea+" "+meb+" "+mec+" ，共"+meall+"点！\n",me);
	mepower=1;

	switch(random(2))
	{
		case 0 :
		oba=(1+random(6));
		obb=(1+random(6));
		obc=(1+random(6));
		break;

		case 1 :
		oba=(2+random(5));
		obb=(3+random(4));
		obc=(4+random(3));
		break;
	}

	oball=(oba+obb+obc);
	write("庄家开的点数为："+oba+" "+obb+" "+obc+" ，共"+oball+"点！\n",me);
	obpower=1;

	if(mea==meb && mea==mec)
	{
		mepower=5;
		write("闲家为同骰！赔率为5倍。\n",me);
	}

	if(oba==obb && oba==obc)
	{
		obpower=5;
		write("庄家为同骰！赔率为5倍。\n",me);
	}

	if(obpower!=5 && mepower==5)
	{
		jjout = (betmoney*mepower);
		jj->set_amount(jjout);
		t_wina+=jjout; // 写入记录。
		jj->move(me);
		message_vision("爱琳淡淡地说道：三个都相同者胜，这一局$N赢了"+jjout+"两黄金。运气不错嘛，再来？\n",me);
		set_temp("playtime",time());
		return 1;
	}

	if(obpower==5 && mepower!=5)
	{
		qian->add_amount(-betmoney*obpower);
		t_beta+=(betmoney*obpower); // 写入游戏历史记录。
		command("giggle");
		message_vision("爱琳微笑着说道：三个都相同者胜，$N输了"+(betmoney*obpower)+"两黄金。怎么样，再来一局吧？\n",me);
		set_temp("playtime",time());
		return 1;
	}

	if(meall>oball)
	{
		jjout = (betmoney*mepower);
		jj->set_amount(jjout);
		t_wina+=jjout; // 写入历史记录。
		jj->move(me);
		message_vision("爱琳淡淡地说道：这一局$N赢了"+jjout+"两黄金。运气不错嘛，再来？\n",me);
		set_temp("playtime",time());
		return 1;
	}

	qian->add_amount(-betmoney*obpower);
	t_beta+=(betmoney*obpower); // 写入游戏历史记录。
	command("giggle");
	message_vision("爱琳微笑着说道：$N输了"+(betmoney*obpower)+"两黄金。怎么样，再来一局吧？\n",me);
	set_temp("playtime",time());
	return 1;
}

int do_douniu(string arg)
{
	object me,qian,jj;
	int jjout,betmoney,mepower,obpower;
	int aa,ab,ac,ad,ae,aall;
	int ba,bb,bc,bd,be,ball;
	string betname,mepk,obpk,winner;

	mepower=0;
	obpower=0;
	me=this_player();
	qian=present("gold_money", me);
	jj=new("/clone/money/gold");

	if(gdn !="open")
		return notify_fail("嗯……今天我不想赌这些，还是赌点别的吧。\n");

	if (time()-query_temp("playtime")<3)
	{
	tell_object(me,"上一局赌局才刚完，先等一会吧。\n");
	return 1;
	}

	if(!qian)
	{
		command("say 开玩笑吧，没钱也来这里添乱？护卫！");
                message_vision(""HIY"只见两个护卫走了进来，把$N往外架了出去。"NOR"\n",me);
		me->set("jingli",1);
		me->set("neili",1);
		me->set("qi",1);
		me->set("jing",1);
		me->set("food",20);
		me->set("water",20);
//                me->move("/d/city/dc_dating");
              me->move("/clone/misc/naihe/dc_dating");
            message_vision(""HIY"$N从贵宾房里给轰了出来。"NOR"\n",me);
		return 1;
	}

	if (!arg || sscanf(arg, "%d %s",betmoney,betname) !=2) 
	return notify_fail("请看看赌局的规矩再开始吧！\n");

	if(betname != "gold") return notify_fail("请看看赌局的规矩再开始吧！\n");

	if(betmoney<1) return notify_fail("怎么？你的意思是如果我赢就给钱给你？\n");
	if(betmoney>10) return notify_fail("啊，这赌注似乎大了点，我就怕您输不起哪。\n");

	if((int)qian->query_amount() < betmoney*5)
	return notify_fail("你带的钱好象不太够吧……摆阔气也要看实力嘛。\n");

// 正式开始游戏了。
	t_playb++;
	message_vision(""HIY"$N拿出"+betmoney+"两黄金往桌上一放，大声说道：“我和你来一局斗牛！”"NOR"\n",me);

	aa=(1+random(13));
	ab=(1+random(13));
	ac=(1+random(13));
	ad=(1+random(13));
	ae=(1+random(13));

	ba=(1+random(13));
	bb=(1+random(13));
	bc=(1+random(13));
	bd=(1+random(13));
	be=(1+random(13));


	if(aa>10) aa=10;
	if(ab>10) ab=10;
	if(ac>10) ac=10;
	if(ad>10) ad=10;
	if(ae>10) ae=10;

	if(ba>10) ba=10;
	if(bb>10) bb=10;
	if(bc>10) bc=10;
	if(bd>10) bd=10;
	if(be>10) be=10;

	write("闲家开出的牌是："+aa+" "+ab+" "+ac+" "+ad+" "+ae+" "+"。\n",me);
	write("庄家开出的牌是："+ba+" "+bb+" "+bc+" "+bd+" "+be+" "+"。\n",me);

	if(aa==10 && ab==10 && ac==10 && ad==10 && ae==10) mepower=5;

// 下面以超级烦琐的指令判断任意三个值相加能成为10的倍数；然后确定该用哪两个剩余的数来相加。

	if(mepower==0)
	{
		if(aa+ab+ac == 10 || aa+ab+ac == 20 || aa+ab+ac == 30)
		{
			mepk="de";
			mepower=1;
		}
	}

	if(mepower==0)	
	{
		if(aa+ab+ad == 10 || aa+ab+ad == 20 || aa+ab+ad == 30)
		{
			mepk="ce";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(aa+ab+ae == 10 || aa+ab+ae == 20 || aa+ab+ae == 30)
		{
			mepk="cd";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(aa+ac+ad == 10 || aa+ac+ad == 20 || aa+ac+ad == 30)
		{
			mepk="be";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(aa+ac+ae == 10 || aa+ac+ae == 20 || aa+ac+ae == 30)
		{
			mepk="bd";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(aa+ad+ae == 10 || aa+ad+ae == 20 || aa+ad+ae == 30)
		{
			mepk="bc";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(ab+ac+ad == 10 || ab+ac+ad == 20 || ab+ac+ad == 30)
		{
			mepk="ae";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(ab+ac+ae == 10 || ab+ac+ae == 20 || ab+ac+ae == 30)
		{
			mepk="ad";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(ab+ad+ae == 10 || ab+ad+ae == 20 || ab+ad+ae == 30)
		{
			mepk="ac";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(ac+ad+ae == 10 || ac+ad+ae == 20 || ac+ad+ae == 30)
		{
			mepk="ab";
			mepower=1;
		}
	}

	if(mepower==0) mepk="other";

// 下面判断该加哪两个的值。
	if(mepk=="ab") aall=(aa+ab);
	if(mepk=="ac") aall=(aa+ac);
	if(mepk=="ad") aall=(aa+ad);
	if(mepk=="ae") aall=(aa+ae);
	if(mepk=="bc") aall=(ab+ac);
	if(mepk=="bd") aall=(ab+ad);
	if(mepk=="be") aall=(ab+ae);
	if(mepk=="cd") aall=(ac+ad);
	if(mepk=="ce") aall=(ac+ae);
	if(mepk=="de") aall=(ad+ae);

	if(aall>10) aall-=10;
	if(aall==10) mepower=3;
	if(aall==9 || aall==8) mepower=2;

	if(mepower==0) message_vision("闲家的牌没牛！\n",me);

	if(mepower>0 && mepower<5) message_vision("闲家的牌是牛"+aall+" ，赔率为"+mepower+"倍！\n",me);

	if(mepower==5) message_vision("闲家是五牛！！！赔率为"+mepower+"倍！\n",me);

// 这里上面是闲家的判断，下面是庄家的判断！！！！！！

	if(ba==10 && bb==10 && bc==10 && bd==10 && be==10) obpower=5;

// 下面以超级烦琐的指令判断任意三个值相加为10的倍数；然后确定该用哪两个剩余的数来相加。

	if(obpower==0)
	{
		if(ba+bb+bc == 10 || ba+bb+bc == 20 || ba+bb+bc == 30)
		{
			obpk="de";
			obpower=1;
		}
	}

	if(obpower==0)	
	{
		if(ba+bb+bd == 10 || ba+bb+bd == 20 || ba+bb+bd == 30)
		{
			obpk="ce";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(ba+bb+be == 10 || ba+bb+be == 20 || ba+bb+be == 30)
		{
			obpk="cd";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(ba+bc+bd == 10 || ba+bc+bd == 20 || ba+bc+bd == 30)
		{
			obpk="be";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(ba+bc+be == 10 || ba+bc+be == 20 || ba+bc+be == 30)
		{
			obpk="bd";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(ba+bd+be == 10 || ba+bd+be == 20 || ba+bd+be == 30)
		{
			obpk="bc";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(bb+bc+bd == 10 || bb+bc+bd == 20 || bb+bc+bd == 30)
		{
			obpk="ae";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(bb+bc+be == 10 || bb+bc+be == 20 || bb+bc+be == 30)
		{
			obpk="ad";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(bb+bd+be == 10 || bb+bd+be == 20 || bb+bd+be == 30)
		{
			obpk="ac";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(bc+bd+be == 10 || bc+bd+be == 20 || bc+bd+be == 30)
		{
			obpk="ab";
			obpower=1;
		}
	}

	if(obpower==0) obpk="other";

// 下面判断该加哪两个的值。
	if(obpk=="ab") ball=(ba+bb);
	if(obpk=="ac") ball=(ba+bc);
	if(obpk=="ad") ball=(ba+bd);
	if(obpk=="ae") ball=(ba+be);
	if(obpk=="bc") ball=(bb+bc);
	if(obpk=="bd") ball=(bb+bd);
	if(obpk=="be") ball=(bb+be);
	if(obpk=="cd") ball=(bc+bd);
	if(obpk=="ce") ball=(bc+be);
	if(obpk=="de") ball=(bd+be);

	if(ball>10) ball-=10;
	if(ball==10) obpower=3;
	if(ball==9 || ball==8) obpower=2;

	if(obpower==0) message_vision("庄家的牌没牛！\n",me);

	if(obpower>0 && obpower<5) message_vision("庄家的牌是牛"+ball+" ，赔率为"+obpower+"倍！\n",me);

	if(obpower==5) message_vision("庄家是五牛！！！赔率为"+obpower+"倍！\n",me);

//  开始判断胜负！	

	if(mepower>obpower) winner="player";
		else winner="npc";

	if(mepower!=1 && mepower!=0 && mepower!=2 && mepower==obpower) command("say 大家的一样，庄家赢。");

	if(mepower==1 && mepower==obpower)
	{
		if(aall>ball) winner="player";
			else winner="npc";
		if(aall==ball) command("say 大家的一样，庄家赢。");
	}
	
	if(winner=="player")
	{
		jjout = (betmoney*mepower);
		jj->set_amount(jjout);
		t_winb+=jjout;
		jj->move(me);
		message_vision("爱琳淡淡地说道：这一局$N赢了"+jjout+"两黄金。运气不错嘛，再来？\n",me);
		set_temp("playtime",time());
		return 1;
	}

	if(obpower==0 && mepower==0)
	{
		command("say 大家都没有牛，庄家赢！");
		obpower=1;
	}

	qian->add_amount(-betmoney*obpower);
	t_betb+=(betmoney*obpower); // 写入游戏历史记录。
	command("giggle");
	message_vision("爱琳微笑着说道：$N输了"+(betmoney*obpower)+"两黄金。怎么样，再来一局吧？\n",me);
	set_temp("playtime",time());
	return 1;
}


int do_yizhang(string arg)
{
	object me,qian,jj;
	int jjout,betmoney,mea,oba,meb,obb;
	string betname,winner,mehs,obhs;
	me=this_player();
	qian=present("gold_money", me);
	jj=new("/clone/money/gold");

	if(gyz !="open")
		return notify_fail("嗯……今天我不想赌这些，还是赌点别的吧。\n");

	if (time()-query_temp("playtime")<3)
	{
	tell_object(me,"上一局赌局才刚完，先等一会吧。\n");
	return 1;
	}

	if(!qian)
	{
		command("say 开玩笑吧，没钱也来这里添乱？护卫！");
                message_vision(""HIY"只见两个护卫走了进来，把$N往外架了出去。"NOR"\n",me);
		me->set("jingli",1);
		me->set("neili",1);
		me->set("qi",1);
		me->set("jing",1);
		me->set("food",20);
		me->set("water",20);
//                me->move("/d/city/dc_dating");
              me->move("/clone/misc/naihe/dc_dating");
            message_vision(""HIY"$N从贵宾房里给轰了出来。"NOR"\n",me);
		return 1;
	}

	if (!arg || sscanf(arg, "%d %s", betmoney,betname) !=2) 
	return notify_fail("请看看赌局的规矩再开始吧！\n");

	if(betname != "gold") return notify_fail("请看看赌局的规矩再开始吧！\n");

	if(betmoney<1) return notify_fail("怎么？你的意思是如果我赢就给钱给你？\n");
	if(betmoney>10) return notify_fail("啊，这赌注似乎大了点，我就怕您输不起哪。\n");

	if((int)qian->query_amount() < betmoney)
	return notify_fail("你带的钱好象不太够吧……摆阔气也要看实力嘛。\n");

	t_playc++;
	message_vision(""HIY"$N拿出"+betmoney+"两黄金往桌上一放，说道：“我和你来一局一张定输赢！”"NOR"\n",me);

	mea=(1+random(13));
	switch(random(4))
	{
		case 0 :
		mehs="◇";
		meb=0;
		break;

		case 1 :
		mehs="※";
		meb=1;
		break;

		case 2 :
		mehs="☆";
		meb=2;
		break;

		case 3 :
		mehs="▲";
		meb=3;
		break;
	}
	write("闲家开的牌是："+mehs+mea+" 。\n",me);

	switch(random(2))
	{
		case 0 :
		oba=(1+random(13));
		break;

		case 1 :
		oba=(6+random(8));
		break;
	}

	switch(random(4))
	{
		case 0 :
		obhs="◇";
		obb=0;
		break;

		case 1 :
		obhs="※";
		obb=1;
		break;

		case 2 :
		obhs="☆";
		obb=2;
		break;

		case 3 :
		obhs="▲";
		obb=3;
		break;
	}
	write("庄家开的牌是："+obhs+oba+" 。\n",me);

	if(mea==1) mea=100;
	if(oba==1) oba=100;
	if(mea>oba) winner="player";
	if(mea<oba) winner="npc";
	if(mea==oba)
	{
		if(mehs>obhs) winner="player";
		if(mehs<obhs) winner="npc";
		if(mehs==obhs) winner="none";
	}

	if(winner=="none" || winner=="player")
	{
		if(winner=="none") message_vision("爱琳惊讶地对$N说道：“大家的牌居然相同？！……一副牌里怎么会这样……\n                    这局不算，我赔偿一些黄金给你吧。\n",me);
		jjout = betmoney;
		jj->set_amount(jjout);
		t_winc+=jjout;
		jj->move(me);
		message_vision("爱琳淡淡地说道：这一局$N赢了"+jjout+"两黄金。运气不错嘛，再来？\n",me);
		set_temp("playtime",time());
		return 1;
	}

	qian->add_amount(-betmoney);
	t_betc+=(betmoney); // 写入游戏历史记录。
	command("giggle");
	message_vision("爱琳微笑着说道：$N输了"+betmoney+"两黄金。怎么样，再来一局吧？\n",me);
	set_temp("playtime",time());
	return 1;
}
/* 从一点都不懂LPC就开始做“赌场”到现在，差不多过了一个月了。想想还真是挺有
意思的经历，问人，抄别的物品的CODE，猜格式，乱写乱测试……什么手段都出来了，哈
哈。写完了这个NPC ，总算告一段落了；一个简简单单的赌场，也就是这样罢。其实很多
地方的CODE写得都挺“基本化”的——也就是很烦琐啦，哈哈哈…… 
奈何 --naihe 2002-05-06 于茂名 */
