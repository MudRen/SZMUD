// Code of ShenZhou
// xiang-ke.c �����

inherit NPC;

void create()
{
	int value;

	value = random(10);

	set_name("�����", ({ "jingxiang ke", "ke", "guest" }));
	set("gender", "����");
	set("age", 15 + value * 3 );

	set("combat_exp", 500 + 10 * value);
	set("shen_type", 0);
	setup();
	add_money("silver", 3 + value);
}
