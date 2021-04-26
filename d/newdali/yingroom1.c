// Code of ShenZhou
inherit ROOM;

void create()
{
	set("short", "��̶");
	set("long", @LONG
������һ��Ƭ����̶����ǰ��ȥ����ǰһ��ãã�������һ��һԲ����é�ݣ�
����ԼԼ�еƹ�ӷ������������é�������޻�����������û��һ������֪����
ǽ(wall)�Ǳ���Щʲô��
LONG);
	set("item_desc",([
		"wall" : "һ�¿��������Ǻܸߵ���ǽ��\n",
		]));
	set("exits", ([
		"north" : "/d/dali/maze1",
		]));
	set("cost", 4);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali" );
	set("invalid_startroom", 1);
	setup();
}
void init()
{
	add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	object me = this_player();

	if ( !arg || arg != "wall") return notify_fail( "ʲô��\n");
	message_vision("$N��������ǽ����ȥ��\n", me);
	if ( me->query_skill("dodge",1) <= 50)
	{
		message_vision("$Nͨ��һ��ˤ������̶�����������\n", me);
		me->receive_wound("qi", 100);
	}
	if ( me->query_skill("dodge",1) > 50 )
	{
		me->move("/d/dali/yingroom2");
		message("vision", me->name() + "������ǽ�����˹�����\n",environment(me), ({me}) );
	}
	return 1;
} 
