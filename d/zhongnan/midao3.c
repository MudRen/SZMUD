// Code of ShenZhou
// road: /zhongnan/midao3.c

inherit ROOM;

void create()
{
        set("short", "�ܵ�");

        set("long",@LONG
�ܵ���������ڣ����ֲ�����ָ��ˮ����������ϥ�ǣ����Ҳ�������
���������롣��ֻ����һ�ɰ���������ˮ�������������߿��ܾ�Ҫ�����ˡ�
�����Ǻںڵ�һƬ��������Ҫ����ˮ���ˡ�
LONG);

		  set("exits",([ "westup" : __DIR__"midao2",
								"eastdown" : __DIR__"water1",

							 ])
			  );
	  set("cost",3);

	  setup();
}


