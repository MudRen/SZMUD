//Cracked by Roath
// haigui
// Ssy


#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({ "haigui", "gui"}));
        set("race", "Ұ��");
        set("age", 100+random(100));
	set("long", "����ֻ���ϵĺ��꣬����ֺ��ִ�\n");
	set("attitude", "peaceful");

	set("str", 15);
	set("int", 10);
	set("con", 19);
	set("dex", 15);

	set("max_qi", 300);
	set("eff_qi", 300);
	set("qi", 300);
	set("max_jing", 150);
	set("eff_jing", 150);
	set("jing", 150);

	set("max_jingli", 150);
	set("eff_jingli", 150);
	set("jingli", 150);
	set("combat_exp", 80);
        set_temp("apply/armor",  30);


	setup();
}


