// Code of ShenZhou
// meng-shi1.c �ɹ���ʿ

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�ɹ���ʿ", ({ "wei shi", "shi", "guard" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"����λ�ɹ���ʿ�������ּף���ִ�ֵ���˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
	set("combat_exp", 100000);
        set("shen_type", 1);
	set("attitude", "heroism");

	set("str", 25);
	set("con", 30);
	set("int", 20);
	set("dex", 30);

	set("max_qi", 800);
	set("eff_qi", 800);
	set("qi", 800);
	set("max_jing", 500);
	set("jing", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 30);
	set("shen_type", 0);


	set_skill("hand", 80);
	set_skill("wrestling", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	map_skill("hand", "wrestling");
	map_skill("parry", "wrestling");

	prepare_skill("hand", "wrestling");
	setup();

        carry_object(__DIR__"obj/m-robe")->wear();
}

