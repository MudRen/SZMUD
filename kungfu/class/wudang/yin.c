// Code of ShenZhou
// /kungfu/class/wudang/yin.c 殷梨亭
// xQin 14/08/99
// xQin 15/2/99
// xQin 04/01
// UPDATE BY SCATTER
// 1/9/2002

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_me(object me);
int ask_zwz();

int auto_perform();

void create()
{
        set_name("殷梨亭", ({ "yin liting", "yin" }));
        set("nickname", "武当六侠");
        set("long",
                "他就是张三丰的六弟子殷梨亭。\n"
                "他今年虽才三十多岁，但已经满面风尘之色，两楚微见斑白。\n"
                "在武当七侠中排名第六，武当剑法尤为精通。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 32);
        set("int", 38);
        set("con", 36);
        set("dex", 38);

        set("max_qi", 2600);
        set("max_jing", 2200);
        set("neili", 3200);
        set("max_neili", 3200);
        set("jiali", 100);
        set("combat_exp", 800000);
        set("shen", 80000);

        set_skill("force", 160);
        set_skill("taiji-shengong", 160);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 180);
        set_skill("cuff", 120);
        set_skill("taiji-quan", 120);
        //set_skill("chang-quan", 120);
        set_skill("strike", 120);
        set_skill("mian-zhang",120);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        //set_skill("wudang-jian", 200);
//      set_skill("throwing", 100);
        set_skill("literate", 180);
        set_skill("taoism", 180);
       // set_skill("taiji-gong",140);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");
        prepare_skill("strike", "mian-zhang");

        create_family("武当派", 2, "弟子");


       
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action("sword.shenmen") :),
        }) );

        set("inquiry", ([
                "天地同寿" : (: ask_me :),
                "纪晓芙" : "可怜我那未过门的妻子，居然被杨逍那淫徒。。。",
                "杨逍" : "总有一天我要手刃这魔教淫贼，以祭晓芙在天。。。",
                "神门十三剑" : "神门十三剑乃。。。 唉，可怜晓芙居然被杨消那淫徒。。。",
                                "真武七截阵" : (: ask_zwz :),

        ]));

        
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
        command("sigh");
        command("say 虽然" + RANK_D->query_respect(ob) + "也是" +
                "我辈中人，但自晓芙去后，我已无心收徒；不过你我今日"+
                "相见也是有缘，我就传你一式“天地同寿”，也不枉你我相"+
                "识一场。");

        ob->set("yinliting_teach",1);
}

string ask_me(object me)
{
        mapping fam; 
        me=this_player();
        
        if(me->query("family/family_name") != "武当派")
        {
        return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        }

        if(me->query_skill("taiji-shengong") < 60 )
        {
        command("say 我武当派乃内家武功，最重视内功心法。"); 
        return RANK_D->query_respect(me) + "是否还应该在太极神功上多下点功夫？";
        }

        if(me->query("shen") < 800000 )
        {
        command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
        return RANK_D->query_respect(me) + "若能做出" + "几件侠义之事，我一定收你。";
        }

        me->set("yinliting_teach", 1);
        command("sigh");
        return RANK_D->query_respect(me) + "也是" +
        "我辈中人，但自晓芙去后，我已无心收徒；不过你我今日"+
        "相见也是有缘，我就传你一式“天地同寿”，也不枉你我相"+
        "识一场。";
        
}


int ask_zwz()
{
        object me = this_player();

                if ( !me->query("zhenwu/7x") )
                {
                        command("say 你基本的都不会，我还不能教你。");
                        return 1;
                }

                if ( me->query_temp("zhenwu/asking") )
                {
                                command("say 你是不想学了是不是？");
                                return 1;
                }
                if ( me->query("zhenwu/6x") )
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

                command("say 好吧！我就传授你「真武七截阵」的第五个位置．看好了是否能领悟就看你的了。");
        command("say 看清楚喔！");
                
                remove_action("do_xiang", "xiang");
                me->start_busy(20);

        call_out("stepone",5,me);
                return 1;
}

void stepone(object me)
{
        command("say 我先传授你口诀！");
        message_vision(HIC"殷梨亭将手上的剑放到胸前，口里念到\n天划一才得清明，\n地划一才得安宁，\n神划一才得灵冥，\n侯王得一才得成为天下之正统。\n殷梨亭手中的剑突然开始震动"NOR, me);
        message_vision(HIY"殷梨亭赶紧将内利收回。\n"NOR, me);
        command("say 你看懂了吗？");

                message_vision(NOR"$N反复琢磨着殷梨亭所授的阵法要诀。\n"NOR, me);

        call_out("steptwo",8,me);
}

void steptwo(object me)
{
        int rndnum;
        rndnum = random(200);

                me->delete_temp("zhenwu/asking");

        if(rndnum < 130)
        {
                                message_vision(HIR"$N突然一阵晕眩，眼前的一切似乎都在打转。．\n"NOR, me);
                me->unconcious();
                return;
        }
        else
        {
                                message_vision(HIC"$N心演阵法，灵动如长蛇，凝重如乌龟，对阵法大有领悟！\n"NOR, me);
                me->set("zhenwu/6x", 1);
                return;
        }
}