//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("�������", ({
		"xuanzhen daozhang",
		"daozhang",
		"xuanzhen",
	}));
	set("title", "��ľ�û���");
	set("long",
		"�����Ƴ��ף�һ���ʿ��磬������뺸��������Ƣ����Ϊ���ꡣ\n"
	);


	set("gender", "����");
	set("attitude", "heroism");
	set("class", "taoist");

	set("age", 40);
	set("shen_type",1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 200000);
	set("score", 10);
	

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("cuff", 90);
	set_skill("claw",40);
	set_skill("strike",90);
	set_skill("unarmed",90);
	set_skill("parry", 100);
	set_skill("blade",90);
	set_skill("sword",100);
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

