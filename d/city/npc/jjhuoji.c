// Code of ShenZhou
// jjhuoji. �۽����

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�۽����", ({ "huoji", "keeper" }));
	set("str", 20);
	set("gender", "����");
	set("age", 25);
	set("long", "�����ü�׳�����һ�����������ӡ�\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");

	setup();
}
