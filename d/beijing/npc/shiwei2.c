//Cracked by Roath
// Npc: ��������
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);

void create()
{
	set_name("��������", ({
		"erdeng shiwei",
		"shiwei",
		"wei",
	}));
	set("long",
		"����һ��Ʒ�����͵���ǰ����������������������ӵܡ�\n"
		"���������е��Ĳ����ɡ�\n"
	);

	set("age", 35);
	setup();
	set_shiwei_status(120);

}

#include "/d/beijing/autok.h"
