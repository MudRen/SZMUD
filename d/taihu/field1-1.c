// Code of ShenZhou
//by haowen 
//09/10/98
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ����ء����ܵ����������ų�һ�������֣���
���������ȥ�����۾����̵أ��м伸����ֱ��С���⽻��
��һ��ʹ���ѱ涫�������ѹ�����˳����ǰ��С������ǰ
�߰ɡ�
LONG
	);

	set("cost", 4);
	set("outdoors", "forest");

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
        if (last=="field")
		next="field1-2";
	else next="field";
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
		write("���������С���⣬������ǰ��ȥ��\n");
		}
	if (dir == "west" )
		{
		write("���������С���⣬������ǰ��ȥ��\n");
		me->set_temp("last_exit","west");
		}
	if (dir == "south" )
		{
		write("���������С���⣬������ǰ��ȥ��\n");
		me->set_temp("last_exit","south");
		}
	if (dir == "north" )
		{
		write("���������С���⣬������ǰ��ȥ��\n");	
		me->set_temp("last_exit","north");
		}
	return ::valid_leave(me,dir);
}
	
