//jiuer 09/09/2001
// longhua.c  ��Ů��

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "��Ů��" NOR, ({ "longnu hua", "hua" }));
	set("weight", 10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",HIR"һ�����ɫ���ʻ��������ò��á�\n"NOR);
		set("unit", "��");
		set("material", "wood");
	}
	setup();
}	
