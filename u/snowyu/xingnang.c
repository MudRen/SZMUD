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
           
          message_vision(HIG"\n$N不禁对眼前美丽的精致大为折服，开始疾笔揣摩画画的技巧了。\n\n"NOR,me);          
          me->start_busy(8); 
          call_out("cmhua",8,me);
          return 1;
       	}
       	else
        if ( arg == "qin" )
        {
          
          message_vision(HIW"\n$N临山背水，心中顿生豪情，开始拨弄琴弦，揣摩琴艺了。\n\n"NOR,me);          
          me->start_busy(8); 
          call_out("cmqin",8,me);
          return 1;
       	}

}

int cmhua(object me)
{
        //奖励 30*风景 左右的 exp,  琴画技艺熟练度增加 200
        message_vision(HIY"$N作完一张精致的山水画，满意地欣赏着。\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("chuaimo",1);        
        return 1;
}

int cmqin(object me)
{
        //奖励 30*风景 左右的 exp，琴画技艺熟练度增加 200
        message_vision(HIY"$N一曲弹罢，豪情依然不能自已。\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("chuaimo",1);        
        return 1;
}

