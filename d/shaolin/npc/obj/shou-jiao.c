// Code of ShenZhou
// shou-jiao.c

inherit ITEM;

void create()
{
	set_name("�޽�", ({"shou jiao", "jiao", "unicorn"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����Ǳ�ˮ���޵��޽ǣ��ഫ�����ƳɵĮ�ˮ�鹦�ܮ�ˮ���Һ������֡�\n");
		set("unit", "֧");
		set("material", "leather");
	}
	setup();
}

