// Code of ShenZhou
// Summer 9/26/1996.

inherit NPC;

string ask_me();

void create()
{
	set_name("���ַ���", ({ "jinlun fawang", "jinlun", "fawang" }));
//	set("nickname", "�ɹŹ�ʦ");
	set("long", 
"һ�����귬ɮ�����μ��߼��ݣ�����һ������ˡ�����΢�ݣ�����һ�����ӡ�\n"
"�����ǵ����ɹŹ�����������\n");
	set("title", "�ɹŹ�ʦ");
	set("gender", "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("class","lama");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 3500);
	set("max_jing", 3500);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 100);
	set("combat_exp", 3600000);
	set("score", 5000);
	set("inquiry", ([
		"����" : (: ask_me:),
        ]) );
	set("lun_count", 1);
	set_temp("apply/armor", 100);

	set_skill("force", 360);
	set_skill("dodge", 360);
	set_skill("parry", 360);
	set_skill("hammer", 360);
	set_skill("cuff", 300);
	set_skill("lamaism", 360);
	set_skill("hand", 300);
	set_skill("riyue-lun", 400);
	set_skill("shenkongxing", 400);
	set_skill("longxiang-banruo", 360);
	set_skill("jingang-chu", 360);
	set_skill("staff", 320);
	set_skill("necromancy", 360);
	set_skill("dashou-yin", 360);

	map_skill("force", "longxiang-banruo");
	map_skill("parry", "riyue-lun");
	map_skill("hammer", "riyue-lun");
	map_skill("dodge", "shenkongxing");
	map_skill("staff", "jingang-chu");
	map_skill("hand", "dashou-yin");
	
	prepare_skill("hand", "dashou-yin");

	create_family("ѩɽ��", 9, "����" );

	setup();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
	carry_object("/clone/weapon/falun")->set_amount(4);
	carry_object("/clone/weapon/falun")->wield();
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

	if ((int)ob->query_skill("longxiang-banruo", 1) < 60
	&& (int)ob->query_skill("xiaowuxiang", 1) < 60) {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ��������������϶��µ㹦��");
		return;
	}
	if ((int)ob->query("jlfw") < 1){
		command("say " + RANK_D->query_respect(ob) +
                        "��ȥ����ͽ�ܴ���ʹ�ܣ��������Ұɡ�");
	return;
	}
        command("recruit " + ob->query("id"));
	command("say ��ƶɮ��������ɡ�");
}
string ask_me()
{
        object ob, me = this_player();
                return "�ⶫ���һ���һǧ�����ӲŴ�������ɲ��ܸ����档";
/*	if (me->query("family/master_id") != "jinlun fawang" ) 
		return "���Ȱ���Ϊʦ�ɡ�";
        add("lun_count", -1);
        command ("give lun to "+ me->query("id"));
        return "�ã�����ȥ�棬��ǧ������Ū���ˡ�";
*/
}

