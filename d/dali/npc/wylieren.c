// Code of ShenZhou
// wylieren.c ��������

inherit NPC;

void create()
{
	set_name("����", ({ "lie ren", "ren", "hunter" }) );
	set("long", "һλ��ǿ��׳�����������֡�\n");

	set("age", 25);
	set("gender", "����");
	set("dalivictim",1);

	set("str", 20);
	set("cor", 20);

    set("combat_exp", 10000);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 20);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 10);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/d/dali/obj/hunterbow.c")->wield();
	carry_object("/clone/weapon/arrow.c");
	carry_object("/d/dali/npc/obj/wyhui.c")->wear();
}
