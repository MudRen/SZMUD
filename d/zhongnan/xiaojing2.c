// Code of ShenZhou
// road: /zhongnan/xiaojing2.c

inherit ROOM;

void create()
{
        set("short", "ɽ��С��");

        set("long",@LONG
����һ��λ�����ɽ�ţ���Ϊ��֪��С�������ܹ�ľ���죬���ֲԴ�
�����ɽ����֦ͷ���񳪺Ͳ����������Ͷ��Ͽ�ͨ��ɽ�����
LONG);

        set("exits",([ "west" : __DIR__"xiaojing3",
                        "southeast" : __DIR__"xiaojing1",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}

