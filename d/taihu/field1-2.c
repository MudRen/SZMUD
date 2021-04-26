// Code of ShenZhou
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "���");
        set("long", @LONG
������һƬũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ
��һ������أ����д�����ų�һ�������֣�������һЩ���ڸ���
��ũ�ˣ���·��̰��·Ҳ���Դ���侮�ַָ��С��������
LONG
        );

        set("exits", ([
//                "northeast"  : "/d/forest/clforest1",
		"northwest"  : __DIR__"yixing",
        ]));

	set("outdoors","forest");
        set("objects", ([
                "/clone/beast/banjiu" : random(2),
        ]));

	set("cost", 2);
        setup();
//	replace_program(ROOM);
}
void init()
{	object room = this_object();
	object me = this_player();
	room->delete("exits/north");
	room->delete("exits/south");
	room->delete("exits/east");
	room->delete("exits/west");
	if (me->query_temp("last_exit") == "east")
			{
			set("exits/west",__DIR__"field1-1");
			me->delete_temp("last_exit");
			me->delete_temp("last_place");
			}	
	else if (me->query_temp("last_exit") == "west")
			{
			set("exits/east",__DIR__"field1-1");
			me->delete_temp("last_exit");
			me->delete_temp("last_place");
			}
			
	else if (me->query_temp("last_exit") == "north")
			{
			set("exits/south",__DIR__"field1-1");
			me->delete_temp("last_exit");
			me->delete_temp("last_place");
			}
	else if (me->query_temp("last_exit") == "south")
			{
			set("exits/north",__DIR__"field1-1");
			me->delete_temp("last_exit");
			me->delete_temp("last_place");
			}	
	else
	{switch(random(3)) {
	case(0):
		set("exits/east",__DIR__"field1-1");
		break;
	case(1):
		set("exits/west",__DIR__"field1-1");
		break;
	case(2):
		set("exits/north",__DIR__"field1-1");
		break;
	case(3):
		set("exits/south",__DIR__"field1-1");
		break;
		}
	}
}
int valid_leave(object me,string dir)
{
	if (dir == "east" )
		{
		me->set_temp("last_exit","east");
		me->set_temp("last_place","field1-2");
		write("���������ͻ���С���⣬���ĺ�����խ�����������˽�ȥ��\n");
		}
	if (dir == "west" )
		{
		me->set_temp("last_exit","west");
		me->set_temp("last_place","field1-2");
		write("���������ͻ���С���⣬���ĺ�����խ�����������˽�ȥ��\n");
		}
	if (dir == "south" )
		{
		me->set_temp("last_exit","south");
		me->set_temp("last_place","field1-2");
		write("���������ͻ���С���⣬���ĺ�����խ�����������˽�ȥ��\n");
		}
	if (dir == "north" )
		{
		me->set_temp("last_exit","north");
		me->set_temp("last_place","field1-2");
		write("���������ͻ���С���⣬���ĺ�����խ�����������˽�ȥ��\n");		
		}
			
	return ::valid_leave(me,dir);
}
