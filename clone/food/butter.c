// Code of ShenZhou
// mitao.c ���� 
// By Summer 

inherit ITEM;

void create()
{
	set_name("����", ({"butter", "suyou"}));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��׼��������Ժ��ȥ��Ը�����õ����͡�\n");
		set("unit", "��");
		set("value", 500);
	}
}
