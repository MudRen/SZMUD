// July 31,2000
// Code by April
// /gumu/midao3.c

inherit ROOM;

void create()
{
	set("short", "�ܵ�");

    set("long",@LONG
�½���ԼĪ���ʱ������·��ƽ��ֻ��ʪ��ȴҲ���أ�����������ˮ
��ˮû���ף����ȶ������������롣��ֻ����һ�ɰ���������ˮ��������
�����߿��ܾ�Ҫ�����ˡ�
LONG);

          set("exits",([ "westup" : __DIR__"midao2",
                        "eastdown" : __DIR__"water1",
                         ])
                          );
          set("cost",5);

          setup();
}
