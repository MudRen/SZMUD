// Code of ShenZhou
// taomu.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(YEL"��ľ"NOR,({ "taomu"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "wood");
                set("long", "����һ�������������տ��µ���ľ���Լӵ���(cut)�ȿ�����һ����ľ����\n");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(2);
        setup();
}

void init()
{
        add_action("do_cut", "cut");
}

int do_cut(string arg)
{
        object ob1, ob2, me;

        me = this_player();

        if (me->is_busy()
        || me->query_temp("pending/exercising")
        || me->query_temp("exit_blocked"))
                return notify_fail("��������æ���ء�\n");

        if (!arg || arg != "taomu")
                return notify_fail("��Ҫ���ʲ�᣿\n");

        if( !objectp(ob1 = me->query_temp("weapon"))
        || (string)ob1->query("name") != "С����")
                return notify_fail("��û�й�����ε�̣���\n"); 

        message_vision(CYN"$N����С��������ľ��ϸ�ĵ�������......\n"NOR, me);

        if (random(2) == 1) {
        message_vision(CYN"$Næ�˰��죬���ڵ��һ�Ѵֲڵ���ľ�������ڽ����Ͽ������֡�\n"NOR, me);
        ob2 = new(__DIR__"taomujian");
        ob2->set("long", "����һ�������������ֹ��Ƴɵ���ľ�����ƺ�����һ���ñ�����\n"
                         "�����Ͽ��š�"+me->name()+"�������֡�\n");
        ob2->set("owner", me->query("id"));
        ob2->move(me);
        destruct(this_object());
        } else {
        message_vision(CYN"$Nһ����С�ģ�����ѽ�����꣡������ľ�ϵ��ˣ�\n"NOR,me);
        destruct(this_object());
        }

        return 1;
}
