// Code of ShenZhou
// road: /zhongnan/water2.c

inherit ROOM;

void create()
{
        set("short", "����ˮ��");

        set("long",@LONG
�ڵ���Ǳ����,��ֻ����ˮ�����,���Ӳ��������ı�ǿ���ˮ����ǰ
����.
LONG);

        set("exits",([ "west" : __DIR__"water1",
                        "eastup" : __DIR__"dong",

                      ])
           );
	  set("cost",5);

	  setup();
}


