// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(HIB"����"NOR, ({"lan hua","hua","flower"}));
	set_weight(5);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
	set("unit", "��");
      set("long", "����������ɫ����������״���أ�ÿ�仨������һֻЬ�ӡ�\n");
      set("value", 100);
	set("medicine", 1);
	set("no_get",1);
	}
	setup();
}

