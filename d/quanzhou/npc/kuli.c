// Code of ShenZhou
// kuli.c

inherit NPC;

void create()
{
	set_name("����", ({ "ku li", "worker" }) );
	set("gender", "����" );
	set("age", 28);
	set("long",
		"���Ǹ���ʵ�ͽ��Ŀ��������ð�����Բ��һ���⡣\n");
//	set("shen_type", 1);
	set("combat_exp", 1200);
        set("str", 25);
        set("dex", 22);
        set("con", 20);
        set("int", 15);
	set("attitude", "heroism");
        set_temp("apply/attack", 12);
        set_temp("apply/defense", 15);

	setup();
        carry_object("clone/misc/cloth")->wear();

}

