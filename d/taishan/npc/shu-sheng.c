// Code of ShenZhou
// shu-sheng.c

inherit NPC;

void create()
{
	set_name("����", ({ "shu sheng", "sheng" }) );
	set("gender", "����" );
	set("age", 22);
	set("int", 28);
	set("long",
		"���Ǹ�����ʫ�飬ȴ���޲���֮��������������\n");

	set("attitude", "peaceful");
	set("combat_exp", 400);
	set_skill("literate", 40);
	setup();
}

