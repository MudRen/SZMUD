// Sep 11,2001
// Code by jiuer
// /gumu/milin18.c

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
        "north" : __DIR__"huangshaling",
        "west" : __FILE__,
        "south" : __DIR__"milin19",
        "east" : __DIR__"milin8",
                      ]));

          set("cost",2);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}
