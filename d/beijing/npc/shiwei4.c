//Cracked by Roath
// Npc: �ĵ�����
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);

void create()
{
	set_name("�ĵ�����", ({
		"sideng shiwei",
		"shiwei",
		"wei",
	}));
	set("long", "������ǰ���������������Ǹ������������ӵܡ�\n");

	set("age", 29);
	setup();
	set_shiwei_status(80);

}

#include "/d/beijing/autok.h"
