// Code of ShenZhou

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������ʿ", ({ "wu shi", "shi", "guard" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"һ��������׵�������ʿ��\n");
	set("combat_exp", 100000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_qi", 800);
	set("eff_qi", 800);
	set("qi", 800);
	set("max_jing", 500);
	set("jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);

	set_skill("blade", 100);
	set_skill("unarmed", 80);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set("no_get", "�㿸����");

	setup();

        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}

