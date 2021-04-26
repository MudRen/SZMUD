// Code of ShenZhou
// Summer 9/26/1996.

inherit NPC;


void create()
{
	set_name("��ľ���", ({ "samu huofo", "samu", "huofo" }));
	set("long", 
"һ���ݸߵ����������һ���ɫ���ģ����ޱ��顣�i\n");
	set_weight(10000000);
	set("gender", "����");
	set("age", 45);
	set("attitude", "heroism");
	set("class","lama");
	set("shen_type", -1);
	set("str", 27);
	set("int", 33);
	set("con", 27);
	set("dex", 30);
	
	set("max_qi", 700);
	set("max_jing", 700);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);
	set("combat_exp", 250000);

	set_skill("force", 70);
	set_skill("dodge", 75);
	set_skill("parry", 70);
	set_skill("staff", 70);
	set_skill("cuff", 70);
	set_skill("jingang-chu", 80);
        set_skill("lamaism", 140);
	set_skill("shenkongxing", 80);
	set_skill("longxiang-banruo", 80);
	set_skill("necromancy", 80);
	set("inquiry", ([
        "����" : "�Ҳ��������Ϊ����Ȱɡ�\n"
	]) );

	map_skill("force", "longxiang-banruo");
	map_skill("parry", "jingang-chu");
	map_skill("staff", "jingang-chu");
	map_skill("cuff", "yujiamu-quan");
	map_skill("dodge", "shenkongxing");
	
	prepare_skill("cuff", "yujiamu-quan");

	create_family("ѩɽ��", 11, "����");


	setup();
	carry_object("/d/xingxiu/npc/obj/gangzhang")->wield();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
}

void attempt_apprentice(object ob)
{
	if( ob->query("family/family_name") != "ѩɽ��"
        && ob->query("family/family_name") != "Ѫ����"
        && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
        }
	if (ob->query("class") != "lama") {
		command("say " + RANK_D->query_respect(ob) +
			"�����������ڵĹ��򣬳�Եδ�Ϻ�����ߡ�"); 
		return;
	}
        else if ((int)ob->query_skill("longxiang-banruo", 1) < 30) {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ���ڰ��������϶��µ㹦��");
		return;
	}
        else if ((int)ob->query("max_neili") < 300) {
		command("say " + RANK_D->query_respect(ob) +
			"Ӧ���ټ���һ��������Ϊ�ɡ�");
		return;
	}
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}
