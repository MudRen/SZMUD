// Code of ShenZhou
inherit ITEM;

void create()
{
	set_name("��ī", ({ "hui mo", "mo" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һ�˰��ճ�����ī����һ��ϣ��֮�䣬���ʺ��͸������ˡ�\n");
		set("unit", "��");
		set("value", 3000);
		set("material", "gold");
	}
	setup();
}	
