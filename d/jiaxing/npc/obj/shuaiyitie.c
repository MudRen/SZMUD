// Code of ShenZhou
inherit ITEM;

void create()
{
	set_name("������", ({ "shuaiyi tie", "tie" }));
	set("weight", 1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"�����Ƴ�����Ŀ���漣���������������ϲ���󿪴��أ�"
		"����һλ���ָ���չ���Ṧ���ܸ߷��ͣ���Ȼ�ж�Ѹ�ݣ�"
		"ȴ��ʧ���ŵķ��¡�\n");
		set("unit", "��");
		set("value",2000);
	}
	setup();
}	
