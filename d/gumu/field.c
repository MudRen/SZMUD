// Oct 31,2001
// Code by Jiuer
// /gumu/field.c

inherit ROOM;

void create()
{
        set("short","��ʯ��");

        set("long",@LONG
��������ɽ���Ͻǵ�һƬ��ʯ�أ������ߵ���ݼ����Ŵ��СС��ɽ
ʯ��ʯ������ǿ�ؼ����ż���֦Ҷï�ܵ��ɰء�
LONG);
		set("exits",([ 
			"west" : __DIR__"grassland",
			"south" : __DIR__"huangshaling",
			])
			);
          set("cost",1);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}

