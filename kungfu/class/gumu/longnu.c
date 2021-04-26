//7/14/2001 by Xuanyuan

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
int auto_perform();
string ask_yufengjiang();

void create()
{
        set_name("С��Ů", ({ "xiao longnu", "long", "longnu" }));
		set("long", "�������쳣����Ҳ���ǳ��ӹ�Ĺ֮�ʣ���ɫ�԰ס�\n");
        set("gender", "Ů��");
        set("age", 18);
        set("attitude", "friendly");
        set("str", 20);
        set("dex", 28);
        set("con", 20);
        set("int", 28);
        set("shen", 20000);

        set("combat_exp", 1600000);
        set("max_qi", 2500);
        set("max_jing", 5600);
        set("neili", 4500);
        set("max_neili", 4500);

        set("jiali",50);

        set_skill("literate", 150);
        set_skill("parry", 240);
        set_skill("force", 240);
        set_skill("dodge", 240);
        set_skill("sword", 240);
        set_skill("whip", 240);
        set_skill("throwing",240);
        set_skill("cuff", 240);
        set_skill("strike", 240);
        set_skill("meinu-quan", 240);
        set_skill("gumu-shenfa", 240);
        set_skill("tianluo-diwang", 240);
        set_skill("yinsuo-jinling", 240);
        set_skill("yunu-jue", 300);
        set_skill("yunu-jianfa", 240);
        set_skill("quanzhen-jian", 240);
        set_skill("yunu-xinjing", 240);

        map_skill("force", "yunu-xinjing");
        map_skill("dodge", "gumu-shenfa");
        map_skill("cuff", "meinu-quan");
        map_skill("strike", "tianluo-diwang");
        map_skill("whip", "yinsuo-jinling");
        map_skill("sword", "yunu-jianfa");
        map_skill("parry", "yunu-jianfa");

        prepare_skill("cuff", "meinu-quanfa");
        prepare_skill("strike", "tianluo-diwang");

        create_family("��Ĺ��",3,"����");
        set("inquiry", ([
		"���" : "�������ҷ������֪�����ܰ��ң���һֱ���������������ơ�",
		"job" : "��ȥĹ������ץץ��ȸ��������ϰһ���Ṧȥ�ɡ�",
		"����" : "��ȥĹ������ץץ��ȸ��������ϰһ���Ṧȥ�ɡ�",
		"work" : "��ȥĹ������ץץ��ȸ��������ϰһ���Ṧȥ�ɡ�",
		"�ؼ�" : (: ask_me :),
		"��佬" : (: ask_yufengjiang :),
       ]) );
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	set("book_count", 1);
	set("jiang_count", 4);

        setup();
        carry_object("/d/zhongnan/obj/baipao")->wear();
        carry_object("/d/zhongnan/obj/jinsi-shoutao")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/zhongnan/obj/jinling-suo");
}

void attempt_apprentice(object ob)
{

	mapping fam = ob->query("family");

	if(ob->query("gender") != "Ů��") {
                command("say ��ʦ���Ŷ��µĹ�أ����ǹ�Ĺ��ֻ��Ůͽ���Ҳ������㣬"+RANK_D->query_respect(ob)+"������ذɡ�");
                return;
                }
	if (!fam || fam["family_name"] != "��Ĺ��"){
                command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                return;
                }
	if(fam["master_name"] == "��Ī��") {
		command("say ������ʦ��"+fam["master_name"]+"��ͽ�ܣ��Ҳ������㡣");
		return;
		}       
	if((int)ob->query_skill("force", 1) < 100) {
                command("say �ҹ�Ĺ�书�ڹ��ǻ�����"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
                return;
                }  
	if((int)ob->query_skill("dodge", 1) < 100) {
                command("say ���Ṧ��ô��ҽ̵��㲻һ��ѧ�ûᡣ"); 
                command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����Ṧ�϶��µ㹦��");
                return;
                }
	if((int)ob->query_skill("sword", 1) < 100) {
                command("say �㽣����ô��ҽ̵��㲻һ��ѧ�ûᡣ"); 
                command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                return;
                }
	if((int)ob->query_skill("yunu-jue", 1) < 100) {
                command("say �����Ů��ʮ�ľ���Ϊ��ǳ���������ҵĹ���"); 
                command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ������Ů��ʮ�ľ��϶��µ㹦��");
                return;
                }
	if((int)ob->query_skill("tianluo-diwang", 1) < 100) {
                command("say ������޵�������Ϊ��ǳ���������ҵĹ���"); 
                command("say "+RANK_D->query_respect(ob)+"���Ƕ�ץ��ֻ��ȸ�������Ұɡ�");
                return;
                }
	if(ob->query_int() < 30) {
                command("say �ҵ��书��Ҫ���ߵ����Բ���ѧ�ᡣ");
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
                command("say ��λ"+RANK_D->query_respect(ob)+"�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
                }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob, *obs;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "��Ĺ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";

	obs = filter_array(children("/d/zhongnan/obj/yunu_book1.c"), (: clonep :));
        if (sizeof(obs) > 2)
		return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";

	ob=new("/d/zhongnan/obj/yunu_book1");
	ob->move(this_player());
	add("book_count", -1);
	command ("rumor "+this_player()->query("name")+"Ū����һ����Ů��ʮ�ľ��Ͼ�");
	return "���ɵ��ڹ��ķ���Ů�ľ�����������������Ȿ����Ů��ʮ�ľ��Ͼ�������û�ȥ�ú����С�";
}

string ask_yufengjiang()
{
	mapping fam; 
	object ob, *obs;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "��Ĺ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if(fam["master_name"] == "��Ī��") 
		return "��ôʦ���ͽ��Ҳ�����Ĺ��Ķ�������Ȥ��";

	if (query("jiang_count") < 1)
		return "�������ˣ���佬�Ѿ����������ʦ��ʦ�����ˡ�";

	if ( (int)this_player()->query("eff_qi")==(int)this_player()->query("max_qi") ) {
                message_vision("$N��$n������ϸ�ش�����һ��ҡ��ҡͷ��\n", this_object(), this_player());
                return "��佬���Ʋ��ף��㲢δ���ˣ��Ҳ��ܸ��㡣\n";
        }

	ob=new("/clone/drug/yufeng-jiang");
	ob->move(this_player());
	add("jiang_count", -1);
	return "�������ǹ�Ĺ�ɵ�������ҩ������ȥ�ú÷��á�";
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