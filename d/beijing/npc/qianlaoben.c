//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("Ǯ�ϱ�", ({
		"qian laoben",
		"laoben",
		"qian",
	}));
	set("title", "��ľ�û���");
	set("long",
		"���ڳ���㡢�����������洦�ɼ�����ͨ�п�һ�㣬�������ۡ�\n"
	);


	set("gender", "����");
	set("attitude", "heroism");

	set("age", 40);
	set("shen_type",1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 600);
	set("max_neili", 600);
	set("combat_exp", 50000);
	set("score", 100);
	

	set_skill("force", 80);
	set_skill("dodge", 70);
	set_skill("cuff", 60);
	set_skill("claw",60);
	set_skill("strike",60);
	set_skill("unarmed",60);
	set_skill("parry", 80);
	set_skill("blade",60);
	set_skill("sword",60);
	set_skill("stick",60);
	set_skill("staff",60);
	
/*
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("blade", "cibei-dao");
*/
	setup();

      carry_object("/d/taihu/obj/cloth")->wear();
	carry_object("/d/city/obj/gangdao")->wield();
}

