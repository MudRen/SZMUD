// July 31,2000
// /gumu/huangshaling.c

inherit ROOM;

void create()
{
        set("short","��ɳ��");

        set("long",@LONG
�˴�λ�����ɽ������ֻ��Զ������ԭ�ϣ�������һ���ɻ�ɳ�ѻ���
�ɵ�ɽ�룬�䲨����Ϊ���ء��ݵ�����˵���������̳�ʱ�ڵ�һλ����½
���ɵ��ˣ��÷���ǲ����һ�ɻ�ɳ�ѻ����ɡ�������һƬ���֣�������һ
Ƭ��ʯ�֡�
LONG);

        set("exits",([ 
			"east" : __DIR__"milin9",
			"west" : __DIR__"river",
			"south" : __DIR__"milin18",
			"north" : __DIR__"field",
			]));

          set("cost",1);
          set("outdoors", "gumu");

        setup();

        replace_program(ROOM);
}

