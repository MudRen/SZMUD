// Code of ShenZhou
// yufu.c ���
inherit NPC;

void create()
{
	set_name("���", ({ "yu fu","fu" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"�����Դ���Ϊ�������\n");
	set("combat_exp", 8800);
	set("shen_type", 0);
	set("attitude", "friendly");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set("jingli",100);

//      set_skill("unarmed", 30);
//      set_skill("parry", 30);
//      set_skill("dodge", 30);

	setup();
	carry_object("/d/shenlong/obj/cloth")->wear();
	add_money("coin", 50);
}
