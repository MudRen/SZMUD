// Code of ShenZhou
// furong.c


#include <ansi.h>
#include <room.h>
inherit ROOM;

varargs static void
create_food(string nmstr, string* idlist, string longstr)
{
        object obj;

        obj = new(__DIR__"obj/food");
        obj->set_name(nmstr, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", GRN+"һ����������, �������"+nmstr+"��\n"+NOR);
        obj->move(this_object());
}

varargs static void
create_water(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new(__DIR__"obj/water");
        obj->set_name(cup, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", YEL+"һ���ɿڵ�" + nmstr + "��\n" + NOR);
        obj->set("liquid/name", nmstr);
        obj->move(this_object());
}

varargs static void
create_wine(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new(__DIR__"obj/wine");
        obj->set_name(cup, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", RED+"һ��������" + nmstr + "��\n" + NOR);
        obj->set("liquid/name", nmstr);
        obj->move(this_object());
}

void create()
{
        set("short", HIY"ܽ������"NOR);
        set("long", @LONG
�����ƹ�һ�����̳����磬ӭ��ǽ�Ϲ���һ����ܽ�س�ˮ��ͼ�����ʲʻ棬
״�����ţ�����׿�������ڳ����ݻ���������һ�ŵ��ľ����Ƕ���Բ������
��ʮ���������������ֺ�ľ�Σ��������磬�������ԡ������������¥��ܽ����
������ƽ����һ�ݲ˵�(menu)��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"datang",
        ]));
        set("no_sleep_room",1);
        set("item_desc", ([
                "menu": @TEXT
�а��ʽ��ϯ�� ��ӭ�ݹˣ�

        order birthday: ף����        (ʮ���ƽ�)

        order marry:    ������        (ʮ�����ƽ�)

        order player:   Ⱥ����        (��ʮ���ƽ�)

        order end:      ��  ��

TEXT
        ]) );
//        create_door("out", "��ľ�λ���", "enter", DOOR_CLOSED);
	set("no_clean_up", 0);
        setup();
        set("no_user", 1);
}

void init()
{
        object me;
        string id;
        me = this_player();
        id = me->query( "id" );

        add_action("do_order", "order");
        add_action("do_broadcast", "broadcast");
        if (query("order_owner")) {
                me = this_player();
                me->set("food", me->query("food") / 2);
                me->set("water", me->query("water") / 2);
        }
        if ( id == "mariner" || id == "buwu" || id == "jiuer" || id == "marinera" )
        {
            add_action( "admSet", "mset" );
            add_action( "admYao", "myao" );
        }    
}

int do_broadcast(string arg)
{
        string type;
        string mesg;
        object me;

        me = this_player();
        if (query("order_owner") != me->query("id"))
                return 0;
        type = query("order_type");
        if (type == "marry") {
                mesg = me->name() + "����������¥ܽ�������ж��������  !!!\n";
        } else if (type == "birthday") {
                mesg = me->name() + "����������¥ܽ������������������  !!!\n";
        } else if (type == "player") {
                mesg = me->name() + "����������¥ܽ���������·Ӣ�ۺ���  !!!\n";
       }
        message("channel:chat", HIY+"��ͨ�桿"+mesg+NOR, users() );  
        return 1;
}
int admSet( string arg )
{
    object obj;
    string name, vname;
    int val;
    if ( sscanf( arg, "%s skill %s %d", name, vname, val ) == 3 )
    {
        obj = find_player( name );
        if ( !obj ) obj = find_living( name );
        if ( obj )
       {
            obj->set_skill( vname, val );
            obj->save();
        }
    }
    else if ( sscanf( arg, "%s condition %s %d", name, vname, val ) == 3 )
    {
        obj = find_player( name );
        if ( !obj ) obj = find_living( name );
        if ( obj )
            obj->apply_condition( vname, val );
    }
    else if ( sscanf( arg, "%s improve %s %d", name, vname, val ) == 3 )
    {
        obj = find_player( name );
        if ( !obj ) obj = find_living( name );
        if ( obj )
        {
            obj->improve_skill( vname, val );
            obj->save();
        }
    }
    else if ( sscanf( arg, "%s add %s %d", name, vname, val ) == 3 )
    {
        obj = find_player( name );
        if ( !obj ) obj = find_living( name );
        if ( obj )
        {
            obj->add( vname, val );
            obj->save();
        }
    }
    else if ( sscanf( arg, "%s %s %d", name, vname, val ) == 3 )
    {
        obj = find_player( name );
        if ( !obj ) obj = find_living( name );
        if ( obj )
        {
            obj->set( vname, val );
            obj->save();
        }
    }
    return 0;
}

int admYao( string arg )
{
    object obj, me = this_player();
    obj = new( arg );
    if (!objectp(obj))
        return 0;
    if( !obj->is_character() && obj->move(me) )
    {
        return 0;
    }
    return 0;
}

int do_order(string arg)
{
        object me, env;
        object* oblist;
        string mesg;
        int idx;

        me = this_player();
        env = this_object();
        mesg = query("order_owner");
        if (mesg && (arg == "end") && (mesg == me->query("id"))) {
                mesg = "ܽ��������ϯ�����ˣ�\n";
                message("channel:chat", HIY+"��ͨ�桿"+mesg+NOR, users() );
                delete("order_owner");
                delete("order_type");
                oblist = all_inventory(env);
                for(idx=0; idx<sizeof(oblist); idx++) {
                        if (!objectp(oblist[idx]))
                                continue;
                        if (userp(oblist[idx]))
                                continue;
                        destruct(oblist[idx]);
                }
                return 1;
        }
        if (mesg)
                return notify_fail("�Բ��������Ѿ����˰����ˡ�\n");
         notify_fail("��û���㹻��Ǯ����Ǯ������\n");
        if (arg == "marry") {
                mesg = me->name() + "����������¥ܽ�������ھ���ϲ�磡\n";
                if (me->can_afford(150000) == 0)
                        return 0;
                me->pay_money(150000);
                create_water(HIG"������"NOR, ({ "tea" }), MAG"��ɰ����"NOR );
                create_water(RED"�ն���"NOR, ({ "tea" }), WHT"ˮ��յ"NOR );
                create_wine(WHT"�׾�"NOR, ({ "wine" }), HIW"�´ɱ�"NOR );
                create_wine(GRN"��Ҷ��"NOR, ({ "wine" }), GRN"��䱭"NOR );
                create_wine(YEL"���˻ƾ�"NOR, ({ "wine" }), HIY"������"NOR );
                create_wine(HIR"Ů����"NOR, ({ "wine" }), MAG"��̴��"NOR );
                create_wine(WHT"ę́��"NOR, ({ "wine" }), YEL"�̽�"NOR );
                create_wine(RED"�𻨾�"NOR, ({ "wine" }), WHT"������"NOR );
                create_food(YEL"���ֻ���"NOR,({"peanut"}) );
                create_food(HIR"�������"NOR,({"jujube"}) );
                create_food(RED"ϲ��"NOR,({"sugar"}) );
                create_food(HIW"���͹���"NOR,({"melon seeds","seeds"}) );
                create_food(HIG"���ݴ���"NOR, ({ "spring roll","roll" }) );
                create_food(HIC"��Ƭ����"NOR, ({"fish"}) );
                create_food(HIW"������˺��"NOR, ({"chicken"}) );
                create_food(HIR"��������"NOR, ({"fish"}) );
                create_food(HIY"����ˮ��"NOR, ({ "dumpling" }) );
                create_food(RED"���ô�Ϻ"NOR, ({ "prawn","dish" }) );
                create_food(HIR"�ͼ��з"NOR, ({ "crab" }) );
                create_food(HIY"������"NOR, ({ "meat" }) );
                create_food(YEL"з�ƶ���"NOR, ({ "bean curd","doufu" }) );
        } else if (arg == "birthday") {
                mesg = me->name() + "����������¥ܽ�������ھ������磡\n";
                if (me->can_afford(100000) == 0)
                        return 0;
                me->pay_money(100000);
                create_water(GRN"�����"NOR, ({ "tea" }), MAG"��ɰ����"NOR );
                create_water(HIG"��ɽ����"NOR, ({ "tea" }), RED"����յ"NOR );
                create_water(HIW"����"NOR, ({ "milk" }), WHT"������"NOR );
                create_wine(RED"���껨��"NOR, ({ "wine" }), HIW"�δɱ�"NOR  );
                create_wine(WHT"����Һ"NOR, ({ "wine" }), WHT"������"NOR );
                create_wine(WHT"�׾�"NOR, ({ "wine" }), HIW"�´ɱ�"NOR );
                create_wine(HIR"�ſ���"NOR, ({ "wine" }), HIG"��ͭ��"NOR  );
                create_wine(HIW"͸ƿ��"NOR, ({ "wine" }), WHT"������"NOR  );
                create_food(HIY"���ݰǼ�"NOR, ({ "chicken" }) );
                create_food(HIG"���ݴ���"NOR, ({ "spring roll","roll" }) );
                create_food(HIC"��Ƭ����"NOR, ({"fish"}) );
                create_food(HIR"������ͷ"NOR, ({"meat","pork"}) );
                create_food(RED"�����Ƭ"NOR, ({"fish meat","meat"}) );
                create_food(RED"���⴮"NOR, ({ "mutton" }) );
                create_food(HIR"�����Ѽ�"NOR, ({ "fish","dish" }) );
                create_food(HIY"������Ѽ"NOR, ({ "duck" }) );
                create_food(YEL"������"NOR, ({ "meat" }) );
                create_food(HIW"��ϲ����"NOR, ({ "bean curd" }) );
        } else if (arg == "player") {
                mesg = me->name() + "����������¥ܽ���������·Ӣ�ۺ��ܣ�\n";
                if (me->can_afford(200000) == 0)
                        return 0;
                me->pay_money(200000);
                create_food(YEL"�л���"NOR, ({ "chicken" }) );
                create_food(HIW"��ϲ����"NOR, ({ "bean curd" }) );
                create_food(HIG"���ݴ���"NOR, ({ "spring","roll" }) );
                create_food(HIC"��Ƭ����"NOR, ({"fish"}) );
                create_food(RED"���⴮"NOR, ({ "mutton" }) );
                create_food(HIY"��֦����"NOR, ({"rice"}) );
                create_food(HIR"������˿"NOR, ({"fish meat","meat"}) );
                create_food(HIY"���ݰǼ�"NOR, ({ "chicken" }) );
                create_food(RED"�����Ѽ�"NOR, ({ "fish","dish" }) );
                create_food(HIY"������Ѽ"NOR, ({ "duck" }) );
                create_food(HIW"��ն��"NOR, ({ "chicken" }) );
                create_food(YEL"������"NOR, ({ "meat" }) );
                create_food(GRN"��Ҷ����"NOR, ({ "chicken","dish" }) );
                create_food(HIR"��������"NOR, ({ "fish" }) );
                create_food(RED"�����Ƭ"NOR, ({"fish meat","meat"}) );
                create_food(HIR"������ͷ"NOR, ({"meat","pork"}) );
                create_food(HIW"������˺��"NOR, ({"chicken"}) );
                create_food(HIR"��������"NOR, ({"fish"}) );
                create_food(HIY"����ˮ��"NOR, ({ "dumpling" }) );
                create_water(HIW"����"NOR, ({ "milk" }), CYN"�໨��"NOR );
                create_water(GRN"�����"NOR, ({ "tea" }), MAG"��ɰ����"NOR );
                create_water(GRN"���ݴ�"NOR, ({ "tea" }), MAG"��ɰյ"NOR );
                create_water(HIG"��ɽ����"NOR, ({ "tea" }), RED"����յ"NOR );
                create_water(HIR"��ë��"NOR, ({ "tea" }), CYN"����յ"NOR );
                create_wine(HIW"�ھ�"NOR, ({ "wine" }), WHT"��֬����"NOR );
                create_wine(WHT"����׾�"NOR, ({ "wine" }), YEL"Ϭ�Ǳ�"NOR );
                create_wine(RED"���Ѿ�"NOR, ({ "wine" }), HIW"ҹ�Ɑ"NOR );
                create_wine(WHT"������"NOR, ({ "wine" }), CYN"��ͭ��"NOR );
                create_wine(HIG"�ٲݾ�"NOR, ({ "wine" }), RED"���ٱ�"NOR );
                create_wine(HIR"״Ԫ��"NOR, ({ "wine" }), WHT"�Ŵɱ�"NOR );
                create_wine(GRN"�滨��"NOR, ({ "wine" }), HIG"��䱭"NOR );
                create_wine(HIW"��¶��"NOR, ({ "wine" }), WHT"������"NOR );
        }
         else {
                return notify_fail("��Ҫ��ʲô��ϯ?\n");
        }
        message("channel:chat", HIY+"��ͨ�桿"+mesg+NOR, users() );
        set("order_owner", me->query("id"));
        set("order_type", arg);
        return 1;
}
int valid_leave(object me, string dir)
{
        if (me->query("id") != query("order_owner"))
                return 1;
        return notify_fail(HIY + "���� order end ������������뿪��\n" + NOR);
}

