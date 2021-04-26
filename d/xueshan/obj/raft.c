// Code of ShenZhou
// item: /d/qilian/obj/raft.c

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_ride", "ride");
}

void create()
{
        set_name("ľ��", ({"raft", "mu fa"}));
        set_weight(35000);
        set_max_encumbrance(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ֹ����Ƶ�ľ�������Գ�(ride)�����ӡ�\n");
                set("value", 1000);
		set("no_get", "��������̫���ˣ����ò�����\n");
        }
}

int do_ride(string arg)
{
	object  me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

               message("vision",this_player()->name() + "����ľ����\n",
                        environment(me), ({me}) );
               write("���ľ���ӽ�ˮ�Ȼ������ȥ����������ǰ����\n");
		me->move("/d/qilian/mufa");
		destruct(this_object());
        return 1;
}
