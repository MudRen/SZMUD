// Filename:   /d/jueqinggu/chufang.c
// Program:    Jiuer
// Date:       Aug 15, 2001

inherit ROOM;
int serve();

void create()
{
		  set("short","����");

		  set("long",@LONG
ׯ���˽�ʳ���ȣ��������ϡ�١��������󣬿�ǽ��һ����̨����
������������֧һ�ڴ������������æ���ղ�(serve)�� �Ա�С���ϰ�
�ż�����ˮ��ͼ��̳�ʣ����ʳ��
LONG);

	  set("exits",([ 
		  "south" : __DIR__"changlang5",
			 ]));
	  
	  set("cost",1);
	  setup();
}
void init()
{ 
	add_action("do_serve","serve");
}

int do_serve()
{
	object ob,me;
	me=this_player();

	message_vision("$N�����ҪЩʳ��Ժȡ�\n", me);

    if (!present("donggu", environment(me))
		&& !present("doufu", environment(me))
		&& !present("douya", environment(me))
	    && !present("donggu", me)
        && !present("doufu", me)
        && !present("douya", me))
	{
		switch(random(3)) {
        case 0:
			ob=new("/d/jueqing/obj/doufu");
            break;
		case 1:
			ob=new("/d/jueqing/obj/donggu");
			break;
		case 2:
			ob=new("/d/jueqing/obj/douya");
            break;
		}    
        ob->move(environment(me));
        message_vision("����˳�"+ob->name()+"��$N��\n", me);
	}
    else message_vision("�����$NЦ��������ô̰�����ѹ�����һ��Ĺ�����������\n", me);
    
    if (!present("migao", environment(me))
		&& !present("xiaowancha", environment(me))
		&& !present("huaban",environment(me))
        && !present("migao", me)
        && !present("xiaowancha", me)
		&& !present("huaban",me))
	{
        switch(random(3)) {
        case 0:
			ob=new("/d/jueqing/obj/migao");
            break;
		case 1:
			ob=new("/d/wudang/obj/xiaowancha");
            break;
		case 2:
			ob=new("/d/jueqing/obj/huaban");
			break;
		}
        ob->move(environment(me));
        message_vision("����˳�"+ob->name()+"��$N��\n", me);
	}
    else message_vision("�����$NЦ��������ô̰�����ѹ�����һ��Ĺ�����������\n", me);
    return 1;
}

int valid_leave(object me, string dir)
{
	if (present("doufu", me)
		|| present("douya", me)
        || present("donggu", me)
        || present("migao", me)
		|| present("huaban",me))
        return notify_fail("����������˵���������ǳ������߰ɡ���\n");
	return ::valid_leave(me, dir);
}