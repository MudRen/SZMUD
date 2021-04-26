// Code of ShenZhou
// road: /zhongnan/gate.c

#include <ansi.h>
inherit ROOM;
void init();
void close_gate();
int do_open();
int valid_leave();
string look_gate();


void create()
{
        set("short", HIR"����������"NOR);

        set("long",@LONG
�����ߵ�������ɽ��ɽ����ǰ�����ȫ��̵��ܲ��������ˡ�
������ɽ�������ߵʹ������¡���Χ��ľɭɭ��������֣���ɫ��
�ġ���ǰ����ǽ���ߣ��������ݣ�����һ�����������������ߵ�
���ɼľ��ͭ����(door)���Ϸ�һ����ң����ɷ�������š�����
�����������֡������ǹ㳡��
LONG);
        set("exits",([  //"northup" : __DIR__"dadian",
                        "southdown" : __DIR__"dajiaochang",
                      ])
           );

    set("outdoors", "shaolin");
    set("item_desc",([
        "door"        :    (: look_door :),
    ]));
    set("objects",([
		  CLASS_D("quanzhen") + "/pi" : 1,
	 ]));
	 set("cost", 1);
	 setup();
}

void init()
{
	 add_action("do_knock", "knock");
}

int close_door()
{
	 object room;

	 if(!( room = find_object(__DIR__"gate1")) )
		  room = load_object(__DIR__"gate1");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n",
            this_object());
        room->delete("exits/south");
        if (objectp(present("������", room)))
            message("vision", "��������ǰ�Ѵ��Ź���������\n", room);
        else
            message("vision", "�����ʿ��ǰ�Ѵ��Ź���������\n", room);
    }
    else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;
    string event=NATURE_D->outdoor_room_event();

    if (query("exits/north"))
        return notify_fail("�����Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "door" && arg != "north"))
        return notify_fail("��Ҫ��ʲô��\n");


    if(!( room = find_object(__DIR__"gate1")) )
        room = load_object(__DIR__"gate1");
	 if(objectp(room))
    {
        set("exits/north", __DIR__"gate1");
        message_vision("$N������������ţ�ֻ��֨��һ����"
            "һλ�����ʿӦ���򿪴��ţ�\n"
            "����ϸ�ؿ���$N���ۡ�\n",
            this_player());
        room->set("exits/south", __FILE__);
        message("vision", "���洫��һ���������������ʿӦ����ǰ�Ѵ��ſ���\n", room);
        remove_call_out("close_door");
        call_out("close_door", 10);
    }

    return 1;
}

int valid_leave(object me, string dir)
{
    if ( dir != "north" )
	 {
        return ::valid_leave(me, dir);
    }

    if (!::valid_leave(me, dir))
        return 0;

    if ( (me->query("family/family_name") == "ȫ���"))
    {
            write("�����ʿ�����ÿ���˵�������������ˣ������\n");
				return 1;
	}
    else 
	{
              if( present("incense", me) )
              {
                   write("�����ʿ�����ÿ���˵����ԭ���ǹ�ͼݵ�����������\n");
                   return 1;
              }
              else
              {
                   return notify_fail("�����ʿ˵����������ǽ��㣬��ذɡ�\n");
              }
	}
}

string look_door()
{
    return "����һ���������ߵ����ɫɼľ��ͭ���ţ������������һ���� (Knock door) ������\n";
}
