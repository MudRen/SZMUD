// Code of ShenZhou
//by haowen 
//09/10/98
inherit ROOM;

void create()
{
	set("short", "�ɹ�");
	set("long", @LONG
�����п�ѷ�����ʲ֮���һ��Ͽ�ȡ��ɹ����Ǹɿݵĺ�
�������ѵ��ڴ���֮�����ɽ�飬��ʱӿ������ʱ��ʧ���⣬
ƽʱ丵ν��ޡ�������ǰ������飬��������ߵ�ȴ����
���ױ��巽λ�����ѹ�����˳����ǰ����ϡ�ɱ����·��ǰ
�߰ɡ�
LONG
	);

	set("cost", 4);
	set("outdoors", "tianshan");

	setup();
//	replace_program(ROOM);
}
void init()
{
	object room = this_object();
	object me = this_player();
	string last,next;
	room->delete("exits/north");
	room->delete("exits/south");
	room->delete("exits/east");
	room->delete("exits/west");
	last=me->query_temp("last_place");
	if (last=="yinshan")
		next="gangou2";
	else next="yinshan";
	switch(random(3)) {
	case(0):
		if (me->query_temp("last_exit") != "west" )
 			set("exits/east",__DIR__+next);
		else 	
			set("exits/west",__DIR__+next);
		break;
	case(1):
		if (me->query_temp("last_exit") != "east" )
 			set("exits/west",__DIR__+next);
		else 
			set("exits/east",__DIR__+next);
		break;
	case(2):
		if (me->query_temp("last_exit") != "north" )
 			set("exits/south",__DIR__+next);
		else 	
			set("exits/north",__DIR__+next);
		break;
	case(3):
		if (me->query_temp("last_exit") != "south" )
 			set("exits/north",__DIR__+next);
		else 	
			set("exits/south",__DIR__+next);
		break;
		}
	if (me->query_temp("last_exit") == "east")
		set("exits/west",__DIR__+me->query_temp("last_place"));
	if (me->query_temp("last_exit") == "west")
		set("exits/east",__DIR__+me->query_temp("last_place"));
	if (me->query_temp("last_exit") == "north")
		set("exits/south",__DIR__+me->query_temp("last_place"));
	if (me->query_temp("last_exit") == "south")
		set("exits/north",__DIR__+me->query_temp("last_place"));

}
int valid_leave(object me,string dir)
{
	if (dir == "east" )
		{
		me->set_temp("last_exit","east");
                  write("����Ÿɿݵĺӵף��첽��ǰ��ȥ��\n");
		}
	if (dir == "west" )
		{
                  write("����Ÿɿݵĺӵף��첽��ǰ��ȥ��\n");
		me->set_temp("last_exit","west");
		}
	if (dir == "south" )
		{
                  write("����Ÿɿݵĺӵף��첽��ǰ��ȥ��\n");
		me->set_temp("last_exit","south");
		}
	if (dir == "north" )
		{
                  write("����Ÿɿݵĺӵף��첽��ǰ��ȥ��\n");
		me->set_temp("last_exit","north");
		}
	return ::valid_leave(me,dir);
}
	
