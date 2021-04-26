// Code of ShenZhou
inherit NPC;
inherit F_MASTER;
inherit F_CLEAN_UP;
string ask_me();

void create()

{
        set_name("�쵤��", ({ "zhu danchen", "zhu"}));
        set("long", "������һ��ʫ�飬���������ж������ϲ���һ���йٱʡ�\n");
        set("title","������佫");
        set("gender", "����");
        set("age", 35);
        set("inquiry", ([
		"������": "�Ҽ���ү���Է�����",
		"����": "���ʸ���֪���Ҽ�С��ү�����䡣",
		"��" : (: ask_me :),

        ]));
        set_skill("strike", 60);
        set_skill("qingyan-zhang", 60);
        set_skill("dodge", 50);
        set_skill("duanshi-shenfa", 50);
        set_skill("parry", 50);
        set_skill("force", 40);
        set_skill("buddhism", 80);
	set_skill("sword", 60);
        set_skill("kurong-changong",60);
	set_skill("duanjia-jian", 65);
	
        map_skill("cuff","jinyu-quan");
        map_skill("dodge","duanshi-shenfa");
	map_skill("sword","duanjia-jian");
        map_skill("force","kurong-changong");
        map_skill("parry","duanjia-jian");
	
	 prepare_skill("strike","qingyan-zhang");

        set("str", 28);
        set("int", 29);
        set("con", 27);
        set("dex", 23);

        set("max_qi", 700);
        set("max_jing", 700);
        set("neili", 550);
        set("max_neili", 550);
        set("jiali", 50);
        set("combat_exp", 300000);

        set("attitude", "peaceful");
        set("shen_type", 1);
        create_family("����μ�", 15, "����");
        setup();
        carry_object("/d/city/obj/cloth")->wear();
	carry_object("/d/dali/obj/panguanbi")->wield();

}
void attempt_apprentice(object ob)
{
        mapping fam;
        string dldj;

        command ("look "+ob->query("id"));
        if ( ob->query("class")=="bonze" ) {
             if (ob->query("gender")=="Ů��")
                command ("say ʦ̫�Ƕ����ɵĸ��֣������Ƨ֮�粻�Ҷ�����");
             else
                command ("say ��ʦ�������ɵĸ��֣������Ƨ֮�粻�Ҷ�����");
             return;
        }
        if( ob->query("family/family_name") == "ؤ��") {
                command ("say �������ǻ���֮�أ����ʼ�������ؤ�ɺ���ͳ��");
                return;
        }
        if ( ob->query("family/family_name") == "�䵱��" && ob->query("combat_exp") >= 10000 ) {
                command ("say ����֮�����з�̣���λ���ֻ�����������ɡ�");
                return;
        }

       if ( ob->query("family/family_name") == "������" && ob->query("combat_exp") >= 10000 ) {
                command ("say �������޶���Ҳ�����Ҵ����ڳ���������ȥ!");
                return;
        }
      if ( ob->query("family/family_name") == "����ɽ" && ob->query("combat_exp") >= 10000 ) {
                command ("say ������ն���Ҳ�����Ҵ����ڳ���������ȥ!");
                return;
        }
       if ( ob->query("family/family_name") == "��ɽ��" && ob->query("combat_exp") >= 10000 ) {
                command ("say ����֮�����з�̣���λ���ֻ�����������ɡ�");
                return;
        }
		if ( ob->query("family/family_name") == "Ѫ����" && ob->query("combat_exp") >= 10000 ) {
                command ("say ����Ѫ���ŵĶ���Ҳ�����Ҵ����ڳ���������ȥ!");
                return;
        }
		if ( ob->query("family/family_name") == "������" && ob->query("combat_exp") >= 10000 ) {
                command ("say ���������̵Ķ���Ҳ�����Ҵ����ڳ���������ȥ!");
                return;
        }

	if (ob->query("combat_exp") > 20000) {
                command ("say "+ RANK_D->query_respect(ob) + 
                           "�����ָ��֣�����Ϊʦ����ȡЦ�������ˡ�");
                return;
        }

        if (ob->query("gender")=="Ů��") dldj="�Ů";
        else  dldj = "�Ҷ�";
        command("say �ðɣ��ҾͶ�������ү����������" + dldj + "�ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title","�������"+dldj);
        return;
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "����μ�")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";

        if (query("book_count") > 10)
                return "�������ˣ��𾭲��ڴ˴���";

        add("book_count", 1);
        ob = new("/d/shaolin/obj/fojing10");
        ob->move(this_player());

        return "�ðɣ��Ȿ�����û�ȥ�ú����С�";
}
#include "/kungfu/class/dali/promote4.h"
