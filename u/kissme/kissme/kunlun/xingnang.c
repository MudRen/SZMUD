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
    "突然天上传来一声飞禽的鸣叫，将$P胸中作画的思路打断了。\n",
    "$P画了一会，感觉越画越不满意，索性拿了一张纸，重新开始画了。\n",
    "$P感觉画笔犹如神助，将胸中的壮美画卷，一笔一笔地描绘了出来！\n",
          });

  string *qin_msg = ({
    "$P感觉心中一阵烦躁，结果都没有弹完一首完整的曲子。\n",
    "突然从天上传来一阵清脆的鸟叫，将$P的演奏完全打断了！\n",
    "$P弹了一会，感觉兴味索然，便深深地吸了一口气，决定重头再来！\n",
    "从$P指下传来的琴声，犹如天籁之音，曲尽而意未尽！\n",
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
		set("long", "这是一套昆仑弟子外出携带的行囊，里面有一副围棋、文房四宝和一些水彩，\n以便昆仑弟子外出揣摩(chuaimo)琴画的技艺。\n");
		set("value", 0);
	}
	setup();
}

int do_chuaimo(string arg)
{
        object me=this_player();


        if (me->query_temp("obj/done") >= 1)
        {
          tell_object(me,HIG"\n终于今天有些收获，改天再来吧。"NOR"\n\n");
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
          tell_object(me,"库房先生要你来的，不是这个地方吧？\n");
          return 1;
        }
        else
        if (environment(me)->query_temp("chuaimo") >= 1)
        {
          tell_object(me,NOR"\n你本想在这里开始练习琴画，但是周围的人群还没有散去，正在讨论琴技和画艺。\n看来刚刚有人在这里练习过，还是换个地方吧。"NOR"\n\n");
          return 1;
        }
        else
        if(environment(me)->query("fjing")<1)
        {
        tell_object(me,HIB"\n这里景色太差，丝毫找不到灵感揣摩琴画技艺！"NOR"\n\n");
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
          return notify_fail("你正忙着呢。\n");
           
            message_vision(NOR"\n眼前的景色让$N陶醉不已，$N开始专注地提笔揣摩作画的技巧了。\n\n"NOR,me);          
            me->add("jing",-random(60));
          me->start_busy(8); 
          call_out("cmhua",8,me);
          return 1;
       	}
       	else
        if ( arg == "qin" )
        {
        if(me->is_busy()||me->is_fighting())
          return notify_fail("你正忙着呢。\n");
          
          message_vision(NOR"\n临山背水，$N心中豪情万丈，便开始拨弄琴弦，揣摩琴艺了。\n\n"NOR,me);          
          me->add("jing",-random(60));
          me->start_busy(8); 
          call_out("cmqin",8,me);
          return 1;
       	}

}

int cmhua(object me)
{
    int jlexp;
    int rnd=random(5);
      int asnum=me->query("int")*me->query_skill("qinqi-shuhua");

     if(random(sizeof(hua_msg))){
        message_vision(YEL"\n"+hua_msg[random(sizeof(hua_msg)-1)]+""NOR,me);
      return 1;
        }
        //奖励 30*风景 左右的 exp,  琴画技艺熟练度增加 200

          jlexp=150*(int)environment(me)->query("fjing")+random(me->query("int"));
      message_vision(YEL"\n"+hua_msg[3]+""NOR,me);
        message_vision(HIY"$N终于完成了一张风景画卷，满意地欣赏着。\n\n"NOR,me);
        me->add_temp("chuaimo/done",100+me->query("int"));
      if(me->query_temp("chuaimo/done")>asnum){
        me->set_temp("obj/done",1);
        me->set("kunlun/jlexp",jlexp);
          environment(me)->set_temp("chuaimo",1);        
        message_vision(HIW"$N仔细揣摩了一番琴艺，自感受益匪浅。\n\n"NOR,me);
          me->delete_temp("chuaimo/done");
    }
    //以下是加入一些突发事件
    if(rnd==0){
          object ob=new(__DIR__"rascal");
        ob->move(environment(me));
        ob->set("combat_exp",me->query("combat_exp"));
        tell_object(me,NOR"突然人群一阵嘈杂，有个流氓分开人群走到你的面前。\n"NOR,me);
        tell_object(me,CYN"小流氓冷笑道：小兔崽子到我地盘上，也不知道孝敬老子？！\n"NOR,me);
        tell_object(me,CYN"小流氓恶狠狠地说道：老子教训你一下，让你吸取一些教训。\n"NOR,me);
        ob->kill_ob(me);
        }

        if(rnd==1){
          message_vision("围观的人众里走出一老者，想要花重金买$N的画。\n",me);
        tell_object(me,"你在考虑，是要卖画（"HIW"sell hua"NOR")，还是拒绝("HIW"jujue"NOR")。\n");
    add_action("do_no","jujue");
    add_action("do_sell","sell");
    }
        return 1;
        }

int cmqin(object me)
{
    int jlexp;
    int rnd=random(5);
    int asnum=me->query("int")*me->query_skill("qinqi-shuhua");

    if(random(sizeof(hua_msg))) {
              message_vision(YEL"\n"+qin_msg[random(sizeof(qin_msg)-1)]+""NOR,me);
       return 1;
       }
        //奖励 30*风景 左右的 exp，琴画技艺熟练度增加 200
          jlexp=150*(int)environment(me)->query("fjing")+random(me->query("int"));
      message_vision(YEL"\n"+qin_msg[3]+""NOR,me);
        message_vision(HIY"\n$N一曲弹罢，豪情依然不能自已。\n"NOR,me);
       me->add_temp("chuaimo/done",me->query("int"));
    if(me->query_temp("chuaimo/done")>asnum){
        me->set_temp("obj/done",1);
       me->set("kunlun/jlexp",jlexp);
       environment(me)->set_temp("chuaimo",1);
       message_vision("\n$N仔细揣摩了一番之后，感到受益非浅！\n",me);
          me->delete_temp("chuaimo/done");
    }
    //以下加入突发事件
    if(rnd==0){
              object ob=new(__DIR__"rascal");
               ob->move(environment(me));
          ob->set("combat_exp",me->query("combat_exp"));
             tell_object(me,NOR"\n突然人群一阵嘈杂，有个流氓分开人群走到你的面前。\n"NOR,me);
             tell_object(me,CYN"小流氓冷笑道：小兔崽子到我地盘上，也不知道孝敬老子？！\n"NOR,me);
             tell_object(me,CYN"小流氓恶狠狠地说道：老子教训你一下，让你吸取一些教训。\n"NOR,me);
          ob->kill_ob(me);
          }
    if(rnd==1){
          object ob=new("/clone/money/gold");
          ob->set_amount(2);
    message_vision("\n围观的人群中走出一位老婆婆，一个劲地夸你的琴艺。\n她想花钱请你为大家再奏一曲。\n");
    tell_object(me,"如果你同意就输入愿意("HIW"yuanyi"NOR")，要不然你也可以推委没空("HIW"meikong"NOR")。\n");
    add_action("do_yuanyi","yuanyi");
      add_action("do_no","jujue");
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
    me->add("combat_exp",100+random(20));
    me->add("shen",10+random(50));
        message_vision("\n$N思量自己外出揣摩不图名不图利，只为了技艺的精进，所以没有同意。\n",me);
      message_vision("老者深深叹了口气，失望地消失在人群中了。\n",me);
      message_vision("$N感觉自己的经验和正气提高了不少！\n",me);
    return 1;
}

int do_yuanyi()
{
    object me=this_player();
    object ob=new("/clone/money/gold");
        ob->set_amount(1+random(5));
    message_vision("老者给$N一些黄金，乡亲们高高兴兴的听$N有演奏了一曲。\n",me);
    me->start_busy(8);
    ob->move(me);
    return 1;
}
