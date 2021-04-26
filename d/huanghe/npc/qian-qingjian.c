// Code of ShenZhou
// qian.c Ǯ�ཡ

inherit NPC;

void create()
{
	set_name("Ǯ�ཡ", ({ "qian qingjian", "qian" }));
	set("nickname", "ɥ�Ÿ�");
	set("long", 
"Ǯ�ཡ�ǻƺ��Ĺ�����ģ��ǹ�������ɳͨ����ĵ��ӣ����ڸ�����\n");
        set("title", "�ƺ��Ĺ�����");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 21);
	set("int", 18);
	set("con", 21);
	set("dex", 20);
	
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 20);
	set("combat_exp", 9500);

        set_temp("apply/attack",  30);
        set_temp("apply/defense", 30);

	set_skill("force", 30);
	set_skill("dodge", 35);
	set_skill("parry", 40);
	set_skill("axe", 45);
	set_skill("unarmed", 30);

	setup();
	carry_object("/clone/weapon/dafu")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}
