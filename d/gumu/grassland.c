// Oct 31,2001
// Code by Jiuer
// /gumu/grassland.c

inherit ROOM;

void create()
{
        set("short","��ݵ�");

        set("long",@LONG
����ɽ����һ�����б�£���������Ҫ����С�ģ��Է���������֮�С�
���������һСƬƽ�ش�������б����˵Ҳ�������ɣ��Ƶ���������ϣ�
˳�Ųݵ���ѹƽ��һ��·�߿�Ѱ�����ԣ�Խ�����ֻ�Խ�ܡ�
LONG);
		set("exits",([ 
			"east" : __DIR__"field",
			"south" : __DIR__"river",
			])
			);
          set("cost",1);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}

