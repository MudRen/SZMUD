// Code of ShenZhou
// jinchuang.c ��ҩ

//inherit ITEM;
inherit COMBINED_ITEM;
void setup()
{}

int cure_ob(string);
void create()
{
	set_name("��ҩ", ({"jinchuang yao", "jin", "jinchuang"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Щ");
		set("base_unit", "��");
		set("long", "����һ��������ʿ�ر��Ľ�ҩ��\n");
		set("value", 5000);
		set("medicine", 1);
	}
	::set_amount(1);
}

int cure_ob(object me)
{
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
	else {
		this_player()->receive_curing("qi", 50);
		message_vision("$NС������ذ�һ����ҩ�����˿��ϣ�ֻ�����ƴ�Ϊ��ת����ɫ�������ö��ˡ�\n", this_player());
		add_amount(-1);
		return 1;
	}
}

