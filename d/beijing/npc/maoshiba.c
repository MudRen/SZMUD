//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("éʮ��", ({
		"mao shiba",
		"shiba",
		"mao",
	}));
//	set("title", "");
	set("long",
		"����һ�������׳�����ֱ��ϼ�����򰣬Ŀ�����⣬�������͡�\n"
	);


	set("gender", "����");
	set("attitude", "heroism");

	set("age", 45);
	set("shen_type",0);
	set("str", 35);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 300000);
	set("score", 100);
	

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("cuff", 100);
	set_skill("claw",100);
	set_skill("strike",100);
	set_skill("wuhu-duanmen",100);
	set_skill("parry", 100);
	set_skill("blade",120);
	set_skill("sword",100);
	set_skill("stick",100);
	set_skill("staff",100);
	set_skill("wuxing-quan",100);	
	set_skill("wuxingbu",100);


	map_skill("blade", "wuhu-duanmen");
	map_skill("parry", "wuhu-duanmen");
	map_skill("dodge", "wuxingbu");
	map_skill("cuff", "wuxing-quan");

	prepare_skill("cuff", "wuxing-quan");
	setup();

      carry_object("/d/taihu/obj/cloth")->wear();
	carry_object("/d/city/obj/gangdao")->wield();
}

