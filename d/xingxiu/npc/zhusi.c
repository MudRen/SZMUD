// Code of ShenZhou
//  poison: shachongke.c
// Jay 3/17/96

// more work needed to use this object to make poison

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("����˿", ({"Du zhusi", "zhusi", "silk"}));
        set("unit", "��");
        set("long", "����һ��һֻ��֩�������³���˿�����Ʊ���ҩ��ԭ�ϡ�\n");
        set("value", 200);
	set("medicine", 1);
//        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        return notify_fail("����������\n");
}

