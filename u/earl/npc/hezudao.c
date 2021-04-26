// hezudao.c (kunlun)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�����", ({ "he zudao", "he" }));
	set("title", "�����ɿ�ɽ��ʦ");
	set("nickname", "������ʥ");
	set("long",
		"�����������ɿ�ɽ��ʦ���ų��ٽ��������ġ�������ʥ����\n"
		"������Ŀ���ݹ����⣬ԼĪ��ʮ��������͡�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 28);

	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 200);
	set("max_jingli", 5000);
	set("jingli", 5000);
	set("combat_exp", 6400000);
	set("score", 400000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		 (: perform_action, "sword.xunlei" :)
	}));

        set_skill("qinqi-shuhua", 380);
		set_skill("taoism", 380);
        set_skill("literate", 300);
        set_skill("force", 400);
        set_skill("cuff", 400);
        set_skill("xuantian-wuji", 400);
        set_skill("dodge", 400);
        set_skill("taxue-wuhen", 400);
        set_skill("strike", 400);
        set_skill("kunlun-zhang", 400);
        set_skill("zhentian-quan", 400);
        set_skill("parry", 400);
        set_skill("sword", 420);
        set_skill("liangyi-jian", 420);
        
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("strike", "kunlun-zhang");
	map_skill("parry", "liangyi-jian");
        map_skill("cuff", "zhentian-quan");
        map_skill("sword", "liangyi-jian");
	prepare_skill("strike", "kunlun-zhang");
        prepare_skill("cuff", "zhentian-quan");

	create_family("������", 1, "��ɽ��ʦ");
	        set("inquiry", ([
                            "���ǽ���" : "���Ǳ��Ų��⴫�ľ�ѧ��\n",
                            "���ǽ�" : "���Ǳ��Ų��⴫�ľ�ѧ��\n",
                                            "�����" : "�������������ķ��ˡ�\n",
				                ]));

//	set("class", "taoist");
	setup();
	carry_object("/d/kunlun/obj/sword")->wield();
    carry_object("/d/kunlun/obj/pao4")->wear();

  }



void attempt_apprentice(object ob)
{
                mapping skill;
		string *skl;
                int i;

//		if(ob->query("kar") < 20)
//		return;

//		if(ob->query_int() < 32 ) {
//		command("say ����������Ҫ���Լ��ߵ��˲ſ������������У��������书�������ۡ�");
//		command("say "+RANK_D->query_respect(ob)+"�����Ȼ�ȥ�������ɡ�");
//		return;
//	}


        if( ob->query("family/family_name") != "������" && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                        +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
        }

        if (ob->query("class")=="bonze") {
                command ("say ������һ���ճ�����Ϊͽ������ذɡ�");
                return;
        }

	    if ((string)ob->query("gender") == "����" && (int)ob->query_skill("pixie-jian",1) > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "���Ѿ����б�а����,�α��������ǽ���");
                return;
        }


                if ((int)ob->query_skill("xuantian-wuji", 1) < 100) {
		command("say �����黭��ΪС������Ҳ�������������С�");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�����������޼����϶��µ㹦��");
		return;
	}

		if ((int)ob->query("max_neili", 1) < 500) {
		command("say ����������һ�Ķ����������߻���ħ��");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ���Ⱥú�����������");
		return;
	}

/*        	skill = ob->query_skills();
		skl = keys(skill);
		i = sizeof(skl);
		while (i--) {
                if (skill[skl[i]] < 80)
                command("say " + RANK_D->query_respect(ob) + 
		        "�Ƿ���" + 
		        CHINESE_D->chinese(skl[i]) + 
		        "�϶���Щ����");
        	return;
	}
*/	        
		command("say ������Ҳ���������ˣ��Ҿͽ���һЩ�ٽ����֪ʶ�ɡ�");
		command("recruit "+ob->query("id"));

                ob->set("appren_hezudao", 1);
		ob->add("int", 1);
                  ob->set_skill("qinqi-shuhua", ob->query_skill("literate",1));
//		ob->set_skill("literate", 10 + ob->query_skill("literate", 1));
}
