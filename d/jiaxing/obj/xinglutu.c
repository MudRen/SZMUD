// Code of ShenZhou
inherit ITEM;

void create()
{
	set_name("����ͼ", ({ "xinglu tu", "tu" }));
	set("weight", 1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"����һ����Ϊ�¾ɵĻ�ͼ�����Ͻ����š����η�����Ϫɽ����ͼ��ʮ�֣�"
		"һ����ɽ�������ī�����������۾�֮����\n");
		set("unit", "��");
		set("value",2000);
	}
	setup();
}	
