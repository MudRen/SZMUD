// Code of ShenZhou
// gang.c ˮ��
// zhangchi 7/00


inherit ITEM;

void create()
{
        set_name("ˮ��", ({ "shui gang", "gang" }) );
        set_weight(90000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�������ˮ�ף���������������ˮ��\n");
                set("unit", "��");
		set("no_get", 1);
		set("value",1);
		set("amount", 0);
        }
}

string extra_long()
{
	int amount=query("amount");

	return "������"+chinese_number(amount)+"��ˮ��\n";
}	