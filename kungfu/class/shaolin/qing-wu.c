// Code of ShenZhou
// Npc: /kungfu/class/shaolin/qing-wu.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("���ޱ���", ({
		"qingwu biqiu",
		"qingwu",
		"biqiu",
	}));
	set("long",
		"����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺�\n"
		"�������������һϮ�ײ��ڱ����ģ��ƺ������ա�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 23);
	set("int", 17);
	set("con", 20);
	set("dex", 24);
	set("max_qi", 350);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 20000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan-yiqi", 30);
	set_skill("dodge", 30);
	set_skill("shaolin-shenfa", 30);
	set_skill("cuff", 30);
	set_skill("luohan-quan", 30);
	set_skill("blade", 30);
	set_skill("cibei-dao", 30);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "cibei-dao");

        prepare_skill("cuff", "luohan-quan");

	create_family("������", 40, "����");

	setup();

        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}


void attempt_apprentice(object ob)
{
	mapping fam;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "������" 
	&&  ob->query("combat_exp") >= 10000 )
	{
		command ("say �����ӷ� ʩ����" + fam["family_name"] + "���书���֣����¿ɲ���������");
		return;
	}

	if( (string)ob->query("gender") == "Ů��" )
	{
		command ("say �����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
	}
	
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say �����ӷ�ƶɮ�������������׼ҵ��ӡ��ˡ�");
	}
	else    command ("say �����ӷ����գ����գ�");

	command("recruit " + ob->query("id"));
}
