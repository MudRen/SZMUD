//Cracked by Roath
// Npc: ��������
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);

void create()
{
	set_name("��������", ({
		"sandeng shiwei",
		"shiwei",
		"wei",
	}));
	set("long", "����һ����ǰ���������������Ǹ������������ӵܡ�\n");

	set("age", 32);
	setup();
	set_shiwei_status(100);

}

#include "/d/beijing/autok.h"
