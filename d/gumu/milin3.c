// July 31,2000
// Code by April
// /gumu/milin3.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
�������У�һ�ɹ�����ɴ��ı�����ż���Ļ����������Բ�ʱ����
����ɢ�������������䣬����ݺݺ����ɫ��ɽ����һ�ء���һ�ص�׺����
�У���ֻ���ɫ���۷�������������һȦ���ַ���ɽ������ȥ�ˡ�������
����ȥ���ƺ��������Ķ��߾���ï�ܵ����֣����б����ƺ�������Ĺ����
���ɰ�֮�䡣
LONG);


        set("exits", ([
        "north" : __DIR__"gumu",
        "west" : __DIR__"milin9",
        "south" : __DIR__"milin7",
        "east" : __DIR__"milin2",
                      ]));

          set("cost",2);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}
