// Code of ShenZhou
// Summer 9/26/1996.
inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("ʤ��", ({ "shengdi", "sheng", "di" }));
	set("long", 
"����һ�����ο��������ɮ�ˣ���ɫ��Į���书��ͬ������ߵ�һ�ˡ�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "heroism");
	set("class","lama");

	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1000);
	set("max_jing", 750);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 60);
	set("combat_exp", 300000);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("blade", 90);
        set_skill("lamaism", 80);
	set_skill("cuff", 80);
	set_skill("yujiamu-quan", 90);
	set_skill("xue-dao", 90);
	set_skill("xueshitiao", 80);
	set_skill("longxiang-banruo", 80);

	map_skill("force", "longxiang-banruo");
	map_skill("cuff", "yujiamu-quan");
	map_skill("blade", "xue-dao");
	map_skill("parry", "xue-dao");
	map_skill("dodge", "xueshitiao");
	
	prepare_skill("cuff", "yujiamu-quan");

	create_family("Ѫ����", 5, "����");

	setup();
	carry_object("/d/qilian/obj/miandao")->wield();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
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
	if ((int)ob->query("shen") > -50000) {
                command("say �ֵ����������췹�ԣ��������������������");
		return;
	}
	else if ((int)ob->query_skill("longxiang-banruo", 1) < 45) {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ���ڰ��������϶��µ㹦��");
                return;
        }
	command("say �ðɣ�ƶɮ���������ˡ�");
        command("recruit " + ob->query("id"));
}
