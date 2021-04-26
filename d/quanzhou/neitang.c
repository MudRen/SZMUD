// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ҩ�̵����ã����װ���һ����ܣ�������˲���ҽ�顣��
�⻹�м�������(chair)�����������ҩ�̽Ӵ����˵ĵط���
LONG
	);
	set("exits", ([ 
 	"out" : __DIR__"yaopu",
]));
	set("no_clean_up", 0);

	set("item_desc", ([
	"chair" : "һ�����ӣ�Ĩ�õúܸɾ����α�����˫�������ͼ����
�������̵�����������������צ������һ�������α�����ⷢ��������(Iron Ball)��\n",
]));
	setup();
}


void init()
{
	add_action("do_push","zhuan");
	add_action("do_push","turn");
}

int do_push(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg == "" ) return 0;
	if( arg == "ball" || arg == "qiu") 
	{
	message_vision("$N��������һ�����ӣ��������α�������һ������\n\n"+
	"���ӻ�����һ����ȥ��¶��һ��������Ĵ󶴡�\n",me);
        set("exits/down", __DIR__"yaopu_mishi");
        remove_call_out("close_door");
        call_out("close_door",15,me);	
		return 1;
	}
	else
		return notify_fail("��Ҫ��ʲô��\n");
}

void close_door()
{
	tell_room(this_object(),"���ӻ����ƻ�ԭλ����ס�˵ض���\n");
	delete("exits/down");
}
