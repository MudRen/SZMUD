// Code of ShenZhou
// /d/emei/npc/woman.c
// Shan: 96/07/08

inherit NPC;

void create()
{
        set_name("�ٸ�", ({ "young woman", "woman" }) );
        set("gender", "Ů��" );
        set("age", 20+random(10));
        set("long", 
"һ���ٸ�����Ц���е�����ӭ����\n");
	set("shen_type", 1);
	set("combat_exp", 500);
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 15);
        set("attitude", "friendly");
        setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

