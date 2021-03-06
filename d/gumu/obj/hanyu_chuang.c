// Program make by fengyu, Describing by Jiuer.
// /d/gumu/obj/hanyu_chuang.c.
// 2002/8/12.

#include <ansi.h>
inherit ITEM;

//公共变量定义区--------------------------------------------------------------------------------

object me,ob;

//函数定义区------------------------------------------------------------------------------------

int do_bedin();				// action 命令，上床。
int do_bedout();			// action 命令，下床。

//程序正式开始区--------------------------------------------------------------------------------

void create()
{
	set_name(HIW"寒玉床"NOR, ({"hanyu chuang","chuang","bed"}));
	set_weight(200000);
	if( clonep() )
		set_default_object(__FILE__);
	else {

		set("long","    这是古墓祖师婆婆花了七年心血，到极北苦寒之地，在数百丈坚冰"+
			   "之下挖出来\n的寒玉制成的一张上古寒玉床"+HIW"(  bed )"NOR+"，实"+
	  		   "修习上乘内功的良助。睡在这玉床上练\n功"+HIW"(  gotobed )"NOR+
		   	   "，一年抵得上平常修练的十年。床上铺了张草席，一幅白布当作薄\n"+
			   "被。如果你抵受不了此床的寒气，可以下床"+HIW"( getout )"NOR+
			   "。\n"
		   );
                set("unit", "张");
                set("material", "steal");
	     } 
	setup();
}


void init()
{
        add_action("do_bedin", "gotobed");
	add_action("do_bedout","getout");
}

int do_bedin() //上床---------------------------------------------------------------------------
{
//局部变量定义区

	string wss; 		// ws 的英文意思是缓冲区，凡是 ws 的仅仅暂时使用。
	int wsi; 		// int 形势的 ws 。
	object *inv; 		// 储存 当前房间 inventory 物品（包括玩家）的数组。

	ob=this_player();

//如果已经有玩家在床上，退出。

	inv = all_inventory(environment(ob));
	for(wsi=0; wsi<sizeof(inv); wsi++)
		{if( (int)inv[wsi]->query_temp("hanyu_chuang") != 0)
			return notify_fail("床上已经有人了，寒玉床只能一个人使用。\n");
		}

//显示玩家上床，并且temp("hanyu_chuang")=1。
	me=ob;
	message_vision("$N纵身跳上寒玉床，躺了下去。\n", me);
	me->delete_temp("apply/short");
	wss=me->short();
	me->set_temp("apply/short",wss+HIW"  （正躺在寒玉床上）"NOR); //用look命令看到的新ID。
	me->set_temp("hanyu_chuang",1);
	set_heart_beat(1); 					//开始心跳。
	return 1;
}

int do_bedout()//下床----如果是在床上的玩家使用getout命令，显示下床，且参数清零。---------------
{
	ob=this_player();
	if((int)ob->query_temp("hanyu_chuang") != 0)
		{
		 ob->delete_temp("apply/short");
		 ob->delete_temp("hanyu_chuang");
		 message_vision("$N伸了伸懒腰，跳下了寒玉床。\n", ob);
		 set_heart_beat(0);				//关闭心跳。
		 return 1;
		}	
	return notify_fail("什么？\n");
}

void heart_beat()//当玩家上床后，每两秒钟自动执行一次。-----------------------------------------
{
	int f=(int)me->query_skill("force");			//内功等级。
	int mnl=(int)me->query("max_neili");			//最大内力。
	int q=(int)me->query("qi");				//当前气。
	int qc=f/10+1;						//每次心跳减多少气。
	int nla,nl,gg;						//要加的内力和当前的内力和根骨。

	if( me->query_skill_mapped("force") != "yunu-xinjing")	//如果用别的内功，退出。
		{
		 tell_object(me, HIB"你觉得一阵寒气袭来，不由打了个寒颤。\n"NOR);
		 if( (int)me->query("qi") < 20 )		//如果已经快死了，退出。
			{
			 message_vision("$N从床上滚了下来。\n", me);
			 me->delete_temp("apply/short");
			 me->delete_temp("hanyu_chuang");
			 set_heart_beat(0);
			 return;
			}
		 me->add("qi",-20);
		 return;
		}

	if(mnl>999) return;					//如果最大内力大于1000，退出。

	if (q<qc)						//防止晕倒。
		{if(q<1)
			qc=0;
		 else
		 	qc=q-1;
		}	

	if((int)me->query_temp("pending/exercise") != 0)	//如果正在打坐。
		{
		 nla=(qc + qc) * (1000-mnl) / 1000;
		 me->add("neili",nla);	
		 if( random(10)==1 )
			tell_object(me, "你觉得体内的热气不断的被寒气所抵消，顿觉全身舒畅。\n");
		}
	else
		{
		 nla=qc + qc * (1000-mnl) / 1000;
		 me->add("neili",nla);	
		 me->add("qi",-qc);				//如没打坐，减气。
		 if( random(10)==1 )
		 	tell_object(me, "你觉得体内真气竟自动的开始游走，顿觉一身轻松。\n");
		}

	nl=(int)me->query("neili");				//当前内力。
	gg=(int)me->query("con");				//根骨值。

	if (nl+1 > mnl*2)
		{if (mnl > f*gg*2/3)
			{tell_object(me, "你的内力修为似乎已经达到了瓶颈。\n");
                         me->set("neili", mnl);
                         return;
                	}
                 else 
			{me->add("max_neili", 2);
			 me->set("neili", mnl+2);
			 tell_object(me, "你的内力增加了两点！！\n");                        
			 return; 
			}
		}	

	return;
}
