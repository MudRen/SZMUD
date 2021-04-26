// Code of ShenZhou
// /kungfu/class/quanzhen/ma.c
// ma.c ����
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("����", ({ "ma yu", "ma" }));
	set("nickname", "������");
	set("long",
		"������ȫ�������е���ͽ���ڣ����ŵ����ӣ�ǰ��ȫ����ƽ����ˡ�\n"
		"����һ�������ʿ����ɫ������������һ�����档\n"
		"װ��ʮ�ֹŹ֣�ͷ�������������ӣ��߸�������һ������һ����Ⱦ��\n"
      );
	set("gender", "����");
	set("age", 75);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 3000);
	set("max_jing", 2500);
	set("max_jingli", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 120);
	set("combat_exp", 800000);
	set("score", 60000);

	set_skill("beidou-zhenfa", 160);
	set_skill("force", 380);
	set_skill("xiantian-gong", 170);
	set_skill("dodge", 150);
	set_skill("jinyangong", 150);
	set_skill("cuff", 150);
	set_skill("chunyang-quan", 150);
	set_skill("strike", 150);
	set_skill("sanhua-juding", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("whip", 150);
	set_skill("duanyun-bian", 150);
	set_skill("quanzhen-jian", 160);
	set_skill("literate", 101);
	set_skill("taoism", 380);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");
	map_skill("whip", "duanyun-bian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("ȫ���", 2, "����");


	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	set("inquiry", ([
		"�ؼ�" : (: ask_me :),
		"miji" : (: ask_me :),
	]));


	set("book_count", 1);

	setup();
	carry_object("/clone/weapon/fuchen")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam;
	string name,new_name;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "ȫ���" )
	{
		command ("say " + RANK_D->query_respect(this_player())
			+ "�����������ˣ�ϰ�仹���ȴӸ�λ������ɣ�");
		return;
	}

	if ((int)ob->query_skill("xiantian-gong", 1) < 70) {
		command("say ��ȫ������ڼ��书���������ڹ��ķ���");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�����������칦�϶��µ㹦��");
		return;
	}

	if ((int)ob->query("shen") < 35000) {
		command("say ��ȫ������������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	command("say �ðɣ�ƶ�����������ˡ�");
	name = ob->query("name");
	new_name = name[0..01]+"־" + name[4..5];
	command("say �ӽ��Ժ���ͽ���" + new_name + "��");
	ob->set("name",new_name);
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam;
	object ob, *obs,ob2 ;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "ȫ���")
		return RANK_D->query_respect(this_player()) +
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (query("book_count") < 1)
		return "�������ˣ����ɵı޷��ؼ����ڴ˴���";

	obs = filter_array(children("/d/zhongnan/obj/whip_book"), (: clonep :));
		  if (sizeof(obs) > 5)
		return "�������ˣ����ɵı޷��ؼ����ڴ˴���";

	ob=new("/d/zhongnan/obj/whip_book");
	ob->move(this_player());
	add("book_count", -1);
	command ("rumor "+this_player()->query("name")+"Ū����һ�ᵤ���޷��ס�");
	return "�ðɣ��Ȿ�������޷��ס����û�ȥ�ú����С�";
}

#include "auto_perform.h"

