// Code of ShenZhou
// byskirt.c

inherit ITEM;

void create()
{
	set_name("��ɴ��", ({ "fangsha ji", "ji", "machine" }) );
	set("long", "һ̨�����൱�򵥵��ֹ���ɴ�����������ɵİ��ĸ�Ů�������ֲִڵķ����֯�����֯Ʒ��\n");
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "̨");
		set("material", "wood");
		set("no_get", 1);
	}
	setup();
}
