// July 31,2000
// Code by jiuer
// /gumu/milin12.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
�������У�һ�ɹ�����ɴ��ı�����ż���Ļ����������Բ�ʱ����
����ɢ�������������䣬����ݺݺ����ɫ��ɽ����һ�ء���һ�ص�׺����
�У���ֻ���ɫ���۷�������������һȦ���ַ���ɽ������ȥ�ˡ�������
����ȥ���ƺ��������Ķ��߾���ï�ܵ����֡�
LONG);


        set("exits", ([
        "north" : __DIR__"milin5",
        "west" : __DIR__"milin13",
        "south" : __DIR__"milin17",
        "east" : __FILE__,
                      ]));

          set("cost",2);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}
