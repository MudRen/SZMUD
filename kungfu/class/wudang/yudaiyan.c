
                        // Code of ShenZhou
// yu.c 俞莲舟
// Update by Scatter
// V 1.0


#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_zwz();
string ask_drug1();
string ask_drug2();
string ask_drug3();
string ask_drug4();

void create()
{
        set_name("俞岱岩", ({ "yu daiyan", "yu" }));
        set("nickname", "武当三侠");
        set("long", "他是武当七侠中的愈三侠，现掌管丹药房。\n"
                    "只见他面目憔悴，右手支撑着拐杖似乎十分吃力。\n"
                    "据说多年前因被歹人以大力金刚指捏碎四肢，后来虽得以黑玉断续膏治疗但仍无法痊愈。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 5);
        set("int", 38);
        set("con", 10);
        set("dex", 20);

        set("max_qi", 500);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 0);
        set("combat_exp", 1050000);
        set("shen", 80000);

        set_skill("force", 120);
        set_skill("taiji-shengong", 120);
        set_skill("dodge", 100);
        set_skill("tiyun-zong", 100);
        set_skill("strike", 90);
        set_skill("mian-zhang",90);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("taiji-jian", 100);
        set_skill("literate", 150);
        set_skill("taoism", 150);
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("strike", "mian-zhang");
        map_skill("sword", "taiji-jian");
        prepare_skill("strike", "mian-zhang");
        create_family("武当派", 2, "弟子");
        set("inquiry", ([
        "丹药房" : "这里还没用完全开放，请耐心等待。\n",
        "天心解毒丹" : (:ask_drug1:),
        "三黄宝腊丸" : (:ask_drug2:),
        "天王护心丹" : (:ask_drug3:),
        "白虎夺命丸" : (:ask_drug4:),
                "真武七截阵" : (: ask_zwz :),
        
        ]));
        
        set("drug1_count", 5);
        set("drug2_count", 5);
        set("drug3_count", 5);
        set("drug4_count", 3);
        
        setup();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

string ask_drug1()
{ 
        mapping fam; 
        object me, ob,*obs;
        me=this_player();
        ob=this_object();
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
        return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        
        if (me->query_temp("obtained_drug1"))
        {
        command("hmm "+me->query("id"));
        return "天心解毒丹不是已经给过你了吗？";
        }
        
        obs = filter_array(children("/clone/drug/tianxin.c"), (: clonep :));
        if (sizeof(obs) > 5)
return "你来晚了，天心解毒丹都已经被其他同门拿走了，需要再行炼制。";

        if (query("drug1_count") < 1)
return "你来晚了，天心解毒丹都已经被其他同门拿走了，需要再行炼制。";
        
        ob=new("/clone/drug/tianxin");
        ob->move(me);
        add("drug1_count", -1);
        me->set_temp("obtained_drug1", 1);
        message_vision("俞岱岩转身找了找，在架子上拿下了一个小白瓶，从里面倒了一颗药丸出来给$N。\n",me);
        return "好吧，这里有一颗天心解毒丹，切记要慎用。";
}
        
string ask_drug2()
{ 
        mapping fam; 
        object me, ob,*obs;
        me=this_player();
        ob=this_object();
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
        return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        
        if (me->query_temp("obtained_drug2"))
        {
        command("hmm "+me->query("id"));
        return "三黄宝腊丸不是已经给过你了吗？";
        }
        
        obs = filter_array(children("/clone/drug/sanhuang-wan.c"), (: clonep :));
        if (sizeof(obs) > 5)
return "你来晚了，三黄宝腊丸都已经被其他同门拿走了，需要再行炼制。";

        if (query("drug2_count") < 1)
return "你来晚了，三黄宝腊丸都已经被其他同门拿走了，需要再行炼制。";
        
        ob=new("/clone/drug/sanhuang-wan");
        ob->move(me);
        add("drug2_count", -1);
        me->set_temp("obtained_drug2", 1);
        message_vision("俞岱岩转身找了找，在架子上拿下了一个小白瓶，从里面倒了一颗药丸出来给$N。\n",me);
        return "好吧，这里有一颗三黄宝腊丸，切记要慎用。";
}

string ask_drug3()
{ 
        mapping fam; 
        object me, ob,*obs;
        me=this_player();
        ob=this_object();
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
        return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        
        if (me->query_temp("obtained_drug3"))
        {
        command("hmm "+me->query("id"));
        return "天王护心丹不是已经给过你了吗？";
        }
        
        obs = filter_array(children("/clone/drug/huxin"), (: clonep :));
        if (sizeof(obs) > 5)
return "你来晚了，天王护心丹都已经被其他同门拿走了，需要再行炼制。";

        if (query("drug3_count") < 1)
return "你来晚了，天王护心丹都已经被其他同门拿走了，需要再行炼制。";
        
        ob=new("/clone/drug/huxin");
        ob->move(me);
        add("drug3_count", -1);
        me->set_temp("obtained_drug3", 1);
        message_vision("俞岱岩转身找了找，在架子上拿下了一个小白瓶，从里面倒了一颗药丸出来给$N。\n",me);
        return "好吧，这里有一颗天王护心丹，切记要慎用。";
}

string ask_drug4()
{ 
        mapping fam; 
        object me, ob,*obs;
        me=this_player();
        ob=this_object();
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
        return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        
        if (me->query_temp("obtained_drug2"))
        {
        command("hmm "+me->query("id"));
        return "白虎夺命丸不是已经给过你了吗？";
        }
        
        obs = filter_array(children("/clone/drug/baihu.c"), (: clonep :));
        if (sizeof(obs) > 5)
                return "你来晚了，白虎夺命丸都已经被其他同们拿走了，需要再行练制。";

        if (query("drug2_count") < 1)
return "你来晚了，白虎夺命丸都已经被其他同门拿走了，需要再行炼制。";
        
        if (me->query("combat_exp") < 50000 )
        {
        command("look "+me->query("id"));
return "白虎夺命丸配制极为不易，以你目前的功力应该不会需要的，以后再说吧。";
        }
        ob=new("/clone/drug/baihu");
        ob->move(me);
        add("drug2_count", -1);
        me->set_temp("obtained_drug2", 1);
        message_vision("俞岱岩转身找了找，在架子上拿下了一个小白瓶，从里面倒了一颗药丸出来给$N。\n",me);
        return "好吧，这里有一颗白虎夺命丸，它配置不易切记要慎用。";
}


int ask_zwz()
{
        object me = this_player();

                if ( !me->query("zhenwu/4x") )
                {
                        command("say 你基本的都不会，我还不能教你。");
                        return 1;
                }

                if ( me->query_temp("zhenwu/asking") )
                {
                                command("say 你是不想学了是不是？");
                                return 1;
                }
                if ( me->query("zhenwu/3x") )
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
                command("say 我这是实际招数，看清楚啦！");
        message_vision(HIW"俞岱岩在空中画了很多圈，大圈，小圈，高圈，低圈，双圈，单圈，圈中圈，正圈，反圈，阴圈，阳圈。\n"NOR, me);
        message_vision(HIY"俞岱岩气定神闲，将内力收回丹田\n"NOR, me);
        command("say 你看懂了吗？");

		message_vision(NOR"$N反复琢磨着俞岱岩所授的阵法要诀。\n"NOR, me);

        call_out("steptwo",10,me);
}

void steptwo(object me)
{
        int rndnum;
        rndnum = random(210);

                me->delete_temp("zhenwu/asking");

        if(rndnum < 190)
        {
                message_vision(HIR"$N突然一阵晕眩，眼前的一切似乎都在打转。．\n"NOR, me);
                me->unconcious();
                return;
        }
        else
        {
                message_vision(HIC"$N心演阵法，灵动如长蛇，凝重如乌龟，对阵法大有领悟！\n"NOR, me);
                me->set("zhenwu/3x", 1);
                return;
        }
}
