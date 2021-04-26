// Code of ShenZhou
// jiuguan.c
// xQin 7/00

inherit ROOM;
void init();
#include <ansi.h>
void create()
{
        set("short", "�����ƹ�");
        set("long", @LONG
�����Ǹ����Ų��õľƹݣ������µ��������м����ƿ��ںȾƳ�С�ˡ���
��������ʱʱ����Ȱ�ƣ��о��������������ʮ�����֡������Ǹ�������Ϣ��
�õط���¥���Աߵ�ľ������һ������(paizi)��¥����������              
LONG
        );

        set("exits", ([
                "east" : __DIR__"nandajie3",
                "up" : __DIR__"jiuguan2",

        ]));

        set("objects", ([
                __DIR__"npc/j_waiter" : 1,
                __DIR__"npc/zhang15" : 1,
        ]));
        set("item_desc", ([
                "paizi" : "���㻨��(Huasheng)            ��ʮ����ͭ��\n"
                          "��䶹��(Doufu)               ����ʮ����ͭ��\n"
                          "�վ�(fill_shaojiu)            ����ʮ��ͭ��\n"
                          "�׾�(fill_mijiu)              ����ʮ��ͭ��\n"
                          "�ھ�(fill_fenjiu)             ����ʮ����ͭ��\n"
        ]));

        set("cost", 0);
//        set("day_shop", 1);
        setup();
}
void init()
{
        add_action("do_fill_shaojiu", "fill_shaojiu");
        add_action("do_fill_mijiu", "fill_mijiu");
        add_action("do_fill_fenjiu", "fill_fenjiu");
        
}
int do_fill_shaojiu(string arg)
{
        object ob, obj, me = this_player();

        if (!objectp(obj = present("xiao er", environment(me))))
        {       write("�ƹ�С�����ڣ�\n");
                return 1;
        }

        if (!living(obj)){
                write("�㻹�ǵȾƹ�С���ѹ�����˵�ɡ�\n");
                return 1;
        }

        if (!arg || !(ob = present(arg, this_player())) || !ob->query("liquid")){
                write("��Ҫ�Ѿ�װ���Ķ���\n");
                return 1;
        }

        switch (MONEY_D->player_pay(this_player(), 20)) {
        case 0: {
                write("��⵰��һ�ߴ���ȥ��\n");
                return 1;
                }
        case 2: {
                write("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
                return 1;
                }
       }	
        if( ob->query("liquid/remaining") )
                message_vision("$N��" + ob->name() + "��ʣ�µ�" + ob->query("liquid/name") + 
                "������\n", this_player());
        message_vision("$N���ƹ�С����ʮ��ͭ�塣\n�ƹ�С����$N��"+ob->name()+"װ���վơ�\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        ob->set("liquid/type", "alcohol");
        ob->set("liquid/name", "�վ�");
        ob->set("liquid/remaining", query("max_liquid"));
        ob->set("liquid/drink_func", 0);
        ob->set("liquid/drunk_apply", 4);
        return 1;
}
int do_fill_mijiu(string arg)
{
        object ob, obj, me = this_player();
        
        if (!objectp(obj = present("xiao er", environment(me))))
        {       write("�ƹ�С�����ڣ�\n");
                return 1;
        }

        if (!living(obj)){
                write("�㻹�ǵȾƹ�С���ѹ�����˵�ɡ�\n");
                return 1;
        }

        if (!arg || !(ob = present(arg, this_player())) || !ob->query("liquid")){
                write("��Ҫ�Ѿ�װ���Ķ���\n");
                return 1;
        }

        switch (MONEY_D->player_pay(this_player(), 20)) {
        case 0: {
                write("��⵰��һ�ߴ���ȥ��\n");
                return 1;
                }
        case 2: {
                write("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
                return 1;
                }
       }	
        if( ob->query("liquid/remaining") )
                message_vision("$N��" + ob->name() + "��ʣ�µ�" + ob->query("liquid/name") + 
                "������\n", this_player());
        message_vision("$N���ƹ�С����ʮ��ͭ�塣\n�ƹ�С����$N��"+ob->name()+"װ���׾ơ�\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        ob->set("liquid/type", "alcohol");
        ob->set("liquid/name", "�׾�");
        ob->set("liquid/remaining", query("max_liquid"));
        ob->set("liquid/drink_func", 0);
        ob->set("liquid/drunk_apply", 3);
        return 1;
}
int do_fill_fenjiu(string arg)
{
        object ob, obj, me = this_player();
        
        if (!objectp(obj = present("xiao er", environment(me))))
        {       write("�ƹ�С�����ڣ�\n");
                return 1;
        }

        if (!living(obj)){
                write("�㻹�ǵȾƹ�С���ѹ�����˵�ɡ�\n");
                return 1;
        }

        if (!arg || !(ob = present(arg, this_player())) || !ob->query("liquid")){
                write("��Ҫ�Ѿ�װ���Ķ���\n");
                return 1;
        }

        switch (MONEY_D->player_pay(this_player(), 25)) {
        case 0: {
                write("��⵰��һ�ߴ���ȥ��\n");
                return 1;
                }
        case 2: {
                write("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
                return 1;
                }
       }	
        if( ob->query("liquid/remaining") )
                message_vision("$N��" + ob->name() + "��ʣ�µ�" + ob->query("liquid/name") + 
                "������\n", this_player());
        message_vision("$N���ƹ�С����ʮ����ͭ�塣\n�ƹ�С����$N��"+ob->name()+"װ���ھơ�\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        ob->set("liquid/type", "alcohol");
        ob->set("liquid/name", "�ھ�");
        ob->set("liquid/remaining", query("max_liquid"));
        ob->set("liquid/drink_func", 0);
        ob->set("liquid/drunk_apply", 5);
        return 1;
}