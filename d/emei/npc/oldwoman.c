// Code of ShenZhou
// /d/emei/npc/oldwoman.c
// Shan: 96/07/08

inherit NPC;

void create()
{
        set_name("�ϴ���", ({ "old woman", "woman" }) );
        set("gender", "Ů��" );
        set("age", 63);
        set("long", "һ��������˪֮ɫ�������š�\n");
//	set("shen", 1000);
	set("shen_type", 1);
	set("combat_exp", 150);
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 13);
        set("attitude", "friendly");
        setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 100);
}

