// Code of ShenZhou
// allow-letter2.c ��������ù���
inherit ITEM;

void create()
{
	set_name("����", ({"gong wen", "wen", "letter"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ���ɸߺ�үǩ���Ĺ��ģ�ƾ�˿��򶨰�������������\n");
		set("no_get", "�������������뿪�Ƕ���\n");
		set("material", "paper");
	}
}

