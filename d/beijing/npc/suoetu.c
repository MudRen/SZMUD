//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("����ͼ", ({
		"suo etu",
		"etu",
		"suo",
	}));
	set("title", "��ʷ�ݴ�ѧʿ");
	set("long",
		"���ٰݹ�ʷ�ݴ�ѧʿ���Դ����ݱ���ְ�н��Ժ������˺�ͨ����Ϊ�����س�����\n"
	);


	set("gender", "����");
	set("attitude", "heroism");

	set("age", 45);
	set("shen_type",1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 600);
	set("max_jing", 600);
	set("neili", 600);
	set("max_neili", 600);
	set("combat_exp", 50000);
	set("score", 100);
	

	set_skill("force", 50);
	set_skill("dodge", 60);
	set_skill("cuff", 50);
	set_skill("claw",50);
	set_skill("strike",50);
	set_skill("unarmed",50);
	set_skill("parry", 50);
	set_skill("blade",50);
	set_skill("sword",50);
	set_skill("stick",50);
	
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

