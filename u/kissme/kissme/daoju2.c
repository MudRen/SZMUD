// Obj: /clone/obj/daoju.c
// buwu Feb 4, 2002 
// to kissme: 有关房间繁华度的判断还没有增加。繁华度(fanhua)定为 1-5，5 为最高。如果这个地区没有设置繁华度，则不能表演。
// 繁华度除了和表演失败的处罚有关，而且还和表演成功的奖励有关。
// 奖励都写在 guanshi.c 里。

#include <ansi.h>
inherit ITEM;

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
		set("long", "这是一套表演用的道具，里面有各种常见的杂耍卖艺的工具。\n有了它，你就可以开始表演了(biaoyan)。\n");
		set("value", 0);
	}
	setup();
}

int do_biaoyan(string arg)
{
        object me=this_player();

        if(me->is_busy())
        return notify_fail("你正忙着呢！\n");
                  if(me->query_temp("obj/done") >= 1)
        {
          tell_object(me,HIG"\n你累了一天，该回去交差了 ..."NOR"\n\n");
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
          tell_object(me,"管事交待的不是这个地方吧？\n");
          return 1;
        }
        else
        if(environment(me)->query("fanhua")<1)
        {
        tell_object(me,"这里人迹罕至，你表演给谁看？\n",me);
        return 1;
        }
        else
        if (environment(me)->query_temp("changxi") >= 1)
        {
          tell_object(me,HIC"\n你大声吆喝了一下，可是没有人理睬你。\n看来刚刚有人在这里表演过，还是换个地方看看吧 ..."NOR"\n\n");
          return 1;
        }
        else          
        if ((me->query("jing") < 20))
        {  
          tell_object(me,HIB"\n你的精力不济，需要调整一下才能表演！"NOR"\n\n");
          return 1;
        }
        else
        if ((me->query("qi") < 30 ))
        {
          tell_object(me,HIB"\n你的气血不佳，需要休息一下才能表演！"NOR"\n\n");
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
          if ((me->query_skill("sword") < 2))
            return notify_fail("你一点剑法都不会，怎么表演？\n");
            
          if ((me->query("int") < 23))
            return notify_fail("你的剑法一点灵气都没有。杀杀人还可以，表演的话就免了吧。\n");
           
          message_vision(HIW"\n$N拿起一把剑，哼哼嗤嗤地开始表演起了剑法 ...\n\n"NOR,me);          
          me->start_busy(8); 
          call_out("wujian",8,me);
        if(random(2)){
            object ob1=new("/u/kissme/rascal");
          ob1->move(environment(me));
          ob1->set("combat_exp",me->query("combat_exp"));
        tell_object(me,"小流氓对你大声骂道：在老子地盘上混饭吃也不知道孝敬老子！\n",me);
          ob1->kill_ob(me);
        }
          return 1;
       	}
       	else
        if ( arg == "qu" )
        {
        if(me->is_busy())
          return notify_fail("你正忙着呢\n");
          if ((me->query("neili") < 100))
            return notify_fail("你的内力不足，没有足够的内息唱出像样的曲子。\n");
          if ((me->query("per") < 25))
            return notify_fail("你长得丑不是你的错。要是你那么丑还唱小曲吓唬人，就是你不对了。\n");
           
          message_vision(HIW"\n$N一边拉着胡琴，一边应和着唱起了小曲儿 ...\n\n"NOR,me);          
          me->start_busy(8); 
          call_out("changqu",8,me);
        if(random(2)){
        object ob1;
        ob1=new("/u/kissme/rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",me->query("combat_exp"));
          tell_object(me,"小流氓对你大声骂道：在老子地盘上混饭吃也不知道孝敬老子！\n",me);
            ob1->kill_ob(me);
       }
          return 1;
       	}
       	else
        if ( arg == "sui" )
        {
        if(me->is_busy())
        return notify_fail("你正忙着呢!\n");
          if ((me->query_skill("strike") < 30))
            return notify_fail("你的掌法根基太差，小心伤了自己！\n");
          if ((me->query("str") < 23))
            return notify_fail("你一副弱不禁风的样子，当你作出要劈石块的样子时，所有人都闭上了眼睛不忍心看。\n");
                       
          message_vision(HIW"$N运功于掌，一声大喝，用力向一个石块劈去。\n"NOR,me);          
          me->start_busy(8); 
       	  call_out("suizhuan",8,me);
          if(random(2)){
            object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",me->query("combat_exp"));
          tell_object(me,"小流氓对你大声骂道：在老子地盘上混饭吃也不知道孝敬老子!\n",me);
            ob1->kill_ob(me);
}
       	  return 1;
       	}
       	else
        if ( arg == "zou" )
        {
        if(me->is_busy())
        return notify_fail("你正忙着呢!\n");
          if ((me->query_skill("dodge") < 2))
            return notify_fail("你的轻功太差了吧？走路都走不稳，还走绳索？\n");
	  if ((me->query("dex") < 23))
            return notify_fail("你手长腿短，重心偏上，一副笨拙的样子，怎么表演走绳索？\n");

          message_vision(HIW"$N飞快的绑好一根绳索，开始在绳索上走来走去，做着复杂的动作。\n"NOR,me);          
          me->start_busy(8); 
       	  call_out("zousheng",8,me);
          if(random(2)){
            object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",me->query("combat_exp"));
          tell_object(me,"小流氓对你大声骂道：在老子地盘上混饭吃也不知道孝敬老子！\n",me);
        ob1->kill_ob(me);
}
       	  return 1;
       	}
}

int wujian(object me)
{
        //奖励 50*繁华度 左右的 exp,  skill sword 熟练度增加 400
        int jlexp=50*(int)environment(me)->query("fanhua")+me->query("int");
        message_vision(HIY"$N舞剑完毕，引来了一阵喝采声。\n"NOR,me);
        me->set_temp("obj/done",1);
        me->set("kljob/jlexp",jlexp);
        me->improve_skill("sword",400);
        environment(me)->set_temp("changxi",1);        
        return 1;
}

int changqu(object me)
{
        //奖励 50*繁华度 左右的 exp，奖励 max_neili 一点。内力最高到 1200
        int jlexp=50*(int)environment(me)->query("fanhua")+me->query("int");
        me->set("kljob/jlexp",jlexp);
        me->improve_skill("force",400);
    if(me->query("max_neili")<1200){
        me->add("max_neili",1);
        }
        message_vision(HIY"$N一曲唱毕，旁边的人鼓起了掌。\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("changxi",1);        
        return 1;
}

int suizhuan(object me)
{
        //奖励 50*繁华度 左右的 exp，奖励 eff_jingli，需要身上有 id 为 shikuai 的物品。精力最高到 600
        int jlexp=50*(int)environment(me)->query("fanhua")+me->query("int");
        me->set("kljob/jlexp",jlexp);
        message_vision(HIY"$N只见好大的块砖头应声而碎，旁人看得张大口说不出话来。\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("changxi",1); 
        return 1;
} 

int zousheng(object me)
{
        //奖励 50*繁华度 左右的 exp，奖励 dodge 熟练度 400
        int jlexp=50*(int)environment(me)->query("fanhua")+me->query("int");
        me->set("kljob/jlexp",jlexp);
        me->improve_skill("force",400);
        message_vision(HIY"$N从绳索上轻轻的走了过去，晃也没晃一下，围观的乡亲赶紧喝彩。\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("changxi",1); 
        return 1;
}          
