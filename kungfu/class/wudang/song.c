
                   // Code of ShenZhou
// song.c 宋远桥

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();
int ask_zwz();

int auto_perform();

void create()
{
        set_name("宋远桥", ({ "song yuanqiao", "song" }));
        set("nickname", "武当首侠");
        set("long", 
                "他就是张三丰的大弟子、武当七侠之首的宋远桥。\n"
                "只见他身穿一件干干净净的灰色道袍。看上去已年过五十，楚边微见花白，\n"
                "三络长须垂胸，满脸红光，脸上神情冲淡恬和，相貌甚是清雅，身材却稍有\n"
                "肥胖，想是中年发福。\n" );
        set("gender", "男性");
        set("age", 55);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 42);
        set("int", 40);
        set("con", 42);
        set("dex", 40);

        set("max_qi", 3500);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 120);
        set("combat_exp", 1100000);
        set("score", 60000);

        set_skill("force", 220);
        set_skill("taiji-shengong", 220);
        set_skill("dodge", 200);
        set_skill("tiyunzong", 200);
        set_skill("cuff", 220);
        set_skill("taiji-quan", 220);
        set_skill("strike", 180);
        set_skill("mian-zhang",180);
        set_skill("parry", 200);
        set_skill("sword", 160);
        set_skill("taiji-jian", 160);
        set_skill("literate", 101);
        set_skill("taoism", 200);
        //set_skill("taiji-gong",200);


        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");
        prepare_skill("strike", "mian-zhang");
        create_family("武当派", 2, "弟子");

        set("inquiry", ([
                "秘籍" : (: ask_me :),
                                "真武七截阵" : (: ask_zwz :),
        ]));

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("book_count", 1);

        setup();
//      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

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
                        "是否还应该在武当九阳功上多下点功夫？");
                return;
        }

        if ((int)ob->query("shen") < 35000) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，今天就收下你了。");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam; 
        object ob, *obs;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";

        if (query("book_count") < 1)
                return "你来晚了，本派的内功心法不在此处。";

        obs = filter_array(children(__DIR__"force_book.c"), (: clonep :));
        if (sizeof(obs) > 2)
                return "你来晚了，本派的内功心法不在此处。";

        ob=new(__DIR__"force_book");
        ob->move(this_player());
        add("book_count", -1);
        command ("rumor "+this_player()->query("name")+"弄到了一册太极十三式。");
        return "好吧，这本「太极十三式」你拿回去好好钻研。";
}

int ask_zwz()
{
        object me = this_player();

                if ( !me->query("zhenwu/2x") )
                {
                        command("say 你基本的都不会，我还不能教你。");
                        return 1;
                }

                if ( me->query_temp("zhenwu/asking") )
                {
                                command("say 你是不想学了是不是？");
                                return 1;
                }
                if ( me->query("zhenwu/1x") )
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

                command("say 好吧！我就传授你「真武七截阵」的第一个位置．看好了是否能领悟就看你的了。");
        command("say 看清楚喔！");
                
                remove_action("do_xiang", "xiang");
                me->start_busy(20);

        call_out("stepone",5,me);
                return 1;
}

void stepone(object me)
{
                command("say 我先传授你口诀！");
        message_vision(HIY"宋远桥向后跳，面朝前，剑朝后，左手握拳，右手放掌，左手阴，右手阳，以右手和到左手，一阳合并．\n"NOR, me);
        message_vision(HIY"宋远桥气定神嫌，将内力收回丹田\n"NOR, me);
        command("say 你看懂了吗？");

		message_vision(NOR"$N反复琢磨着宋远桥所授的阵法要诀。\n"NOR, me);

        call_out("steptwo",8,me);
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
                me->set("zhenwu/1x", 1);
                return;
        }
}
#include "/kungfu/class/wudang/auto_perform.h"
