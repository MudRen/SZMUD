// Code of ShenZhou
// Npc: /kungfu/class/shaolin/xuan-tong.c
// Date: YZC 96/01/19

inherit NPC;
int auto_perform();
void create()
{
	set_name("��ʹ��ʦ", ({
		"xuantong dashi",
		"xuantong",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�����ĸߴ�\n"
		"���ֹ�ϥ��˫Ŀ������գ�ȴ��ʱ���һ�ƾ��⡣\n"
	);

	set("nickname", "����Ժ����");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 900000);
	set("score", 500000);

	set_skill("force", 150);
	set_skill("hunyuan-yiqi", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 150);
        set_skill("cuff", 120);
        set_skill("luohan-quan", 120);
        set_skill("club", 150);
        set_skill("weituo-gun", 120);
        set_skill("zui-gun", 150);
        set_skill("strike", 120);
        set_skill("sanhua-zhang", 120);
        set_skill("hand", 120);
        set_skill("qianye-shou", 120);
	set_skill("parry", 150);
	set_skill("buddhism", 150);
	set_skill("literate", 101);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("strike", "sanhua-zhang");
        map_skill("hand", "qianye-shou");
	map_skill("club", "zui-gun");
	map_skill("parry", "zui-gun");

	prepare_skill("finger", "nianhua-zhi");

	create_family("������", 36, "����");
	
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	(: auto_perform :), }));
	
	setup();
	carry_object("/clone/weapon/qimeigun")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
#include "/kungfu/class/shaolin/auto_perform.h"

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] < my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( (ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��") 
	||   (ob_fam["generation"] >=  my_fam["generation"]      && name[0..1] == "��") )
	{
		command("say " + ob_fam["master_name"] + "��ͽ����ô�ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}
	else
	{
		command("say " + RANK_D->query_respect(ob) + "���㱲�ݲ��ϣ�����Խ����ʦ��");
		return;
	}

	return;
}





