// ���պ��ǵĹ�ͷ����Ⱦ�����Ķ���ѽ�����ٺ�  hs_gutou.c
// by naihe  02-06-06

inherit ITEM;

void create()
{
	set_name("��ͷ", ({"gutou","gu tou"}));
	set_weight(100);
	set("long", "����һ���ͷ���ƺ���ʲô��ʽ��ʣ�ġ�\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
	}
	setup();
}

