// July 31,2000
// Code by April
// /gumu/midao1.c

inherit ROOM;

void create()
{
        set("short", "�ܵ�");

        set("long",@LONG
�ܵ������һƬ�����ֲ�����ָ����ֻ��Խ��Խ�ͣ�ʪ��ҲԽ��Խ�ء�
������һ��С�����������Ǻںڵ�һƬ��
LONG);

          set("exits",([ "up" : __DIR__"mudao13",
                        "eastdown" : __DIR__"midao2", ])
                          );
          set("cost",3);

          setup();
}
