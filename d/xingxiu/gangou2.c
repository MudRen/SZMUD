// Code of ShenZhou
// by haowen
// 09/10/98

inherit ROOM;

void create()
{
	set("short", "�ɹ�");
	set("long", @LONG
�����п�ѷ�����ʲ֮���һ��Ͽ�ȡ��ɹ����Ǹɿݵĺ�
�������ѵ��ڴ���֮�����ɽ�飬��ʱӿ������ʱ��ʧ���⣬
ƽʱ丵ν��ޡ���ʱ���׾��ǰ������飬���ʺ�����ͨ����
LONG
	);
	set("exits", ([
//            "eastdown" : __DIR__"shankou",
            "northup" : __DIR__"tianroad2",
            "westup" : __DIR__"tianroad3",
]));
	set("cost", 4);
	set("outdoors", "tianshan");

	setup();
//	replace_program(ROOM);
}
void init()
{
	object room = this_object();
	object me = this_player();
	room->delete("exits/north");
	room->delete("exits/south");
	room->delete("exits/east");
	room->delete("exits/west");
	
	if (me->query_temp("last_exit") == "east")
			{
			set("exits/west",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("lase_place");
			}	
	else if (me->query_temp("last_exit") == "west")
			{
			set("exits/east",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("lase_place");
			}	
	else if (me->query_temp("last_exit") == "north")
			{
			set("exits/south",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("lase_place");
			}
	else if (me->query_temp("last_exit") == "south")
			{
			set("exits/north",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("lase_place");
			}
	
	else{
	switch(random(3)) {
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
		me->set_temp("last_place","gangou2");
		write("����˲ȸɿݵĺӵף����ĺ���ƽ̹�����ĵ����˽�ȥ��\n");
		}
	if (dir == "west" )
		{
		me->set_temp("last_exit","west");
		me->set_temp("last_place","gangou2");
		write("����˲ȸɿݵĺӵף����ĺ���ƽ̹�����ĵ����˽�ȥ��\n");
		}
	if (dir == "south" )
		{
		me->set_temp("last_exit","south");
		me->set_temp("last_place","gangou2");
		write("����˲ȸɿݵĺӵף����ĺ���ƽ̹�����ĵ����˽�ȥ��\n");
		}
	if (dir == "north" )
		{
		me->set_temp("last_exit","north");
		me->set_temp("last_place","gangou2");
		write("����˲ȸɿݵĺӵף����ĺ���ƽ̹�����ĵ����˽�ȥ��\n");
		}
	return ::valid_leave(me,dir);
}
	