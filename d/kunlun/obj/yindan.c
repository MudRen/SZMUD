inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name("�����ߵ�", ({"yin dan", "dan"}));
        set("unit", "��");
        set("long", "����һ�ź춬���������ߵ���\n");
        set("value", 100);
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
            this_player()->set("jing", this_player()->query("max_jing"));
          this_player()->set("qi", this_player()->query("max_qi"));
        message_vision(HIG"$N����һ�������ߵ�,�پ�ȫ�����¶������˻���!\n"NOR, this_player());
    destruct(this_object());
    return 1;
}
