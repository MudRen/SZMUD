// Code of ShenZhou
inherit ITEM;

void create()
{
	set_name("����", ({ "liaokao" }));
	set("weight", 3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"����һ�������Ƴɵ��������εع����������ͽ����ϡ�\n");
		set("unit", "��");
		set("no_drop", "�㻹û�����ء�\n");
                set("no_get", "�������������뿪�Ƕ���\n");
	}

	setup();
}	
