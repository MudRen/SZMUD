// Code of ShenZhou
// Summer 9/26/1996.
inherit F_MASTER;
inherit NPC;
void create()
{
	set_name("����", ({ "shanyong", "shan", "yong" }));
	set("long", 
"һ�����ֵ�����ɮ�ˣ����Ц�ݣ�ȴ����Ц��ص����¡�\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "heroism");
	set("class","lama");
	set("chat_chance", 20);
	set("shen_type", -1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 500);
	set("max_jing", 350);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 60);
	set("combat_exp", 60000);

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 60);
        set_skill("lamaism", 60);
//	set_skill("xue-dao", 50);
	set_skill("xueshitiao", 50);
//	set_skill("longxiang-banruo", 50);

//	map_skill("force", "longxiang-banruo");
//	map_skill("blade", "xue-dao");
	map_skill("dodge", "xueshitiao");
	

	create_family("Ѫ����", 5, "����");

	setup();
	carry_object("/d/qilian/obj/miandao")->wield();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player())
	&& ob->query("gender") == "Ů��"){
		message_vision("$Nб����Ц��Ŀ�ⲻס��$n����ת��תȥ��\n", this_object(), ob);
		command("flirt "+ob->query("id"));
        }
}
void attempt_apprentice(object ob)
{
        if (ob->query("gender")=="Ů��") {
                command ("say ���ɲ���Ů���ӣ����ȥ�ɡ�");
                return;
        }

	if( ob->query("family/family_name") != "ѩɽ��"
        && ob->query("family/family_name") != "Ѫ����"
        && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
        }
 if ((string)ob->query("family/family_name") == "ؤ��" && ob->query("rank") > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
                return;
        }
	command("say �ðɣ�ƶɮ���������ˡ�");
        command("recruit " + ob->query("id"));
}

