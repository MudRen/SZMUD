// Code of ShenZhou
// road: /zhongnan/xiaojing1.c

inherit ROOM;

void create()
{
        set("short", "ɽ��С��");

        set("long",@LONG
����һ��λ�����ɽ�ţ���Ϊ��֪��С�������ܹ�ľ���죬���ֲԴ�
�����ɽ����֦ͷ���񳪺Ͳ����������ɿ���һ����·����������ͨ��ɽ
�����
LONG);

        set("exits",([ "northwest" : __DIR__"xiaojing2",
                        "east" : __DIR__"daolu",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}



