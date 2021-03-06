
                              // Code of ShenZhou
// yu.c 俞莲舟


#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_zwz();

void create()
{
        set_name("俞莲舟", ({ "yu lianzhou", "yu" }));
        set("nickname", "武当二侠");
        set("long", 
                "他就是张三丰的二弟子俞莲舟。\n"
                "他今年五十岁，身材魁梧，气度凝重。\n"
                "虽在武当七侠中排名第二，功夫却是最精。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 1200);
        set("max_jing", 1200);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 800000);
        set("shen", 80000);

                set("inquiry", ([
                                "真武七截阵" : (: ask_zwz :),
        ]));

        set_skill("force", 120);
        set_skill("taiji-shengong", 110);
        set_skill("dodge", 130);
        set_skill("tiyunzong", 130);
        set_skill("cuff", 110);
        set_skill("taiji-quan", 110);
        set_skill("parry", 130);
        set_skill("sword", 130);
        set_skill("taiji-jian", 130);
//      set_skill("taoism", 80);
//      set_skill("literate", 50);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");

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

        if ((int)ob->query_skill("taiji-shengong", 1) < 60) {
                command("say 我武当派乃内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在太极神功上多下点功夫？");
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

                if ( !me->query("zhenwu/3x") )
                {
                        command("say 你基本的都不会，我还不能教你。");
                        return 1;
                }

                if ( me->query_temp("zhenwu/asking") )
                {
                                command("say 你是不想学了是不是？");
                                return 1;
                }
                if ( me->query("zhenwu/2x") )
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

                command("say 好吧！我就传授你「真武七截阵」的第三个位置．看好了是否能领悟就看你的了。");
        command("say 看清楚喔！");
                
                remove_action("do_xiang", "xiang");
                me->start_busy(20);

        call_out("stepone",5,me);
                return 1;
}

void stepone(object me)
{
                command("say 我也先传授你口诀！");
        message_vision(HIG"俞莲舟左手阳右手阴正好与太极的道理相反　俞莲舟右手握拳　左手用掌　顿时间房间充满了一股热气．\n"NOR, me);
        message_vision(HIY"俞莲舟气定神嫌，将内力收回丹田\n"NOR, me);
        command("say 你看懂了吗？");

		message_vision(NOR"$N反复琢磨着俞莲舟所授的阵法要诀。\n"NOR, me);

        call_out("steptwo",10,me);
}

void steptwo(object me)
{
        int rndnum;
        rndnum = random(240);

                me->delete_temp("zhenwu/asking");

        if(rndnum < 220)
        {
                message_vision(HIR"$N突然一阵晕眩，眼前的一切似乎都在打转。．\n"NOR, me);
                me->unconcious();
                return;
        }
        else
        {
                message_vision(HIC"$N心演阵法，灵动如长蛇，凝重如乌龟，对阵法大有领悟！\n"NOR, me);
                me->set("zhenwu/2x", 1);
                return;
        }
}
