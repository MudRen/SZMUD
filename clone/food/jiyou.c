// Code of ShenZhou
// jiyou.c ���� 
// By xbc 

inherit ITEM;

void create()
{
	set_name("����", ({"ji you", "chicken butter", "butter"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������ļ��͡�\n");
		set("unit", "��");
		set("value", 0);
	}
}
