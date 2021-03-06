// Gumu NPC: Sun 
// /d/gumu/npc/sun.c 
// By jiuer--08/05/2001
// update april 01.10.30

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_job();
string ask_ping();
string ask_miansha();
string ask_jiedu();

void create()
{
	set_name("孙婆婆", ({
		"sun popo",
		"sun",
		"nanny",
	}));
	
	set("title", "古墓管家");
	set("long",
"她是小龙儿的贴身奶妈。她长着一张生满鸡皮疙瘩的丑脸，正瞪眼瞧着你，
她的笑容更是十分丑陋，但奇丑之中却含仁慈温柔之意，登时叫你心中感到
一阵温暖。\n"
	);

	set("gender", "女性");
	set("attitude", "peaceful");

	set("age", 50);
	set("shen_type",1);

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 80000);
	set("score", 1000);
	

	set_skill("force", 90);
	set_skill("yunu-xinjing", 90);
	set_skill("dodge", 90);
	set_skill("feiyan-gong", 90);
	set_skill("bee-training", 90);
	set_skill("sword",90);
	set_skill("yunu-jianfa",90);
	set_skill("parry", 90);
	set_skill("throwing",90);

	map_skill("force", "yunu-xinjing");
	map_skill("dodge", "feiyan-gong");
	map_skill("parry", "yunu-jianfa");
	map_skill("sword", "yunu-jianfa");
    
//	create_family("古墓派", 6, "弟子");
	create_family("古墓派", 5, "管家");

	set("inquiry", ([
		"job" : (: ask_job :),
		"青瓷瓶" : (: ask_ping :),
		"面纱" : (: ask_miansha :),
		"解毒" : (: ask_jiedu :),
        ]));

	set_temp("job_pos",10);

   /*     set("inquiry",([
                "玉蜂浆"  : (: ask_for_honey :),
        ])); 
	*/

	setup();

        carry_object("/kungfu/class/gumu/obj/pao")->wear();

}

void init()
{
	object ob;

	::init();
	return;
}


string ask_job()
{
	object ob2;
	object ob = this_player();
	object me = this_object();

	if ( ob->query("family/family_name") != "古墓派" )
	return "这位"+RANK_D->query_respect(ob)+"非我古墓派弟子，岂敢劳烦。\n";

	if(ob->query_temp("gm_xunfeng")){
		command("hmm "+ob->query("id"));
		return "你还没完成任务，就又想要新的？\n";
	}

/*
	if ( me->query_temp("job_pos" ) == 0 ) {
		 return "现在没什么要紧的事去作，你去休息吧。\n";
	}
*/

	me->add_temp("job_pos", -1);

	command("nod");
	command("say 好，今天天气不错，"+RANK_D->query_respect(ob)+"把玉蜂带出去采些花蜜吧。");
	ob2 = new("/kungfu/class/gumu/obj/beehive");
	ob2->set("owner",ob);
	ob2->set("mi_lvl",0);
	if(!ob->query_temp("bee_count")){
		ob->set("bee_count",ob->query("bee_count")-2);
		if (ob->query("bee_count")<1) ob->set("bee_count",1);
		ob->set_temp("bee_count",ob->query("bee_count"));
	}
	if(ob->query_temp("bee_count") > 6) ob->set_temp("bee_count",6);
	ob2->set("bee_count",ob->query_temp("bee_count"));
	ob2->set_amount(ob->query_temp("bee_count"));
	ob2->move(ob);
	ob->set_temp("gm_xunfeng",1);
//	command("give beehive to "+ob->query("id"));
	message_vision("$N给$n"+chinese_number(ob2->query_amount())
		+"个"+HIW"玉蜂箱。\n"NOR, me, ob);

	return "早去早回，小心麻雀！\n";
}

string ask_ping()
{
	object pl = this_player();
	object me = this_object();
	object *inv;	// 身上带的东西
	int i,j;
	object ping;

	if ( pl->query("family/family_name") != "古墓派" )
		return "青瓷瓶虽无奇，却深为我派弟子所爱。\n";

	inv = all_inventory(pl);
	j=0;
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("name") == CYN"青瓷瓶"NOR )
			j += 1;
	if (j > pl->query_temp("bee_count") + 4){
		command("hmm "+pl->query("id"));
		command("smile "+pl->query("id"));
        return ("要那么多青瓷瓶做什么？\n");
	}
	
	command("nod");
	ping = new("/kungfu/class/gumu/obj/qingci-ping");
	ping->set("liquid/remaining",0);
	ping->move(me);
	command("give ping to "+pl->query("id"));
	return ("这青瓷瓶又小又脆，别弄丢了！\n");
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
	command("give sha to "+pl->query("id"));
	return ("别弄丢了！\n");
}

string ask_jiedu()
{
	object pl = this_player();
	object me = this_object();
	object ping,xiang;

	if ( pl->query("family/family_name") != "古墓派" ) {
		if ((int)pl->query_condition("yufeng_poison")) {
			command("laugh "+pl->query("id"));
			command("shrug");
			return ("恭喜你啦！玉蜂毒也没什么厉害的，只不过无药可解而已！\n");
		}
		else return 0;
	}

	if (present("qingci ping", pl))
		return ("你不是有解药吗？\n");

	if (!(int)pl->query_condition("yufeng_poison")) return ("你没中毒呀？");
	
	ping = new("/kungfu/class/gumu/obj/qingci-ping");
	ping->move(me);

	xiang = present("feng xiang", pl);
	if ( xiang && xiang->query("mi_lvl")>1) {
		message_vision("$N慢慢打开玉蜂箱的盖子。\n", me);
		message_vision("$N慢慢抽出一排装满玉蜂蜜的木板。\n", me);
		message_vision("$N慢慢刮下玉蜂蜜装入青瓷瓶。\n", me);
		message_vision("$N把玉蜂箱恢复原状。\n", me);

		ping->set("liquid/remaining",xiang->query("mi_lvl")/2 +1);
		xiang->set("mi_lvl",0);
	}
	else ping->set("liquid/remaining",1);

	command("give ping to "+pl->query("id"));
	return ("赶紧拿去用吧！");
}

void attempt_apprentice(object ob)
{
	mapping fam;
	string ttt;

	command("look "+ob->query("id"));
	if ( ob->query("class")=="bonze" ) {
		command ("say 我派武功粗鄙得紧，大师见笑了。");
	    return;
	}

/*
	if( ob->query("family/family_name") && ob->query("family/family_name") != "古墓派" ) {
		command ("say 我古墓派已经退隐江湖，你去吧。");
		return;
	}
*/

	if (ob->query("family/family_name") == "古墓派"){
		command ("hmm " + ob->query("id"));
		command ("sigh " + ob->query("id"));
		return;
	}

	if (ob->query("combat_exp") > 10000 || ob->query("age") >16 ) {
		command ("say "+ RANK_D->query_respect(ob) + 
                           "是武林高手，拜我为师？别取笑于在下了。");
		return;
	}

	if (ob->query("gender") == "女性")
		ob->set("title","古墓派侍女");
	else if (ob->query("gender") == "男性")
		ob->set("title","古墓派见习弟子");
	else {
		command ("sigh " + ob->query("id"));
		command("say 可怜的孩子，这么早就......");
		command("say 你去吧，你在古墓没前途的。");
		return;
	}

	command("say 可怜的孩子，以后就陪我养养玉蜂吧！");
	command("recruit " + ob->query("id"));

	if (ob->query("gender") == "女性")
		ob->set("title","古墓派侍女");
	else if (ob->query("gender") == "男性")
		ob->set("title","古墓派见习弟子");

	return;
}
