// Code of ShenZhou
// allow-letter3.c ��������ù���
inherit ITEM;

void create()
{
	set_name("����", ({"shou yu", "yu", "letter"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ���ɸ�˼��ǩ�������ͣ�ƾ�˿�����ʿ����ս������������\n");
		set("no_get", "�������������뿪�Ƕ���\n");
		set("material", "paper");
	}
}

