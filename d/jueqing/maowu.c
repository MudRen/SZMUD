// /d/jueqing/maowu.c  é��
// By jiuer

inherit ROOM;

void create()
{
	set("short","é��");
	set("long",@LONG 
�ߵ���é������֮�أ���������������ﾲ���ĵģ������������
Ω����������΢�졣é����ľͷé�ݴ��ƣ�һ�Ȱ���(door)΢΢���š�
LONG);
	
	set("exits",([ 
                "west" : __DIR__"garden",
		]));
	
	set("item_desc", (["door" :"��û����������������һ��(push)���š�\n"
		]));

	set("outdoors","jueqing");
	set("cost",1);
	setup();
}

void init()
{
	add_action("do_push","push");
}
int do_push(string arg)
{
	object me = this_player();
	if(!arg)
		return 0;
	if(arg = "door") 
	{
		message_vision("$N���ڹ�������������������ð�����ˣ�����ͼ�����\n",me);
               write("��˵���������������˻ش�\n");
		message_vision("$N��������һ�ư��š�\n",me);
                message_vision("�š�ѽ����һ�����ˡ�\n\n",me);
		set("exits/enter",__DIR__"shi1");
		remove_call_out("close_door");
		call_out("close_door",10,me);
	}
	return 1;
}
void close_door()
{
        tell_room(this_object(),"�š�ѽ����һ���ֹ����ˡ�\n");
	delete("exits/enter");

}
