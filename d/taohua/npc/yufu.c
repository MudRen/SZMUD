// Code of ShenZhou
// yufu.c ���

inherit NPC;

void create()
{
	set_name("���", ({ "yu fu","fu" }) );
	set("gender", "����");
	set("age", 35);
        set("long",
		"һ��Ѱ�����Դ���Ϊ�������\n");
	set("combat_exp", 8800);
	set("shen_type", 0);
	set("attitude", "friendly");

	set("apply/attack",  50);
	set("apply/defense", 50);
	set("jingli",300);
	set("max_jingli",300);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_skill("dodge", 30);


        setup();
	carry_object("/d/shenlong/obj/cloth")->wear();
	add_money("coin", 50);
}

