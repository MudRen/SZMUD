// July 31,2000
// Code by April
// d/gumu/shishi5.c

inherit ROOM;

void create()
{
        set("short","ʯ��");

        set("long",@LONG
����һ����ͨʯ�ң����пտն��������ͱ��Ĺ�����졣����һ�Ƿ�
��һ����ʯ�������������Ų�ϯ��һ���ײ�����������������ޱ����
����һЩ���ӣ���֪��ʲô�á�
LONG);

	 set("exits",([ 
		"west" : __DIR__"mudao18",
		 ])
			  );

	 
	 set("objects", ([
		 "/kungfu/class/gumu/obj/hanyu_chuang" : 1,
		 ]));
	  
	 set("cost",1);

     setup();

}

int valid_leave(object me, string dir)
{
	if (me->query_temp("onbed")) return notify_fail("�㻹���ȴӺ����������ɣ�\n");

	return ::valid_leave(me, dir);
}
