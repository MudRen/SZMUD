// Code of ShenZhou
// allow-letter5.c ��������ù���
inherit ITEM;

void create()
{
	set_name("��ӡ", ({"xin yin", "xin", "letter"}));
	set_weight(100);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long","����һ���ɵ���ʥ��ǩ������ӡ��ƾ�˿��������Ʋ�����ս��\n");
		set("no_get", "�������������뿪�㡣\n");
		set("material", "paper");
	}
}
