// July 31,2000
// Code by jiuer
// /gumu/milin14.c

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
        "north" : __DIR__"milin7",
        "west" : __DIR__"milin10",
        "south" : __DIR__"milin15",
        "east" : __DIR__"milin13",
                      ]));

          set("cost",2);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}
