// August 1 31,2000
// Code by April
// /gumu/mishi.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
����Ҳ������֮�����Ҷ����������д�����ּ����ţ����Ҵ�д����
�����֣��������澭�������Ͻǻ���һ��ͼ�������书�޹أ�����ϸ����
�����Ƿ���ͼ��ԭ����Ĺ�������г�Ĺͨ����
LONG);

	  set("cost",1);

		  setup();
}

void init()
{
        add_action("do_push","push");
}

int do_push()
{
        object me;
        me = this_player();

        message_vision("$N�������ƣ�һ��ͨ���ͳ����ˡ� 
		\n\n",me);
        set("exits/out", __DIR__"mushi");
        remove_call_out("close_door");
        call_out("close_door",15,me);   
        return 1;
}

void close_door()
{
        tell_room(this_object(),"��һ������׵�ʯ����������ˡ�\n");
        delete("exits/out");
}
