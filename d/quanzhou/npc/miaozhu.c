// Code of ShenZhou
// miaozhu.c ��ף

inherit NPC;

void create()
{
	set_name("��ף", ({ "miao zhu", "zhu" }));
	set("long",
		"����һλ���ϵ���ף���ڴ��Ѽ�ʮ���ˣ��Դ˵�һ�ж�ʮ����Ϥ��\n"
	);

	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("chat_msg",({
		"��ף˵������λʩ�����������㣬������������ү���ӡ�\n",
		"��ף˵���������Ʊ�������������үһ���ᱣ�������˵ġ�\n",
	}));

	set("age", 65);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 300);
	set("max_jing", 150);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 3000);
	set("score", 100);
	set("chat_chance", 5);

	set_skill("force", 25);
	set_skill("dodge", 25);
	set_skill("unarmed", 25);
	set_skill("parry", 25);

	setup();
}
