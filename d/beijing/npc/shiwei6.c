//Cracked by Roath
// Npc: ��������
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);

void create()
{
	set_name("��������", ({
		"liudeng shiwei",
		"shiwei",
		"wei",
	}));
	set("long", "����һ���մӹٱ�����γ�����������\n");

	set("age", 25);
	setup();
	set_shiwei_status(30);

}

#include "/d/beijing/autok.h"
