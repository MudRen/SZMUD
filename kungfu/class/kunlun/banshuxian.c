// bashuxian.c (kunlun)

inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_qupu();

void create()
{
	set_name("班淑娴", ({ "ban shuxian", "ban" }));
	set("title", "昆仑派掌门夫人");
	set("long",
		"她就是昆仑派掌门、名扬江湖的铁琴先生何太冲的夫人。\n"
		"她是一个身材高大的半老女子，头发花白，双目含威，眉心间聚有煞气。\n");
	set("gender", "女性");
	set("age", 44);
	set("attitude", "heroism");
        set("shen_type", 1);
	set("str", 26);
	set("int", 24);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 4000);
	set("max_jingli", 4000);
	set("jingli", 4000);
    set("max_jing", 1000);
	set("neili", 5500);
	set("max_neili", 5500);
	set("jiali", 50);
	set("combat_exp", 1800000);
	set("score", 40000);

    set_skill("qinqi-shuhua", 200);
	set_skill("taoism",200);
    set_skill("literate", 200);
	set_skill("force", 220);
    set_skill("xuantian-wuji", 220);
    set_skill("cuff", 220);
    set_skill("zhentian-quan", 220);
    set_skill("dodge", 220);
	set_skill("taxue-wuhen", 220);
    set_skill("strike", 220);
    set_skill("kunlun-zhang", 220);
	set_skill("parry", 220);
        set_skill("throwing", 220);
        set_skill("mantian-huayu", 220);
	set_skill("sword", 220);
    set_skill("liangyi-jian", 220);
	
	
	map_skill("force", "xuantian-wuji");
	
	map_skill("strike", "kunlun-zhang");
	map_skill("dodge", "taxue-wuhen");
        map_skill("cuff", "zhentian-quan");
    map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");
        map_skill("throwing", "mantian-huayu");
    prepare_skill("strike", "kunlun-zhang");
    prepare_skill("cuff", "zhentian-quan");

	create_family("昆仑派", 4, "掌门夫人");
	set("class", "taoist");

		set("inquiry",
		([  
            "两仪剑法" : "那是本门不外传的绝学。\n",
            "两仪剑" : "那是本门不外传的绝学。\n",
              "五姑" : "这个不要脸的女人，总有一天我会杀了她。\n",
			"何太冲" : "他是我的丈夫。\n",
		    "何足道" : "他是本派掌门。\n",
		    "秘籍" : (: ask_me :),
                    "曲谱" : (: ask_qupu :),
		]));

	set("book_count", 1);

	setup();
	carry_object("/d/kunlun/obj/sword.c")->wield();
	carry_object("/d/kunlun/obj/pao2.c")->wear();

}

void attempt_apprentice(object ob)
{
/*	 if((int)ob->query("shen")<0){
	 command("say 我昆仑乃是堂堂名门正派，"+RANK_D->query_respect(ob)+
				"的品德实在令人怀疑。");
	 command("say "+RANK_D->query_respect(ob)+
				"还是先回去做点善事吧。");
	 return;
	 }
*/
	 if ((string)ob->query("gender") != "女性") {
                command("say 我只收女弟子，" + RANK_D->query_respect(ob) + "还是拜入铁琴先生门下吧。");
                return;
        } 
                if ((int)ob->query_skill("qinqi-shuhua", 1) < 5) {
                command("say 我昆仑派历来讲究琴剑双绝。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该先在琴棋书画上多下点功夫？");
                return;
        }

	 if( ob->query("family/family_name") != "昆仑派" && ob->query("combat_exp") >= 100000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "是"
                        +ob->query("family/family_name")+"高手，本派可不敢收留！");
                return;
        }

	 command("say 好吧，以后你就跟我学武功吧，你须得安心学艺，不可乱来。");
	 command("recruit " + ob->query("id"));
}


string ask_me()
{
		  mapping fam;
		  object ob , me = this_player();
		  


		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "昆仑派")
					 return RANK_D->query_respect(this_player()) +
					 "与本派素无来往，不知此话从何谈起？";
//			 if(ob->query("gender")=="男性")
//        	     	 return "给我走开，我看见你们这些臭男人就烦。";
//                    if (query("book_count") < 1)
                                         return "被那该死的和太冲拿走了。";
//                    add("book_count", -1);
//                 ob = new("/d/kunlun/obj/lyj-book");
//                    CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到一本两仪剑谱。", me->query("name")));
//                    ob->move(me); 
//                    return "先师曾传下来这本「两仪剑心得」，你拿回去好好钻研。";
}
string ask_qupu()
{
		  mapping fam;
		  object ob , me = this_player();
		  


		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "昆仑派")
					 return RANK_D->query_respect(this_player()) +
					 "与本派素无来往，不知此话从何谈起？";
		  if (query("book_count") < 0)
					 return "你来晚了，本派的曲谱已被你师兄拿走了。";
		  add("book_count", -1);
		  ob = new("/d/kunlun/obj/qupu.c");
		  ob->move(this_player());
		  return "这是掌门自己所写的曲谱，你拿回去好好练习一下。";
}

