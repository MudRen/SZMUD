// July 31,2000
// Code by April
// /gumu/milin6.c

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
        "north" : __DIR__"milin2",
        "west" : __DIR__"milin7",
        "south" : __DIR__"milin13",
        "east" : __DIR__"milin5",
                      ]));

          set("cost",2);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}
