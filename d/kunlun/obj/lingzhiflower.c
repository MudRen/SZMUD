//lingzhi.c ��֬��
inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
          add_action("do_cai","cai");
}
void create()
{
    set_name( MAG "��֬��" NOR, ({"lingzhi flower","lingzhi","flower"}));
        set("unit", "��");
        set("value", 60);
      set("long", "��������˻����֥������������һ�ɵ�����������\n");
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
message_vision(RED"$N��ϸ������"+this_object()->name()+RED+"����ԥ�˰���,�̲�סһ�ڰ�"+this_object()->name()+RED+"����!\n" NOR,this_player());
    if(random(2)==0)
        this_player()->unconcious();
    else{
    this_player()->set_temp("die_for","����֥����");
        this_player()->die();
    }
       this_object()->move(VOID_OB);
    destruct(this_object());
    return 1;
}
  int do_cai(string arg)
{
        if( !arg || !id(arg) )
        return notify_fail("�����ʲô��\n");
        if (environment()==this_player())
             return notify_fail("��������֥���ڵ��ϲ��ܲȡ�\n");
        if (query("name")=="�õ�����֥��") return 0;
        set_name("�õ�����֥��", ({ "lan flower","flower" }) );
        set("long", "һ���õ�����֥����\n");
        set("value", 0);              
       set("no_get",1);
             message_vision("$N��������֥���ȳɽ�״��\n", this_player());
       environment()->she_come(this_player());
                return 1;
}

