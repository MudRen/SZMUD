// Code of ShenZhou
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������ʿ", ({ "wei shi", "shi", "guard" }) );
	set("gender", "����");
	set("age", 35);
	set("long", "����λ������������ʿ��\n");
	set("combat_exp", 120000);
	set("shen_type", 1);
	set("attitude", "heroism");

	set("str", 25);
	set("con", 30);
	set("int", 20);
	set("dex", 30);

	set("max_qi", 1000);
	set("qi", 1000);
	set("max_jing", 500);
	set("jing", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 30);
	set("shen_type", 0);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);

	set_skill("blade", 120);
	set_skill("unarmed", 80);
	set_skill("parry", 120);
	set_skill("dodge", 120);

	set("no_get", "�㿸����");

	setup();

	carry_object("/d/city/obj/gangdao")->wield();
	carry_object("/d/city/obj/tiejia")->wear();

}
#include "/kungfu/class/dali/condition.h"
