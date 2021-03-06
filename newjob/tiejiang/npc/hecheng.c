//CODE OF SHENZHOU
//CODE BY NEWBE

#include <ansi.h>
inherit NPC;

int do_dig();
int do_da(string arg);

void create()
{
	set_name("何成",({"he cheng", "he", "cheng"}));
        set("title",HIC"监管工"NOR);
        set("age",35);
        set("gender","男性");
        set("long", "他是矿场里的监管工，时不时问矿工一些问题,以防他们偷懒。 \n");

        setup();
        carry_object("/clone/armor/cloth")->wear();
}

void init()
{
object me;
::init();
if(interactive(me =this_player())&& !is_fighting()&& (int)me->query_condition("bonze_drug" ) < 10)
{
remove_call_out("greeting");
call_out("greeting",1,me);
this_player()->apply_condition("bonze_drug", 20);
}
}

void greeting(object me)
{
if(!me || environment(me) !=environment()) return;

	message_vision(HIG"何成对$N说道；现在我问你一个问题,答对了就有奖励。 (用 da或answer 来回答)\n"NOR, me);

	switch( random(19) )
     {
             case 0:
                  message_vision(HIG"何成问道；请问挖矿是否要工具?\n"NOR, me);
                  message_vision(HIY"1) 要    2) 不要\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 1:
                  message_vision(HIG"何成问道；请问能否连续挖几次矿?\n"NOR, me);
                  message_vision(HIY"1) 能    2) 不能\n"NOR, me);
                  me->set_temp("wenti", "2");
                  break;
             case 2:
                  message_vision(HIG"何成问道；请问挖矿会需要 精力, 内力, 精, 或 气吗?\n"NOR, me);
                  message_vision(HIY"1) 会    2) 不会\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 3:
                  message_vision(HIG"何成问道；请问挖矿会否有特别事发生? 工具会断?\n"NOR, me);
                  message_vision(HIY"1) 会    2) 不会\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 4:
                  message_vision(HIG"何成问道；请问如果挖到矿会有什么?\n"NOR, me);
                  message_vision(HIY"1) 宝剑    2) 石人   3) 矿    4) 金沙\n"NOR, me);
                  me->set_temp("wenti", "3");
                  break;
             case 5:
                  message_vision(HIG"何成问道；请问谁才可以挖矿?\n"NOR, me);
                  message_vision(HIY"1) 男性    2) 女性    3) 以上皆是\n"NOR, me);
                  me->set_temp("wenti", "3");
                  break;
             case 6:
                  message_vision(HIG"何成问道；请问挖矿有没有条件? ( 例如要多少经验 )\n"NOR, me);
                  message_vision(HIY"1) 有    2) 没有\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 7:
                  message_vision(HIG"何成问道；请问在哪理挖矿?\n"NOR, me);
                  message_vision(HIY"1) 矿场    2) 密林    3) 树林   4) 山路\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 8:
                  message_vision(HIG"何成问道；请问什么时候才可以去挖矿?\n"NOR, me);
                  message_vision(HIY"1) 晚上    2) 早上    3) 整天\n"NOR, me);
                  me->set_temp("wenti", "3");
                  break;
             case 9:
                  message_vision(HIG"何成问道；请问要用什么来挖矿?\n"NOR, me);
                  message_vision(HIY"1) 令牌    2) 木支    3) 剑    4) 枪   5) 以上皆非\n"NOR, me);
                  me->set_temp("wenti", "5");
                  break;
             case 10:
                  message_vision(HIG"何成问道；请问一人可以挖己多次矿?\n"NOR, me);
                  message_vision(HIY"1) 一次    2) 十次    3) 五次    4) 无限制\n"NOR, me);
                  me->set_temp("wenti", "4");
                  break;
             case 11:
                  message_vision(HIG"何成问道；请问挖矿是不是每次都会成功?\n"NOR, me);
                  message_vision(HIY"1) 是    2) 不是\n"NOR, me);
                  me->set_temp("wenti", "2");
                  break;
             case 12:
                  message_vision(HIG"何成问道；请问是用什么指令来挖矿?\n"NOR, me);
		  message_vision(HIY"1) dig    2) wa 3) 两个都可以\n"NOR, me);	
                  me->set_temp("wenti", "3");
                  break;
             case 13:
                  message_vision(HIG"何成问道；请问挖矿有没有难度?\n"NOR, me);
                  message_vision(HIY"1) 有    2) 没有\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 14:
                  message_vision(HIG"何成问道；请问要用什么来运矿?\n"NOR, me);
                  message_vision(HIY"1) 矿车    2) 用手    3) 依服    4) 飞机\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 15:
                  message_vision(HIG"何成问道；请问挖矿是用来做什么的?\n"NOR, me);
                  message_vision(HIY"1) 武器    2) 依服    3) 水果    4) 房屋\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 16:
                  message_vision(HIG"何成问道；请问男和女挖矿有分别吗?\n"NOR, me);
                  message_vision(HIY"1) 有    2) 没有\n"NOR, me);
                  me->set_temp("wenti", "2");
                  break;
             case 17:
                  message_vision(HIG"何成问道；请问挖矿会加 exp 吗?\n"NOR, me);
                  message_vision(HIY"1) 会    2) 不会\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 18:
                  message_vision(HIG"何成问道；请问挖矿会加 literate 吗?\n"NOR, me);
                  message_vision(HIY"1) 会    2) 不会\n"NOR, me);
                  me->set_temp("wenti", "2");
                  break;
             case 19:
                  message_vision(HIG"何成问道；请问挖矿要矿车吗?\n"NOR, me);
                  message_vision(HIY"1) 要    2) 不要\n"NOR, me);
                  me->set_temp("wenti", "2");
                  break;
        }
        
     add_action("do_da", "da");
     add_action("do_da", "answer");
     add_action("do_dig", "dig");
     add_action("do_dig", "wa");
     return ;
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
        me->improve_skill("caikuang", me->query_int()+random(100));
	command("say 好！果然是人才，继续努力吧。");
        message_vision(HIG"$N答对了问题,觉得自己的采矿技术有所提高。\n"NOR, me);
        me->delete_temp("wenti", 1);
        me->apply_condition("bonze_drug", 80);
        return 1;
        }
	
	else if( arg != me->query_temp("wenti") )
        {
        message_vision(HIG"何成拍了拍$N的头,对$N说；答错了不要紧，继续努力吧。\n"NOR, me);
        me->delete_temp("wenti", 1);
        me->apply_condition("bonze_drug", 70);
        return 1;
        }
}

int do_dig()
{
	object me = this_player();
	if(me->query_temp("wenti"))
	return notify_fail("你还是先回答我的问题吧！");
}
