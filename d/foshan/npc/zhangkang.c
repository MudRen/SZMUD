// Code of ShenZhou
// kuli.c
// Jay 6/1/97

inherit NPC;

void create()
{
	set_name("�ſ�", ({ "zhang kang", "zhang", "kang" }) );
	set("gender", "����" );
	set("age", 28);
	set("long",
		"���Ǹ���ʵ�ͽ��ĺ��ӣ����ų��ƵĴ��ˡ�\n");
	set("shen_type", 1);
	set("combat_exp", 1200);
        set("str", 25);
        set("dex", 22);
        set("con", 20);
        set("int", 15);
	set("attitude", "friendly");

	setup();
	add_money("silver", 30);
        carry_object("clone/misc/cloth")->wear();

}

