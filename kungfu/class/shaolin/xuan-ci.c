// Code of ShenZhou
// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
int auto_perform();

string ask_job();

void create()
{
	set_name("���ȴ�ʦ", ({
		"xuanci dashi",
		"xuanci",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿������ġ�\n"
		"������������ͣ���ȴ�����⣬Ŀ�̴�Ц���Ե��������㡣\n"
	);

	set("nickname", "�����·���");
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
        set_skill("jingang-quan", 120);
        set_skill("club", 120);
        set_skill("weituo-gun", 120);
        set_skill("strike", 160);
        set_skill("sanhua-zhang", 160);
        set_skill("hand", 120);
        set_skill("qianye-shou", 120);
	set_skill("finger", 160);
        set_skill("nianhua-zhi", 160);
	set_skill("parry", 150);
	set_skill("buddhism", 150);
	set_skill("literate", 101);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	create_family("������", 36, "����");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	(: auto_perform :), }));

        set("inquiry", ([
                "����" : (: ask_job :),
        ]));
	
	setup();

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

string ask_job()
{
        object obj, me = this_player();
        mapping myfam = me->query("family");

        if( !myfam || myfam["family_name"] != "������" )
                return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";

        if( myfam["generation"] > 37 )
                return RANK_D->query_respect(me) + "��������������������ɡ�";

        if( time() < (int)me->query("fz_ask") + 300 )
                return RANK_D->query_respect(me) + "���Ǹ��ʹ�����";

        if( present("tuijian xin", me) )
                return RANK_D->query_respect(me) + "�Ѿ��õ�ȥ�����ھִ����书���Ƽ����ˡ�";

        command("nod");
        me->set("fz_ask", time());

        obj = new("/d/shaolin/obj/letter-job");
        obj->set("owner", me->query("id"));
        obj->move(me);
        message_vision("$N����$nһ���Ƽ��š�\n", this_object(), me);
        return RANK_D->query_self(me) + "��һλ�׼ҵ����������ھֵ�����ͷ��" + RANK_D->query_respect(me) + "��ȥ�Ƕ�������ͷ�书��";
}

