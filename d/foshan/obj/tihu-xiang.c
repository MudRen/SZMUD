// Code of ShenZhou
//tihu-xiang.c ������
//�׻����������ˣ��ŵ��Ծã���������Ҿ�һ��
//by Apache

#include <ansi.h>

inherit ITEM;

void create() {
    set_name(HIW "������" NOR, ({ "tihu xiang", "xiang" }) );
    set("weight", 10);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "һ��С�׻�������Ũ����\n");
        set("unit", "��");
        set("material", "wood");
    }
    setup();
}

void init() {
    add_action("do_smell", "smell");
}

int do_smell(string arg) {
    object me = this_player();

    if(!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

    me->apply_condition("drunk", (int)me->query_condition("drunk") + random(20));

    message_vision(HIG "$N�����������㣬һ��Ũ��������ֱ��ͷ����\n" NOR, me);

    return 1;
}