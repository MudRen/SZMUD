// Code of ShenZhou
// daobaifeng.c ���׷�
// Acep

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���׷�", ({ "dao baifeng", "dao"}));
	set("long", 
"���Ǹ���ò������������ã��Ǹ�������Ů�ӣ�����Ӻ�����ʡ�\n�����Ǵ�����ʵ۶�����������ԭ����ˡ�\n�����ɷ�������մ���ǲݣ�һŭ֮���ܵ�������˼ҡ�");
	set("title","�����������");
	set("nick","����ɢ��");
	set("gender", "Ů��");
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
		"������": "���Ǹ���������ʲô��",
		"����"  : "�����Һþ�û������������",
        ]));
        
	create_family("����μ�", 15, "����");
	setup();

	carry_object("/d/dali/obj/ycloth")->wear();	
	carry_object("/d/quanzhou/obj/fuchen")->wield();
}

void attempt_apprentice(object ob)
{
	string current_title;
	current_title=ob->query("title");

	command ("look "+ob->query("id"));
	
	if (ob->query("gender")!="Ů��") {
		command("shake "+ob->query("id"));
		command("say �Բ�����ֻ��Ůͽ�ܡ�");
		return;
	}
	if (ob->query("family/family_name")!="����μ�") {
		command("hmm "+ob->query("id"));
		command("say �㲻�Ǵ�����Ӱ����ܵ�����������ʲô��");
		return;
        }

	command("say �ðɣ��Ҿ��������ˣ�ϣ����ú�ѧ�գ���Ҫ����Щ���ı��˵ĳ������۸���");
	command("recruit " + ob->query("id"));
	ob->set("title", current_title);
	return;
}
