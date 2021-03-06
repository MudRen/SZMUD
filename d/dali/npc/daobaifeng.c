// Code of ShenZhou
// daobaifeng.c 刀白凤
// Acep

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("刀白凤", ({ "dao baifeng", "dao"}));
	set("long", 
"这是个容貌秀丽的中年道姑，是个摆夷族女子，颇有雍容气质。\n她本是大理国皇帝段正淳的正房原配夫人。\n因恼丈夫风流不羁，沾花惹草，一怒之下跑到这里出了家。");
	set("title","大理段氏王妃");
	set("nick","玉虚散人");
	set("gender", "女性");
	set("age", 35);
	
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 50);
	set("combat_exp", 300000);

	set("attitude", "peaceful");
	set("shen_type", 1);
	
	set_skill("strike", 80);
	set_skill("qingyan-zhang", 80);
	set_skill("dodge", 80);
	set_skill("duanshi-shenfa", 80);
	set_skill("parry", 80);
	set_skill("force", 70);
	set_skill("buddhism", 80);
	set_skill("sword", 70);
	set_skill("kurong-changong",70);
	set_skill("duanjia-jian", 70);
	set_skill("whip", 100);
	set_skill("feifeng-bian", 100);
	
	map_skill("dodge","duanshi-shenfa");
	map_skill("sword","duanjia-jian");
	map_skill("force","kurong-changong");
	map_skill("parry","duanjia-jian");
	map_skill("whip","feifeng-bian");
	prepare_skill("strike","qingyan-zhang");

	set("inquiry", ([
		"段正淳": "提那个负心人做什么？",
		"段誉"  : "唉，我好久没见到誉儿啦。",
        ]));
        
	create_family("大理段家", 15, "弟子");
	setup();

	carry_object("/d/dali/obj/ycloth")->wear();	
	carry_object("/d/quanzhou/obj/fuchen")->wield();
}

void attempt_apprentice(object ob)
{
	string current_title;
	current_title=ob->query("title");

	command ("look "+ob->query("id"));
	
	if (ob->query("gender")!="女性") {
		command("shake "+ob->query("id"));
		command("say 对不起，我只收女徒弟。");
		return;
	}
	if (ob->query("family/family_name")!="大理段家") {
		command("hmm "+ob->query("id"));
		command("say 你不是大理弟子啊，跑到我这里来干什么？");
		return;
        }

	command("say 好吧，我就收下你了，希望你好好学艺，不要给那些负心薄兴的臭男人欺负。");
	command("recruit " + ob->query("id"));
	ob->set("title", current_title);
	return;
}
