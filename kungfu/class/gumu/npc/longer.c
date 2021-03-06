// longer.c 小龙女
// by April 01/08/03
// update 01/09/14

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_miansha();

void create()
{
	object bj;

	set_name("小龙女", ({ "xiao longer", "long", "longer" }));
    set("long", 
		"她披著一袭轻纱般的白衣，宛若身在烟中雾里的女神。她看起来不到三十岁，除了\n"
		+"一头披肩的黑发之外，全身素白。她面容秀美绝俗，只是肌肤间少了一层血色，显得\n"
		+"苍白异常。\n");
	set("gender", "女性");
	set("nickname","神雕侠侣");
	set("age", 38);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
        set("per", 35);
	set("max_qi", 4500);
	set("max_jing", 6000);
	set("jiali", 200);
	set("neili", 7500);
	set("max_neili", 7500);
	set("jingli",5500);
	set("eff_jingli",5500);
	set("max_jingli",5500);

	set("combat_exp", 4500000);
	set("shen", 1000000);

        set_skill("force", 360);
	set_skill("yunu-xinjing", 300);
	set_skill("cuff", 300);
	set_skill("meinu-quan", 300);
	set_skill("sword", 320);
	set_skill("yunu-jianfa", 320);
	set_skill("quanzhen-jian", 300);
	set_skill("finger", 300);
	set_skill("suhan-zhi", 300);
	set_skill("parry", 300);
	set_skill("dodge", 350);
	set_skill("feiyan-gong", 350);
	set_skill("bee-training",320);
	set_skill("lovingness",400);
	set_skill("parry",300);
	set_skill("suxin-jue",400);
	set_skill("zuoyou-hubo",300);
	set_skill("throwing",320);
	set_skill("whip",300);
	set_skill("jueqing-bian",300);
	set_skill("finger",300);
	set_skill("suhan-zhi",300);

	map_skill("force", "yunu-xinjing");
	map_skill("dodge", "feiyan-gong");
	map_skill("cuff", "meinu-quan");
	map_skill("parry", "yunu-jianfa");
	map_skill("sword", "yunu-jianfa");
	map_skill("whip", "jueqing-bian");
	map_skill("finger", "suhan-zhi");

	prepare_skill("cuff", "meinu-quan");
	prepare_skill("finger", "suhan-zhi");

	create_family("古墓派", 3, "弟子");

	set("spouse/id", "yang guo");
	set("spouse/name", "杨过");
	set("spouse/title", "丈夫");

	set("inquiry", ([
//		"job" : (: ask_job :),
		"面纱" : (: ask_miansha :),
        ]));

	set("chat_chance_combat", 50);

	setup();

	if( clonep() ){
		bj=carry_object("/kungfu/class/gumu/obj/shunv-jian");
		if( objectp(bj) ) bj->wield();
		else carry_object("/clone/weapon/changjian")->wield();
		carry_object("/kungfu/class/gumu/obj/white_silk")->wear();
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
	
	if (ob->query("gender")!="女性"){
		// 只收女性
		command("say 若想学得刚猛武功就去找我丈夫杨过吧。");
		return;
	}

	if (ob->query_per() < 25) {
		// 容貌<25不收
	    command("say 我派武功博大精深，你的资质似乎不够");
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

string ask_miansha()
{
	object pl = this_player();
	object me = this_object();
	object *inv;	// 身上带的东西
	int i,j;
	object miansha;

	if ( pl->query("family/family_name") != "古墓派" )
		return "承蒙错爱，面纱并非什么宝物，不足为外人道。\n";

	inv = all_inventory(pl);
	j=0;
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("name") == HIW"面纱"NOR )
			j += 1;
	if (j > 1){
		command("hmm "+pl->query("id"));
		command("smile "+pl->query("id"));
        return ("你也莫太贪心了！\n");
	}
	
	command("nod");
	miansha = new("/kungfu/class/gumu/obj/miansha");
	miansha->move(pl);
	command("smile "+pl->query("id"));
	command("give sha to "+pl->query("id"));
	return ("别弄丢了！\n");
}
