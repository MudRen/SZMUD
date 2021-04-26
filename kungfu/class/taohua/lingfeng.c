// Code of ShenZhou
// kane, 21/01/98

inherit NPC;

void create()
{
	set_name("�����", ({ "qu lingfeng", "lingfeng", "qu" }));
	set("shen_type", 0);

	set("str", 28);
	set("con", 30);
	set("dex", 20);
	set("gender", "����");
	set("age", 35);
	set("long",
		"���ǻ�ҩʦ������������硣�������Ȼ���ᣬ�������Ѿ��߰ס�\n"+
		"�������һ��Ĵ���������е���������ѧ��Ϊȴ��ߡ�\n");
	set("combat_exp", 400000);
        set("max_qi", 1500);
        set("max_jing", 800);
        set("neili", 1800);
        set("max_neili", 1800);
        set("jiali", 80);
	set("shen_type", -1);

        set_skill("force", 160);
	set_skill("bitao-xuangong", 160);
	set_skill("luoying-shenfa", 160);
	set_skill("qimen-dunjia", 160);
	set_skill("hand", 160);
	set_skill("throwing",200);
	set_skill("lanhua-fuxue", 160);
	set_skill("strike", 160);
	set_skill("kick", 160);
	set_skill("luoying-shenjian", 160);
	set_skill("xuanfeng-saoye", 160);
        set_skill("dodge", 160);
        set_skill("parry", 160);
	set_skill("sword", 160);
	set_skill("yuxiao-jian", 160);

	map_skill("force", "bitao-xuangong");
        map_skill("parry", "luoying-shenjian");
        map_skill("dodge", "luoying-shenfa");
        map_skill("strike", "luoying-shenjian");
	map_skill("kick", "xuanfeng-saoye");

        prepare_skill("strike", "luoying-shenjian");

	set("attitude", "friendly");
/*
	set("inquiry", ([
		"��ҩʦ" : "��ʦ����ʲô�������ﲻ��ҩ��\n",
		"��ҩ" : "����ҩ���ǲ���ҩ��\n",
		"�����" : "�����ң�������˵�����Ҳ���ʶ��\n",
		"����" : "���ô������\n",
	]));
*/	
	create_family("�һ���", 2, "����");

	setup();
	carry_object("/d/taohua/obj/robe")->wear();
	carry_object("/d/taohua/obj/bagua")->wield();
}

void attempt_apprentice(object ob)
{
	string ttt;

        if( ob->query("family/family_name") != "�һ���" ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
        }

        if( ob->query("family/family_name") == "�һ���"
        && ob->query("family/master_name") == "��ҩʦ" ) {
                command ("say " + RANK_D->query_respect(ob) + "��"
                + "���ɸ��֣��ҿɲ���������");
                return;
	}               
        if ((int)ob->query_skill("bitao-xuangong", 1) < 60){
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�����ڹ���Ϊ�϶��µ㹦��");
                return;
        }

        if ((int)ob->query_skill("literate", 1) < 60){
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ������ѧ�����϶��µ㹦��");
                return;
        }

	if (this_player()->query("gender") == "����") ttt = "����";
	else  if (this_player()->query("gender") == "Ů��") ttt = "����"; 
	command("recruit " + ob->query("id"));
	ob->set("title", "����ׯ" + ttt);
	command("say " + "��Ȼ������Ϊͽ�����Ҳ�ϲ���������㻹��½ʦ�ܵ����£��������᣿\n");
	command("say " + "������������Ƚ����ҵ��ң�ע����ñ��˷����ˡ�\n");
}
