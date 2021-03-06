// hezudao.c (kunlun)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("何足道", ({ "he zudao", "he" }));
	set("title", "昆仑派开山祖师");
	set("nickname", "昆仑三圣");
	set("long",
		"他就是昆仑派开山祖师，号称琴剑棋三绝的“昆仑三圣”。\n"
		"长脸深目，瘦骨棱棱，约莫三十岁左右年纪。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 28);

	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 200);
	set("max_jingli", 5000);
	set("jingli", 5000);
	set("combat_exp", 6400000);
	set("score", 400000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		 (: perform_action, "sword.xunlei" :)
	}));

        set_skill("qinqi-shuhua", 380);
		set_skill("taoism", 380);
        set_skill("literate", 300);
        set_skill("force", 400);
        set_skill("cuff", 400);
        set_skill("xuantian-wuji", 400);
        set_skill("dodge", 400);
        set_skill("taxue-wuhen", 400);
        set_skill("strike", 400);
        set_skill("kunlun-zhang", 400);
        set_skill("zhentian-quan", 400);
        set_skill("parry", 400);
        set_skill("sword", 420);
        set_skill("liangyi-jian", 420);
        
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("strike", "kunlun-zhang");
	map_skill("parry", "liangyi-jian");
        map_skill("cuff", "zhentian-quan");
        map_skill("sword", "liangyi-jian");
	prepare_skill("strike", "kunlun-zhang");
        prepare_skill("cuff", "zhentian-quan");

	create_family("昆仑派", 1, "开山祖师");
	        set("inquiry", ([
                            "两仪剑法" : "那是本门不外传的绝学。\n",
                            "两仪剑" : "那是本门不外传的绝学。\n",
                                            "班淑娴" : "她是铁琴先生的夫人。\n",
				                ]));

//	set("class", "taoist");
	setup();
	carry_object("/d/kunlun/obj/sword")->wield();
    carry_object("/d/kunlun/obj/pao4")->wear();

  }



void attempt_apprentice(object ob)
{
                mapping skill;
		string *skl;
                int i;

//		if(ob->query("kar") < 20)
//		return;

//		if(ob->query_int() < 32 ) {
//		command("say 弹琴下棋需要灵性极高的人才可以领悟其真谛，不致与武功背道而驰。");
//		command("say "+RANK_D->query_respect(ob)+"还是先回去多读点书吧。");
//		return;
//	}


        if( ob->query("family/family_name") != "昆仑派" && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "是"
                        +ob->query("family/family_name")+"高手，本派可不敢收留！");
                return;
        }

        if (ob->query("class")=="bonze") {
                command ("say 昆仑派一向不收出家人为徒，你请回吧。");
                return;
        }

	    if ((string)ob->query("gender") == "无性" && (int)ob->query_skill("pixie-jian",1) > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "你已经修行辟邪剑法,何必在练两仪剑。");
                return;
        }


                if ((int)ob->query_skill("xuantian-wuji", 1) < 100) {
		command("say 琴棋书画虽为小技，但也需内力融入其中。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该先在玄天无极功上多下点功夫？");
		return;
	}

		if ((int)ob->query("max_neili", 1) < 500) {
		command("say 内力不够，一心二用则极容易走火入魔。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该先好好修炼内力？");
		return;
	}

/*        	skill = ob->query_skills();
		skl = keys(skill);
		i = sizeof(skl);
		while (i--) {
                if (skill[skl[i]] < 80)
                command("say " + RANK_D->query_respect(ob) + 
		        "是否在" + 
		        CHINESE_D->chinese(skl[i]) + 
		        "上多下些功夫？");
        	return;
	}
*/	        
		command("say 看来你也是性情中人，我就教你一些琴剑棋的知识吧。");
		command("recruit "+ob->query("id"));

                ob->set("appren_hezudao", 1);
		ob->add("int", 1);
                ob->set_skill("qinqi-shuhua", ob->query_skill("literate",1));
//		ob->set_skill("literate", 10 + ob->query_skill("literate", 1));
}
