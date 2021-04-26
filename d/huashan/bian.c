// Code of ShenZhou
// bian.c �Һ�
// qfy July 14, 1996

inherit ROOM;

void create()
{
	set("short", "�Һ�");
	set("long", @LONG
�Һ�ط���С�����������������������ôҲ��������
LONG
	);

	set("exits", ([
		"down" : __DIR__"buwei1",
	]));
	
	set("zixia_count", 1);

	set("cost", 2);
	setup();
}

void init()
{
	add_action("do_use","use");
}

int do_use(string arg)
{
    object ob, me = this_player();
    int seed;	

    if( !arg || arg=="" ) return 0;
	
    if (!present("fire", me))  return 0;

    if ( me->query("family/family_name") == "��ɽ��" ) seed = 1;
    else if ( random(100) == 3 ) seed == 1;
    else seed = 0;

    if( arg=="fire" && seed == 1 ) {
	if ( query("zixia_count") >= 1 && !me->query_temp("marks/��") ) {
	   ob = new(__DIR__"obj/zixia_book");
	   if (!ob) 
	   return notify_fail("�㷢��ԭ����������������������֪�����к���ͼ��\n"); 
	   ob->move(me);
	   add("zixia_count", -1);
	   CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ������ϼ�ؼ���", me->query("name")));
           me->set_temp("marks/��", 1);
	   write("��ͻȻ����һ�������Ĳ��ӣ���ϸһ��ԭ���ǻ�ɽ��ɽ֮������ϼ���š���\n");
	   write("�㡸��ϼ���š�С�ĵ��պá�\n");
	}
	else {
	   write("�㷢��ԭ����������������������֪�����к���ͼ��\n");
	}
    }
    else write("�㷢��ԭ����������������������֪�����к���ͼ��\n");

    return 1;
}
