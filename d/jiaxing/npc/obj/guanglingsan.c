// Code of ShenZhou
inherit ITEM;

void create()
{
	set_name("����ɢ", ({ "guangling san", "san" }));
	set("weight", 1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"���������ڶ�������Ĺ�����õù������ף�"
		"��������������������������¡�\n");
		set("unit", "��");
		set("value",1000);
	}
	setup();
}	
