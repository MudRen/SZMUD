// sun.c ������
// 15/7/2001  by xuanyuan

#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
        set_name("������", ({"sun popo", "sun"}));
        set("gender", "Ů��");
        set("age", 55);
        set("long",
                "����һλ����������ţ���������΢΢һЦ��\n"
        );
        set("attitude", "friendly");

        set("qi", 1200);
        set("max_qi", 1200);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 40);

        set("combat_exp", 150000);
        set("score", 0);

        set_skill("force", 80);
        set_skill("yunu-xinjing", 60);   
        set_skill("sword", 90);
        set_skill("yunu-jianfa", 80);     
        set_skill("dodge", 70);
        set_skill("gumu-shenfa", 70);   
        set_skill("parry", 60);
        set_skill("cuff",80);
        set_skill("meinu-quan", 60);    
        set_skill("literate",40);

        map_skill("force", "yunu-xinjing");
        map_skill("sword", "yunu-jianfa");
        map_skill("dodge", "gumu-shenfa");
        map_skill("parry", "meinu-quan");
        map_skill("cuff", "meinu-quan");

        set("inquiry", ([
                "С��Ů" :  "����������һ�ִ���ģ�����Сû�˸�ĸ�������ֶ�����ס�����Ĺ���..\n",
		"��佬" : (: ask_me :),
        ]) );

	set("book_count", 1);
	set("jiang_count", 4);

        create_family("��Ĺ��",2,"����");
        set("env/wimpy", 50);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/armor/cloth")->wear();

}

void attempt_apprentice(object ob)
{
	mapping fam = ob->query("family");
	object obj, *obs;

	if (!fam || fam["family_name"] != "��Ĺ��"){
                command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                return;
                }
	if(fam["master_name"] == "��Ī��") {
		command("say �����Ǹ���ͽ��ͽ�ܣ����������㣡");
		return;
		}       
	if((int)ob->query_skill("yunu-jue", 1) < 60) {
                command("say �����Ů��ʮ�ľ���Ϊ��ǳ���������ҵĹ���"); 
                command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ������Ů��ʮ�ľ��϶��µ㹦��");
                return;
                }
/*
	if (query("book_count") > 0){
		command("sigh");
		command("say ��Ȼ" + RANK_D->query_respect(ob) + "Ҳ���ұ����ˣ�������ʦȥ����ûʲô�ܽ���ġ�");
		command("say �������ҽ������Ҳ����Ե���Ȿ����Ů��ʮ�ľ��¾������������У�Ҳ����������ʶһ����");
		obj=new("/d/zhongnan/obj/yunu_book2");
		obj->move(this_object());
		add("book_count", -1);
		command ("give book to "+this_player()->query("id")+"");
                return;
	}
		command("sigh");
		command("say ��Ȼ" + RANK_D->query_respect(ob) + "Ҳ���ұ����ˣ�������ʦȥ����ûʲô�ܽ���ġ�");
*/

	if (query("book_count") < 1){
		command("sigh");
		command("say ��Ȼ" + RANK_D->query_respect(ob) + "Ҳ���ұ����ˣ�������ʦȥ����ûʲô�ܽ���ġ�");
                return;
	}
	obs = filter_array(children("/d/zhongnan/obj/yunu_book2.c"), (: clonep :));
        if (sizeof(obs) > 2){
		command("sigh");
		command("say ��Ȼ" + RANK_D->query_respect(ob) + "Ҳ���ұ����ˣ�������ʦȥ����ûʲô�ܽ���ġ�");
                return;
	}
		command("sigh");
		command("say ��Ȼ" + RANK_D->query_respect(ob) + "Ҳ���ұ����ˣ�������ʦȥ����ûʲô�ܽ���ġ�");
		command("say �������ҽ������Ҳ����Ե���Ȿ����Ů��ʮ�ľ��¾������������У�Ҳ����������ʶһ����");
		obj=new("/d/zhongnan/obj/yunu_book2");
		obj->move(this_object());
		add("book_count", -1);
		command ("rumor "+this_player()->query("name")+"Ū����һ����Ů��ʮ�ľ��¾�");
		command ("give book to "+this_player()->query("id")+"");
}

string ask_me()
{
	mapping fam; 
	object ob, *obs;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "��Ĺ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if(fam["master_name"] == "��Ī��") 
		return "�����Ǹ���ͽ��ͽ�ܣ���Ҫ��̫���Ҹ�����佬�������򲻿��ܵģ�";

	if (query("jiang_count") < 1)
		return "�������ˣ���佬�Ѿ����������ʦ��ʦ�����ˡ�";

	if ( (int)this_player()->query("eff_qi")==(int)this_player()->query("max_qi") ) {
                message_vision("$N��$n������ϸ�ش�����һ�󣬱�����üͷ��\n", this_object(), this_player());
                return "�㲢δ���ˣ�Ҫ��佬����\n";
        }

	ob=new("/clone/drug/yufeng-jiang");
	ob->move(this_player());
	add("jiang_count", -1);
	return "�������ǹ�Ĺ�ɵ�������ҩ������ȥ�ú÷��á�";
}
