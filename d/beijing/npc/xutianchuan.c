//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("���촨", ({
		"xu tianchuan",
		"tianchuan",
		"xu",
	}));
	set("title", "��ľ�û���");
	set("long",
		"�������������������һ������ͷ�ӣ���������һ�������ĸ�ҩ�졣\n"
	);


	set("gender", "����");
	set("attitude", "heroism");

	set("age", 50);
	set("shen_type",1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 900);
	set("max_jing", 900);
	set("neili", 900);
	set("max_neili", 900);
	set("combat_exp", 150000);
	set("score", 100);
	

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("cuff", 70);
	set_skill("claw",90);
	set_skill("strike",50);
	set_skill("unarmed",50);
	set_skill("parry", 90);
	set_skill("blade",80);
	set_skill("sword",90);
	set_skill("stick",70);
	
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

