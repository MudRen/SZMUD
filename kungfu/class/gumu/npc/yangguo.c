// yangguo.c 杨过
// by April 01/08/04
// update 01/08/06

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_mianju();

void create()
{
	object bj;	// 宝剑
	object me;

	set_name("杨过", ({ "yang guo", "yang"}));
	set("long", 
		"他身穿灰色长袍，右臂断了，空当当的衣袖束在腰带之中。只见他脸色焦黄，形容\n"
		+"枯槁，如同僵尸一般。只有一双眸子精光四射，英气逼人。\n");
	set("gender", "男性");
	set("nickname","神雕大侠");
    set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 25);
	set("int", 30);
	set("con", 30);
	set("dex", 25);

	set("max_qi", 6500);
	set("max_jing", 6000);
	set("jiali", 250);
	set("neili", 10500);
	set("max_neili", 10500);
	set("jingli",8000);
	set("eff_jingli",8000);
	set("max_jingli",8000);

	set("combat_exp", 5500000);
	set("shen", 3000000);

	set_skill("force", 360);
	set_skill("yunu-xinjing", 360);
	set_skill("strike", 380);
	set_skill("xiaohun-zhang",380);
	set_skill("cuff",300);
	set_skill("meinu-quan", 300);
	set_skill("sword", 360);
	set_skill("xuantie-jian", 360);
	set_skill("parry", 360);
	set_skill("dodge", 360);
	set_skill("feiyan-gong", 360);
	set_skill("bee-training",300);
	set_skill("lovingness",400);
	set_skill("suxin-jue",320);
	set_skill("throwing",320);
	set_skill("quanzhen-jian",320);

	map_skill("force", "yunu-xinjing");
	map_skill("dodge", "feiyan-gong");
	map_skill("cuff", "meinu-quan");
	map_skill("strike", "xiaohun-zhang");
	map_skill("parry", "xuantie-jian");
	map_skill("sword", "xuantie-jian");

	prepare_skill("strike", "xiaohun-zhang");
	prepare_skill("cuff", "meinu-quan");

	create_family("古墓派", 4, "弟子");

	set("spouse/id", "xiao longer");
	set("spouse/name", "小龙女");
	set("spouse/title", "妻子");

	set("chat_chance_combat", 50);

	set("inquiry", ([
		"面具" : (: ask_mianju :),
		]));

	setup();

	if( clonep() ){
		bj=carry_object("/kungfu/class/gumu/obj/junzi-jian");
		if( objectp(bj) ) bj->wield();
		else carry_object("/clone/weapon/zhujian")->wield();
		carry_object("/kungfu/class/gumu/obj/pao")->wear();
		carry_object("/kungfu/class/gumu/obj/mianju")->wear();
	}
}

void init()
{
        object ob;

        ::init();
        return;
}

void attempt_apprentice(object ob)
{
	if (ob->query("family/family_name") != "古墓派"){
		command ("say 我古墓派已经退隐江湖，不再收徒，你去吧。");
		return;
	}

	if (ob->query("gender")!="男性"){
		// 只收男性
		command("say 若真有心终老古墓，可以去找吾妻小龙女。");
		return;
	}

	if (ob->query_int() < 20 || ob->query_str() < 25 ) {
		// 悟性<25不收
	    command("say 我派武功博大精深，非凡夫俗子可为。你去吧...");
		return;
	}

	if ((int)ob->query_skill("yunu-xinjing", 1) < 90) {
		command("say 我古墓派武功以玉女心经为基础。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该多花点时间修习玉女心经？");
		return;
	}

	command("say 好吧，我就收下你了。");
    command("recruit " + ob->query("id"));
}

string ask_mianju()
{
	object pl = this_player();
	object me = this_object();
	object *inv;	// 身上带的东西
	int i,j;
	object mianju;

	if ( pl->query("family/family_name") != "古墓派" )
		return "承蒙错爱，面具并非什么宝物，不足为外人道。\n";

	inv = all_inventory(pl);
	j=0;
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("name") == WHT"面具"NOR )
			j += 1;
	if (j > 1){
		command("hmm "+pl->query("id"));
		command("smile "+pl->query("id"));
        return ("你也莫太贪心了！\n");
	}
	
	command("nod");
	mianju = new("/kungfu/class/gumu/obj/mianju");
	mianju->move(me);
	command("give mask to "+pl->query("id"));
	return ("别弄丢了！\n");
}