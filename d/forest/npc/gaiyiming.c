// Code of ShenZhou
// Jay 7/11/96

inherit NPC;

void create()
{
	set_name("��һ��", ({ "gai yiming","gai" }) );
	set("gender", "����");
	set("age", 25);
	set("long",
		"����С�������°ͼ�����˵����ϸ��ϸ����\n");
	set("nickname","�˲���󸡢��ר�̤ѩ�޺ۡ�����ˮ�Ϸɡ�˫�̸���ʡ");
	set("title","̫������");
	set("combat_exp", 10000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  20);
	set("apply/defense", 20);

	set("chat_chance", 15);
	set("chat_msg", ({
		"��һ��һ�ڶ�ü�̣�ϸ��ϸ���ĵ���������ʲ�ᱦ�������������°ɣ���\n",
		"��һ��˫��һ�����������졣\n",
	}) );

	set_skill("sword", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_skill("dodge", 30);

	setup();
        carry_object(__DIR__"obj/emeici")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 1);
}
