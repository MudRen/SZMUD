inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name("����ߵ�", ({"jin dan", "dan"}));
        set("unit", "��");
        set("long", "����һ�ź춬���Ľ���ߵ���\n");
        set("value", 100);
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
      this_player()->set("jingli", this_player()->query("max_jingli"));
          message_vision(HIY"$N����һ�Ž���ߵ�,�پ������ٱ�!\n"NOR, this_player());
    destruct(this_object());
    return 1;
}
