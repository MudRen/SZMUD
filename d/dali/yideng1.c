// Code of ShenZhou
// yideng quest room 1
// acep

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
�˴�����ɽ��Ķ�����ɽ�崩�Ʋ��죬ɽʯ�����ɽ�żţ�ֻ
��һ�������ƵĴ��ٲ�(waterfall) �Ӷ���˫��֮�䱼�ڶ��£�����
���Ǿ��ˣ�ˮ����ɽ�ȼ伤�����죬������ڣ�����������ȥ���ٲ�
����һ����ݡ�
LONG
        );

	set("exits", ([
		"out" : __DIR__"maze1",
		]));

	set("objects", ([ 
		"/kungfu/class/dali/fisher" : 1,
        ]));

	set("item_desc", ([
		"waterfall" : "
��Ŀ�������ٲ�����������ͻȻ��ǰ�����˸��ˮ�������ζ���
������ȥ��ֻ��һ�Խ���������ɽʯ֮�У�����β��ȴ�����һΡ�",
		]) );

	set("invalid_startroom", 1);
	set("outdoor","dali");
	set("cost", 1);
	setup();
}

void init()
{
	add_action("do_dive", "dive");
}

int do_dive(string arg)
{
	object me = this_player();

	if ( !arg || arg != "waterfall" )
		return notify_fail( "ʲô��\n");

	message_vision("$N�����������ٲ��С�\n", me);
	if ( me->query_skill("dodge",1) <= 50 ) {
		message_vision("$N˫��һ��ˮ���ٲ��ļ�����������ҡ�һΣ�����վ�ȡ�һ����㷢��\n", me);
		message_vision("һ���Һ�����ɽ������Ӱ�����ˡ�\n", me);
		me->receive_wound("qi", me->query("max_qi")+100,"��ɽ��������");
	}

	if ( me->query_skill("dodge",1) > 50 && 
		me->query_skill("dodge",1) < 120 ) {
		message_vision("$N˫��һ��ˮ���ٲ��ļ���������ҡ�һΣ�����վ�ȡ�ֻ����������\n", me);
		message_vision("���������򰶱ߡ�\n", me);
		me->unconcious();
        }

	if ( me->query_skill("dodge",1) >= 120 ) {
		me->move(__DIR__"yideng2");
		message("vision", me->name()+"�����ˡ���һ������������\n",environment(me), ({me}) );
	}
	return 1;
} 

