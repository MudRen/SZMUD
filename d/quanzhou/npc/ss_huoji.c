// Code of ShenZhou
// ss_huoji. ������ׯ���

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("������ׯ���", ({ "huoji", "keeper" }));
	set("str", 20);
	set("gender", "����");
	set("age", 25);
	set("long", "���Ǹ����͵Ļ�ƣ������������Ĺ˿ͽ��ܸ�ʽ��ɫ���ʵصĳ�С�\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");

	setup();
}
