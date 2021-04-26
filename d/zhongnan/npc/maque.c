// maque.c ��ȸ
// Xuanyuan
#include <room.h>
#include <command.h>
inherit NPC;

void create()
{
        set_name("��ȸ", ({ "ma que", "que", "bird" }) );
        set("race", "����");
        set("age", 3);
        set("long", "һֻߴߴ������������ȥ��С��ȸ��\n");
        set("attitude", "peaceful");

        set("str", 10);
        set("dex", 100);
        set("combat_exp", 100);
        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
        set("chat_chance", 10);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "С��ȸߴߴ�����Ļ����ţ�����ͷ���Ϸ�����ȥ��\n",
                "С��ȸ����ͣ��ǽͷ�������������ң�æµ����ʳ�ԡ�\n",
        }) );

        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "С��ȸߴߴߴ��ŭ���ţ�ȫ�����ë������������\n",
        }) );

        setup();
}

void init()
{
        add_action("do_catch", "zhuo");
        add_action("do_catch", "zhua");
        add_action("do_catch", "catch");
        add_action("do_flee", "fang");
        add_action("do_flee", "throw");
}

int do_catch(string arg)
{
        object room, dest, me = this_player(), ob = this_object();
        string dir, *dirs;
        mapping exits;
        int ap;

        if( !living(me) ) return 0;

        if( !arg || !(arg == "ma que" || arg == "que" || arg == "bird") )
                return notify_fail("��Ҫץʲô��\n");

        if( present(arg, environment(me)) != ob )
                return notify_fail("");

        if( !living(ob) )
                return notify_fail("���õ���ץ��?\n");

        if( environment(ob) == me )
                return notify_fail("���Ѿ�ץס���ˡ�\n");

//      if( environment(ob) != find_object("/d/gumu/gmlg1") )
//              return notify_fail("���������ץ��ȸ�ĵط���\n");

	if( me->query("family/family_name") != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");

	if ( (int)me->query_skill("dodge", 1) > 101 )
		return notify_fail("�㲻���������˷�ʱ�侫���ˡ�\n");

        if ( (int)me->query("qi") < 60 && (int)me->query("jing") < 40 )
                return notify_fail("��̫����, ����Ϣһ�¡�\n");

	message("\n$NͻȻ��$n��ȥ��\n", me, ob);

        me->receive_damage("jing", 10 + random(10), "����͸֧��������");
        me->receive_damage("qi", 20 + random(10), "����͸֧��������");

        ap = (int)me->query_skill("force") + (int)me->query_skill("dodge");
        if( ap < 1 ) ap = 1;
        ap = ap * me->query_dex() / 20;
        ap = random(ap);

        if( ap < 10 ) {
                message_vision("���$N����һչ�ᣬ�ɵ��˰�ա�\n", ob);
                room = environment(me);
                if( !mapp(exits = room->query("exits")) )  return 1;

                dirs = keys(exits);
                for( int i = 0; i < sizeof(dirs); i ++ )
                        if( room->query_door(dirs[i], "status") & DOOR_CLOSED )
                          dirs -= ({dirs[i]});
                if( sizeof(dirs) < 1 ) return 1;
                dir = dirs[random(sizeof(dirs))];

                message_vision("$Nһת�۱�������Ұ����ʧ�ˡ�\n", ob);
                GO_CMD->main(ob, dir);

                dest = find_object(exits[dir]);
                message_vision("$N��" + dir + "��������ˡ�\n", ob);
                ob->move(dest);
                message_vision("$Nߴߴ�����ط��˹�����\n", ob);


        } else if( ap < 20 ) {
                message_vision("���$N������һ�������˿�ȥ��\n", ob);
        } else {
                message_vision("���$Nһ���ӱ�ץס��$n��\n", me, ob);
                ob->move(me);
                ob->set_temp("chat_msg", ob->query("chat_msg"));
                ob->delete("chat_msg");
                me->improve_skill("dodge", me->query("dex",1));

		if(me->query_skill("tianluo-diwang", 1) > 0) 
                	me->improve_skill("tianluo-diwang", me->query("dex",1)/2);

		me->add("combat_exp",1+random(2));
        }

        return 1;
}

int do_flee(string arg)
{
        object me = this_player();
        object ob = this_object();

        if( !living(me) ) return 0;

        if( !arg || !(arg == "ma que" || arg == "que" || arg == "bird") )
                return notify_fail("��Ҫ��ʲô��\n");

        if( present(arg, me) != ob )
                return notify_fail("");

        message_vision("$N����һ�ɣ�$n�����ŷɿ��ˡ�\n", me, ob);

        ob->move(environment(me));
        ob->set("chat_msg", ob->query_temp("chat_msg"));
        ob->delete_temp("chat_msg");

        return 1;
}