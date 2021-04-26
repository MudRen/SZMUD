// yangguo.c ���
// by April 01/08/04
// update 01/08/06

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_mianju();

void create()
{
	object bj;	// ����
	object me;

	set_name("���", ({ "yang guo", "yang"}));
	set("long", 
		"������ɫ���ۣ��ұ۶��ˣ��յ�����������������֮�С�ֻ������ɫ���ƣ�����\n"
		+"���£���ͬ��ʬһ�㡣ֻ��һ˫���Ӿ������䣬Ӣ�����ˡ�\n");
	set("gender", "����");
	set("nickname","������");
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

	create_family("��Ĺ��", 4, "����");

	set("spouse/id", "xiao longer");
	set("spouse/name", "С��Ů");
	set("spouse/title", "����");

	set("chat_chance_combat", 50);

	set("inquiry", ([
		"���" : (: ask_mianju :),
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
	if (ob->query("family/family_name") != "��Ĺ��"){
		command ("say �ҹ�Ĺ���Ѿ�����������������ͽ����ȥ�ɡ�");
		return;
	}

	if (ob->query("gender")!="����"){
		// ֻ������
		command("say �����������Ϲ�Ĺ������ȥ������С��Ů��");
		return;
	}

	if (ob->query_int() < 20 || ob->query_str() < 25 ) {
		// ����<25����
	    command("say �����书������Ƿ������ӿ�Ϊ����ȥ��...");
		return;
	}

	if ((int)ob->query_skill("yunu-xinjing", 1) < 90) {
		command("say �ҹ�Ĺ���书����Ů�ľ�Ϊ������");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�ö໨��ʱ����ϰ��Ů�ľ���");
		return;
	}

	command("say �ðɣ��Ҿ��������ˡ�");
    command("recruit " + ob->query("id"));
}

string ask_mianju()
{
	object pl = this_player();
	object me = this_object();
	object *inv;	// ���ϴ��Ķ���
	int i,j;
	object mianju;

	if ( pl->query("family/family_name") != "��Ĺ��" )
		return "���ɴ�����߲���ʲô�������Ϊ���˵���\n";

	inv = all_inventory(pl);
	j=0;
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("name") == WHT"���"NOR )
			j += 1;
	if (j > 1){
		command("hmm "+pl->query("id"));
		command("smile "+pl->query("id"));
        return ("��ҲĪ̫̰���ˣ�\n");
	}
	
	command("nod");
	mianju = new("/kungfu/class/gumu/obj/mianju");
	mianju->move(me);
	command("give mask to "+pl->query("id"));
	return ("��Ū���ˣ�\n");
}