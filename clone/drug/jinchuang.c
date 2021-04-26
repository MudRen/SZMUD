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
		set("value", 500);
                set("no_sell", 1);
		set("medicine", 1);
	}
	::set_amount(1);
}

int cure_ob(object me)
{
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
	else if (this_player()->query_condition("jin_used") > 0) {
		add_amount(-1);
		message_vision("$NС������ذ�һ����ҩ�����˿��ϡ�\n", this_player());
		return 1;
	}
	else if ((int)this_player()->query("eff_qi") < 10
	      || (int)this_player()->query("qi") < 10) {
		add_amount(-1);
		message_vision("$NС������ذ�һ����ҩ�����˿��ϣ�������Ѫӿ������ҩ�۶��忪�ˡ�\n", this_player());
		return 1;
	}
	else {
		this_player()->receive_curing("qi", 50+random(100));
		add_amount(-1);
		message_vision("$NС������ذ�һ����ҩ�����˿��ϣ�ֻ�����ƴ�Ϊ��ת����ɫ�������ö��ˡ�\n", this_player());
		this_player()->apply_condition("jin_used", 1+random(3));
		return 1;
	}
}

