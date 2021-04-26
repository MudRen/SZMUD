// Code of ShenZhou
// huang.c �����ŵ���
inherit NPC;

void create()
{
	set_name("�����ŵ���", ({ "huanglong dizi","dizi" }) );
	set("gender", "����");
	set("age", 15+random(10));
	set("long",
		"���ǻ����ŵ��ӣ���Ͷ���С���ƺ��������¡�\n");
	set("combat_exp", 2000+random(20000));
	set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  15);
	set("apply/defense", 15);

	set("jingli",100);

	set("chat_chance", 5);
	set("chat_msg", ({
		"����˵�����������ͨ���ӣ��ڵ��������ٱ�����һ���٣��԰ٵ���\n",
		"����˵�����������Ŀ��磬�����ķ���\n",
		"����˵�����ҵ���ɱ�л��̣�������׼���Σ�����ʥְ��\n",
		"����˵�����ҽ̵��ӻ��̶�����ͬ�����á�\n",
	}) );

	set_skill("sword", 15+random(50));
	set_skill("unarmed", 15+random(50));
	set_skill("parry", 15+random(50));
	set_skill("dodge", 15+random(50));
	set_skill("strike", 15+random(50));

	create_family("������", 4, "����");

	setup();
	switch( random(3) )
	{
		case 0:
			carry_object("/clone/weapon/gangjian")->wield();
			break;
		case 1:
			carry_object("/clone/weapon/changjian")->wield();
			break;
		case 2:
			carry_object("/clone/weapon/duanjian")->wield();
			break;
	}

	carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 20);
}
