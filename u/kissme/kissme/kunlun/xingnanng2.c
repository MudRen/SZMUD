// buwu Feb 4, 2002 
// 有关房间风景的判断还没有增加。风景(fjing)定为 1-5，5 为最高。如果这个地区没有设置风景，则不能揣摩。
// 揣摩除了和表演失败的处罚有关，而且还和揣摩的奖励有关。
// 奖励都写在 guanshi.c 里。

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_chuaimo", "chuaimo");
}
  string *hua_msg = ({
    "$P感到心中一阵烦躁,不小心一团墨滴到了画上,看来这张画是没用了。\n",
    "突然天上传来一声大雁的鸣叫，将$P胸中作画的思路打断了。\n",
    "$P画了一会，感觉此处风景没有开始的感觉好，想换个地方画！\n",
    "$P感觉画笔犹如神助，胸中景物历历在目，一一在笔下描绘了出来！\n",
          });

  string *qin_msg = ({
    "$P感觉心中一阵烦躁，再也不想在这里演奏下去！\n",
    "突然从天上传来一声雁鸣，将$P的演奏打断了！\n",
    "$P弹了一会，感觉兴味索然，想换一个地方演奏！\n",
    "从$P手下传来琴音，犹如天籁之音，曲尽而意未尽！\n",
         });

void create()
{
	set_name(HIW"琴画行囊"NOR, ({"xing nang", "xingnang"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_drop","扔了行囊，如何学习绘画？\n");
		set("no_get", 1); 
                set("no_steal", 1); 
		set("long", "这是一套昆仑弟子外出携带的行囊，里面有一副围棋、文房四宝和一些颜料，\n以便昆仑弟子外出揣摩(chuaimo)琴画的技艺。\n");
		set("value", 0);
	}
	setup();
}

int do_chuaimo(string arg)
{
        object me=this_player();


        if (me->query_temp("obj/done") >= 1)
        {
          tell_object(me,HIG"\n钻研一整天了，先回去交差，明天再来继续练习吧。 ..."NOR"\n\n");
          return 1;
        }
        else
        if (me->query_temp("obj/chuaimo") < 1)
        {
          tell_object(me,HIB"你的琴画行囊是偷来的吧？"NOR"\n\n");
          return 1;
        }
        else
        if (me->query_temp("obj/where") != environment(me)->query("outdoors"))
        {
          tell_object(me,"总管要你来的，不是这个地方吧？\n");
          return 1;
        }
        else
        if (environment(me)->query_temp("chuaimo") >= 1)
        {
          tell_object(me,HIC"\n你本想在这里开始练习琴画，但是突然想起刚才有人谈起过这里。\n看来刚刚有人在这里练习过，没有新意，还是换个地方揣摩琴画技艺吧 ..."NOR"\n\n");
          return 1;
        }
        else
        if(environment(me)->query("fjing")<1)
        {
        tell_object(me,HIC"\n这里景色太差，不适合揣摩琴画技艺！"NOR"\n\n");
        return 1;
        }
        else          
        if ((me->query("jing") < 100))
        {  
          tell_object(me,HIB"\n你的精力不济，需要调整一下才能练习！"NOR"\n\n");
          return 1;
        }
        else
        if ((me->query("qi") < 100 ))
        {
          tell_object(me,HIB"\n你的气血不佳，需要休息一下才能练习！"NOR"\n\n");
          return 1;
        }
        else          
	if (environment(me)->query_temp("chuaimo") >= 1)
        {
        tell_object(me,"看来刚刚有人在这里练习过，没有新意，还是换个地方揣摩吧。\n"NOR,me);
       	return 1;
      	}
      	else
        if (!arg || arg == "" )
        { 
          tell_object(me,"你要揣摩哪种技艺？
          \n    琴艺(qin)、画艺(hua)？\n\n");
          return 1;
        }
        else
        if ( arg == "hua" )
        {
          if(me->is_busy())
          return notify_fail("你正忙着呢!\n");
           
          message_vision(HIG"\n$N不禁对眼前美丽的精致大为折服，开始疾笔揣摩画画的技巧了。\n\n"NOR,me);          
          me->start_busy(8); 
          call_out("cmhua",8,me);
          return 1;
       	}
       	else
        if ( arg == "qin" )
        {
        if(me->is_busy()||me->is_fighting())
          return notify_fail("你正忙着呢!\n");
          
          message_vision(HIW"\n$N临山背水，心中顿生豪情，开始拨弄琴弦，揣摩琴艺了。\n\n"NOR,me);          
          me->start_busy(8); 
          call_out("cmqin",8,me);
          return 1;
       	}

}

int cmhua(object me)
{
    int jlexp;
    int rnd=random(5);

     if(random(sizeof(hua_msg))){
        message_vision(YEL"\n"+hua_msg[random(sizeof(hua_msg)-1)]+""NOR,me);
    environment(me)->set_temp("chuaimo",1);
      return 1;
        }
        //奖励 30*风景 左右的 exp,  琴画技艺熟练度增加 200

          jlexp=30*(int)environment(me)->query("fjing")+random(me->query("int"));
      message_vision(YEL"\n"+hua_msg[3]+""NOR,me);
        message_vision(HIY"$N作完一张精致的山水画，满意地欣赏着。\n"NOR,me);
        me->set_temp("obj/done",1);
        me->set("kunlun/jlexp",jlexp);
        environment(me)->set_temp("chuaimo",1);        
    //以下是加入一些突发事件
    if(rnd==0){
          object ob=new(__DIR__"rascal");
        ob->move(environment(me));
        ob->set("combat_exp",me->query("combat_exp"));
        tell_object(me,"小流氓恶狠狠的对你骂道：小兔崽子到我地盘上也不知道孝敬老子！\n",me);
        ob->kill_ob(me);
        }

        if(rnd==1){
          message_vision("围观的人众里走出一老者想要花重金买$N的画。\n",me);
      tell_object(me,"如果你同意的话，请输入（sell hua)。\n");
        tell_object(me,"如果你不同意的话，请输入（jujue)。\n");
    add_action("do_no","jujue");
    add_action("do_sell","sell");
    }
        return 1;
        }

int cmqin(object me)
{
    int jlexp;
    int rnd=random(5);
    if(random(sizeof(hua_msg))) {
              message_vision(YEL"\n"+qin_msg[random(sizeof(qin_msg)-1)]+""NOR,me);
    environment(me)->set_temp("chuaimo",1);
       return 1;
       }
        //奖励 30*风景 左右的 exp，琴画技艺熟练度增加 200
          jlexp=30*(int)environment(me)->query("fjing")+random(me->query("int"));
      message_vision(YEL"\n"+qin_msg[3]+""NOR,me);
        message_vision(HIY"$N一曲弹罢，豪情依然不能自已。\n"NOR,me);
        me->set_temp("obj/done",1);
        me->set("kunlun/jlexp",jlexp);
        environment(me)->set_temp("chuaimo",1);        
    //以下加入突发事件
    if(rnd==0){
              object ob=new(__DIR__"rascal");
               ob->move(environment(me));
          ob->set("combat_exp",me->query("combat_exp"));
             tell_object(me,"小流氓恶狠狠的对你骂道：小兔崽子到我地盘上也不知道孝敬老子！\n",me);
          ob->kill_ob(me);
          }
    if(rnd==1){
          object ob=new("/clone/money/gold");
          ob->set_amount(2);
    message_vision("围观的人群里有人花钱请你为大家再奏一曲。\n");
    tell_object(me,"如果你同意，请输入(yuanyi);否则，请输入(meikong)。\n");
    add_action("do_yuanyi","yuanyi");
    add_action("do_meikong","meikong");
    }
        return 1;
}


  int do_sell(string arg)
{
      object me=this_player();

    if(!arg||arg=="")
    return notify_fail("你要卖什么？\n");

      if(arg=="hua"||arg=="画"){
    object ob=new("/clone/money/gold");
      ob->set_amount(1+random(5));
          message_vision("老者给$N一些黄金，高高兴兴的把画拿走了。\n",me);
        ob->move(me);
        return 1;
    }
    }

int do_no()
{
    object me=this_player();
    me->add("combat_exp",10+random(20));
    me->add("shen",10+random(50));
      message_vision("$N不屑得笑了两声，说道“对不起，我没空！\n",me);
      message_vision("老者深深叹了口气，对着$N作了一揖，离开了！\n",me);
    return 1;
}

int do_yuanyi()
{
    object me=this_player();
    object ob=new("/clone/money/gold");
        ob->set_amount(1+random(5));

    message_vision("老者给$N一些黄金，高高兴兴的听$N有演奏了一曲。\n",me);
    me->start_busy(8);
    ob->move(me);
    return 1;
}
