// Code of ShenZhou
// work-letter2.c ��������ù���
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "����" NOR, ({"zou zhe", "letter"}));
	set_weight(100);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long",HIB"һ���Ʋ�������ϳʱ���������ۡ�\n"NOR);
		set("no_get", "�������������뿪�㡣\n");
		set("material", "paper");
	}
}
