// Code of ShenZhou
// amulet.c ������
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name("������", ({ "amulet" }));
        set_color("$YEL$");
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ����Ϊ���µĳ��������������൱�ƾɣ�"+
			    "������ϡ���ˡ��������ꡱ�����֣������ƺ���һ��СС�ġ������֡�\n");
		set("unit", "��");
		set("value", 1500);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
