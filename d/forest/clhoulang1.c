//Cracked by Yujie
///d/forest/clhoulang1.c
// by yujie 10 / 2001

inherit ROOM;

#define DDR "/kungfu/class/changle/"

void create()
{
        set("short", "��������");
        set("long", @LONG
���ǳ��ְ����һ���ľ������ȣ����������˸����滨��ݣ�������
������Ŀ��������������������˽����������ʨ����������˽����װ�ζ�
ʮ�ֵĻ�����
LONG );
        set("exits", ([
		"north": __DIR__"clhoulang2",
		"south": __DIR__"clhoutang",
		"east" : DDR+"clsifang1",
		"west" : DDR+"clsifang2",
		
        ]));
	
        set("objects",(["/d/forest/npc/shicong" : 1 ]));
        setup();
       
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
                if (stringp (pos = me->query("clbpos")) && (pos != "ʨ����") && (me->query_temp("invite")!= "ʨ����"))
        		return notify_fail("��䲻�����Լ���˽����\n");
        		  
                if (!stringp (pos = me->query("clbpos")) && (me->query_temp("invite")!= "ʨ����"))
        		return notify_fail("����ʨ����������˽����û�б����벻�����Դ��롣\n");
        	
        	return ::valid_leave(me, dir);
	}
	
	return ::valid_leave(me, dir);
}
	
	
        

