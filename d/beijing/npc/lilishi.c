//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("������", ({
		"li lishi",
		"lishi",
		"li",
	}));
	set("title", "��ľ�û���");
	set("long",
		"һ�����£�ͷ���ײ�����ϵ�״����������ߡ�\n"
	);


	set("gender", "����");
	set("attitude", "heroism");

	set("age", 35);
	set("shen_type",1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 600);
	set("max_jing", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("combat_exp", 100000);
	set("score", 100);
	

	set_skill("force", 100);
	set_skill("dodge", 80);
	set_skill("cuff", 80);
	set_skill("claw",70);
	set_skill("strike",80);
	set_skill("unarmed",80);
	set_skill("parry", 80);
	set_skill("blade",80);
	set_skill("sword",80);
	set_skill("stick",80);

	
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

