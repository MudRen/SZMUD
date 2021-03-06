//CODE OF SHENZHOU
//CODE BY NEWBE
//UPDATE BY SCATTER 2002/1/1 (UPDATE 加入 code)

#include <ansi.h>
inherit NPC;

int do_da(string arg);
int ask_question();
int ask_jialu();
int do_learn(string arg);

void create()
{
        set_name("白长石",({"bai changshi", "bai", "changshi"}));
        set("title",HIC"督查总管"NOR);
        set("age",45);
        set("gender","男性");
        set("long", "他是打铁场的督查总管，专门负责打铁场里的检查工作。 \n");
        set("inquiry", ([
                        "问题" : (: ask_question :),
                        "打铁" : "打铁可以,可你要先回答我一个『问题』!",
                                                "jialu" : (: ask_jialu :),
                                                "加入" : (: ask_jialu :),
        ]) );
        setup();
        carry_object("/clone/armor/cloth")->wear();
}

void init()
{
object me;
::init();
add_action("do_learn", "shixi");
add_action("do_learn", "实习");
if( interactive(me =this_player())&& !is_fighting()&& (int)me->query_temp("wenti"))
{
        add_action("do_da", "da");
        add_action("do_da", "answer");
}
}

int ask_jialu()
{
        object me = this_player();

        if ( me->query("newjob/jobtitle") == "铁匠")
        {
                message_vision(NOR"白长石对$N说道: 你已经是铁匠啦，壮士何出此言？\n"NOR, me);
                return 1;
        }

        if ( me->query("newjob/jobtitle") )
        {
                message_vision(NOR"白长石对$N说道: 你已经是"+ me->query("newjob/jobtitle") +"啦，壮士何出此言？\n"NOR, me);
                return 1;
        }

        if ( me->query("str") < 15 )
        {
                message_vision(NOR"白长石对$N说道: 你这种身材也要来当铁匠？\n"NOR, me);
                return 1;
        }

        if ( me->query("int") > 28 )
        {
                message_vision(NOR"白长石对$N说道: 你的悟性极高，壮士可能当铁匠是一种浪费呀？\n"NOR, me);
                return 1;
        }

        if ( me->query("neili") < 300 )
        {
                message_vision(NOR"白长石对$N说道: 你的内力不够深厚，壮士还是回去勤加练习吧？\n"NOR, me);
                return 1;
        }

        message_vision(HIG"白长石对$N说道: 好吧，从今天起你就是铁匠了，好好的做，前途无量．\n"NOR, me);
        me->set("newjob/jobtitle", "铁匠");
        
        return 1;
}


int ask_question()
{
     object me = this_player();
     if(me->query_temp("wenti"))
     {
        tell_object(me,"你还是先回答上一题吧！\n");
        return 1;
     }
        
     if(me->query_temp("datiechang/enter"))
     {
        tell_object(me,"白长石皱了皱眉说；我不是允许你使用了吗?\n");
        return 1;
     }
     
     if(me->query("combat_exp")<10000
       ||me->query("max_neili")<1000
       ||me->query("max_jingli")<1000
       ||me->query("str")<23
       ||me->query_skill("tiejiang", 1)<10)
     {
        tell_object(me,"白长石仔细看了看你说；你还是先回去锻炼锻炼吧!\n");
        return 1;
     }
                 
        message_vision(HIG"白长石对$N说道；好,现在我问你一个关于矿石的问题,答对了就有奖励。 (用 da或answer 来回答)\n"NOR, me);
        
        switch( random(19) )
     {
             case 0:
                  message_vision(HIG"白长石问道；请问下面哪种石料属于金属矿石?\n"NOR, me);
                  message_vision(HIY"a:大理石  b:花岗石  c:孔雀石  d:金刚石\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 1:
                  message_vision(HIG"白长石问道；请问下面哪种石料属于金属矿石?\n"NOR, me);
                  message_vision(HIY"a:玉石  b:蔬石  c:水晶石  d:磁石\n"NOR, me);
                  me->set_temp("wenti", "d");
                  break;
             case 2:
                  message_vision(HIG"白长石问道；请问下面哪种石料不属于金属矿石?\n"NOR, me);
                  message_vision(HIY"a:硫锡石  b:金刚石  c:孔雀石  d:磁石\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 3:
                  message_vision(HIG"白长石问道；请问下面哪种矿石属于铜矿石?\n"NOR, me);
                  message_vision(HIY"a:叶卤矿  b:硫锡石  c:孔雀石  d:磁石\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 4:
                  message_vision(HIG"白长石问道；请问下面哪种矿石不属于铜矿石?\n"NOR, me);
                  message_vision(HIY"a:叶卤矿  b:辉铜矿  c:孔雀石  d:斑铜矿\n"NOR, me);
                  me->set_temp("wenti", "a");
                  break;
             case 5:
                  message_vision(HIG"白长石问道；请问下面哪种矿石不属于铁矿石?\n"NOR, me);
                  message_vision(HIY"a:菱铁矿  b:矿石  c:褐铁矿  d:磁石\n"NOR, me);
                  me->set_temp("wenti", "b");
                  break;
             case 6:
                  message_vision(HIG"白长石问道；请问下面哪种物品须要用金属矿石溶炼之物品制成?\n"NOR, me);
                  message_vision(HIY"a:玉  b:水晶  c:金饰  d:刀剑\n"NOR, me);
                  me->set_temp("wenti", "d");
                  break;
             case 7:
                  message_vision(HIG"白长石问道；请问下面哪种物品的的制作原料与金属矿石无关?\n"NOR, me);
                  message_vision(HIY"a:罗盘  b:古镜  c:石墨  d:首饰\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 8:
                  message_vision(HIG"白长石问道；请问下面哪种金属矿石中有磁性的是?\n"NOR, me);
                  message_vision(HIY"a:铁矿  b:铜矿  c:金矿  d:铅矿\n"NOR, me);
                  me->set_temp("wenti", "a");
                  break;
             case 9:
                  message_vision(HIG"白长石问道；请问下面哪种物品的的是直接由金属矿石制成，而不须经过提炼和锻造的加工过程?\n"NOR, me);
                  message_vision(HIY"a:玉佩  b:铜盆  c:司南  d:针\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 10:
                  message_vision(HIG"白长石问道；请问下面与金矿石制品有关的是?\n"NOR, me);
                  message_vision(HIY"a:金科玉律  b:金缕玉衣  c:金枝玉叶  d:金童玉女\n"NOR, me);
                  me->set_temp("wenti", "b");
                  break;
             case 11:
                  message_vision(HIG"白长石问道；请问下面与银矿石制品有关的是?\n"NOR, me);
                  message_vision(HIY"a:水银  b:银楼  c:银耳  d:银霜炭\n"NOR, me);
                  me->set_temp("wenti", "b");
                  break;
             case 12:
                  message_vision(HIG"白长石问道；请问下面与铜矿石及其制品有关的是?\n"NOR, me);
                  message_vision(HIY"a:青铜器时代         b:铜□铁壁  c:铜筋铁骨  d:铜匠鸟\n"NOR, me);  
                  me->set_temp("wenti", "a");
                  break;
             case 13:
                  message_vision(HIG"白长石问道；请问下面与铁矿石制品有关的是?\n"NOR, me);
                  message_vision(HIY"a:铁树开花  c:铜□铁壁  b:铁证如山  d:金戈铁马\n"NOR, me);
                  me->set_temp("wenti", "d");
                  break;
             case 14:
                  message_vision(HIG"白长石问道；请问下面与锡矿石及其制品有关的是?\n"NOR, me);
                  message_vision(HIY"a:用锡若蹴  b:金锡连丹  c:申锡无疆，及尔斯所\n"NOR, me);
                  me->set_temp("wenti", "b");
                  break;
             case 15:
                  message_vision(HIG"白长石问道；请问下面与铅矿石及其制品无关的是?\n"NOR, me);
                  message_vision(HIY"a:铅华  b:铅刀为  c:铅垂线  d:铅印\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 16:
                  message_vision(HIG"白长石问道；请问金属矿石和普通石头表面看上去有什么分别?\n"NOR, me);
                  message_vision(HIY"a:一模一样，没有区别  b:有明显区别，一眼就能辨识出来  c:一般都会有些区别，但要有经验的人才能够辨识出来\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 17:
                  message_vision(HIG"白长石问道；请问下面金属矿中熔点太高，不适合用熔烧的方法提炼的是?\n"NOR, me);
                  message_vision(HIY"a:金  b:铁  c:青铜  d:铅\n"NOR, me);
                  me->set_temp("wenti", "a");
                  break;
             case 18:
                  message_vision(HIG"白长石问道；请问下面词语中，哪个是一种工作过程(动作)的别称?\n"NOR, me);
                  message_vision(HIY"a:司南  b:铁匠  c:铅汞  d:造剑师\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 19:
                  message_vision(HIG"白长石问道；请问金的产状主要为?\n"NOR, me);
                  message_vision(HIY"a:针卤金矿  b:独立存在的自然金  c:叶卤矿  d:含有金元素，可以提炼矿石\n"NOR, me);
                  me->set_temp("wenti", "b");
                  break;
        }
        
     add_action("do_da", "da");
     add_action("do_da", "answer");
     return 1;
}

int do_da(string arg)
{
        object me = this_player();
        if( !arg )
                return notify_fail("你要答什么呀？\n");
        if( !me->query_temp("wenti") )
                return notify_fail("你要答什么呀？\n");
        if( arg == me->query_temp("wenti"))
        {
        me->improve_skill("tiejiang", me->query_int()+random(50));
        command("say 好！果然是人才，继续努力吧。");
        message_vision(HIG"$N答对了问题,觉得自己对矿石的了解有所提高。\n"NOR, me);
        me->delete_temp("wenti", 1);
        me->set_temp("datiechang/enter", 1);
        return 1;
        }
        
        else if( arg != me->query_temp("wenti") )
        {
        message_vision(HIG"白长石拍了拍$N的头,对$N说；答错了不要紧，继续努力吧。\n"NOR, me);
        me->delete_temp("wenti", 1);
        return 1;
        }
}






int accept_object(object who, object ob)
{
	if(who->query_temp("tiejiang/bailearn"))
	{
		tell_object(who, "我还没教你呢。\n");
		return 1;
	}
                
    if (ob->query("money_id") && ob->value() >= 100) 
	{
		message_vision("白长石同意指点$N一些铁匠知识的问题。\n", who);
        who->add_temp("tiejiang/bailearn", 2 + random(2));
        return 1;
    }
       
}





int do_learn(string arg)
{
	object me = this_player();


//	if(arg != "bai")
//	{
//		tell_object(me,"什么？\n");
//		return 0;
//	}

	if (me->query("jing") < 11)
	{
		tell_object(me, "你精神不集中。");
		return 1;
	}

	if (!me->query_temp("tiejiang/bailearn"))
	{
		tell_object(me, "你还没付钱给白长石。\n");
		return 1;
	}

	if (me->query_skill("tiejiang", 1) > 10)
	{
		tell_object(me, "你知道的和白长石差不多了。\n");
		return 1;
	}
		

	if (me->query_temp("tiejiang/bailearn"))
	{
		tell_object(me, "你向白长石请教有关「铁匠知识」的疑问。\n你听了白长石的指导，似乎有些心得。\n");
		me->improve_skill("tiejiang", 5+random(5) ); 
		me->add_temp("tiejiang/bailearn", -1);
		me->add("potential", -1);
		me->add("jing", -10);


		if (me->query_temp("tiejiang/bailearn") < 1)
		{
			me->delete_temp("tiejiang/bailearn");
		}
		
		return 1;
	}

	return 1;

}
