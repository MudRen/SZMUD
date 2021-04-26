// Code of ShenZhou
// Room: /d/zhongnan/gate1.c
// Date: sdong 07/23/98

inherit ROOM;


void init();
void close_gate();
int do_open(string);
int do_close(string);
string look_gate();


void create()
{
		  set("short", "������");
        set("long", @LONG
��������������ǰ������������ש�̵أ����߸���һ��ľ������������
���Թ�ߵ�ݡ�������һ���������ߵ����ɼľ��ͭ����(door)��
LONG
		  );

		  set("exits", ([
					 "north" : __DIR__"taijie1",
		  ]));

		  set("item_desc",([
					 "door"          :       (: look_door :),
		  ]));
		  set("objects",([
					 __DIR__"npc/xiang-ke" : 1,
					 CLASS_D("quanzhen") + "/yin" : 1,
		  ]));
		  set("cost", 1);
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

        if(!( room = find_object(__DIR__"gate")) )
                room = load_object(__DIR__"gate");
        if(objectp(room))
        {
                delete("exits/south");
								message("vision", "�����ʿ��ǰ�Ѵ��Ź���������\n", this_object());
                room->delete("exits/north");
                message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n", room);
        }
}

int do_close(string arg)
{
        if (!query("exits/south"))
                return notify_fail("�����Ѿ��ǹ��ŵ��ˡ�\n");

        if (!arg || (arg != "door" && arg != "south"))
                return notify_fail("��Ҫ��ʲô��\n");

		  message_vision("$N�������ʿ���˵�ͷ��\n", this_player());

        remove_call_out("close_door");
		  call_out("close_door", 2);

        return 1;
}

int do_open(string arg)
{
        object room;

        if (query("exits/south"))
                return notify_fail("�����Ѿ��ǿ����ˡ�\n");

		  if (!arg || (arg != "door" && arg != "south"))
                return notify_fail("��Ҫ��ʲô��\n");

        if(!( room = find_object(__DIR__"gate")) )
                room = load_object(__DIR__"gate");
        if(objectp(room))
        {
                set("exits/south", __DIR__"gate");
                message_vision("$Nʹ���Ѵ��Ŵ��˿�����\n", this_player());
                room->set("exits/north", __FILE__);
                message("vision", "֨��һ�����������˰Ѵ��Ŵ��ˡ�\n", room);
                remove_call_out("close_door");
                call_out("close_door", 10);
        }

        return 1;
}

string look_door()
{
        return "һ���������ߵ����ɼľ��ͭ���š�\n";
}


int valid_leave(object me, string dir)
{
//        if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;
        return ::valid_leave(me, dir);
}
