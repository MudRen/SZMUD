// Code of ShenZhou
inherit ITEM;

void create()
{
	set_name("ʩ��������", ({ "shi lingpai", "lingpai", "pai" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һ֧ľ���ƣ�����һ����ʩ���֡�\n");
		set("unit", "֧");
		set("material", "wood");
	}
	setup();
}	
