inherit ITEM;

#include <ansi.h>
void create()
{
        set_name("�������ţ�⴮", ({ "niu rouchuan", "chuan" }) );
        set("long", "һ����yujie���ֿ�������ţ�⴮���������ܰ���^_^\n");
        set_weight(200);
        set("unit","��");
        setup();
}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");
}

int do_eat(string arg)
{

        if ( !arg || arg == "") { write("��Ҫ��ʲô��\n"); return 1;}

        if ( arg == "niu rouchuan" || arg == "chuan" ) {
        if ( random(2) )
        { message_vision(HIG"$N�����⴮���ҧ����ȥ��ֻ������һ��������2��������\n"NOR,this_player() );
        set_name("������", ({ "men ya", "mooth" }) );
        remove_action("do_eat", "eat");
        remove_action("do_eat", "chi");
        set("long", "һ�Ž��Ƶ�������\n�Ǻܶ���ǰ�㲻С��ˤ�����������������ȥ���ģ��������˻���ѽ��^_^\n" );
        set("unit","��");
        set("value",15000);
        return 1;
}
message_vision(HIG"$N�����⴮���ҧ����ȥ��ֻ������һ��������2��������\n"NOR,this_player() );
write(HIW"��������������Ϲ����ˣ���\n"NOR);
write("���ǿ�ϧ�ˡ�\n");
destruct(this_object());
return 1;
}
return 0;
}
