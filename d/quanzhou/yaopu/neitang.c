// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ҩ�̵����ã����װ���һ����ܣ�������˲���ҽ�顣��
�⻹�м������Ρ����������ҩ�̽Ӵ����˵ĵط���
LONG
	);
	set("exits", ([ 
 	"out" : __DIR__"yaopu",
]));
	set("no_clean_up", 0);

	set("item_desc", ([
	"chair" : "һ�����ӣ�Ĩ�õúܸɾ����α�����˫�������ͼ����
�������̵�����������������צ������һ�������α�����ⷢ��������\n",
]));
	setup();
}


void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg == "" ) return 0;
	if( arg == "ball" || arg == "qiu") 
	{
		message_vision("$N�������׵ڶ������ϣ��������α�������һ������\n\n��������һ�գ����˴����䵽һ�������\n",me);
	me->move(__DIR__"mishi");
		return 1;
	}
	else
		return notify_fail("��Ҫ��ʲô��\n");
}
