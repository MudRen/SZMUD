/*-------------------------------------------------------------
** �ļ���: xiaolu1.c
** Copyright (c) 2000-2001
** ������: ��ݹ�����
** ��  ��: 2001/08/13
** ��  ��: ��ɽС��
**-----------------------------------------------------------*/

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","��ɽС��");

        set("long",@LONG
����һ��ͨ����ɽ���ּ�С·����Χ����໨�ݺ���ľ���Ϸ���һ��
Сľ��(door)����ͨ����ݵġ�
LONG);

         set("exits",([ 
                "northeast" : __DIR__"houshan",
//		"west"   : __DIR__"xiaojing2",
                 ]));

        set("item_desc", ([
                "door" : "����Դ�(open)����\n",
                         ]));   
        
//	create_door("south","ľ��","north",DOOR_CLOSED);	
         set("outdoors", "wuguan" );
         set("cost",1);
	 set("no_fight", 1);
         set("no_steal", 1);
         set("no_hit", 1);

     setup();
}

void init()
{
	  add_action("do_open", "open");
	  add_action("do_close", "close");
}


void close_door()
{
	 object room;

	 if(!( room = find_object(__DIR__"zhengting")) )
		  room = load_object(__DIR__"zhengting");
    if(objectp(room))
    {
        delete("exits/south");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n",this_object());
        room->delete("exits/north");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", room);
    }
    else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_close(string arg)
{
	object room;
        if (!query("exits/south"))
                return notify_fail("ľ���Ѿ��ǹ��ŵ��ˡ�\n");

        if (!arg || (arg != "door" && arg != "south" && arg != "men"))
                return notify_fail("��Ҫ��ʲô��\n");

        if(!( room = find_object(__DIR__"zhengting")) )
                room = load_object(__DIR__"zhengting");
	delete("exits/south");
	message_vision("$N����ذ�Сľ�Ź��ϡ�\n", this_player());
        room->delete("exits/north");
        message("vision", "�������˰�ľ�Ź����ˡ�\n", room);
        return 1;
}

int do_open(string arg)
{
        object room;

        if (query("exits/south"))
                return notify_fail("ľ���Ѿ��ǿ����ˡ�\n");

        if (!arg || (arg != "door" && arg != "south" && arg != "men"))
                return notify_fail("��Ҫ��ʲô��\n");

        if(!( room = find_object(__DIR__"zhengting")) )
                room = load_object(__DIR__"zhengting");
        if(objectp(room))
        {
                set("exits/south", __DIR__"zhengting");
                message_vision("$N����ذ�ľ�Ŵ򿪡�\n", this_player());
                room->set("exits/north", __FILE__);
                message("vision", "֨��һ�����������˰�ľ�Ŵ��ˡ�\n", room);
                remove_call_out("close_door");
                call_out("close_door", 40);
        }

        return 1;
}
