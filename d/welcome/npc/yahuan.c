// yahuan.c

inherit NPC;

void create()
{
	set_name("СѾ��", ({ "ya huan","yahuan","ya" }) );
	set("gender", "Ů��");
	set("age", 16);
	set("long",
		"����ӭ���ݵ�СѾ�ߣ���Լʮ���꣬��������æ�Ŵ�ɨ��\n");
	set("combat_exp", 200);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("apply/attack", 10);
	set("apply/defense", 10);

	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();

	carry_object("/clone/misc/cloth")->wear();
}
