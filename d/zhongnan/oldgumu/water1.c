// Code of ShenZhou
// road: /zhongnan/water1.c

inherit ROOM;

void create()
{
        set("short", "����ˮ��");

        set("long",@LONG
	�ڵ���Ǳ����,��ֻ����ˮ�����,���Ӳ��������ı�ǿ���ˮ����ǰ
����.
LONG);

        set("exits",([ "westup" : __DIR__"midao3",
                        "east" : __DIR__"water2",

                      ])
           );
	  set("cost",5);

		  setup();
}
