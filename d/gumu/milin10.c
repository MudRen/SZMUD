// July 31,2000
// Code by April
// /gumu/milin10.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
������������ת��ת��ת��ɽ�꣬��Ȼһ��Ժ컨��������ǰ�����
�컨�ſ����������ɣ����ܲ�㣬�����˱ǡ��ڴ˻�����ӡ�£��ƺ����
�������ڡ�
LONG);


        set("exits", ([
        "north" : __DIR__"milin"+(random(2)+7),
        "west" : __DIR__"milin"+(random(2)+7),
        "south" : __DIR__"milin"+(random(2)+7),
        "east" : __DIR__"milin"+(random(2)+7),
	"enter" : __DIR__"huawu",
                      ]));

          set("cost",1);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}
