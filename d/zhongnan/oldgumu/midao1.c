// Code of ShenZhou
// road: /zhongnan/midao1.c

inherit ROOM;

void create()
{
        set("short", "�ܵ�");

        set("long",@LONG
�ܵ���������ڣ����ֲ�����ָ����ֻ��Խ��Խ�ͣ�ʪ��ҲԽ��Խ��
��������һ��С�����������Ǻںڵ�һƬ��
LONG);

		  set("exits",([ "up" : __DIR__"shishi",
								"eastdown" : __DIR__"midao2",

							 ])
			  );
	  set("cost",3);

	  setup();
}

