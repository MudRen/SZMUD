// Code of ShenZhou

inherit NPC;

void create()
{
	set_name("�Ϻ���", ({"seng ren","heshang"}));
	set("long",
		"����һλ�Ϻ��У�����������ϵ����Ĵ����˲�����\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 65);
	set("shen_type", 1);
	set("str", 20);
	set("int", 30);
	set("con", 25);
	set("dex", 23);
	set("max_qi", 580);
	set("max_jing", 500);
	set("neili", 480);
	set("max_neili", 480);
	set("jiali", 27);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("force", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);

	setup();
	carry_object("/d/shaolin/obj/cloth")->wear();

	setup();
}

int accept_object(object me, object obj)
{
	if( obj->query("name") == "��վ�" )
	{
		command("smile");
		command("say �����ӷ𣬶�л��λ" + RANK_D->query_respect(me) + "�� ��");
	}

	return 1;
}

