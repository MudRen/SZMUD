// Code of ShenZhou
// hama.c

inherit NPC;

void create()
{
	set_name("ç�����", ({"hama"}) );
	set("race", "Ұ��");
	set("age", 1000);
	set("long", "����һֻ�������ǳ���ֵĸ�󡣬���;޴�ȫ��ͨ�졣\n");
	set("str", 50);
	set("dex", 50);
	set("limbs", ({ "ͷ��", "����" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 50);

	setup();
}
