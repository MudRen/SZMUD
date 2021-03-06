// longnv.c 白衣少女--玉蜂房
// by April 01/08/29

#include <ansi.h>
inherit NPC;
string ask_ping();
string ask_miansha();
string ask_jiedu();

void create()
{
	object bj;
	int lvl;	//skill lvl

    set_name("白衣少女", ({ "baiyi girl", "girl"}));
    set("long", 
		"她披著一袭轻纱般的白衣，面容秀美绝俗。\n");
	set("gender", "女性");
    set("age", 18+random(10));
    set("attitude", "peaceful");
    set("shen_type", 1);

    set("str", 20);
    set("int", 25);
    set("con", 25);
    set("dex", 30);
        
    set("max_qi", 900);
	set("max_jing", 800);
    set("jiali", 50);
    set("neili", 2500);
    set("max_neili", 2500);
    set("jingli",1800);
    set("eff_jingli",1800);
    set("max_jingli",1800);

	lvl = 90 + random(30);

    set("combat_exp", lvl*lvl*lvl/10);
    set("score", 1000);

    set_skill("force", lvl);
    set_skill("yunu-xinjing", lvl);
    set_skill("cuff", lvl);
    set_skill("meinu-quan", lvl);
    set_skill("sword", lvl);
    set_skill("yunu-jianfa", lvl);
    set_skill("finger", lvl);
    set_skill("suhan-zhi", lvl);
    set_skill("parry", lvl);
    set_skill("dodge", lvl);
    set_skill("feiyan-gong", lvl);
	set_skill("bee-training",lvl);
    set_skill("lovingness",lvl);
    set_skill("parry",lvl);
    set_skill("suxin-jue",lvl);
    set_skill("zuoyou-hubo",lvl);
    set_skill("throwing",lvl);
    set_skill("whip",lvl);
    set_skill("jueqing-bian",lvl);
    set_skill("finger",lvl);
    set_skill("suhan-zhi",lvl);

    map_skill("force", "yunu-xinjing");
    map_skill("dodge", "feiyan-gong");
    map_skill("cuff", "meinu-quan");
    map_skill("parry", "yunu-jianfa");
	map_skill("sword", "yunu-jianfa");

    prepare_skill("cuff", "meinu-quan");

    create_family("古墓派", 4, "弟子");

    set("chat_chance_combat", 50);

    set("inquiry", ([
		"青瓷瓶" : (: ask_ping :),
		"面纱" : (: ask_miansha :),
		"解毒" : (: ask_jiedu :),
        ]));

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/kungfu/class/gumu/obj/white_silk")->wear();
        
}

void init()
{
    object ob;
    ::init();
    return;
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
	if (j > 8){
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
	miansha->move(me);
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
			return ("恭喜你啦！玉蜂毒也没什么厉害的，只不过无药可解而已！");
		}
		else return 0;
	}

	ping = new("/kungfu/class/gumu/obj/qingci-ping");
	ping->move(me);

	xiang = present("feng xiang", environment(me));
	if ( xiang ) {
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
