// ling.c
//jiuer 9/2001
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL "����" NOR, ({ "shou ling", "ling" }));
	set("weight", 8);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",YEL"һ��ֽ�Ƶ�ׯ�����\n"NOR);
		set("unit", "��");
		set("material", "paper");
	}
	setup();
}	
