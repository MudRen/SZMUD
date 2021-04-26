// Code of ShenZhou
// /kungfu/class/dali/zhuwanli.c
// LARA 2001/12/17 ���dali job����dali/arrestmade��ֵΪ0
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("������", ({ "zhu wanli", "zhu"}));
    set("long","����һλ�����µľ��٣�ԼĪ��ʮ������ͣ�����Ӣ�����ˡ��ֳ�һ�����ˡ�\n");
	set("title","������佫");
    set("gender", "����");
    set("age", 35);
    set("inquiry", ([
		"Ͷ��" : (: ask_me :),
		"Ч��" : (: ask_me :),
		]));

	set("no_get","�����ſھ���������");
	set_skill("cuff", 65);
    set_skill("jinyu-quan", 65);
    set_skill("dodge", 65);
    set_skill("duanshi-shenfa", 65);
    set_skill("parry", 60);
    set_skill("force", 60);
    set_skill("staff", 65);
	set_skill("buddhism",70);
    set_skill("kurong-changong",60);
	set_skill("duanjia-jian",70);
    map_skill("cuff","jinyu-quan");
    map_skill("dodge","duanshi-shenfa");
    map_skill("force","kurong-changong");
	map_skill("staff","duanjia-jian");
	map_skill("parry","duanjia-jian");
	prepare_skill("cuff","jinyu-quan");
    set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);
    set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
    set("max_neili", 500);
    set("jiali", 30);
    set("combat_exp", 120000);
    set("attitude", "peaceful");
    set("shen_type", 1);
    create_family("����μ�", 15, "����");

    setup();
	carry_object("/d/dali/obj/ycloth")->wear();	
	carry_object("/d/dali/obj/diaogan")->wield();
}

string ask_me()
{
	object me=this_object(), who=this_player(), room=find_object("/d/dali/wangfu1.c");

	if (who->query("family/family_name")== "����μ�"
		|| who->query("dali/employee")) {
		message_vision("$N����$nһ�ۣ���ֵ��������Ѿ��Ǵ��������ѽ������������ʲô����\n", me, who);
		return RANK_D->query_respect(who)+"�е�û�¶���ȥ������ʲô������������Ҫ�����ҵ��ҡ�";
	}

	if (environment(me)!=room)
		return "�Բ�����ֻ�����������������һ�ȥ�������Ұɡ�";

	if (who->query("gender")=="����")
		return "��λ����������ı�߾Ͱɡ�";

	if (who->query("class") && who->query("class")!="officer")
		return RANK_D->query_respect(who)+"��ô���Ե���벻Ҫ�ñ�ְ����Ц��";

	if (who->query("combat_exp")<15000)
		return "��λ��"+RANK_D->query_respect(who)+"���޸���֮������ε��������ذɡ�";

	if (who->query("dali/betrayer"))
		return "������ͽ����������������";

	if (who->query("family/family_name")== "ؤ��")
		return "������������֮�أ��ɻʼ�������ؤ�ɺ���ͳ��"+RANK_D->query_respect(who)+"������ذɡ�";

	if (who->query("shen")>(who->query("combat_exp")/10)
		|| who->query("combat_exp")>350000
		|| who->query("family/family_name")== "�һ���")
		return RANK_D->query_respect(who)+"���ǽ����Ϻպ������ĸ��֣�����ƫ��С���������͸�������";

	if (who->query("shen")<(-who->query("combat_exp")/50)
		|| who->query("family/family_name")== "����ɽ"
		|| who->query("family/family_name")== "������"
		|| who->query("family/family_name")== "ѩɽ��"
		|| who->query("family/family_name")== "Ѫ����"
		|| who->query("sg/spy")
		|| (who->query("PKS")>20
		&& who->query("combat_exp")/who->query("PKS") < 10000))
		return RANK_D->query_rude(who)+"������Ͷ�٣������ڿ��ݲ��������ּ���С�ˣ�";

	who->set("dali/employee",1);
	who->set("dali/trust",100);
        who->set("dali/arrestmade",0);//����arrestmade��ֵ
	command("say �ðɣ�������Ϊ�����ҳ���ϣ��"+RANK_D->query_respect(me)+"Ϊ���������������������");
	return RANK_D->query_respect(who)+"��Ҫ��ס����������Ƚ������ɣ���һ��Ҫ���ط��棬����ᱻ���������ġ�";
}

void attempt_apprentice(object ob)
{
	mapping fam;
    string dldj;

	if (ob->query("family/family_name")=="����μ�") {
		command ("look "+ob->query("id"));
		if (ob->query("shen")<0) {
			command("say �������ݲ������������С�ˣ�");
			return;
		}
		command("hehehe "+getuid(ob));
		command("say ���ұ���ͬ�����£�������ѧЩ����Ȼû���⡣");
		ob->set_temp("title", ob->query("title"));
		command("recruit " + ob->query("id"));
		ob->set("title", ob->query_temp("title"));
		ob->delete_temp("title");
		return;
	}

	if ((!ob->query("family/family_name") || ob->query("family/family_name")=="��")
		&& ob->query("dali/trust")>=150) {
		command("say "+RANK_D->query_respect(ob)+"���Ҹ���ְ���գ������������Ŀ���ã��Ҿ�����ү���������������Ӱɡ�");
		ob->set_temp("title", ob->query("title"));
		command("recruit " + ob->query("id"));
		ob->set("title", ob->query_temp("title"));
		ob->delete_temp("title");
		ob->set("class","officer");
		command("addoil "+ob->query("id"));
		return;
	}

	command("shake "+ob->query("id"));
	command("say ������Ͷ�����Ϊ�����������㽭�����񣬲�����ͽ�ˡ�");
    return;
}

#include "/kungfu/class/dali/sangong.h"
