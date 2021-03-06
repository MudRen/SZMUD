
// Code of ShenZhou
// xi.c 张松溪
// Update by Scatter
// V 1.0


#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int ask_zwz();

void create()
{
        set_name("张松溪", ({ "zhang songxi", "zhang" }));
        set("nickname", "武当四侠");
        set("long", 
                "他就是张三丰的四弟子张松溪。\n"
                "他今年四十岁，身材短小精悍，满脸英气，\n"
                "为人精明能干，以足智多谋著称。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 36);
        set("int", 44);
        set("con", 37);
        set("dex", 36);

        set("max_qi", 3000);
        set("max_jing", 2600);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 110);
        set("combat_exp", 900000);
        set("score", 50000);

        set_skill("force", 180);
        set_skill("taiji-shengong", 180);
        set_skill("dodge", 170);
        set_skill("tiyunzong", 170);
        set_skill("cuff", 160);
        set_skill("taiji-quan", 160);
        set_skill("strike", 170);
        set_skill("mian-zhang",170);
        set_skill("parry", 180);
        set_skill("sword", 190);
        set_skill("taiji-jian",190);
        set_skill("literate", 180);
        set_skill("taoism", 180);

                set("inquiry", ([
                                "真武七截阵" : (: ask_zwz :),
        ]));
        //set_skill("taiji-gong",160);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");
        prepare_skill("strike", "mian-zhang");
        
        create_family("武当派", 2, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();

}

void attempt_apprentice(object ob)
{
        mapping fam;

        if( mapp(fam = ob->query("family")) && fam["family_name"] != "武当派" )
        {
                command ("say " + RANK_D->query_respect(this_player())
                        + "并非我门中人，习武还是先从各位道长起吧！");
                return;
        }

        if ((int)ob->query_skill("wudang-jiuyang", 1) < 60) {
                command("say 我武当派乃内家武功，最重视内功心法。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在武当九阳功上多下点功夫？");
                return;
        }

        if ((int)ob->query("shen") < 80000) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，我一定收你。");
                return;
        }
        command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
                "我辈中人，今天就收下你吧。");
        command("recruit " + ob->query("id"));
}

int ask_zwz()
{
        object me = this_player();

                if ( !me->query("zhenwu/5x") )
                {
                        command("say 你基本的都不会，我还不能教你。");
                        return 1;
                }

                if ( me->query_temp("zhenwu/asking") )
                {
                                command("say 你是不想学了是不是？");
                                return 1;
                }
                if ( me->query("zhenwu/4x") )
                {
                                command("say 你已经会啦，还要学干麻。");
                                return 1;
                }
        if ( me->query("combat_exp") < 100000 )
                {
                                command("say 你的实战经验还不足，现在最好不要学「真武七截阵」。");
                return 1;
                }
        if ( me->query_skill("taiji-shengong", 1) < 100 )
                {
                                command("say 你的内功基础还不够，学「真武七截阵」对你百害而无一益，以后再说吧。");
                                return 1;
                }
        if ( me->query_skill("taoism", 1) < 100 )
                {
                                command("say 你对道学心法还不够了解，所以你不能体会「真武七截阵」的阵意。");
                                return 1;
                }
        if ( me->query("int") < 20 )
                {
                                command("say 你的悟性不够高，不能领悟「真武七截阵」的阵意所在。");
                                return 1;
                }
        if ( me->query("max_neili") < 1000 )
                {
                                command("say 你的内力基础不好，先去打好基础再问我吧！");
                                return 1;
                }
        if ( me->query_skill("parry") < 100 )
                {
                                command("say 武当的绝学就是以柔克刚，你连一般东西都招架不住，怎么学「真武七截阵」？");
                                return 1;
                }
                if ( me->query("jing") < 300 )
                {
                                command("say 你现在过于疲劳，先去休息一下吧。");
                                return 1;
                }
        if ( me->query("jingli") < 2000 )
                {
                                command("say 练习「真武七截阵」不是一天两天的事，我看以你现在的体力还不适合练。");
                                return 1;
                }
		if ( me->query("neili") < 2000)
		{
			command("say 练习「真武七截阵」不是一天两天的事，你现在的内力还不适合练。");
			return 1;
		}

                command("say 你真的想学吗？");
                write(HIY"想学的话请打 xiang\n"NOR);
                me->set_temp("zhenwu/asking", 1);

                add_action("do_xiang", "xiang");
        
                return 1;

}

int do_xiang(string arg)
{
        object me = this_player();

                command("say 好吧！我就传授你「真武七截阵」的第四个位置．看好了是否能领悟就看你的了。");
        command("say 看清楚喔！");
                
                remove_action("do_xiang", "xiang");
                me->start_busy(20);

        call_out("stepone",5,me);
                return 1;
}

void stepone(object me)
{
                command("say 我这也是实际招数，看清楚啦！");
        message_vision(HIM"张松溪将手中的剑在空中画了个半圈，又将剑向左边推去，又将剑推向右边，手轴上提，剑转了一个圈中圈，\n将剑往第上一戳，没想到剑居然完全插到地里．\n"NOR, me);
        message_vision(HIY"张松溪气定神嫌，将内力收回丹田\n"NOR, me);
        command("say 你看懂了吗？");

		message_vision(NOR"$N反复琢磨着张松溪所授的阵法要诀。\n"NOR, me);

        call_out("steptwo",10,me);
}

void steptwo(object me)
{
        int rndnum;
        rndnum = random(300);

                me->delete_temp("zhenwu/asking");

        if(rndnum < 240)
        {
                message_vision(HIR"$N突然一阵晕眩，眼前的一切似乎都在打转。．\n"NOR, me);
                me->unconcious();
                return;
        }
        else
        {
                message_vision(HIC"$N心演阵法，灵动如长蛇，凝重如乌龟，对阵法大有领悟！\n"NOR, me);
                me->set("zhenwu/4x", 1);
                return;
        }
}
