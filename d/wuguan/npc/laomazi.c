// 侠客行100海洋版II
// xiaoer.c 平安城店小二
// 星星lywin 2000/6/1 儿童节
// recode by sinan@sz 2002_3_29
// 简化了任务流程，整个任务首先向小二问任务(ask xiao about job)，
// 然后向小二要盘子(ask xiao about panzi)，小二给你一些盘子以后，
// 到厨房去洗干净盘子(xi panzi),洗干净后交给小二，任务完成，得到
// 奖励。
// 店小儿改名为老妈子，filename: /d/wuguan/npc/laomazi.c  sinan@sz 02-4-8

#include <ansi.h>
#include <command.h>
inherit NPC;

int ask_done();
int do_gongzuo();
string ask_panzi();

void create()
{
        set_name("老妈子", ({"lao mazi", "lao"}));
        set("gender", "女性");
        set("age", 55);
      set("long", 
              "她就是武馆的厨师老妈子。\n");
        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("per", 25);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "工作" : (: do_gongzuo :),
                "job"  : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
                "盘子" : (: ask_panzi :),
                "panzi": (: ask_panzi :),
                "done": (: ask_done :),
                "over": (: ask_done :),
                "完成": (: ask_done :),
        ]) );
        setup();
        carry_object("clone/armor/cloth")->wear();
}

int do_gongzuo()
{      
        object me;
        me = this_player(); 
        
        if (me->query("combat_exp") >= 5000) {
                tell_object(me,"这点小事怎么敢劳您的大驾。\n");
                return 1;
        }  
        if( me->query_temp("gongzuo/xipanzi") > 0) {
                tell_object(me,"快去洗盘子吧。\n");
                return 1;
        }  
        
                tell_object(me,CYN"老妈子对你说道：这几天客人多！盘子洗不过来，你愿意干的话，可以帮我洗盘子。\n"NOR); 
        me->set_temp("gongzuo/xipanzi", 1);
        
        return 1;   
}

string ask_panzi()
{
        object me,ob;
        me = this_player(); 
        if( me->query_temp("gongzuo/xipanzi")< 1)
                return "你需要工作的话，也得和我打个招呼嘛！\n";
                
        if( me->query_temp("gongzuo/geipanzi")> 0)
                return "我不是给过你盘子了吗？难道你丢了它？";
                
        ob = new("/d/wuguan/obj/zangpanzi");
        ob->move(me);
        me->set_temp("gongzuo/geipanzi", 1);
        message_vision("老妈子给了$N一叠脏盘子。\n",me);
        return "好吧，你快去厨房洗赶干净这些盘子吧。";
}

/*
void accept_object(object me, object ob)
{
        int exp,pot;

        if ( (int)me->query("combat_exp") > 5000)
                command("say 这种活不是您这样的大侠干的。\n");
                                
        if ( me->query_temp("gongzuo/xipanzi") < 1 ) {
                command("say 你没有找我要过工作吧。\n");
        }
        
        else if ( ob->query("name") != "盘子" ) {
                command("say 这是洗好的盘子？你不是开玩笑吧！\n");
        }
        
        else
        {
                message_vision(CYN"老妈子对$N说道：辛苦了。经过锻炼，
                        你的经验又增长了一些。\n"NOR,me);
      
                me->delete_temp("gongzuo");
               me->add("combat_exp",exp = 30 + random(40) );
                me->add("potential",pot = 10 + random(20) );
               log_file("xipanzi", me->query("id")+"得到"+exp+"点经验"+pot+"点潜能"+"["+ctime(time())+"]\n" );
//                call_out("destroying", 1, this_object(), ob);
        }
}
void destroying(object me, object obj)
{
//        destruct(obj);
        return;
}
*/
int ask_done()
{
        int exp,pot;
        object ob,me;
        me=this_player();
        
        if ( (int)me->query("combat_exp") > 5000)
                return notify_fail("这种活不是您这样的大侠干的。\n");
                                
        if ( me->query_temp("gongzuo/xipanzi") < 1 ) {
                return notify_fail("你没有找我要过工作吧。\n");
        }
        
        else if ( !( ob = present("pan zi", this_player() )) ) {
                return notify_fail("你把盘子搞丢了？\n");
        }
        
        else
        {
                message_vision(CYN"老妈子对$N说道：辛苦了。经过锻炼，
                        你的经验又增长了一些。\n"NOR,me);
                
                destruct(ob);
                
                me->delete_temp("gongzuo");
                me->add("combat_exp",exp = 30 + random(40) );
                me->add("potential",pot = 10 + random(20) );
     if(me->query("potential")>me->query("max_potential")) 
      me->set("potential",me->query("max_potential")); 
                
                log_file("xipanzi", me->query("id")+"得到"+exp+"点经验"+pot+"点潜能"+"["+ctime(time())+"]\n" );
                
                return 1;
        }
}
