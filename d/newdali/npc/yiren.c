// Code of ShenZhou
// yiren.c ��������

inherit NPC;

void create()
{
	set_name("��������", ({ "jianghu yiren", "yiren" }));
	set("long", "��������һ��������Ľ������ˣ�����ǣ��һֻ��˿����������糾֮ɫ��\n");
	set("gender", "����");
	set("age", 40+random(20));
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 2);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("max_qi", 300);
	set("max_jing", 300);
	set("combat_exp", 3500+random(1500));
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30+random(15));
	set_skill("parry", 50+random(5));
	set_skill("blade", 30+random(10));
	set("chat_chance", 8);
	set("chat_msg", ({
		"�����������������ͭ��ߺ�ȵ��������Ǯ������Ǯ����ûǮ�������˳���\n",
		}) );
	setup();
	carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/tongbo")->wield();
}
