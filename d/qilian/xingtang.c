// Code of ShenZhou
// Summer 9/12/96
// Qfy 26/12/98
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��ս�������;���һ������ӭ��������������һ�����ɶ�ߵĻ�
¯���������һЩ�պ�����������������˴�Ŀ���ģ�ʹ�˸е��������
������֮��ȷ�ǲ�������õ����и�С��(door)ͨ���η���
LONG
        );

        set("exits", ([
                "south" : __DIR__"houtin",
		"west" : __DIR__"jinqu",
        ]));

	set("objects", ([
            __DIR__"npc/rysj_guard" : 2,
        ]));

	set("cost", 1);
	setup();
}

void init()
{
	object *guard, me = this_player();
        int i, j;

        if ( interactive(me) ) {
                guard = all_inventory(environment(me));

                for ( i=0; i<sizeof(guard); i++ ) {
                        if ( guard[i]->query("id") == "rysj weishi" ) {
                                guard[i]->kill_ob(me);
                                j++;
                        }
                }

                if ( j ) message_vision("��ʿ������$N�ȵ��������ô������ͼ���ˣ���������\n", me);
	}

	add_action("do_open", "open");
}

int do_open(string arg)
{
	object *guard, room, me=this_player();
	int i, j;

	if ( !arg || arg=="" ) return notify_fail("ʲô��\n");

	if ( !( room = find_object(__DIR__"dilao")) )
                room = load_object(__DIR__"dilao");

	if ( arg == "door" ) {
	   guard = all_inventory(environment(me));

           for ( i=0; i<sizeof(guard); i++ ) {
          	if ( guard[i]->query("id") == "rysj weishi" ) {
           	     	guard[i]->kill_ob(me);
                	j++;
                }
           }

	   if ( j ) {
		message_vision("��ʿ����$N�ȵ������У��������ڱ���ү���¾��ˣ�\n", me);
		return 1;
	   }
	   else {
		message_vision("$N��ǽ��һ��Ħ�������˻�����ť������һ�������ű��Զ������ˡ�\n", me);
		set("exits/down", __DIR__"dilao");
		room->set("exits/up", __DIR__"xingtang");
		message("info", "���Ż����ؿ����ˣ�����\n", room);
		remove_call_out("close_door");
		call_out("close_door", 10, room);
	   }
	}

	return 1;
}

int close_door(object room)
{
	object *rooms;

	rooms = ({ this_object(), room});

	delete("exits/down");
        room->delete("exits/up");
	message("info", "�����ֻ������Զ������ˣ�����\n", rooms);

	return 1;
}
	
/*
int valid_leave(object me, string dir)
{
	object room;

	if ( !( room = find_object(__DIR__"dilao")) )
                room = load_object(__DIR__"dilao");

        if( dir != "down" && ) {
		delete("exits/down");
		room->delete("exits/up");
        }

        return ::valid_leave(me, dir);
} 
*/
