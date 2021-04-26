// Code of ShenZhou
// Room: damk.c

inherit ROOM;

#include <localtime.h>
#include <command.h>

void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();

void create()
{
	set("short", "���ſ���");
	set("long", @LONG
�������ؽ��򶫵Ĺŵ�����Ϊ��ɽ�ɲεĲο����ߣ����Ҳ�ơ���·��
��ǰ��һ��Сɽ�ض�ȥ·�����������ſ�����Ϊ��ȥ�ɲεĵ�һ�����ϣ���
����Ϊ���ſ��ӡ������ǿ������ɻ������ɻ����ڶ���ʱ�����ͨ�У�����  
������ֻ���Ҵ��Ұ�æ�ˡ�
LONG	);

	set("exits", ([ 
              "west" : __DIR__"chuanc",
              "southeast" : __DIR__"ermk",
        ]));

        set("outdoors", "changbai");
        set("cost", 3);

	setup();
}

int valid_leave(object me, string dir)
{
        mixed *local;
        object *ob;
        int i;

        if( dir == "west" ) {
                local = localtime(time()*60);
                if( local[LT_MON] > 3 && local[LT_MON] < 10 )
                        return notify_fail("�ɻ��������ˣ��㺰(yell)���������ɡ�\n");
                else {
                        ob = all_inventory(environment(me));
                        for(i=0; i<sizeof(ob); i++){
                                if( ob[i]->query("rider") == me )
                                        me->move(__DIR__"bingmian");
                        me->set_temp("new_valid_dest", __DIR__"bingmian");
                        tell_object(me, "�������ᶳ����׳���Ӳȱ�������\n");
                        }                 
                        return 1;
                }
        }

        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_yell", "yell");
}

int do_yell(string arg)
{
        mixed *local;
        string dir;

	local = localtime(time()*60);
        if( !(local[LT_MON] > 3 && local[LT_MON] < 10) ) 
                return 0;       

        if( !arg || arg=="" ) return 0;

        if( (int)this_player()->query("age") < 16 )
                message_vision("$Nʹ�����̵���������һ������" + arg + "��\n", this_player());
        else if( (int)this_player()->query("neili") > 500 )
                message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵ضԶ��"
                "�˳�ȥ��\n", this_player());
        else    message_vision("$N������������Хһ������" + arg + "����\n", this_player());

        if( arg == "����" ) {
                check_trigger();
                return 1;
        } else  message_vision("������ԶԶ����һ���������" + arg +
                "��������\n", this_player());
        return 1;
}

void check_trigger()
{
        object room;

        if( !query("exits/enter") ) {
        if( !(room = find_object(__DIR__"duchuan")) )
                room = load_object(__DIR__"duchuan");
        if( room = find_object(__DIR__"duchuan") ) {
                if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤��"
                    "����ϵ̰����Ա�˿�\n���¡�\n", this_object());
                message("vision", "������һ��̤�Ű���ϵ̰����γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
                } else
                message("vision", "ֻ���ý��������������������"
                "�����æ���š�����\n", this_object());
        }  else
                message("vision", "ERROR: boat not found\n", this_object() );
        } else 
                message("vision", "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n", this_object() );
}


void on_board()
{
        object room;

        if( !query("exits/enter") ) return;

        message("vision", "������̤�Ű��������������һ�㣬��������ʻȥ��\n", this_object());

        if( room = find_object(__DIR__"duchuan") ) {
                room->delete("exits/out");
                message("vision", "������̤�Ű���������˵��һ��������ඡ���"
                "���һ�㣬������\n����ʻȥ��\n", room);
        }

        delete("exits/enter");

        remove_call_out("arrive");
        call_out("arrive", 20);
}

void arrive()
{
        object room;

        if( room = find_object(__DIR__"duchuan") ) {
                room->set("exits/out", __DIR__"chuanc");
                message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű�"
                "���ϵ̰���\n",room );
        }

        remove_call_out("close_passage");
        call_out("close_passage", 20);
}

void close_passage()
{
        object room;

        if( room = find_object(__DIR__"duchuan") ) {
                room->delete("exits/out");
                message("vision","������̤�Ű����������ѱ���ʻ���ġ�\n", room);
                room->delete("yell_trigger"); 
        }
}

void reset()
{
        object room;

        ::reset();

        if( room = find_object(__DIR__"duchuan") )
                room->delete("yell_trigger"); 
}

