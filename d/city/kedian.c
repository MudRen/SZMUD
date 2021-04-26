//Cracked by Kafei
// Room: /city/kedian.c
// YZC 1995/12/04
// sdong 3/2/2000
#include <localtime.h>
#include <ansi.h>
inherit ROOM;

// Marz added indecent or inapproapriate id check here :
string* Banned_id = ({
                  "ufk",
                  "none",
});
int do_close_men();
int do_open_men(string arg);


void create()
{
        mixed *local;
        object *ob;
        local = localtime(time());

        set("short", HIC"�͵�"NOR);
        set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ��������ţ����
����������������صķ������顣��С����������æ������ת���Ӵ�����ǻ����
�Ŀ��ˡ��͵�����˴Ӳ�¶�棬��������˭���и��ָ����Ĳ²⡣ǽ�Ϲ���һ��
����(paizi)��������һ����ǡ�
LONG
        );

//      set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹ����������\n",
//              "vortex" : 
//"���ƺ��Ǵ�˵���ᵽ���Ĵ��͵㣬���͵���Ǳ߿��������ã�Ҳ���ǵ�����\n",
        ]));

        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
        ]));


    if( local[LT_HOUR] == 2 || local[LT_HOUR] == 4 || 
                local[LT_HOUR] == 6 || local[LT_HOUR] == 8 || 
                local[LT_HOUR] >= 10 && local[LT_HOUR] <= 12 
                )
        {
                set("exits", ([
                        "east" : __DIR__"beidajie1",
                        "up" : __DIR__"kedian2",
                        "north" : __DIR__"majiu",
                        "south" : __DIR__"yizhan",
                        "west" : __DIR__"huadian",
                        "enter" : "/d/bwdh/square",
                        ]));
        }
        else
        {
                set("exits", ([
                        "east" : __DIR__"beidajie1",
                        "up" : __DIR__"kedian2",
                        "north" : __DIR__"majiu",
                        "south" : __DIR__"yizhan",
                        "west" : __DIR__"huadian",
                        ]));
        }

        setup();

        "/clone/board/kedian_b"->foo();
//      "/clone/board/jiangpai_b"->foo();
}



int do_open_men(string arg)
{
        object me = this_player();
        object room;

        if (query("exits/enter"))
                  return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");

        if (!arg || (arg != "men" && arg != "west"))
                  return notify_fail("��Ҫ��ʲô��\n");

        if ( (string)SECURITY_D->get_status(me) != "(arch)" && (string) SECURITY_D->get_status(me) != "(admin)" && (string) SECURITY_D->get_status(me) != "(caretaker)" && (string) SECURITY_D->get_status(me) != "(designer)" && (string) SECURITY_D->get_status(me) != "(wizard)" )
                  return notify_fail("ʲô��\n");

        log_file("status_log", sprintf( "%s opened sjsz door on %s.\n", me->query("id"), ctime(time()) ));

        set("exits/enter", "/d/bwdh/square");
        message_vision("$N����ָ���һ�㣬֨��һ������һ�����š�\n", this_player());

        return 1;
}

int do_close_men()
{       
        object me=this_player();
        if ( (string)SECURITY_D->get_status(me) != "(arch)" && (string) SECURITY_D->get_status(me) != "(admin)" && (string) SECURITY_D->get_status(me) != "(caretaker)" && (string) SECURITY_D->get_status(me) != "(designer)" && (string) SECURITY_D->get_status(me) != "(wizard)" )
                  return notify_fail("��Ҫ�ر�ʲô��\n");
        if (!query("exits/enter"))
                  return notify_fail("�������Ѿ��ǹ��ϵġ�\n");

        delete("exits/enter");
        message("vision", "���������ع����ˡ�\n", this_object());
        return 1;
}

// the following is for a Diablo discussion room
// it's only temporary, maybe for a month or so,
// i'll remove it afterwards.  --ding
//void init()
//{
//      add_action("do_enter", "enter");
//}

//int do_enter(string arg)
//{
//      object me;
//      me = this_player();
//      if (arg =="vortex") {
//                        message("vision",
//              me->name() + "������ǽһֱ���˹�ȥ���߽�ǽ�ﲻ���ˡ�\n",
 //                       environment(me), ({me}) );
//                        me->move("/u/ding/diablo_r1");
 //                       message("vision",
//me->name() + "������ͻȻƾ�ճ���������ǰ��\n",
//                        environment(me), ({me}) );
//                return 1;
//        } else 
//        return notify_fail("��Ҫ�������\n");
//}
// end of my temp. code --ding


int valid_leave(object me, string dir)
{
        string id;
        int i;

        if(me == present("xiao er"))
                return ::valid_leave(me, dir);

        if(objectp(present("xiao er", environment(me)))) {
                if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

                if ( me->query_temp("rent_paid") && dir != "up" )
                return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");
        }

                  id = (string)me->query("id");
        for (i = 0; i < sizeof(Banned_id); i++)
        {
        if (id == Banned_id[i])
        {
                me->set("startroom", "/d/death/block");
                me->move("/d/death/block");
                return notify_fail("�ٺ٣��������ܵ�����ȥ����\n");
        }
                  }

                if( dir=="enter" ) {
        me->delete("bwdh"); // clean record when enter bwdh field
                }


        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_dial", "dial");
        add_action("do_open_men", "open");
        add_action("do_close_men", "close");
}

int do_dial(string arg)
{
        object me = this_player();
                if ( !arg || arg != "1-900-NOBODYHOME" )
             return notify_fail( "������Ҫ���˭��\n");
        if ( me->query("family/family_name") == "������") {
                tell_object(me,
                        "��ֻ����һ����ȣ�"+RANK_D->query_rude(me)+"���㻹�Ҵ�绰���ţ��ȸ��⳥�ѣ���\n");
                return 1;
        }
        if ( me->query("family/family_name") == "������") {
                tell_object(me,
                        "���������һ���ƹ����¼�����Բ���û���ڼң�Ǯ��û�յ������Ժ�\n");
                return 1;
        }
        tell_object(me,
                "�Բ���û���ڼң���������Э��ֻ�������������������й���ʦ��ӳ������⣡\n");
        return 1;
}

