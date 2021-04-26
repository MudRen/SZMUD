// Code of ShenZhou
inherit NPC_TRAINEE;

void create()
{
    set_name("Сë¿", ({"donkey", "maolu", "lu"}));
    set("race", "����");
    set("age", 10);
    set("auto_follow",1);
    set("attitude", "peaceful");

    set("wildness", 1);

    set("str", 30);
    set("con", 40);
    set("dex", 40);
    set("int", 20);
    set("combat_exp", 1000);

    set_weight(15000);
    set("unit", "ƥ");
    set("long", "һƥ��ɫ��Сë¿�������Ҳ�����Զ�����\n");
    setup();
}

void init()
{
    ::init();
    add_action("do_ride", "ride");
    add_action("do_unride", "unride");
}

int do_ride(string arg)
{
    object me, ob;
    me = this_object();
    ob = this_player();

    if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
    if( me->query_lord() == ob )  {
        if( !ob->query_temp("riding") ) {
            if( !me->query_temp("rider") )  {
                ob->set_temp("riding", me->name());
                me->set_temp("rider",  ob->name());
                me->set_leader(ob);

                message("vision",this_player()->name() + "������¿��ë¿һ�����ӣ�"
                       "��һ���"+this_player()->name() + "����¿����\n",
                        environment(me), ({me}) );
                write("�㷭������ë¿����һ�����ӣ������ų�һ���亹��\n");
                return 1;
            }
            else return notify_fail( me->query_temp("rider") + "�Ѿ��������������ˣ�\n");
        }
        else return notify_fail("���Ѿ�����" + ob->query_temp("riding") + "���ˣ�\n");
    }
    else return notify_fail("�㲻���������ˣ�\n");

    return 0;
}

int do_unride()
{
        object me, ob;
        me = this_object();
        ob = this_player();
        if( ob->query_temp("riding") == me->name() && me->query_temp("rider") == ob->name() ) 
        {
                ob->delete_temp("riding");
                me->delete_temp("rider" );
                message_vision("\n$Nһ������" + me->name() +"����Ծ��������\n", ob);
                return 1;
        }
        else return notify_fail("�㻹û�����أ�\n");

        return 0;
}
