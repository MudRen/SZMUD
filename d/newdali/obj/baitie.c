// Code of ShenZhou
// baitie.c ����
// AceP

inherit ITEM;

void create()
{
	set_name("����", ({"bai tie", "tie", "letter"}));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);
    else {
		set("unit", "��");
        set("long","����һ����������ױ�д�İ�����ƾ�˿�ǰ������ɽ��������Ħ������������һ�εı��䡣\n");
		set("no_drop", "�������������뿪�㡣\n");
		set("no_get",  "�������������뿪�Ƕ���\n");
        set("material", "paper");
    }
}


