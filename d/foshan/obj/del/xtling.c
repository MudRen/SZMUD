// Code of ShenZhou
inherit ITEM;

void create()
{
	set_name("������", ({ "xuantie ling", "ling" }));
	set("weight", 4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","һ����������Ƭ��һ��д�š�����֮������Ӧ������һ��д�š�Ħ����л�̿͡���\n");
		set("unit", "��");
		set("no_steal", 1);
		set("material", "gold");
	}
	setup();
}	
