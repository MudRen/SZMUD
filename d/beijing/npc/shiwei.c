//Cracked by Roath
// Npc: ����
// Ssy 

inherit NPC;

void create()
{
	set_name("����", ({
		"shi wei",
		"shiwei",
		"wei",
	}));
	set("long",
		"����һ����δ��ȼ�����ǰ����������������ӵܣ��������ĵ���վ�š�\n"
	);


	set("gender", "����");
	set("attitude", "heroism");

	set("age", 20);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 5000);
	set("score", 100);
	

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("cuff", 40);
	set_skill("claw",40);
	set_skill("strike",40);
	set_skill("unarmed",40);
	set_skill("parry", 40);
	set_skill("blade",40);
	set_skill("sword",40);
	set_skill("stick",40);
	set_skill("staff",40);
	
/*
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("blade", "cibei-dao");
*/
	setup();

	carry_object("/d/beijing/obj/shiweicloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

