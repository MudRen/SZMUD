// July 31,2000 
// Code by jiuer
// /gumu/milin11.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
�������У�һ�ɹ�����ɴ��ı�����ż���Ļ����������Բ�ʱ����
����ɢ�������������䣬����ݺݺ����ɫ��ɽ����һ�ء���һ�ص�׺����
�У���ֻ���ɫ���۷�������������һȦ���ַ���ɽ������ȥ�ˡ�������
����ȥ�����˱�����Գ������⣬�ƺ��������Ķ��߾���ï�ܵ����֡�
LONG);

        set("exits", ([
        "north" : __FILE__,
        "west" : __FILE__,
        "south" : __DIR__"milin2",
        "east" : __DIR__"milin1",
                      ]));

          set("cost",2);
    set("tjjob", 3);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}
