// longer.c С��Ů
// by April 01/08/03
// update 01/09/14

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_miansha();

void create()
{
	object bj;

	set_name("С��Ů", ({ "xiao longer", "long", "longer" }));
    set("long", 
		"������һϮ��ɴ��İ��£������������������Ů����������������ʮ�꣬����\n"
		+"һͷ����ĺڷ�֮�⣬ȫ���ذס��������������ף�ֻ�Ǽ���������һ��Ѫɫ���Ե�\n"
		+"�԰��쳣��\n");
	set("gender", "Ů��");
	set("nickname","�������");
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

	create_family("��Ĺ��", 3, "����");

	set("spouse/id", "yang guo");
	set("spouse/name", "���");
	set("spouse/title", "�ɷ�");

	set("inquiry", ([
//		"job" : (: ask_job :),
		"��ɴ" : (: ask_miansha :),
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

	if (ob->query("family/family_name") != "��Ĺ��"){
		command ("say �ҹ�Ĺ���Ѿ�����������������ͽ����ȥ�ɡ�");
		return;
	}
	
	if (ob->query("gender")!="Ů��"){
		// ֻ��Ů��
		command("say ����ѧ�ø����书��ȥ�����ɷ�����ɡ�");
		return;
	}

	if (ob->query_per() < 25) {
		// ��ò<25����
	    command("say �����书�������������ƺ�����");
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
	miansha = new("/kungfu/class/gumu/obj/miansha");
	miansha->move(pl);
	command("smile "+pl->query("id"));
	command("give sha to "+pl->query("id"));
	return ("��Ū���ˣ�\n");
}
