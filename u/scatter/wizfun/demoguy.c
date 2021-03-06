// Code by Scatter
// demoguy.c
#include <ansi.h>
inherit NPC;

int ask_demo();
void do_menpai();
void do_job();
void do_cmds();
void do_weapon();
void do_chat();
void do_other();
void wudang_menu();
void wudang_bai();
void wudang_job_one();
void xx_menu();
void xingxiu_bai();
void xingxiu_job_one();

void create()
{
        set_name("新手帮助精灵", ({ "newbie wizard", "newbie", "wizard" }));
        set("gender", "男性");
        set("age", 25);
        set("long", "他是神州特派的新手协助员。\n");
 
		set("inquiry",
		([ 
			"demo" : (: ask_demo :),
		])); 


        set("combat_exp", 7000);
        set("shen_type", -1);
        set("attitude", "heroism");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}


int ask_demo()
{
	object me=this_player(), obnpc=this_object();
	command("say 好吧，那我一定会尽我所能帮助你的．");
	write("-----------------------------------------------------------------------\n");
	write("|" + HIW + "                         神州新手帮助一览表                        " + NOR + "  |\n");
	write("-----------------------------------------------------------------------\n");
	write("| 1) 门派类                                                           |\n");
	write("| 2) 工作类                                                           |\n");
	write("| 3) 指令类                                                           |\n");
	write("| 4) 武器类                                                           |\n");
	write("| 5) 聊天类                                                           |\n");
	write("| 6) 其他类                                                           |\n");
	write("-----------------------------------------------------------------------\n");
	write("| 请选择 select <号码>  (例如: select 1)                              |\n");
	write("-----------------------------------------------------------------------\n");
	write("\n");

	add_action("do_basemenu", "select");
	return 1;
}

int do_basemenu(string choi)
{
	object me=this_player(), obnpc=this_object();
	int arg;
	arg = atoi(choi);

	if(!arg)
	{
		write("请输入你要的选择 (select <号码>)\n");
		return 1;
	}

	remove_action("do_basemenu", "select");

	if( arg == 1 )
	{
		do_menpai();
	}

	else if(arg == 2)
	{
		do_job();
	}
	
	else if(arg == 3)
	{
		do_cmds();
	}
	
	else if(arg == 4)
	{
		do_weapon();
	}

	else if(arg == 5)
	{
		do_chat();
	}

	else if(arg == 6)
	{
		do_other();
	}
	else
	{
		write("请输入你要的选择 (select <号码>)\n");
		add_action("do_basemenu", "select");
		return 1;
	}
	return 1;
}


void do_menpai()
{
	object me=this_player(), obnpc=this_object();
	write("-----------------------------------------------------------------------\n");
	write("|" + HIW + "                         神州新手帮助一览表                        " + NOR + "  |\n");
	write("-----------------------------------------------------------------------\n");
	write("| **************                                                      |\n");
	write("| *   门派类   *                                                      |\n");
	write("| **************                                                      |\n");
	write("| 1)  少林派 (还未开放)                                               |\n");
	write("| 2)  丐帮   (还未开放)                                               |\n");
	write("| 3)  星宿派                                                          |\n");
	write("| 4)  峨嵋派 (还未开放)                                               |\n");
	write("| 5)  大理段氏 (还未开放)                                             |\n");
	write("| 6)  古墓派   (还未开放)                                             |\n");
	write("| 7)  武当派                                                          |\n");
	write("| 8)  白驼     (还未开放)                                             |\n");
	write("| 9)  华山派   (还未开放)                                             |\n");
	write("| 10) 密宗(雪山派)  (还未开放)                                        |\n");
	write("| 11) 神龙教   (还未开放)                                             |\n");
	write("| 12) 桃花     (还未开放)                                             |\n");
	write("| 13) 全真教   (还未开放)                                             |\n");
	write("-----------------------------------------------------------------------\n");
	write("| 请选择 select <号码>  (例如: select 1)                              |\n");
	write("-----------------------------------------------------------------------\n");
	write("\n");

	add_action("do_selectmenpai", "select");

	return;
}

int do_selectmenpai(string selnum)
{
	object me=this_player(), obnpc=this_object();
	int arg;
	arg = atoi(selnum);

	if(!arg)
	{
		write("请输入你要的选择 (select <号码>)\n");
		return 1;
	}

	remove_action("do_selectmenpai", "select");

	if( arg == 1 )
	{
		write("还未开放");
	}

	else if (arg == 2)
	{
		write("还未开放");
	}

	// 3 = 星宿
	else if (arg == 3)
	{
		xx_menu();
	}

	else if (arg == 4)
	{
		write("还未开放");
	}

	else if (arg == 5)
	{
		write("还未开放");
	}

	else if (arg == 6)
	{
		write("还未开放");
	}

	// 7 = 武当
	else if (arg == 7)
	{
		wudang_menu();
	}

	else if (arg == 8)
	{
		write("还未开放");
	}

	else if (arg == 9)
	{
		write("还未开放");
	}

	else if (arg == 10)
	{
		write("还未开放");
	}
	
	else if (arg == 11)
	{
		write("还未开放");
	}

	else if (arg == 12)
	{
		write("还未开放");
	}
	
	else if (arg == 13)
	{
		write("还未开放");
	}

	else
	{
		write("请输入你要的选择 (select <号码>)\n");
		add_action("do_selectmenpai", "select");
		return 1;
	}
	return 1;
}


//********************************************
//XX MENU (START)
//********************************************
void xx_menu()
{
	object me=this_player(), obnpc=this_object();
	write("-----------------------------------------------------------------------\n");
	write("|" + HIW + "                         神州新手帮助一览表                        " + NOR + "  |\n");
	write("-----------------------------------------------------------------------\n");
	write("| **************                                                      |\n");
	write("| *   星宿派   *                                                      |\n");
	write("| **************                                                      |\n");
	write("| 1) 如何拜入星宿                                                     |\n");
	write("| 2) 星宿工作系统 (扣虫)                                              |\n");
	write("-----------------------------------------------------------------------\n");
	write("| 请选择 select <号码>  (例如: select 1)                              |\n");
	write("-----------------------------------------------------------------------\n");
	write("\n");

	add_action("xingxiu_selmenu", "select");

	return;

}



int xingxiu_selmenu(string selnum)
{
	object me=this_player(), obnpc=this_object();
	int arg;
	arg = atoi(selnum);

	if(!arg)
	{
		write("请输入你要的选择 (select <号码>)\n");
		return 1;
	}

	remove_action("xingxiu_selmenu", "select");

	if( arg == 1 )
	{
		xingxiu_bai();
	}

    else if (arg == 2)
	{
		xingxiu_job_one();
	}

	else
	{
		write("请输入你要的选择 (select <号码>)\n");
		add_action("xingxiu_selmenu", "select");
		return 1;
	}
	return 1;
}

//*************************
//如何拜入星宿 START
//*************************

void xingxiu_bai()
{
	object me=this_player(), obnpc=this_object();
	command("say 那现在就带你去看看如何拜入星宿吧");
	me->start_busy(30000);
	remove_call_out("xingxiu_bai_s1");
	call_out("xingxiu_bai_s1", 4, me, obnpc); 
	return;
}

void xingxiu_bai_s1(object me, object obnpc)
{
	me->move("/d/xingxiu/tianroad3");
	obnpc->move("/d/xingxiu/tianroad3");
	command("say 其实拜入星宿是很简单的");
	command("poke azi");
	command("say 只要打 bai azi 就可以了让我表演一次给你看");
	remove_call_out("xingxiu_bai_s2");
	call_out("xingxiu_bai_s2", 10, me, obnpc); 
	return;
}

void xingxiu_bai_s2(object me, object obnpc)
{
	write(HIY"***** 打入 <bai azi> *****\n"NOR);
	write("你想要拜阿紫为师。\n"+ CYN +"阿紫说道：好吧，我就收下你了。\n"+ NOR +"阿紫决定收你为弟子。\n\n你跪了下来向阿紫恭恭敬敬地磕了四个响头，叫道：「师父！」\n恭喜您成为星宿派的第三代弟子。\n");
	command("say 这样你就成为星宿派三代弟子了");
	remove_call_out("xingxiu_bai_s3");
	call_out("xingxiu_bai_s3", 17, me, obnpc); 
	return;
}

void xingxiu_bai_s3(object me, object obnpc)
{
	command("say 拜入星宿没有经验值得限制, 但是如果你是盖帮弟子, 那星宿可不会收你为徒喔");
	command("xixi");
	remove_call_out("do_end");
	call_out("do_end", 5, me, obnpc); 
	return;
}
//*************************
//如何拜入星宿 END
//*************************





//*************************
//星宿工作系统 START
//*************************
void xingxiu_job_one()
{
	object me=this_player(), obnpc=this_object();
	command("say 那现在就带你去看看星宿的工作系统吧");
	me->start_busy(30000);
	remove_call_out("xingxiu_job1_s1");
	call_out("xingxiu_job1_s1", 4, me, obnpc); 
	return;
}

void xingxiu_job1_s1(object me, object obnpc)
{
	me->move("/d/xingxiu/riyuedong");
	obnpc->move("/d/xingxiu/riyuedong");
	command("say 这里就是星宿扣虫工做的第一现场");
	command("say 如果想开始工作可以 ask ding about job");
	command("say 让我表演一次给你看吧");
	remove_call_out("xingxiu_job1_s2");
	call_out("xingxiu_job1_s2", 7, me, obnpc); 
	return;
}

void xingxiu_job1_s2(object me, object obnpc)
{
	write(HIY"***** 打入 <ask ding about job> *****\n"NOR);
	write("你向丁春秋打听有关『job』的消息。\n"+ CYN +"丁春秋说道：「老仙我最近练功需要一些毒丹，你到后山拿些来给我吧。」\n"+ NOR +"丁春秋顺手从身后架子上取出一个小瓦罐扔给你。\n"+ CYN +"丁春秋说道：「快去快回，路上小心。」\n"NOR);
	command("say 这个时候身上就会多一个东西叫做  瓦罐(Wa guan)");
	remove_call_out("xingxiu_job1_s3");
	call_out("xingxiu_job1_s3", 10, me, obnpc);
	return;
}

void xingxiu_job1_s3(object me, object obnpc)
{
	command("say 拿到瓦灌后就可以开始寻找虫了, 从这里 s, nw, ne, n 可以到星宿后面的丛林");
	remove_call_out("xingxiu_job1_s4");
	call_out("xingxiu_job1_s4", 5, me, obnpc);
	return;
}

void xingxiu_job1_s4(object me, object obnpc)
{
	me->move("/d/xingxiu/forest1");
	obnpc->move("/d/xingxiu/forest1");
	command("say 到这里可以打 search here 开始搜寻");
	command("say 我表演一次给你看");
	remove_call_out("xingxiu_job1_s5");
	call_out("xingxiu_job1_s5", 4, me, obnpc);
	return;
}
	
void xingxiu_job1_s5(object me, object obnpc)
{
	write(HIY"***** 打入 <search bug> *****\n"NOR);
	write("你弯下了腰，伸手将残枝败叶拨开，仔细寻找毒虫的踪迹。\n");
	command("say 如果没有虫出来就继续打 search bug");
	remove_call_out("xingxiu_job1_s6");
	call_out("xingxiu_job1_s6", 6, me, obnpc);
	return;
}

void xingxiu_job1_s6(object me, object obnpc)
{
	write(HIY"***** 打入 <search bug> *****\n"NOR);
	write("你弯下了腰，伸手将残枝败叶拨开，仔细寻找毒虫的踪迹。\n"+ HIG +"突然间一只小虫子钻了出来，迅速地爬动着。\n"NOR);
	write(HIR"朱睛蛙"+NOR+"(Zhu wa)\n");
	write(HIY"***** 打入 <kou wa> *****\n"NOR);
	command("say 这样就完成了");
	remove_call_out("do_end");
	call_out("do_end", 10, me, obnpc);
	return;
}
//*************************
//星宿工作系统 END
//*************************





//********************************************
//WD MENU (START)
//********************************************
void wudang_menu()
{

	object me=this_player(), obnpc=this_object();
	write("-----------------------------------------------------------------------\n");
	write("|" + HIW + "                         神州新手帮助一览表                        " + NOR + "  |\n");
	write("-----------------------------------------------------------------------\n");
	write("| **************                                                      |\n");
	write("| *   武当派   *                                                      |\n");
	write("| **************                                                      |\n");
	write("| 1) 如何拜入武当                                                     |\n");
	write("| 2) 武当工作系统 (守门)                                              |\n");
//	write("| 3) 武当工作系统 (面壁)   (还未开放)                                 |\n");
//	write("| 4) 武当人物介绍 (NPC)    (还未开放)                                 |\n");
	write("-----------------------------------------------------------------------\n");
	write("| 请选择 select <号码>  (例如: select 1)                              |\n");
	write("-----------------------------------------------------------------------\n");
	write("\n");

	add_action("wudang_selmenu", "select");

	return;

}

int wudang_selmenu(string selnum)
{
	object me=this_player(), obnpc=this_object();
	int arg;
	arg = atoi(selnum);

	if(!arg)
	{
		write("请输入你要的选择 (select <号码>)\n");
		return 1;
	}

	remove_action("wudang_selmenu", "select");

	if( arg == 1 )
	{
		wudang_bai();
	}

	else if (arg == 2)
	{
		wudang_job_one();
	}
/*
	else if (arg == 3)
	{
		//wudang_job_two();
	}

	else if (arg == 4)
	{
		//wudang_npc();
	}
*/
	else
	{
		write("请输入你要的选择 (select <号码>)\n");
		add_action("wudang_selmenu", "select");
		return 1;
	}
	return 1;
}




//*************************
//如何拜入武当 START
//*************************
void wudang_bai()
{
	object me=this_player(), obnpc=this_object();
	command("say 那现在就带你去看看如何拜入武当吧");
	me->start_busy(30000);
	remove_call_out("wudang_bai_s1");
	call_out("wudang_bai_s1", 4, me, obnpc); 
	return;
}

void wudang_bai_s1(object me, object obnpc)
{
	me->move("/d/wudang/shanmen");
	obnpc->move("/d/wudang/shanmen");
	command("say 这里就是武当正门了");
	command("poke zhike");
	command("say 他就是你第一个要拜的人");
	command("say 要拜他可以打入 bai zhike");
	command("say 我现在表演一次给你看");
	remove_call_out("wudang_bai_s2");
	call_out("wudang_bai_s2", 10, me, obnpc); 
	return;
}

void wudang_bai_s2(object me, object obnpc)
{
	write(HIY"***** 打入 <bai zhike> *****\n"NOR);
	write("你想要拜灵虚道长为师。\n");
	write(CYN"灵虚道长说道：我武当之所以能在武林中兴不衰，全靠各弟子自觉效力。\n"NOR);
	write(CYN"灵虚道长说道：入门习武以前，老爷子是否愿意为武当主动做些事情？\n"NOR);
	write(HIY"如果你答应的话，键入＂愿意＂二字。\n"NOR);
	write(HIY"***** 打入 <愿意> *****\n"NOR);
	command("say 这个时候你会看到以下的讯息");
	remove_call_out("wudang_bai_s3");
	call_out("wudang_bai_s3", 20, me, obnpc); 
	return;
}

void wudang_bai_s3(object me, object obnpc)
{
	write("你大声说道：愿意！\n");
	write(CYN"灵虚道长「哈哈哈」大笑几声。\n灵虚道长说道：很好！很好！从今日起，你就是武当一名见习学徒。\n灵虚道长说道：希望老爷子勤加努力，早日入我正门中。\n"NOR);
	command("say 此时你算是半个武当弟子了, 等到你做守门工作五次后可以再打一次 bai zhike");
	command("say 等到第二次 bai zhike 成功了你就算正式武当四代弟子了");
	remove_call_out("do_end");
	call_out("do_end", 25, me, obnpc); 
	return;
}
//*************************
//如何拜入武当 END
//*************************



//*************************
//武当工作系统 (守门) START
//*************************
void wudang_job_one()
{
	object me=this_player(), obnpc=this_object();
	command("say 那现在就带你去看看如何做武当的守门工作吧");
	me->start_busy(30000);
	remove_call_out("wudang_job1_s1");
	call_out("wudang_job1_s1", 4, me, obnpc); 
	return;
}

void wudang_job1_s1(object me, object obnpc)
{
	me->move("/d/wudang/shanmen");
	obnpc->move("/d/wudang/shanmen");
	command("say 这里就是武当正门了");
	command("say 这里也就是武当守门工作的地方");
	command("say 要开始守门可以打入 volunteer");
	command("say 我现在表演一次给你看");
	remove_call_out("wudang_job1_s2");
	call_out("wudang_job1_s2", 10, me, obnpc); 
	return;
}

void wudang_job1_s2(object me, object obnpc)
{
	write(HIY"***** 打入 <volunteer> *****\n"NOR);
	write("你想自愿为知客道长守卫山门。\n" + CYN + "知客道长高兴对你说道：来得正好，这里正缺人手。\n灵虚道长说道：你就在这里好好看门吧，可别让那些邪魔歪道的人混进去！\n"NOR);
	command("say 这个时候你就开始守门了, 每次守门约 5 分钟左右");
	write("\n\n~~~~~~~~~ 五分钟后 ~~~~~~~~~~~\n\n");
	remove_call_out("wudang_job1_s3");
	call_out("wudang_job1_s3", 20, me, obnpc);
	return;
}

void wudang_job1_s3(object me, object obnpc)
{
	command("say 当做完守门时会看到以下讯息");
	write("知客道长对你说道：换班时间到，你可以走了！\n"+ CYN +"灵虚道长说道：你如此自愿为武当效力，日后必成武当栋梁！\n灵虚道长对着你竖起了右手大拇指，好样的。\n"NOR);
	command("say 这样就算成功的做完一次武当守门工作了");
	remove_call_out("do_end");
	call_out("do_end", 22, me, obnpc);
}
//*************************
//武当工作系统 (守门) END
//*************************


void do_job()
{
	object me=this_player(), obnpc=this_object();
	write("Jobs\n");
	return;
}


void do_cmds()
{
	object me=this_player(), obnpc=this_object();
	write("Commands\n");
	return;
}

void do_weapon()
{
	object me=this_player(), obnpc=this_object();
	write("Weapon\n");
	return;
}


void do_chat()
{
	object me=this_player(), obnpc=this_object();
	write("Chat\n");
	return;
}

void do_other()
{
	object me=this_player(), obnpc=this_object();
	write("Other\n");
	return;
}





//****************
//* END CLEAN UP *
//****************

void do_end(object me, object obnpc)
{
	me->move("/d/city/wumiao");
	obnpc->move("/d/city/wumiao");
	command("say 谢谢您使用新手帮助 NPC (V. 1.0 BETA)");
	me->start_busy(-30000);
	return;
}