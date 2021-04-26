//Cracked by Yujie
///d/forest/clhoulang1.c
// by yujie 10 / 2001

inherit ROOM;

#define DDR "/kungfu/class/changle/"

void create()
{
        set("short", "���Ⱦ�ͷ");
        set("long", @LONG
�������ȵľ�ͷ��������������������˽���������ǹ���ҡ�ǰ����
�Ե���һ�س��ص�ʯ�ţ�������һ�������Ȼ��Ȫ����ֻ����������Ȩ��
��ȥ���ܡ�
LONG );
        set("exits", ([
                "south": __DIR__"clhoulang4",
		"east" : DDR+"clsifang5",
		"west" : __DIR__"clguibin",
		
        ]));
	
             
        set("objects",([
               __DIR__"npc/cl_laopu" : 1,
               __DIR__"npc/shicong" : 1,
        ]));
        
        setup();

     
}

void init()
{	
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();
	
	if ( arg != "door")
	{	write("��Ҫ��ʲô��\n");
		return 1;
	}
	
	if (stringp ( me->query_temp("bangs/pos")) )
	{	message_vision("$N����ʯ���ϵĻ��أ�ʯ��Ӧ������\n",me);
		message_vision("$N�����˽�ȥ��ʯ�����������\n",me);
		me->move(__DIR__"shilu");
		tell_room(environment(me),me->name()+"�����˽�����\n",({me}));
		return 1;
	}
	
	write("�����ǳ��ְ��صأ�ֻ���������ϵ��˲��ܽ�ȥ�����Ǳ��Ҷ��ĺá�\n");
	return 1;
}

int valid_leave(object me, string dir)
{
        object ob;
	string pos;
	
        if ( dir == "east")
        {	
                if (stringp (pos = me->query("clbpos")) && (pos != "������") && (me->query_temp("invite")!= "������"))
        		return notify_fail("��䲻�����Լ���˽����\n");
        		  
                if (!stringp (pos = me->query("clbpos")) && (me->query_temp("invite")!= "������"))
        		return notify_fail("����������������˽����û�б����벻�����Դ��롣\n");
        	
        	return ::valid_leave(me, dir);
	}
	
	if ( dir == "west")
        {	
                if (!stringp ( me->query("clbpos")) && !stringp (me->query_temp("bangs/pos")) )
        		return notify_fail("���ֲ��ǹ�������ܽ�ȥ��\n");
        	      		        	
        	return ::valid_leave(me, dir);
	}
		
	return ::valid_leave(me, dir);
}

