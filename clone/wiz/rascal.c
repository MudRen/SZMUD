inherit NPC; 
#include <ansi.h>

string *ras_name = ({
        "流氓",
        "无赖",
        "地痞",
        "武林败类",
        "小混混",
        "叛徒",
        "浪人", 
});
 string *ras_id = ({
        "liu mang",
        "wu lai",
        "di pi",
        "wulin bailei",
        "xiao hunhun",
        "pan tu",
        "lang ren",     
});      
string *persuade_msg = ({
        "得饶人处且饶人，施主还是罢手不斗了吧！\n", 
        "别打了，有话好说，不要这般蛮横！\n",
        "两位休得伤了和气，不要再斗下去了吧！\n",
        "阿弥陀佛，大家江湖人士，怎地就动起粗来？两位还是住手吧！\n",
        "住手罢，大家无冤无仇，何必失了武林中的和气？\n",
        "多个朋友多条路, 两位何不化干戈为玉帛, 停手罢斗化敌为友呢？\n",
        "比武较量要点到为止，何必苦苦相斗，枉自伤了自家性命？\n",
});
string *succeed_msg = ({
        "良言相劝，暂且罢手, 在下后会有期。\n",
        "在此相劝，看在人家的面子上，这次就算了....后会有期。\n",
});

string  ask_per();

int do_quanfu(string);
int     per_end(object,object);
void dest_ob(object);


void create() 
{
        string a,b;
        int     i;
        i = random(7);
        a = ras_name[i];
        b = ras_id[i];
 
        set_name(a,({b})); 
        set("long","这是一个彪形大汉。\n"); 
        set("age",25); 
        set("shen_type",-1); 
        set("shen",-2000); 
        set( "str", 25 ); 
        set( "con", 20 ); 
        set( "int", 10 ); 
        set( "dex", 20 ); 
      
        set_skill("strike",20); 
        set_skill("force",20); 
        set_skill("dodge",20); 
        set_skill("parry",20); 
      
        set("combat_chat_chance",5); 
        set("inquiry",([
                "劝架" : (:ask_per:),
        ]));

        setup(); 
        add_money("silver",30); 
} 
void init()
{
        add_action("do_quanfu","quanfu");
}

int do_quanfu(string who)
{
        object me = this_player();
        object target;
        object where = environment(me);
        int     lvl=me->query_skill("persuading",1);
        mixed busy;
        
        if (me->query("family/family_name")!="峨嵋派") {
                command ("grin");
                return notify_fail("你也会劝驾吗？\n");
       }
        if (me->query_temp("mp_persjob")==2)
                return notify_fail("快回去相灭绝师太复命吧。\n");
        
        if ( me->query_temp("mp_persjob") != 1)
                return notify_fail("你在搞什么？\n");

        
        if (!who)
                return notify_fail("你要劝服谁？\n");
        
        target = present(who, environment(me));
        if ( !target || target == me || !living(target) || !objectp(target) ) 
                return notify_fail("你想劝服谁？\n");

        if ( busy = me->query_busy() ) {
                if (intp(busy) && busy<3) me->start_busy(busy+1);
                return notify_fail("你现在正忙着！\n");
        }
        
        if ( target->query("race") != "人类" )
                return notify_fail(target->name() + "听不懂人话！\n");

        if ( target->query("per_mark")!=me)
                return notify_fail("灭绝师太不是让你劝服这个人吧。\n");

        if ( me->query_temp("new_per") == 1)
                return notify_fail("你正在劝服别人。\n");

        if (me->query("jingli") < lvl || me->query("jing")<lvl)
                return notify_fail("你的身体状况不好，没有力气劝架了。\n");

       tell_object(me, HIY + "你对" + EMOTE_D->normal_color(target->name())
              + "说道：" + persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR); 

       tell_object(target, HIY + me->name() + "对你说道：" +
                persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR);

       message("vision", HIY + me->name() + "对" + EMOTE_D->normal_color(target->name()) 
                + "说道：" + persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR,
                where, ({ me, target }) );


        me->set_temp("new_per",1);
        if (me->query("combat_exp") < 100000)
        {
                me->add("jingli",-random(10));
        
        }
        else
        {
                me->add("jingli",-(10+random(lvl)));
                me->add("jing",-(10+random(lvl)));
        }
        if (!target->is_fighting())
        {
                message_vision(HIR"$N嘿嘿一笑，你是什么东西，敢劝老子? 老子宰了你。\n"NOR,target,me);
                target->kill_ob(me);
        }
        call_out("per_end",2+random(4),me,target);


        return 1;
}

int     per_end(object me,object target)
{
        int lvl = me->query_skill("persuading",1);
        int myexp = me->query( "combat_exp" ); 
        int level = to_int(pow(myexp*10,0.33333)+1); 

        if (environment(target) != environment(me)) {
                tell_object(me, "善哉，" + target->name() + "已经走了。\n"); 
                me->delete_temp("new_per");
                return 1;
        }

        if ( !living(target) || !target ) {
                tell_object(me, target->name() + "已不能听取你的劝导了！\n");
                me->delete_temp("new_per");
                return 1;
        }


        if (random(lvl/2) > random(level) || random(15) == 0)
        {
                tell_object(target, HIG + "你受到" + me->name()
                                  + "的感招，决定罢手不斗。\n" + NOR);
                tell_object(me, HIG + EMOTE_D->normal_color(target->name()) 
                              + "受到你佛法感招，决定罢手不斗。\n" + NOR);
              message("vision", CYN"只见" + EMOTE_D->normal_color(target->name()) 
                        + "往后一纵，说道：好！" + me->name() 
                        + succeed_msg[random(sizeof(succeed_msg))] + NOR, 
                        environment(target), ( {me, target} ) );

                tell_object(me,HIW"你的任务已经完成，快回去向灭绝师太复命去吧。\n"NOR);
                target->remove_all_killer();
                me->improve_skill("persuading",random(lvl));
                me->delete_temp("new_per");
                me->set_temp("mp_persjob",2);
                call_out("dest_ob",1,target);



        }
        else
        {
                tell_object(me, RED + EMOTE_D->normal_color(target->name()) + "冲你大喝一声：“"
                                       + RANK_D->query_rude(me) 
                                       + "多管闲事，看招！”\n" + NOR);
                tell_object(target, CYN + "你冲" + me->name() + "大喝一声：“"
                                          + RANK_D->query_rude(me)
                                          + "多管闲事，看招！”\n" + NOR);
                message("vision", CYN + "只见" + EMOTE_D->normal_color(target->name()) + "冲着"
                                        + me->name() + "大喝一声：“"
                                        + RANK_D->query_rude(me)
                                        + "多管闲事，看招！”\n" + NOR, environment(target),
                                        ( {me, target} ) );
                me->delete_temp("new_per");

        }
        me->start_busy(1+random(1));
        return 1;
}

string ask_per()
{
        object ob=this_object();
        object  me=this_player();

        if (ob->query("per_mark") == me)
        {
                ob->kill_ob(me);
                return "你是什么东西，敢对老子劝架。";
        }
        else
        {
                command("idle");
                return "你搞什么，都不晓得你在说什么。";
        }

}

void dest_ob(object target)
{
        destruct(target);
}
      
