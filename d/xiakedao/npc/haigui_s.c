//Cracked by Roath
// haigui_s
// Ssy


#include <ansi.h>

inherit NPC;

void create()
{
	set_name("С����", ({ "small haigui", "haigui", "gui"}));
        set("race", "Ұ��");
        set("age", 20);
	set("long", "����ֻС���꣬ͦ�ɰ������ӡ�\n");
	set("attitude", "peaceful");

	set("str", 13);
	set("int", 10);
	set("con", 19);
	set("dex", 15);

	set("max_qi", 100);
	set("eff_qi", 100);
	set("qi", 100);
	set("max_jing", 100);
	set("eff_jing", 100);
	set("jing", 100);

	set("max_jingli", 100);
	set("eff_jingli", 100);
	set("jingli", 100);
	set("combat_exp", 50);

	setup();
}


