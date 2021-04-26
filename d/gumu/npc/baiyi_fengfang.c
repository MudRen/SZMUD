// longnv.c ������Ů--��䷿
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

    set_name("������Ů", ({ "baiyi girl", "girl"}));
    set("long", 
		"������һϮ��ɴ��İ��£������������ס�\n");
	set("gender", "Ů��");
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

    create_family("��Ĺ��", 4, "����");

    set("chat_chance_combat", 50);

    set("inquiry", ([
		"���ƿ" : (: ask_ping :),
		"��ɴ" : (: ask_miansha :),
		"�ⶾ" : (: ask_jiedu :),
        ]));

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/gumu/obj/white_silk")->wear();
        
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
	object *inv;	// ���ϴ��Ķ���
	int i,j;
	object ping;

	if ( pl->query("family/family_name") != "��Ĺ��" )
		return "���ƿ�����棬ȴ��Ϊ���ɵ���������\n";

	inv = all_inventory(pl);
	j=0;
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("name") == CYN"���ƿ"NOR )
			j += 1;
	if (j > 5){
		command("hmm "+pl->query("id"));
		command("smile "+pl->query("id"));
        return ("���ƿ��ã�����ҲĪ̫̰���ˣ�\n");
	}
	
	command("nod");
	ping = new("/d/gumu/obj/qingci-ping");
	ping->move(me);
	command("give ping to "+pl->query("id"));
	return ("�����ƿ��С�ִ࣬��Ū���ˣ�\n");
}

string ask_miansha()
{
	object pl = this_player();
	object me = this_object();
	object *inv;	// ���ϴ��Ķ���
	int i,j;
	object miansha;

	if ( pl->query("family/family_name") != "��Ĺ��" )
		return "���ɴ�����ɴ����ʲô�������Ϊ���˵���\n";

	inv = all_inventory(pl);
	j=0;
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("name") == HIW"��ɴ"NOR )
			j += 1;
	if (j > 1){
		command("hmm "+pl->query("id"));
		command("smile "+pl->query("id"));
        return ("��ҲĪ̫̰���ˣ�\n");
	}
	
	command("nod");
	miansha = new("/d/gumu/obj/miansha");
	miansha->move(me);
	command("give sha to "+pl->query("id"));
	return ("��Ū���ˣ�\n");
}

string ask_jiedu()
{
	object pl = this_player();
	object me = this_object();
	object ping,xiang;

	if ( pl->query("family/family_name") != "��Ĺ��" ) {
		if ((int)pl->query_condition("yufeng_poison")) {
			command("laugh "+pl->query("id"));
			command("shrug");
			return ("��ϲ��������䶾Ҳûʲô�����ģ�ֻ������ҩ�ɽ���ѣ�");
		}
		else return 0;
	}

	ping = new("/d/gumu/obj/qingci-ping");
	ping->move(me);

	xiang = present("feng xiang", environment(me));
	if ( xiang ) {
		message_vision("$N�����������ĸ��ӡ�\n", me);
		message_vision("$N�������һ��װ������۵�ľ�塣\n", me);
		message_vision("$N�������������װ�����ƿ��\n", me);
		message_vision("$N�������ָ�ԭ״��\n", me);

		ping->set("liquid/remaining",xiang->query("mi_lvl")/2 +1);
		xiang->set("mi_lvl",0);
	}
	else ping->set("liquid/remaining",1);

	command("give ping to "+pl->query("id"));
	return ("�Ͻ���ȥ�ðɣ�");
}
