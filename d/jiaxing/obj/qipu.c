// Code of ShenZhou
inherit ITEM;

void create()
{
	set_name("����", ({ "qipu" }));
	set("weight", 1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"�����������ռ���Χ�����ֶ�ʮ�ֵ����ף�"
		"����������ٸ�����ɽ�Ѷ��ĵġ�ŻѪ�ס���\n");
		set("unit", "��");
		set("value",2000);
	}
	setup();
}	
