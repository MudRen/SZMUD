// item: /d/jueqing/obj/raft2.c
// jiuer

inherit ITEM;
void setup()
{}

void init()
{
	add_action("do_ride", "ride");
}

void create()
{
	set_name("Ƥ��", ({"raft", "pi fa"}));
	set_weight(35000);
	set_max_encumbrance(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ֹ����Ƶ�Ƥ�������Գ�(ride)����\n");
		set("value", 1000);
		set("no_get", "��������̫���ˣ����ò�����\n");
        }
}
int do_ride(string arg)
{
	object  me = this_player();
    if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	message("vision",this_player()->name() + "����Ƥ�����þ��ػ���������������������ȥ��\n",
		environment(me), ({me}) );
	write("���Ƥ���ƽ�ˮ�Ȼ������ȥ���þ�����ǰ��....\n\n");
	me->move("/d/jueqing/valley");
	destruct(this_object());
	return 1;
}
