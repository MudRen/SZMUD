//Cracked by Roath
// Npc: �������
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);

void create()
{
	set_name("�������", ({
		"wudeng shiwei",
		"shiwei",
		"wei",
	}));
	set("long", "����һ���ͼ���ǰ������\n");

	set("age", 29);
	setup();
	set_shiwei_status(50);

}

#include "/d/beijing/autok.h"
