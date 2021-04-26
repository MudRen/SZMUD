// Code of ShenZhou
// ��ɽ��ɽҰ�֣�
// qfy 26/6/1996

inherit ROOM;

void create()
{
        set("short", "��ɽҰ��");
	set("long", @LONG
���ǻ�ɽ��ɽ��һƬ��ɽҰ�֣����ܶ���һ����߾��ޱȵĴ�������
��ï�ܵ�֦Ҷ�����ཻ֯�ţ���������������͸��ʹ���в�������֮�С�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"yelin2",
  		"west" : __DIR__"yelin2",
		"south" : __DIR__"yelin2",
		"north" : __DIR__"yelin2",
	]));

	set("cost", 4);
        setup();
}

int valid_leave(object me, string dir)
{
	me->add_temp("marks/��", 1);
	me->add("jingli", -10);

	if ( me->query_temp("marks/��") == 3 ) {
	   set("exits/northeast", __DIR__"yelin2");
	   set("exits/northwest", __DIR__"yelin2");
	   set("exits/southeast", __DIR__"yelin2");
	   set("exits/southwest", __DIR__"yelin2");
	   delete("exits/east");
	   delete("exits/west");
	   delete("exits/north");
	   delete("exits/south");
	}
	else if( me->query_temp("marks/��") == 6 ) {
	  set("exits/west", __DIR__"yelin2");
	  set("exits/north", __DIR__"yelin2");
	  delete("exits/northeast");
	  delete("exits/southeast");
	}
	else if( me->query_temp("marks/��") == 9 ) {
	  set("exits/east", __DIR__"yelin2");
	  set("exits/south", __DIR__"yelin1");
          set("exits/northeast", __DIR__"yelin2");
          set("exits/southeast", __DIR__"yunu");
          set("exits/southwest", __DIR__"yelin1");
	  delete("exits/west");
	  delete("exits/north");
	  delete("exits/northwest");
	  write("���ڻ�ɽҰ���������Ҵ���ȴ�Ҳ�����·�����ú��ۡ�\n" );
	}
	else if( me->query_temp("marks/��") == 10 && dir == "southeast" ) {
	  write( "�㼸�����ѣ������߳��˻�ɽҰ�֡���е�ʮ��ƣ�������ǸϿ���Ϣ�ɡ�\n" ); 
	  me->delete_temp("marks/��");
          set("exits/east", __DIR__"yelin2");
          set("exits/west", __DIR__"yelin2");
          set("exits/south", __DIR__"yelin2");
          set("exits/north", __DIR__"yelin2");
	  delete("exits/northeast");
          delete("exits/southwest");
          delete("exits/southeast");
	}
	else if( me->query_temp("marks/��") == 10 && dir != "southeast" ) {
	  me->delete_temp("marks/��");
	  set("exits/east", __DIR__"yelin2");
	  set("exits/west", __DIR__"yelin2");
	  set("exits/south", __DIR__"yelin2");
	  set("exits/north", __DIR__"yelin2");
	  delete("exits/northeast");
	  delete("exits/southwest");
	  delete("exits/southeast");
	  write("���ڻ�ɽҰ���������Ҵ���ȴ�Ҳ�����·�����ú��ۡ�\n" );
	}
	else {
	  write("���ڻ�ɽҰ���������Ҵ���ȴ�Ҳ�����·�����ú��ۡ�\n" );
	}
	
	return 1;
}

void init()
{
	add_action("do_drop","drop");
}

int do_drop(string arg)
{
        object obj, obj2, me = this_player();
        int i, amount;
        string item;

        if(!arg) return notify_fail("��Ҫ����ʲô������\n");

        if(!objectp(obj = present(arg, me)))
                return notify_fail("������û������������\n");

	message_vision( sprintf("$N����һ%s$n��\n", obj->query("unit")), me, obj );
	message_vision("һֻ���ӡ�ಡ���һ�����˹���������"+(string)obj->name()+"���ܽ����ֲ�������\n", me);
	destruct(obj);

	return 1;
}
