// Code of ShenZhou
// allow-letter3.c ��������ù���
inherit ITEM;

void create()
{
	set_name("ʥּ", ({"sheng zhi", "zhi", "letter"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ���ɵ���ʥ��ǩ����ʥּ��ƾ�˿�����ʿ�����ս�������佫��\n");
		set("no_get", "�������������뿪�Ƕ���\n");
		set("material", "paper");
	}
}

