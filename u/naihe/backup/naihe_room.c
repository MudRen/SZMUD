//                标准描述长度示例                                   |
// 奈何的房子，全新改版！/u/naihe/naihe_room.c
// by naihe  2002-05-15
// 基本上全是自己写的代码！只有那个设置临时出口的代码，
// 才是“临时抄袭”而来并改装成双重call_out的，哈哈。

#include <ansi.h>
inherit ROOM;

string look_left();
int t_armor,t_note,t_movebed,t_listen,t_find,t_findok,lose_things,gem_take,
lose_things=20;
// 此值lose_things决定了每执行一次需要减少精或精力的函数时，将减少最大某值除以此值的数量。
// 这里的意思就是，例如要减少精力，那就将会减少最大精力 二十分之一 的临时精力。
string msg,path,last_finder,rdpath;

void create()
{
	set("short",BLU"峰顶小屋"NOR);
	set("long",@LONG
这间屋子空荡荡的，只有门对面墙边的一只灯泡在发着昏暗的光，还时不时
地在闪烁着。灯下摆放着一板木床（bed） ，上面整齐地叠放着一些书籍、衣服、
被子和枕头，枕头边上还竖着一幅嵌在小木框里的照片（photo）。 屋子里悄然
无声，四处都充满着某些让人说不清的气息，就像是某种很淡很幽远的叹息声一
般，能够让人平静而思索着。从前留在地上和墙边的灰尘和蜘蛛网全都不见了，
这里的沉寂让人意外——你隐隐觉着有些不对劲，但又说不上来。
LONG
	);
	set("valid_startroom", 1);
	set("no_clean_up","1");
	set("item_desc",([
	    "left": (: look_left :) ,
	    "right":"右边墙上干净平滑，什么特别的地方也看不出来。\n",
	    "front":"前边墙边上有个小灯泡在随风摇晃着；而风从哪里吹来，你却一点感觉也没有。\n",
	    "rear":"你忽地回头看了看，身后什么也没有。太敏感了罢。\n",
            "photo":"这是一幅眼神呆滞的猪头的特写照片，倒有几分可爱。\n照片上签着一个潦草的字：“find”，不知道是什么意思。\n",
	    "bed":"一张小木床，似乎很久没人睡过了。枕头底下隐约可以看到有个小本子（sm_note）的一角。\n",
	    "sm_note":"原来这只是一张纸，已经很旧了。很多地方都看不清楚，只见上面断断续续地写着：
"YEL"我终于知道…………里的秘密，花了我那么多年的心血来寻找……也许……我不该
告诉任何……吧。但是，她该怎么办？她……对我，我应该……不枉………………"NOR"
下面的大半页不知怎么的给撕掉了；也不知道是谁写的。\n",
	]));
	set("exits",([
	    "out":"/d/huashan/fengding",
//	    "dc":"/clone/misc/naihe/dc_dating",
//          "west":"/u/spark/spark_room",
	]));

	setup();
	call_other("/clone/board/naihe_b","???");

}

void init()
{
	add_action("do_note","note");
        add_action("do_sleep","sleep");
	add_action("do_armor","armor");
	add_action("do_listen","listen");
	if(this_player()->query("id")!="naihe") add_action("do_nomore","more");
	if(this_player()->query("id")!="naihe") add_action("do_nomore","cat");
	if(this_player()->query("id")=="naihe") add_action("do_xxx","xxx");
	add_action("do_find","find");
	add_action("do_find","search");
	if(this_player()->query("id")=="naihe" || this_player()->query("id")=="spark")
		add_action("do_gem","gem");
}

int do_xxx()
{
	write("☆do armor:   "HIR""+t_armor+""NOR" times\n☆do note:   "HIR""+t_note+""NOR" times\n☆do listen: "HIR""+t_listen+""NOR" times\n☆do find:   "HIR""+t_find+""NOR" times,the successful times: "HIG""+t_findok+""NOR" ,get gem times: "HIG""+gem_take+""NOR" .\n");
	return 1;
}

  int do_sleep()
  {
          object me=this_player();
          int jing,jingli,neili,qi;

          if(me->query("id")!="naihe" || me->query("name")!="奈何")
          {
                  write("难道你想躺别人的床上去睡？太不礼貌了吧。\n");
                  return 1;
          }

          jing=me->query("max_jing");
          jingli=me->query("max_jingli");
          neili=me->query("max_neili");
          qi=me->query("max_qi");

          message_vision(""MAG"$N阔步走向床边，躺下歇息了片刻。"NOR"\n",me);
          message_vision(""MAG"$N小憩醒来，觉得精神奕奕。"NOR"\n",me);

          me->set("jingli",jingli);
          me->set("jing",jing);
          me->set("neili",neili);
          me->set("qi",qi);

          return 1;
  }

int do_gem()
{
	object me,ob;
	ob=new(__DIR__"obj/gem");
	me=this_player();

	message_vision(""CYN"$N在被子堆里掏了掏，掏出了一"+ob->query("unit")+ob->query("name")+"。"NOR"\n",me);
	ob->move(me);
	return 1;
}

string look_left()
{
	object me=this_player();
	int jing=me->query("max_jing");

	if(random(20)>5)
	{
		me->add("jing",-(jing/lose_things));
		if(me->query("id")=="naihe") me->add("jing",(jing/lose_things));
		return "左边墙上砖头都裂开了，很多缝隙曲曲折折的，凑起来倒像是些什么字一样。\n";
	}

	switch(random(3))
	{
		case 0:tell_object(me,""YEL"有几块墙砖的裂缝似乎凑成了：“a,r,n,o,r”几个字；但第三个字歪歪扭扭的看不大清。"NOR"\n");
			break;
		case 1:tell_object(me,""YEL"有几块墙砖的裂缝似乎凑成了：“n,o,t,……”几个字；但后面是一个还是两个字实在看不清。"NOR"\n");
			break;
		case 2:tell_object(me,""YEL"有几块墙砖的裂缝凑成了：“l,i,s,t,e,n”几个字，清晰如刻。"NOR"\n");
			break;
	}

	me->add("jing",-(jing/lose_things));
	if(me->query("id")=="naihe") me->add("jing",(jing/lose_things));
	message_vision("$N看着左边的墙，觉得怪异莫名。\n",me);
	return "你似乎感觉到了什么……你的背后（rear）似乎刮过了一阵冷嗖嗖的风！\n";
}

int do_nomore()
{
	write(""BLU"你忽地听到一个声音幽幽地说道：“唉，怎么又有人在呢……”"NOR"\n");
	write("这里气氛诡异，你只觉得四处寒气森森。\n");
	return 1;
}

int do_note()
{
	object me=this_player();

	if(me->query("id")=="naihe" || me->query("id")=="spark" || t_note<51)
	{
                new(__DIR__"obj/note_naihe")->move(me);
		message_vision(""BLU"$N在墙边拍了拍，忽地凭空掉下了一个小本子，$N连忙接住，觉得怪异莫名。"NOR"\n",this_player());
		t_note+=5;
		return 1;
	}

	t_note-=3;
	return 0;
}

int do_armor()
{
        object me,oba,obb,obc,obd,obe,obf;
	me=this_player();
	oba=new(__DIR__"obj/anyue-jian");
	obb=new(__DIR__"obj/ay-cloth");
	obc=new(__DIR__"obj/ay-pifeng");
	obd=new(__DIR__"obj/ay-kui");
	obe=new(__DIR__"obj/ay-ring");
        obf=present("cloth",me);

	if(me->query("id")=="naihe" || me->query("id")=="spark" || wizardp(me))
	{
		t_armor++;
		message_vision(""CYN"$N在墙上拍了拍，只见其中几块砖头缩了进去，露出了一个小洞。\n$N从小洞里拿出了一整套装备，又拍了拍墙上，砖头重回原处把小洞封了起来。"NOR"\n",me);

		if(!present("anyue jian",me)) oba->move(me);
		if(!present("anyue cloth",me)) obb->move(me);
		if(!present("anyue manteau",me)) obc->move(me);
		if(!present("anyue kui",me)) obd->move(me);
		if(!present("anyue ring",me)) obe->move(me);
                if(present("cloth",me)) destruct(obf);

		write("all armor ok.\n");
		return 1;
	}
	message_vision(""CYN"$N在墙边上左拍拍，右拍拍，楞是找不出小洞在哪里。"NOR"\n",me);
	return 1;
}

void path()
{ 
	if(!query("exits/"+rdpath)) return;

//	message_vision(""BLU"那个幽怨的叹息声忽地又从四面八方响了起来：……唉……唉……唉…………"NOR"\n",this_player());

	message("vision",""BLU"那个幽怨的叹息声忽地又从四面八方响了起来：……唉……唉……唉…………"NOR"\n",this_object()); 

/************************************************************
上面两句的不同点是，第一句的信息会跟着this_player()走，而第二句则是保持在本房间内。
本来我也尝试用：message_vision("xxx",this_object())的，但这样似乎没有任何效果；而函数
执行到这句似乎就会停顿，不知何解。另外，我也试了用tell_room，试来试去仍是无用，唯有
用上面那句吧，也挺好的。
************************************************************/

	delete("exits/"+rdpath);
	path="no";
} 

void msg()
{
	message("vision",msg,this_object());

	if(path=="yes")
	{
		set("exits/"+rdpath, __DIR__"andaoa_naihe");
                call_out("path",3+random(5));
		delete("temp_listen");
		return;
	}

	delete("temp_listen");
}

int do_listen()
{
	string randoma,randomb,randomc;

	if(this_object()->query("temp_listen")== 1 || path=="yes") return notify_fail("唉，你要听什么？\n");

	switch(random(3))
	{
		case 0:randoma="a";
			break;
		case 1:randoma="b";
			break;
		case 2:randoma="c";
			break;
	}

	switch(random(3))
	{
		case 0:randomb="a";
			break;
		case 1:randomb="b";
			break;
		case 2:randomb="c";
			break;
	}

	switch(random(3))
	{
		case 0:randomc="a";
			break;
		case 1:randomc="b";
			break;
		case 2:randomc="c";
			break;
	}


	rdpath=("down"+"_"+randoma+randomb+randomc);
	if(this_player()->query("id")=="naihe") write("the path is: "+rdpath+" .\n");

	t_listen++;
	path="no";

	message_vision(""BLU"$N侧耳贴近墙边倾听着，忽地似乎听到哪里传来了一个声音。"NOR"\n",this_player());

	switch(random(4))
	{
		case 0 :
		msg="奈何幽幽叹了口气。\n";
		break;

		case 1 :
		msg="奈何深深地叹了口气。\n";
		break;

		case 2 :
		msg="似乎是听错了，凝神听了一会都并没听见什么声音。\n";
		break;

		case 3 :
		msg="只听得一个飘移不定的声音不知在何处断断续续地响起来：“下来……下来……”\n";
		path="yes";
		break;
	}
	set("temp_listen",1);
	call_out("msg",3);
	return 1;
}

int do_find(string arg)
{
	object me,findob;
	int jing,jingli;
	string where,use;

	me=this_player();
	last_finder=me->query("id");
	jing=me->query("max_jing");
	jingli=me->query("max_jingli");


	if (time()-query_temp("findtime")<2)
		return notify_fail("只听见幽幽的声音响起：“唉，你到底在找什么啊。”\n");

	t_find++;

	if(!arg  || arg=="here")
	{
                if(random(20)>10)
		{
			message_vision("$N找来找去，都不知道自己想要找什么。\n",me);
			set_temp("findtime",time());
			return 1;
		}
			
		switch(random(8))
		{
			case 0:write("你似乎发现左边（left）的墙上有些异样！\n");
				break;
			case 1:write("你似乎发现床底下（chuangdi）有些异样！\n");
				break;
			case 2:write("你似乎发现右边（right）的墙上有些异样！\n");
				break;
			case 3:write("你似乎发现顶上的灯泡（bulb）有些异样！\n");
				break;
			case 4:write("你似乎发现脚下的地板（floor）有些异样！\n");
				break;
			case 5:write("你似乎发现门外的大山（mountain）有些异样！\n");
				break;
			case 6:write("你似乎发现你自己（myself）有些异样！\n");
				break;
			case 7:write("你似乎发现前面（front）的墙上有些异样！\n");
				break;
		}
	tell_room(environment(me),(string)me->query("name")+"似乎有所发现。\n",me);
	me->add("jingli",-(jingli/lose_things));
	if(me->query("id")=="naihe") me->add("jingli",(jingli/lose_things));
	set_temp("findtime",time());
	return 1;
	}

	if(arg=="chuangdi")
	{
		where="钻进床底下";	
		use="找";
		if(random(20)<5)
		{
			switch(random(4))
			{
			case 0:
			findob=new("/clone/misc/cloth");
			break;

			case 1:
			findob=new("/clone/weapon/changjian");
			break;

			case 2:
			findob=new("/d/city/npc/obj/caomao");
			break;

			case 3:
			findob=new(__DIR__"obj/pifeng");
			break;
			}
		}

	}

	if(arg=="floor")
	{
		where="往地板上";
		use="踩";
		if(random(20)<10)
		{
			switch(random(3))
			{
			case 0:
			findob=new("/clone/money/coin");
			break;

			case 1:
			findob=new("/clone/money/silver");
			break;

			case 2:
			findob=new("/clone/money/coin");
			break;
			}
		}

	}

	if(arg=="bulb")
	{
		where="盯着头上的灯泡";
		use="看";
		if(random(20)<5)
		{
			switch(random(2))
			{
			    case 0:
                        if(gem_take<10)
			    {
				findob=new(__DIR__"obj/gem");
				write("你发现灯泡里原来装着几颗发光的宝石！灯泡随风摇曳，因此看来闪烁不定。\n");
				message_vision("$N小心翼翼地把灯泡摘了下来，取出了一颗宝石。\n",me);
				gem_take++;
				break;
			    }
				write("你发现灯泡里面空空的，还剩下些细碎的会发光的颗粒在里面，不知道是什么。\n");
				break;

			    case 1:write("灯影忽明忽暗，你实在看不到什么。\n");
			    break;
			}
		}

		else write("灯泡而已，没什么好看的罢。\n");
	}

	if(arg=="mountain")
	{
		where="对着门外的大山";
		use="看";
	}

	if(arg=="myself")
	{
		where="把自己身上";
		use="搜过";
	}

	if(arg=="front")
	{
		where="在前边的墙上";
		use="摸";
	}

	if(arg=="right")
	{
		where="在右边的墙上";
		use="敲";
	}

	if(arg!="chuangdi" && arg!="mountain" && arg!="myself" && arg!="front" && arg!="right" && arg!="floor" && arg!="bulb")
	{
		message_vision(""CYN"$N到处看了看，没发现"+arg+"这个东西。"NOR"\n",me);
		me->add("jingli",-(jingli/lose_things));
		if(me->query("id")=="naihe") me->add("jingli",(jingli/lose_things));
		set_temp("findtime",time());
		return 1;
	}


	if(!findob)
		message_vision(""CYN"$N"+where+use+"来"+use+"去，可是并没有发现什么。"NOR"\n",me);
	else
	{
		t_findok++;
		findob->move(me);
		message_vision(""CYN"$N"+where+use+"来"+use+"去，发现了一"+findob->query("unit")+findob->query("name")+"！"NOR"\n",me);
	}

	me->add("jingli",-(jingli/lose_things));
	if(me->query("id")=="naihe") me->add("jingli",(jingli/lose_things));
	set_temp("findtime",time());
	return 1;
}

