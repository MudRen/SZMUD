// Code of ShenZhou
// road: /zhongnan/midao2.c

inherit ROOM;

void create()
{
        set("short", "�ܵ�");

        set("long",@LONG
�ܵ���������ڣ����ֲ�����ָ����ֻ��Խ��Խ�ͣ�ʪ��ҲԽ��Խ��
����ʱ�ѿ���������ˮ�������Ϻ������Ǻںڵ�һƬ��
LONG);

		  set("exits",([ "westup" : __DIR__"midao1",
								"eastdown" : __DIR__"midao3",

                      ])
           );
	  set("cost",3);
	  setup();
}

