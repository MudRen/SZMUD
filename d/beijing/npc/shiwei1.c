//Cracked by Roath
// Npc: һ������
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);

void create()
{
	set_name("һ������", ({
		"yideng shiwei",
		"shiwei",
		"wei",
	}));
	set("long",
		"����һ��Ʒ�����͵���ǰ����������������������ӵܡ�\n"
		"���������е��Ĳ����ɡ�\n"
	);

	set("age", 39);
	setup();
	set_shiwei_status(150);

}

#include "/d/beijing/autok.h"
