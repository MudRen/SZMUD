// lin.c �ֳ�Ӣ
// 1998.9 by Lgg

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int auto_perform();

void create()
{
        set_name("�ֳ�Ӣ", ({"lin chaoying", "lin"}));
        set("gender", "Ů��");
        set("age", 42);
        set("long",
                "�����ǹ�Ĺ�ɵĿ�ɽ��ʦ�ֳ�Ӣ����Ȼ�Ѿ�����ʮ���ˣ���֮ȴ\n"
                "����ͬ��ʮ��ͷ����������ȫ���������������һ�Գ��İ��£�\n"
                "ֻ��ϧ��Ե�޷ݣ�ֻ�ö��������Ĺ���ľӡ�\n");

        set("attitude", "friendly");
        set("per", 30);
        set("str", 20);
        set("int", 32);
        set("con", 35);
        set("dex", 30);

        set("qi", 3600);
        set("max_qi", 3600);
        set("jing", 7400);
        set("max_jing", 7400);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 3600000);
        set("score", 0);

        set_skill("force", 400);
        set_skill("yunu-xinjing", 400);   
        set_skill("sword", 400);
        set_skill("yunu-jianfa", 400);    
        set_skill("quanzhen-jian",400); 
        set_skill("dodge", 400);
        set_skill("gumu-shenfa", 400);   
        set_skill("parry", 400);
        set_skill("cuff",400);
        set_skill("meinu-quan", 400);    
        set_skill("strike",400);
        set_skill("tianluo-diwang", 400);    
        set_skill("literate",101);
        set_skill("yunu-jue",400);
        set_skill("throwing",400);

        map_skill("force", "yunu-xinjing");
        map_skill("dodge", "gumu-shenfa");
        map_skill("cuff", "meinu-quan");
        map_skill("strike", "tianluo-diwang");
        map_skill("sword", "yunu-jianfa");
        map_skill("parry", "yunu-jianfa");

        prepare_skill("cuff", "meinu-quanfa");
        prepare_skill("strike", "tianluo-diwang");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

        create_family("��Ĺ��", 1, "��ɽ��ʦ");

        set("book_count",1);
        set("inquiry", ([
                "������" :  "�󵨺�С�ӣ�Ҳ��ֱ��������ʦ֮����\n",
                "������ʦ" : "������ȫ��̵��ƽ̣��Ժš������ˡ���\n",
                "��Ĺ��" :  "�ǰ������������һ�ִ��µĹ�Ĺ��\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/armor/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam = ob->query("family");

	if(ob->query("gender") != "Ů��") {
                command("say ���ǹ�Ĺ��ֻ��Ůͽ���Ҳ������㣬"+RANK_D->query_respect(ob)+"������ذɡ�");
                return;
                }
	if (!fam || fam["family_name"] != "��Ĺ��"){
                command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                return;
                }
	if(fam["master_name"] == "��Ī��") {
		command("say ����"+fam["master_name"]+"��ͽ�ܣ��Ҳ������㡣");
		return;
		}       
	if((int)ob->query_skill("force", 1) < 200) {
                command("say �ҹ�Ĺ�书�ڹ��ǻ�����"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
                return;
                }  
	if((int)ob->query_skill("dodge", 1) < 200) {
                command("say ���Ṧ��ô��ҽ̵��㲻һ��ѧ�ûᡣ"); 
                command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����Ṧ�϶��µ㹦��");
                return;
                }
	if((int)ob->query_skill("sword", 1) < 200) {
                command("say �㽣����ô��ҽ̵��㲻һ��ѧ�ûᡣ"); 
                command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                return;
                }
	if((int)ob->query_skill("yunu-jue", 1) < 200) {
                command("say �����Ů��ʮ�ľ���Ϊ��ǳ���������ҵĹ���"); 
                command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ������Ů��ʮ�ľ��϶��µ㹦��");
                return;
                }
	if((int)ob->query_skill("tianluo-diwang", 1) < 200) {
                command("say ������޵�������Ϊ��ǳ���������ҵĹ���"); 
                command("say "+RANK_D->query_respect(ob)+"���Ƕ�ץ��ֻ��ȸ�������Ұɡ�");
                return;
                }
	if(ob->query_int() < 42) {
                command("say �ҵ��书��Ҫ���ߵ����Բ���ѧ�ᡣ");
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
                command("say ��λ"+RANK_D->query_respect(ob)+"�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
                }
        command("say �ðɣ�����Ҳ���������ˣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if( me->query("qi",1) < 0 || me->query("jing",1) < 0 || me->query("jingli",1) < 0) return 1;

	if ( !me->is_fighting() ) {
					 if ( me->query("eff_qi") < me->query("max_qi") )
								me->exert_function("heal");
					 me->set("jiali", 50);

					 return 1;
		  }

		  if ( objectp(weapon) ) {
					 if ( weapon->query("skill_type") == "sword" )
								return perform_action("sword.suxin");
		  }
		  else return perform_action("cuff.luowang");
}