// July 31,2000
// Code by April
// /gumu/milin9.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
�������У�һ�ɹ�����ɴ��ı�����ż���Ļ����������Բ�ʱ����
����ɢ�������������䣬����ݺݺ����ɫ��ɽ����һ�ء���һ�ص�׺����
�У���ֻ���ɫ���۷�������������һȦ���ַ���ɽ������ȥ�ˡ�������
����ȥ�����������и���ɳ�룬�ƺ��������Ķ��߾���ï�ܵ����֡�
LONG);


        set("exits", ([
        "north" : __FILE__,
        "west" : __DIR__"huangshaling",
        "south" : __DIR__"milin8",
        "east" : __DIR__"milin3",
                      ]));

          set("cost",3);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}
