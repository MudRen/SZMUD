// Code of ShenZhou
// /d/emei/npc/puren.c ���� 
// Shan: 96/07/09

inherit NPC;

void create()
{
	int value;

	value = random(5);

	set_name("����", ({ "pu ren", "servant"}));
        set("long", 
"һ�����ͣ����Ӹ߸ߵģ�����һ����������Ĺ����ظ��������̺��档\n");
	set("gender", "����");
	set("age", 14 + value * 2 );

        set("str", 20);
        set("dex", 18);
        set("con", 20);
        set("int", 18);
        set("attitude", "friendly");

	set("combat_exp", 800 + 20 * value);
	set("shen_type", 0);
	setup();
	add_money("silver", 1 + value);
}
