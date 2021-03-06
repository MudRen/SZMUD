// Obj: /clone/obj/daoju.c
// buwu Feb 4, 2002 
// to kissme: 有关房间繁华度的判断还没有增加。繁华度(fanhua)定为 1-5，5 为最高。如果这个地区没有设置繁华度，则不能表演。
// 繁华度除了和表演失败的处罚有关，而且还和表演成功的奖励有关。
// 奖励都写在 guanshi.c 里。

#include <ansi.h>
inherit ITEM;


string *msg_biaoyan = ({
      "$P挥舞着手中的长剑，不料手一滑长剑脱手而飞，围观人群纷纷闪躲！\n",
      "$P把剑舞得相当得意，不小心被脚下的石头绊了一跤，引起围观人群哄堂大笑。\n",
      "$P旁若无人般地表演着剑法，浑然忘了周围的观众。\n",
      "舞剑，舞剑，$P正精彩地表演着剑术套路。\n",
      "舞剑，舞剑，$P专心致志地表演着剑术套路。\n",
      "舞剑，舞剑，$P心无杂念地表演着剑术套路。\n",
      "舞剑，舞剑，$P一丝不苟地表演着剑术套路。\n",
      "舞剑，舞剑，$P熟练地表演着剑术套路。\n",
      "舞剑，舞剑，$P英姿飒爽地表演着剑术套路。\n",
      "舞剑，舞剑，$P纯熟地表演着剑术套路。\n",
      "舞剑，舞剑，$P得意地表演着剑术套路。\n",
      "舞剑，舞剑，$P满腔豪情地表演着剑术套路。\n",
      "$P扯着大破锣嗓子没吼几声，就把围观的人都吓跑了！\n",
      "$P正得意地迈着小碎步，不小心被脚下的石头绊了一跤，引起围观人群哄堂大笑。\n",
      "$P旁若无人般地唱着小曲儿，浑然忘了周围的观众。\n",
      "唱曲儿，唱曲儿，$P正精彩地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P专心致志地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P心无杂念地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P一丝不苟地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P熟练地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P万般风情地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P纯熟地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P得意地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P满腔豪情地唱着小曲儿。\n",
      "$P像模像样的站稳马步，运气，大喝一声劈掌下去，结果手掌鲜血直流。\n",
      "$P想劈面前的石块，结果劈来劈去劈不中，引起围观人群哄堂大笑。\n",
      "$P旁若无人般地劈着石块，结果越劈越来劲，停不下手了。\n",
      "劈砖，劈砖，$P正精彩地表演着劈砖。\n",
      "劈砖，劈砖，$P专心致志地表演着劈砖。\n",
      "劈砖，劈砖，$P心无杂念地表演着劈砖。\n",
      "劈砖，劈砖，$P一丝不苟地表演着劈砖。\n",
      "劈砖，劈砖，$P熟练地表演着劈砖。\n",
      "劈砖，劈砖，$P英姿飒爽地表演着劈砖。\n",
      "劈砖，劈砖，$P纯熟地表演着劈砖。\n",
      "劈砖，劈砖，$P得意地表演着劈砖。\n",
      "劈砖，劈砖，$P气势不凡地表演着劈砖。\n",
      "$P走在绳索上，一摇一晃，煞是好看。却不料绳索突然松开，$P摔了一个嘴啃泥！\n",
      "$P正得意地在绳索上翻着筋斗，突然一个踏空摔了下来，引起围观人群哄堂大笑。\n",
      "$P旁若无人般地走着绳索，来来回回地走了很多趟，没有停下来的意思。\n",
      "走索，走索，$P精彩地表演着走索儿。\n",
      "走索，走索，$P专心致志地表演着走索儿。\n",
      "走索，走索，$P心无杂念地表演着走索儿。\n",
      "走索，走索，$P一丝不苟地表演着走索儿。\n",
      "走索，走索，$P熟练地表演着走索儿。\n",
      "走索，走索，$P英姿飒爽地表演着走索儿。\n",
      "走索，走索，$P纯熟地表演着走索儿。\n",
      "走索，走索，$P得意地表演着走索儿。\n",
      "走索，走索，$P满腔豪情地表演着走索儿。\n",
    });

void init()
{
	add_action("do_biaoyan", "biaoyan");
}

void create()
{
	set_name(CYN"表演道具"NOR, ({"biaoyan daoju", "daoju"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("no_drop","这可是你吃饭的家伙,怎么能扔呢?\n");
		set("no_get", 1); 
                set("no_steal", 1); 
		set("long", "这是一套表演用的道具，里面有各种常见的杂耍卖艺的工具。\n有了它，你就可以开始表演了("HIW"biaoyan"NOR")。\n");
		set("value", 0);
	}
	setup();
}

int do_biaoyan(string arg)
{
        object me=this_player();

          if(me->is_busy()||me->is_fighting())
        return notify_fail("你正忙着呢。\n");
                  if(me->query_temp("obj/done") >= 1)
        {
          tell_object(me,HIG"\n你不觉得累吗？该回去交差了。"NOR"\n\n");
          return 1;
        }
        else
        if (me->query_temp("obj/changxi") < 1)
        {
          tell_object(me,HIB"没有北京戏院管事的允许，谁都不能在街上表演 ..."NOR"\n\n");
          return 1;
        }
        else
        if (me->query_temp("obj/where") != environment(me)->query("outdoors"))
        {
          tell_object(me,"管事安排你来的不是这个地方吧？\n");
          return 1;
        }
        else
        if(environment(me)->query("fanhua")<1)
        {
        tell_object(me,"这里的行人都在匆匆赶路，不是表演的好地方吧？\n",me);
        return 1;
        }
        else
        if (environment(me)->query_temp("changxi") >= 1)
        {
          tell_object(me,HIC"\n你试着大声吆喝了一下，可是没有人理睬你。\n看来刚刚有人在这里表演过，还是换个地方看看吧 ..."NOR"\n\n");
          return 1;
        }
        else          
        if ((me->query("jingli") < 100))
        {  
          tell_object(me,HIB"\n你的精力不济，需要调整一下才能表演！"NOR"\n\n");
          tell_object(me,CYN"\n你可以用吐纳("HIW"tuna 10"NOR")来获得精力，进一步信息可以查询 "HIW"newbie 吐纳"NOR"。"NOR"\n\n");
          return 1;
        }
        else
        if ((me->query("qi") < 100 ))
        {
          tell_object(me,HIB"\n你的气血不佳，需要休息一下才能表演！"NOR"\n\n");
          tell_object(me,CYN"\n只要你有食物，休息一下就可以自然恢复气，进一步信息可以查询 "HIW"newbie 气"NOR"。"NOR"\n\n");
          return 1;
        }
        else          
	if (environment(me)->query_temp("changxi") >= 1)
        {
        tell_object(me,"刚刚才有人来这儿表演过，人们都不想再看卖艺的了。\n"NOR,me);
       	return 1;
      	}
          else
        if (!arg || arg == "" )
        { 
          tell_object(me,"你要进行哪种表演？
          \n    舞剑(jian)，唱曲(qu)，碎石(sui)，走绳索(zou)？\n\n");
          return 1;
        }
        else
        if ( arg == "jian" )
        {

        if(me->is_busy())
        	return notify_fail("你正忙着呢！\n");
        
        if ((me->query_skill("sword",1) < 20))
        	return notify_fail("你一点剑法都不会，怎么表演？\n");
            
        if ((me->query("int") < 19))
        	return notify_fail("你的剑法一点灵气都没有。杀人放火还凑合，表演的话就免了吧。\n");

          if(random(20)>2){
        	message_vision(YEL"\n"+msg_biaoyan[random(12)]+"\n\n"NOR,me);
        	me->start_busy(4+random(2));
        	me->add("jingli",-(10+random(20)));
    		environment(me)->set_temp("changxi",1);
        		return 1;
        }

      if(!random(3)){
              object ob1=new(__DIR__"rascal");
          ob1->move(environment(me));
          ob1->set("combat_exp",2*me->query("combat_exp"));
              message_vision("当$N正要开始表演的时候，人群里突然冲出个小流氓。\n小流氓对$N大声骂道：懂不懂江湖规矩？在老子地盘上混饭吃也不知道孝敬老子！\n",me);
            ob1->kill_ob(me);
            return 1;
        }

          message_vision(HIW"\n$N左手捏了一个剑诀，右手将剑一收，做了一个漂亮的收势。\n\n"NOR,me);          
           me->start_busy(6); 
          call_out("wujian",12,me);
          return 1;
    }

        else
        if ( arg == "qu" )
        {

        if(me->is_busy())
          return notify_fail("你正忙着呢！\n");

    if(me->query("neili")<100)
        return notify_fail("没有足够的内息，是没有办法唱好戏的。\n");

    if(me->query("per")<19)
        return notify_fail("你长得丑不是你的错。要是你那么丑还唱小曲吓唬人，就是你不对了。\n");

             if(random(10)){
        message_vision(YEL"\n"+msg_biaoyan[12+random(12)]+"\n\n"NOR,me);
          me->start_busy(4+random(2));
            me->add("neili",-(20+random(20)));
        return 1;
       }

      if(!random(3)){
              object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",2*me->query("combat_exp"));
            message_vision("当$N正要开始表演的时候，人群里突然冲出个小流氓。\n小流氓对$N大声骂道：懂不懂江湖规矩？在老子地盘上混饭吃也不知道孝敬老子！\n",me);
            ob1->kill_ob(me);
          return 1;
          }
           
            message_vision(HIW"\n$N一边拉着胡琴，一边应和着唱着小曲儿。\n\n"NOR,me);          
           me->start_busy(6); 
            call_out("changqu",12,me);
          return 1;
       	}
       	else
        if ( arg == "sui" )
        {
        if(me->is_busy())
        return notify_fail("你正忙着呢!\n");
            if ((me->query_skill("strike",1) < 61))
            return notify_fail("你的掌法根基太差，小心伤了自己！\n");
          if ((me->query("str") < 19))
            return notify_fail("你一副弱不禁风的样子，就算劈开了石块别人也以为是假的！\n");
                       

          if(random(10)){
             message_vision(RED"\n"+msg_biaoyan[24+random(12)]+"\n\n"NOR,me);
            me->add("eff_qi",-(5+random(10)));
          me->start_busy(4+random(2));
         return 1;
         }
            if(!random(3)){
            object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",2*me->query("combat_exp"));
            message_vision("当$N正要开始表演的时候，人群里突然冲出个小流氓。\n小流氓对$N大声骂道：懂不懂江湖规矩？在老子地盘上混饭吃也不知道孝敬老子！\n",me);
            ob1->kill_ob(me);
            return 1;
}
          message_vision(HIW"$N运功于掌，一声大喝，用力向一个石块劈去。\n"NOR,me);          
           me->start_busy(6); 
       	  call_out("suizhuan",12,me);
       	  return 1;
       	}
       	else
        if ( arg == "zou" )
        {
        if(me->is_busy())
        return notify_fail("你正忙着呢!\n");
            if ((me->query_skill("dodge",1) < 21))
            return notify_fail("你的轻功太差了吧？走路都走不好，还走绳索？\n");
	  if ((me->query("dex") < 19))
            return notify_fail("你手长腿短，重心偏上，一副笨拙的样子，怎么表演走绳索？\n");

            if(random(20)>2){
          message_vision(YEL"\n"+msg_biaoyan[36+random(12)]+"\n\n"NOR,me);
          me->start_busy(4+random(2));
          me->add("jingli",-(10+random(20)));
          return 1;
         }
            if(!random(3)){
            object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",2*me->query("combat_exp"));
            message_vision("当$N正要开始表演的时候，人群里突然冲出个小流氓。\n小流氓对$N大声骂道：懂不懂江湖规矩？在老子地盘上混饭吃也不知道孝敬老子！\n",me);
        ob1->kill_ob(me);
        return 1;
}
          message_vision(HIW"$N在绳索上走来走去，表演着复杂而优美的动作。\n"NOR,me);          
            me->start_busy(6); 
       	  call_out("zousheng",12,me);
       	  return 1;
       	}
}

int wujian(object me)
{
        //奖励 50*繁华度 左右的 exp,  skill sword 熟练度增加 400
        int jlexp=75*(int)environment(me)->query("fanhua")+me->query("int");
        message_vision(HIY"$N舞剑完毕，引来了一阵喝采声。\n"NOR,me);
        tell_object(me,"\n你感到基本剑法有所长进！\n\n");
        me->set_temp("obj/done",1);
        me->set("kljob/jlexp",jlexp);
        me->improve_skill("sword",10*me->query("int")+random(15*me->query("int")));
        me->add("jingli",-(30+random(30)));
        environment(me)->set_temp("changxi",1);        
        return 1;
}

int changqu(object me)
{
        //奖励 50*繁华度 左右的 exp，奖励 max_neili 一点。内力最高到 1200
        int jlexp=75*(int)environment(me)->query("fanhua")+me->query("int");
        me->set("kljob/jlexp",jlexp);
        if (me->query("max_neili")<1200) me->add("max_neili",1);
        if (me->query("max_neili")<1200) tell_object(me,"\n你感到内息修养有所长进！\n\n");
        message_vision(HIY"$N一曲唱毕，围观人群鼓起了掌。\n"NOR,me);
        me->set_temp("obj/done",1);
        me->add("neili",-(30+random(30)));
        environment(me)->set_temp("changxi",1);        
        return 1;
}

int suizhuan(object me)
{
        //奖励 50*繁华度 左右的 exp，奖励 eff_jingli，需要身上有 id 为 shikuai 的物品。精力最高到 600
        int jlexp=70*(int)environment(me)->query("fanhua")+me->query("int");
        me->set("kljob/jlexp",jlexp);
        if (me->query("eff_jingli")<600) me->add("eff_jingli",1);
        if (me->query("eff_jingli")<600) tell_object(me,"\n你掌握了如何运用精力！\n\n");
        message_vision(HIY"$N只见好大的石块应声而碎，旁人看得张大口说不出话来。\n"NOR,me);
        me->set_temp("obj/done",1);
        me->add("eff_qi",-(20+random(20)));
        environment(me)->set_temp("changxi",1); 
        return 1;
} 

int zousheng(object me)
{
        //奖励 50*繁华度 左右的 exp，奖励 dodge 熟练度 400
        int jlexp=75*(int)environment(me)->query("fanhua")+me->query("int");
        me->set("kljob/jlexp",jlexp);
        me->improve_skill("dodge",10*me->query("dex")+random(15*me->query("dex")));
        message_vision(HIY"$N从绳索上轻轻的走了过去，晃也没晃一下，围观的乡亲赶紧喝彩。\n"NOR,me);
        tell_object(me,"\n你感到基本轻功 有所长进！\n\n");
        me->set_temp("obj/done",1);
        me->add("eff_jing",-(5+random(10)));
        environment(me)->set_temp("changxi",1); 
        return 1;
}          
