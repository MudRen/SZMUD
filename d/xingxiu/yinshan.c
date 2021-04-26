// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
�����п�ѷ�����ʲ֮���һ��Ͽ�ȣ��ֽ����ɹ����ɹ�֮����
���鴫�����ѵ��ڴ���֮�����ɽ�飬��ʱӿ������ʱ��ʧ���⣬ƽ
ʱ丵ν��ޡ��������¸��ǿ����Ѱ�������ȴ��һ�ÿɳ�����С��Ҳ
û�С��������ﾢ�ã�����������������ͨ����һ������ͨ�����߱�
��ͨ����
LONG
	);
	set("exits", ([
            "eastdown" : __DIR__"shankou",
//            "north" : __DIR__"tianroad2",
//            "westup" : __DIR__"tianroad3",
]));
	set("cost", 4);
	set("outdoors", "tianshan");

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
			set("exits/west",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("last_place");
			}	
	else if (me->query_temp("last_exit") == "west")
			{
			set("exits/east",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("last_place");
			}
			
	else if (me->query_temp("last_exit") == "north")
			{
			set("exits/south",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("last_place");
			}
	else if (me->query_temp("last_exit") == "south")
			{
			set("exits/north",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("last_place");
			}	
	else
	{switch(random(3)) {
	case(0):
		set("exits/east",__DIR__"gangou1");
		break;
	case(1):
		set("exits/west",__DIR__"gangou1");
		break;
	case(2):
		set("exits/north",__DIR__"gangou1");
		break;
	case(3):
		set("exits/south",__DIR__"gangou1");
		break;
		}
	}
}
int valid_leave(object me,string dir)
{
	if (dir == "east" )
		{
		me->set_temp("last_exit","east");
		me->set_temp("last_place","yinshan");
		write("����˲ȸɿݵĺӵף����ĺ���ƽ̹�����ĵ����˽�ȥ��\n");
		}
	if (dir == "west" )
		{
		me->set_temp("last_exit","west");
		me->set_temp("last_place","yinshan");
		write("����˲ȸɿݵĺӵף����ĺ���ƽ̹�����ĵ����˽�ȥ��\n");
		}
	if (dir == "south" )
		{
		me->set_temp("last_exit","south");
		me->set_temp("last_place","yinshan");
		write("����˲ȸɿݵĺӵף����ĺ���ƽ̹�����ĵ����˽�ȥ��\n");
		}
	if (dir == "north" )
		{
		me->set_temp("last_exit","north");
		me->set_temp("last_place","yinshan");
		write("����˲ȸɿݵĺӵף����ĺ���ƽ̹�����ĵ����˽�ȥ��\n");
		}
			
	return ::valid_leave(me,dir);
}
	