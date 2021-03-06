// xihuazi.c (kunlun)

inherit NPC;
    string ask_me();
inherit F_MASTER;

void create()
{
	set_name("西华子", ({ "xi huazi", "xi" }));
	set("long",
		"他是昆仑派第五代弟子，满腮虬髯，性子十分暴躁。\n");
	set("gender", "男性");
	set("age", 26);
	set("attitude", "peaceful");
        set("shen_type", 1);
        set("book_count", 1);
	set("str", 30);
	set("int", 23);
	set("con", 25);
	set("dex", 28);

	set("max_qi", 800);
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 400000);
	set("score", 1000);

        set_skill("force", 80);
	set_skill("xuantian-wuji", 80);
	set_skill("dodge", 80);
	set_skill("taxue-wuhen", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("strike", 80);
	set_skill("kunlun-zhang", 80);
	set_skill("liangyi-jian", 80);
	
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
        map_skill("sword", "liangyi-jian");
        map_skill("strike", "kunlun-zhang");
	prepare_skill("strike", "kunlun-zhang");

	create_family("昆仑派", 5, "弟子");
set("inquiry",
                ([
                        "投掷秘诀" : (: ask_me :),
                           "丧门钉" : "是我昆仑派独门暗器。\n",
                ]));
	setup();
	carry_object("/d/kunlun/obj/sword")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
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
                                         return "你来晚了，投掷秘诀已被你师兄拿走了。";
                  add("book_count", -1);
                  ob = new("/d/kunlun/obj/throwing-book.c");
                  ob->move(this_player());
                  return "投掷秘诀在我这儿，记住一定要用丧门钉来练习，好好练也让人知道我们昆仑丧门钉的厉害!";
}





