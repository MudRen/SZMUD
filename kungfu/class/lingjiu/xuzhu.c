// /NPC xuzhu.c 
// By Xuanyuan 11/18/2001

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();

void renewing();
string ask_me(string name);
string ask_book();

void create()
{
	set_name("����", ({ "xu zhu", "xu", "zhu" }));
	set("long",
	    "����һ����ʮ�������������, Ũü����,\n"+
	    "���ı��ӱ�ƽ����, ��ò��Ϊ��ª. \n"+
	    "��һ���������µĳ���, ��ʹ�����Լ��־���.\n"+
	    "��������ɽͯ�ѵľ�������.\n");
	set("title", "���չ�����");
	set("gender", "����");
	set("per", 16);
	set("age", 26);
	set("nickname",  "����" );
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 24);
	set("int", 20);
	set("con", 30);
	set("dex", 26);

	set("max_qi", 6000);
	set("max_jing", 1200);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 10);

	set("combat_exp", 2500000);

	set_skill("force", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand",250);
	set_skill("strike", 250);
	set_skill("sword",250);
	set_skill("blade",250);
	set_skill("literate",100);
	set_skill("music",250);

	set_skill("zhemei-shou",250);
	set_skill("liuyang-zhang",250);
	set_skill("tianyu-qijian",250);
	set_skill("yueying-wubu",250);
	set_skill("bahuang-gong", 250);
	set_skill("ruyi-dao", 250);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");
	map_skill("blade", "ruyi-dao");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	set("book_count", 1);
	set("job_count",0);
        set("inquiry", ([
//		"������" : (: ask_me, "lingjiu" :),
//		"����" : (: ask_me, "lingjiu" :),
//		"СԺ" : (: ask_me, "lingjiu" :),
		"job" : "��ȥ��÷���ɣ���������û��ʲô������԰��Ÿ��㡣",
        ]));
	set("ling_count", 1);

	create_family("���չ�",2,"����");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/d/lingjiu/obj/changpao")->wear();
 	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	object me;

    ::init();
    
	me = this_object();

//    remove_call_out("checking");
//    call_out("checking", 1, me);
       
}
string ask_me(string name)
{
	mapping fam;
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "���չ�")
		return RANK_D->query_respect(this_player()) +
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (query("ling_count") < 1)
		return "�����ò���ʱ���Ѿ������������ˡ�";

	ob = new("/d/lingjiu/obj/" + name);
	ob->move(this_player());

	add("ling_count", -1);

	message_vision("�����$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ�";
}
void attempt_apprentice(object ob)
{
        	mapping fam = ob->query("family");

		if (ob->query("gender") != "Ů��") {
			command("say ��ֻ��Ů���ӣ�"+RANK_D->query_respect(ob)+"��ذɡ�");
			return; 
		}
		if (!fam || fam["family_name"] != "���չ�"){
                	command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                	return;
                }
		if((int)ob->query_skill("force", 1) < 150) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
                	return;
                }  
		if((int)ob->query_skill("bahuang-gong", 1) < 150) {
			command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
                	return;
                }  
		if((int)ob->query_skill("dodge", 1) < 150) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����Ṧ�϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("yueying-wubu", 1) < 150 && (int)ob->query_skill("lingbo-weibu", 1) < 150 ) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����Ṧ�϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("sword", 1) < 150) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("tianyu-qijian", 1) < 150) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                	return;
                }
		if (ob->query_con() < 20) {
			command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
			return;
		}
		if ((int)ob->query("shen") < -100)  {
                        command("hmm " + ob->query("id"));
                        command("say �����չ��䲻���������ɣ���Ҳ�����ڼ�а֮��Ϊ�顣");
                	command("say "+RANK_D->query_respect(ob)+"���ұ����ˣ�ˡ�Ҳ������㡣");
        		return;
		}
		command("say �ðɣ��Ҿ��������ˡ�ϣ����������������������չ�������"); 
        	command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
		ob->set("class", "dancer");
}

#include "/kungfu/class/lingjiu/auto_perform.h"
