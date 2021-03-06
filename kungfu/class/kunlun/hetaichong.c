// hetaichong.c (kunlun)

inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_ding();
string ask_su();

void create()
{
	set_name("何太冲", ({ "he taichong", "he" }));
	set("title", "昆仑派掌门");
	set("nickname", "铁琴先生");
	set("long",
		"他就是昆仑派掌门、名扬江湖的铁琴先生何太冲。\n"
		"虽然年纪已大，但仍然看得出他年轻时英俊潇洒。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "heroism");
        set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 2500);
	set("max_jing", 2000);
	set("max_jingli",3000);
	set("jingli",3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
        set("combat_exp", 1800000);
	set("score", 40000);

        set_skill("qinqi-shuhua", 200);
		set_skill("taoism",200);
        set_skill("literate", 200);
          set_skill("force", 260);
        set_skill("xuantian-wuji", 260);
          set_skill("zhentian-quan", 260);
          set_skill("dodge", 260);
        set_skill("taxue-wuhen", 260);
        set_skill("throwing", 230);
        set_skill("mantian-huayu", 260);
        set_skill("strike", 260);
        set_skill("kunlun-zhang", 260);
        set_skill("cuff", 260);
        set_skill("parry", 260);
        set_skill("sword", 260);
        set_skill("liangyi-jian", 260);
       
        map_skill("force", "xuantian-wuji");
		map_skill("strike", "kunlun-zhang");
            map_skill("cuff", "zhentian-quan");
	    map_skill("dodge", "taxue-wuhen");
	    map_skill("parry", "liangyi-jian");
            map_skill("throwing", "mantian-huayu");
	    map_skill("sword", "liangyi-jian");

        prepare_skill("strike", "kunlun-zhang");
        prepare_skill("cuff", "zhentian-quan");

	create_family("昆仑派", 4, "掌门人");
	set("class", "taoist");

	set("inquiry",
		([
		    "两仪剑法" : "那是本门不外传的绝学。\n",
                     "丧门钉" : "你要这做什么?。\n",
                      "投掷秘诀" : "你去找我师弟西华子。\n",
            "何足道" : "是我昆仑派开山祖师。\n",
                      "五姑" : "小点声，不要让夫人听见了。\n",
                    "花园" : "我在西域为五姑带的灵脂兰(flower)都种在花园。\n",
     		"心法" : (: ask_me :),
			"苏习之" : (: ask_su :),
			"追杀" : (: ask_ding :),
		]));

	set("book_count", 1);
	set("ding_count", 18);

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
	 if(ob->query("gender")=="女性"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"老夫可不敢收女弟子，你去找班夫人吧.?");
	 return;
	 }
      
         if( ob->query("family/family_name") != "昆仑派" && ob->query("combat_exp") >= 100000 ) {
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
                if ((int)ob->query_skill("qinqi-shuhua", 1) < 5) {
                command("say 你一点应该去学一些琴艺画艺在来我昆仑山学习。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该先在琴棋书画上多下点功夫？");
                return;
        }
        
	 command("say 好吧，我便收下你，只是你投入我门下之后，须得安心学艺。");
	 command("recruit " + ob->query("id"));
}


string ask_me()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "昆仑派")
					 return RANK_D->query_respect(this_player()) +
					 "与本派素无来往，不知此话从何谈起？";
		  if (query("book_count") < 1)
					 return "你来晚了，本派心经已被你师兄拿走了。";
//          if(ob->query("gender")!="女性"||ob->query("per")<23)
//        	     	 return "本派心经不在我这里。";
	 	  add("book_count", -1);
		  ob = new("/d/kunlun/obj/force-book.c");
		  ob->move(this_player());
		  return "我这里有本「心法」，是有关吐呐吸气的，你拿回去好好钻研，有空多来找我哦";
}

string ask_ding()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "昆仑派")
					 return RANK_D->query_respect(this_player()) +
					 "与本派素无来往，不知此话从何谈起？";
		
                   if(this_player()->query_skill("mantian-huayu",1) < 20)
  return "自不量力的家伙，能使的了本门的独门暗器丧门钉吗?别去给为师丢脸,快给我滚!";
		   
	if ( present("sangmen ding", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有吗，怎么又来要了？";
		  if (query("ding_count") < 1)
					 return "丧门钉已给了我派去追杀苏习之的人，你就不用去了。";
		  add("ding_count", -1);
		  this_player()->set_temp("kunlun/ding",1);
		  ob = new("/d/kunlun/obj/sangmending.c");
		  ob->move(this_player());
		  return "你如此自愿为师门效力，不枉我平时一番栽培，这把丧门钉你就拿去吧。";
}
string ask_su()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "昆仑派")
					 return RANK_D->query_respect(this_player()) +
					 "与本派素无来往，不知此话从何谈起？";
		
		 if(this_player()->query_temp("kunlun/ding",1))
           return "你还待在这里做什么，还不快去追苏习之";
		  return "苏习之这家伙竟然敢偷看本派的两仪神剑，我派弟子必当将其追杀。";
}
